#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void echoppend(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Usage: echoppend <string> <file_path>\n");
        return;
    }

    char *text = args[1];      
    char *file_path = args[2]; 

  
    FILE *file = fopen(file_path, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }


    fprintf(file, "%s\n", text);
    fclose(file);

    printf("Text appended to '%s' successfully.\n", file_path);
}


int main() {
    char *args1[] = {"echoppend", "hello world", "testFile.txt", NULL};
    echoppend(args1);

    return 0;
}
