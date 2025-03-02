#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// פונקציה להעתקת קובץ
void cp(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Usage: cp <source_file> <destination_file>\n");
        return;
    }

    char *source = args[1];
    char *destination = args[2];

    FILE *src = fopen(source, "rb");  // פתיחת קובץ מקור לקריאה בינארית
    if (!src) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(destination, "wb");  // פתיחת קובץ יעד לכתיבה בינארית
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    char buffer[4096]; // באפר לקריאה וכתיבה
    size_t bytesRead;

    // קריאה מהמקור וכתיבה ליעד
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    // סגירת הקבצים
    fclose(src);
    fclose(dest);

    printf("File copied successfully from '%s' to '%s'\n", source, destination);
}

// פונקציה ראשית לבדיקה
int main() {
    char *args1[] = {"cp", "source.txt", "destination.txt", NULL};
    cp(args1);

    return 0;
}
