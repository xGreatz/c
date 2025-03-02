#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mypipe(char **arg1, char **arg2) {
    int pipefd[2]; // צינור בין שני התהליכים
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

    if (pid1 == 0) { // תהליך הבן הראשון
        close(pipefd[0]); // סוגר את קצה הקריאה של הצינור
        dup2(pipefd[1], STDOUT_FILENO); // מפנה את הפלט הסטנדרטי לצינור
        close(pipefd[1]); // סוגר את קצה הכתיבה לאחר השכפול

        // הרצת הפקודה הראשונה
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

    if (pid2 == 0) { // תהליך הבן השני
        close(pipefd[1]); // סוגר את קצה הכתיבה של הצינור
        dup2(pipefd[0], STDIN_FILENO); // מפנה את הקלט הסטנדרטי לצינור
        close(pipefd[0]); // סוגר את קצה הקריאה לאחר השכפול

        // הרצת הפקודה השנייה
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
    char *arg1[] = {"ls", "-l", NULL};    // פקודה ראשונה
    char *arg2[] = {"grep", "g", NULL};   // פקודה שנייה

    mypipe(arg1, arg2); // חיבור ls -l עם grep g

    return 0;
}
