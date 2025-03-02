#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int countLines(FILE *file) {
    int lines = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }
    return lines;
}


int countWords(FILE *file) {
    int words = 0;
    char ch, prev = ' ';
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch) && !isspace(prev)) {
            words++;
        }
        prev = ch;
    }
    return words;
}


void wordCount(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Usage: wordCount <option: -l/-w> <file_path>\n");
        return;
    }

    char *option = args[1];  
    char *file_path = args[2]; 

   
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int result = 0;
    if (strcmp(option, "-l") == 0) {  
        result = countLines(file);
    } else if (strcmp(option, "-w") == 0) {  
        result = countWords(file);
    } else {
        fprintf(stderr, "Invalid option: %s\n", option);
        fclose(file);
        return;
    }

    fclose(file);
    printf("%d %s %s\n", result, option, file_path);
}


int main() {
    char *args1[] = {"wordCount", "-l", "testFile.txt", NULL}; 
    char *args2[] = {"wordCount", "-w", "testFile.txt", NULL}; 

    wordCount(args1);
    wordCount(args2);

    return 0;
}
