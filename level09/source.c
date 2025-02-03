#include <stdio.h>
#include <string.h>

#define MAX_MSG_SIZE 0x400
#define MAX_USERNAME_SIZE 0x80

typedef struct {
    char username[0x8c];  // 140 bytes
    char msg[MAX_MSG_SIZE];
} user_data;

void secret_backdoor() {
    char buffer[0x80];
    fgets(buffer, sizeof(buffer), stdin);
    system(buffer);
}

void set_username(user_data *data) {
    char username[MAX_USERNAME_SIZE];
    memset(username, 0, sizeof(username));

    puts(">: Enter your username");
    printf(">>: ");
    fgets(username, sizeof(username), stdin); // 140

    for (int i = 0; i < 0x28; i++) {
        if (username[i] == '\0') break;
        data->username[i] = username[i];
    }

    printf(">: Welcome, %s", data->username);
}

void set_msg(user_data *data) {
    char msg[MAX_MSG_SIZE];
    memset(msg, 0, sizeof(msg));

    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(msg, sizeof(msg), stdin);

    strncpy(data->msg, msg, MAX_MSG_SIZE);
}

void handle_msg() {
    user_data data;
    memset(&data, 0, sizeof(data));

    set_username(&data);
    set_msg(&data);

    puts(">: Msg sent!");
}

int main(int argc, char **argv, char **envp) {
    puts("------------------------------------");
    handle_msg();
    return 0;
}