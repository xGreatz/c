#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cp(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Usage: cp <source_file> <destination_file>\n");
        return;
    }

    char *source = args[1];
    char *destination = args[2];

    FILE *src = fopen(source, "rb"); 
    if (!src) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(destination, "wb");  
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    char buffer[4096]; 
    size_t bytesRead;


    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);

    printf("File copied successfully from '%s' to '%s'\n", source, destination);
}


int main() {
    char *args1[] = {"cp", "source.txt", "destination.txt", NULL};
    cp(args1);

    return 0;
}
