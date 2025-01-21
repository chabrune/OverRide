#include <stdio.h>
#include <string.h>

char a_user_name[256];

int verify_user_name() {
    printf("verifying username....\n");
    return strcmp(a_user_name, "dat_wil") == 0;
}

int verify_user_pass(char* password) {
    return strcmp(password, "admin") == 0;
}

int main(int argc, char** argv) {
    char password[64] = {0};
    int auth = 0;
    
    printf("********* ADMIN LOGIN PROMPT ***********\n");
    printf("Enter Username: ");
    
    fgets(a_user_name, 256, stdin);
    auth = verify_user_name();
    
    if (auth != 0) {
        printf("nope, incorrect username...\n");
        return 1;
    }
    
    printf("Enter Password: ");
    fgets(password, 100, stdin);
    auth = verify_user_pass(password);
    
    if (auth != 0) {
        printf("nope, incorrect password...\n");
        return 1;
    }
    
    return 0;
}
