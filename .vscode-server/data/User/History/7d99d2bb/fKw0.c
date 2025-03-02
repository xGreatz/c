#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// פונקציה המשלבת את כל הארגומנטים למחרוזת אחת
char *combineArgs(char **args) {
    if (args[1] == NULL) return NULL; // אין נתיב שסופק

    int length = 0;
    for (int i = 1; args[i] != NULL; i++) {
        length += strlen(args[i]) + 1; // חישוב האורך הכולל (+1 לרווחים)
    }

    char *path = malloc(length);
    if (!path) {
        perror("Memory allocation failed");
        return NULL;
    }

    path[0] = '\0'; // אתחול מחרוזת ריקה
    for (int i = 1; args[i] != NULL; i++) {
        strcat(path, args[i]);
        if (args[i + 1] != NULL) strcat(path, " "); // הוספת רווח בין מילים
    }

    return path;
}

// פונקציה להחלפת ספריית העבודה (cd)
void cd(char **args) {
    char *path = combineArgs(args);
    if (path == NULL) {
        fprintf(stderr, "Usage: cd <path>\n");
        return;
    }

    printf("Trying to change directory to: %s\n", path); // ✅ הדפסת הנתיב

    if (chdir(path) != 0) {
        perror("cd failed");  // ✅ מציג את השגיאה הספציפית
    } else {
        printf("Changed directory to: %s\n", path);
    }

    free(path);
}

// פונקציה ראשית לבדיקה
int main() {
    char *args1[] = {"cd", "OneDrive", "-", "Ariel", "University", NULL};
    cd(args1); // בדיקה עם נתיב המכיל רווחים
    return 0;
}