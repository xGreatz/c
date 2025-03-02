#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// פונקציה לכתיבת טקסט לקובץ (מוחקת תוכן קודם)
void echowrite(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Usage: echowrite <string> <file_path>\n");
        return;
    }

    char *text = args[1];       // המחרוזת לכתיבה
    char *file_path = args[2];  // הנתיב לקובץ

    // פתיחת הקובץ במצב "w" (כתיבה - מוחק תוכן קודם)
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // כתיבת המחרוזת לקובץ
    fprintf(file, "%s\n", text);
    fclose(file);

    printf("Text written to '%s' successfully.\n", file_path);
}

// פונקציה ראשית לבדיקה
int main() {
    char *args1[] = {"echowrite", "hello world", "testFile.txt", NULL};
    echowrite(args1);

    return 0;
}
