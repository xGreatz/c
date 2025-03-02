#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <limits.h>

void getLocation() {
    char cwd[PATH_MAX];  // לאחסון הנתיב הנוכחי
    struct utsname system_info;  // מבנה לאחסון פרטי מערכת
    char *username = getenv("USER");  // שם המשתמש

    // קבלת הנתיב הנוכחי
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd error");
        return;
    }

    // קבלת פרטי המחשב
    if (uname(&system_info) == -1) {
        perror("uname error");
        return;
    }

    // הדפסת הנתונים עם צבעים והדגשה
    printf("\033[1;32m");  // צבע ירוק עם הדגשה (bold)
    printf("User: \033[1;34m%s\033[0m\n", username);  // שם המשתמש בכחול
    printf("\033[1;32mHost: \033[1;34m%s\033[0m\n", system_info.nodename);  // שם המחשב בכחול
    printf("\033[1;32mPath: \033[1;34m%s\033[0m\n", cwd);  // הנתיב בכחול
    printf("\033[0m");  // איפוס צבעים
}

int main() {
    getLocation();
    return 0;
}
