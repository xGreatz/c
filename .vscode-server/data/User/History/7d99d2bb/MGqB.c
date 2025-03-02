#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *combineArgs(char **args) {
    if (args[1] == NULL) return NULL; 

    int length = 0;
    for (int i = 1; args[i] != NULL; i++) {
        length += strlen(args[i]) + 1; 
    }

    char *path = malloc(length);
    if (!path) {
        perror("Memory allocation failed");
        return NULL;
    }

    path[0] = '\0'; 
    for (int i = 1; args[i] != NULL; i++) {
        strcat(path, args[i]);
        if (args[i + 1] != NULL) strcat(path, " "); 
    }

    return path;
}


void cd(char **args) {
    char *path = combineArgs(args);
    if (path == NULL) {
        fprintf(stderr, "Usage: cd <path>\n");
        return;
    }

    printf("Trying to change directory to: %s\n", path); 

    if (chdir(path) != 0) {
        perror("cd failed");  
    } else {
        printf("Changed directory to: %s\n", path);
    }

    free(path);
}


int main() {
    char *args1[] = {"cd", "OneDrive", "-", "Ariel", "University", NULL};
    cd(args1); 
    return 0;
}