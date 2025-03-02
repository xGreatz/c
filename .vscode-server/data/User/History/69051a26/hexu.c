#include <stdio.h>
#include <stdlib.h>


void readFile(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Usage: read <file_path>\n");
        return;
    }

    char *file_path = args[1]; 

   
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

   
    char line[1024];  
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file); 
}


int main() {
    char *args1[] = {"read", "testFile2.txt", NULL};
    readFile(args1);

    return 0;
}
