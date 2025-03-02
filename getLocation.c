#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// פונקציה להצגת שם המשתמש ושם המחשב עם צבעים מודגשים
void getLocation() {
    char username[256];
    char hostname[256];

  
    if (getlogin_r(username, sizeof(username)) != 0) {
        perror("Error");
        return;
    }

     // קבלת שם המחשב
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        perror("Error");
        return;
    }

  
    printf("\033[1;32m");  
    printf("User: %s\n", username);
    printf("\033[0m");    


    printf("\033[1;34m");  
    printf("Host: %s\n", hostname);
    printf("\033[0m");    
}


int main() {
    getLocation();
    return 0;
}
