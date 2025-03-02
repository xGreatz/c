#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void mypipe(char **arg1, char **arg2) {
    int pipefd[2];
    pid_t pid1, pid2;
    // יצירת צינור

    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }
    // יצירת תהליך ראשון
    pid1 = fork();
    if (pid1 == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) { 
        printf("Running first command: %s\n", arg1[0]);
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        if (execvp(arg1[0], arg1) == -1) {
            perror("Exec 1 failed");
            exit(EXIT_FAILURE);
        }
    }
  // יצירת תהליך שני
    pid2 = fork();
    if (pid2 == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) { 
        printf("Running second command: %s\n", arg2[0]);
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        if (execvp(arg2[0], arg2) == -1) {
            perror("Exec 2 failed");
            exit(EXIT_FAILURE);
        }
    }
 // תהליך האב סוגר את הצינור וממתין לסיום התהליכים
    close(pipefd[0]);
    close(pipefd[1]);
    
    wait(NULL);
    wait(NULL);
}
// פונקציה ראשית לבדיקה
int main() {
    char *arg1[] = {"ls", "-l", NULL};   
    char *arg2[] = {"grep", "g", NULL};  

    printf("Executing pipe: ls -l | grep g\n");
    mypipe(arg1, arg2);

    return 0;
}
