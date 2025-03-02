#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// פונקציה לספירת שורות בקובץ
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

// פונקציה לספירת מילים בקובץ
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

// פונקציה עיקרית לספירת מילים או שורות בקובץ
void wordCount(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Usage: wordCount <option: -l/-w> <file_path>\n");
        return;
    }

    char *option = args[1];   // סוג הספירה
    char *file_path = args[2]; // הנתיב לקובץ

    // פתיחת הקובץ לקריאה
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int result = 0;
    if (strcmp(option, "-l") == 0) {  // ספירת שורות
        result = countLines(file);
    } else if (strcmp(option, "-w") == 0) {  // ספירת מילים
        result = countWords(file);
    } else {
        fprintf(stderr, "Invalid option: %s\n", option);
        fclose(file);
        return;
    }

    fclose(file);
    printf("%d %s %s\n", result, option, file_path);
}

// פונקציה ראשית לבדיקה
int main() {
    char *args1[] = {"wordCount", "-l", "testFile.txt", NULL}; // ספירת שורות
    char *args2[] = {"wordCount", "-w", "testFile.txt", NULL}; // ספירת מילים

    wordCount(args1);
    wordCount(args2);

    return 0;
}
