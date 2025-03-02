#include <stdio.h>
#include <stdlib.h>

// פונקציה לקריאת תוכן קובץ והדפסתו למסך
void readFile(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Usage: read <file_path>\n");
        return;
    }

    char *file_path = args[1];  // הנתיב לקובץ

    // פתיחת הקובץ לקריאה
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // קריאת תוכן הקובץ והדפסתו למסך
    char line[1024];  // משתנה לאחסון שורות
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file); // סגירת הקובץ
}

// פונקציה ראשית לבדיקה
int main() {
    char *args1[] = {"read", "testFile2.txt", NULL};
    readFile(args1);

    return 0;
}
