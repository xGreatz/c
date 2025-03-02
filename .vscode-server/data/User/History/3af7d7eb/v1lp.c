#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void echowrite(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Usage: echowrite <string> <file_path>\n");
        return;
    }

    char *text = args[1];       
    char *file_path = args[2]; 

   
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }


    fprintf(file, "%s\n", text);
    fclose(file);

    printf("Text written to '%s' successfully.\n", file_path);
}


int main() {
    char *args1[] = {"echowrite", "hello world", "testFile1.txt", NULL};
    echowrite(args1);

    return 0;
}
