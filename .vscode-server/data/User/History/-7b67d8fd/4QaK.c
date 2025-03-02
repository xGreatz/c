#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// פונקציה לניקוי רווחים מההתחלה והסוף של המחרוזת
char *trimSpaces(char *str) {
    while (isspace((unsigned char)*str)) str++; 
    if (*str == 0) return str;  

    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--; 
    *(end + 1) = '\0';

    return str;
}

// פונקציה לביצוע יציאה מהמערכת עם הודעה מתאימה

void logout(char *str) {
    if (str == NULL) return;


    str = trimSpaces(str);

    if (strncmp(str, "exit", 4) == 0) {
        str += 4; 
        str = trimSpaces(str); 

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

    
        input[strcspn(input, "\n")] = '\0';

        logout(input);
    }

    return 0;
}
