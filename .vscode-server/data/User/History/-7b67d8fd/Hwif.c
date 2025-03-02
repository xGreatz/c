#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// פונקציה לניקוי רווחים מההתחלה והסוף של המחרוזת
char *trimSpaces(char *str) {
    while (isspace((unsigned char)*str)) str++;  // הסרת רווחים בהתחלה
    if (*str == 0) return str;  // אם המחרוזת ריקה

    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--; // הסרת רווחים בסוף
    *(end + 1) = '\0';

    return str;
}

// פונקציה לביצוע יציאה מהמערכת עם הודעה מתאימה
void logout(char *str) {
    if (str == NULL) return;

    // ניקוי רווחים מסביב לפקודה
    str = trimSpaces(str);

    // בדיקת האם הפקודה היא "exit" בלבד או עם רווחים
    if (strncmp(str, "exit", 4) == 0) {
        str += 4; // מדלגים על המילה "exit"
        str = trimSpaces(str); // מסירים רווחים נוספים אחרי exit

        if (*str == '\0') {
            printf("Exiting shell... Goodbye!\n");
            exit(0);
        } else {
            printf("Error: Invalid usage of exit.\n");
        }
    }
}

// פונקציה ראשית לבדיקה
int main() {
    char input[256];

    while (1) {
        printf("shell> ");
        fgets(input, sizeof(input), stdin);

        // הסרת תו מעבר שורה (Enter) אם יש
        input[strcspn(input, "\n")] = '\0';

        logout(input);
    }

    return 0;
}
