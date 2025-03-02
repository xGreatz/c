#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// פונקציה המדפיסה את שם המשתמש ושם המחשב עם צבעים מודגשים
void getLocation() {
    char username[256];
    char hostname[256];

    // קבלת שם המשתמש
    if (getlogin_r(username, sizeof(username)) != 0) {
        perror("Error");
        return;
    }

    // קבלת שם המחשב
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        perror("Error");
        return;
    }

    // הדפסת שם המשתמש עם צבע ירוק מודגש
    printf("\033[1;32m");  // קוד ANSI לצבע ירוק מודגש
    printf("User: %s\n", username);
    printf("\033[0m");     // איפוס הצבעים

    // הדפסת שם המחשב עם צבע כחול מודגש
    printf("\033[1;34m");  // קוד ANSI לצבע כחול מודגש
    printf("Host: %s\n", hostname);
    printf("\033[0m");     // איפוס הצבעים
}

// פונקציה ראשית לבדיקת getLocation()
int main() {
    getLocation();
    return 0;
}
