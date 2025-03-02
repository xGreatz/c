#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void deleteFile(char *str) {
    if (str == NULL || strlen(str) == 0) {
        fprintf(stderr, "Usage: delete <filename>\n");
        return;
    }

   
    if (remove(str) == 0) {
        printf("File '%s' deleted successfully.\n", str);
    } else {
        perror("Error deleting file");
    }
}


int main() {
    char input[256];

  
    printf("Enter filename to delete: ");
    fgets(input, sizeof(input), stdin);

    
    input[strcspn(input, "\n")] = '\0';

    deleteFile(input);

    return 0;
}
