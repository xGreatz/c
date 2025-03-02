#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// פונקציה להעברת קובץ ממיקום למיקום (mv)
void move(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Usage: move <source_file> <destination>\n");
        return;
    }

    char command[512];
    snprintf(command, sizeof(command), "mv \"%s\" \"%s\"", args[1], args[2]);
        // ניסיון להעביר את הקובץ
    if (system(command) == 0) {
        printf("File moved successfully from '%s' to '%s'\n", args[1], args[2]);
    } else {
        perror("Error moving file");
    }
}



// פונקציה ראשית לבדיקה
int main() {
    char *args1[] = {"move", "file1.txt", "destination_folder/file1.txt", NULL};
    move(args1);

    return 0;
}


// file1.txt to destination_folder