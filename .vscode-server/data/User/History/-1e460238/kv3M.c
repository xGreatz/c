#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// פונקציה המפרידה את המילים במחרוזת ומחזירה מערך מצביעים
char **splitArgument(char *str) {
    if (str == NULL) return NULL;

    int count = 0;  // מספר המילים
    char *temp = strdup(str); // יצירת עותק של המחרוזת כדי לא לפגוע במקור
    char *token = strtok(temp, " "); // הפרדה ראשונית לפי רווח

    // ספירת כמות המילים
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    free(temp); // שחרור הזיכרון של ההעתק

    // הקצאת זיכרון למערך המילים (כולל NULL בסוף)
    char **args = malloc((count + 1) * sizeof(char *));
    if (!args) {
        perror("Memory allocation failed");
        return NULL;
    }

    // חלוקה בפועל ושמירת המצביעים
    int i = 0;
    token = strtok(str, " "); // הפרדה בפועל
    while (token != NULL) {
        args[i++] = token; // שמירת מצביע לכל מילה
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // הוספת NULL לסימון סוף הרשימה

    return args;
}

// פונקציה ראשית לבדיקה
int main() {
    char input[] = "cd OneDrive - Ariel University"; // מחרוזת לבדיקה
    char **arguments = splitArgument(input);

    if (arguments) {
        // הדפסת המילים לאחר החלוקה
        for (int i = 0; arguments[i] != NULL; i++) {
            printf("Argument %d: %s\n", i, arguments[i]);
        }
        free(arguments); // שחרור הזיכרון של המערך
    }

    return 0;
}
