#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// פונקציה למחיקת קובץ
void deleteFile(char *str) {
    if (str == NULL || strlen(str) == 0) {
        fprintf(stderr, "Usage: delete <filename>\n");
        return;
    }

    // ניסיון למחוק את הקובץ
    if (remove(str) == 0) {
        printf("File '%s' deleted successfully.\n", str);
    } else {
        perror("Error deleting file");
    }
}

// פונקציה ראשית לבדיקה
int main() {
    char input[256];

    // קבלת שם הקובץ למחיקה מהמשתמש
    printf("Enter filename to delete: ");
    fgets(input, sizeof(input), stdin);

    // הסרת תו מעבר שורה
    input[strcspn(input, "\n")] = '\0';

    // קריאה לפונקציה למחיקת הקובץ
    deleteFile(input);

    return 0;
}
