#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// פונקציה המפרידה את המילים במחרוזת ומחזירה מערך מצביעים
char **splitArgument(char *str) {
    if (str == NULL) return NULL;

    int count = 0;  
    char *temp = strdup(str); 
    char *token = strtok(temp, " "); 

  // ספירת כמות המילים
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    free(temp); 


    char **args = malloc((count + 1) * sizeof(char *));
    if (!args) {
        perror("Memory allocation failed");
        return NULL;
    }

   // חלוקה בפועל ושמירת המצביעים
    int i = 0;
    token = strtok(str, " "); 
    while (token != NULL) {
        args[i++] = token; 
        token = strtok(NULL, " ");
    }
    args[i] = NULL; 

    return args;
}
// פונקציה ראשית לבדיקה
int main() {
    char input[] = "cd OneDrive - Ariel University"; 
    char **arguments = splitArgument(input);

    if (arguments) {
      // הדפסת המילים לאחר החלוקה
        for (int i = 0; arguments[i] != NULL; i++) {
            printf("Argument %d: %s\n", i, arguments[i]);
        }
        free(arguments); 
    }

    return 0;
}
