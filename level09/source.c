#include <stdio.h>
#include <string.h>

void secret_backdoor() {
    char buffer[128];

    fgets(buffer, 128, stdin);

    system(buffer);
}

void handle_msg() {
    char buffer[192];

    // Initialiser une partie du buffer à 0 ?
    memset(buffer + 140, 0, 40);

    // Appeler set_username pour remplir une partie du buffer
    set_username(buffer);

    // Appeler set_msg pour remplir une autre partie du buffer
    set_msg(buffer);

    puts(">: Msg sent!");

    return;
}

void set_msg(char *buffer) {
    char input[1024];

    memset(input, 0, 1024);

    puts(">: Msg @Unix-Dude");
    printf(">>: ");

    // (vulnérabilité : débordement possible si l'entrée dépasse 1024 octets)
    fgets(input, 1024, stdin);

    // Copier l'entrée utilisateur dans le buffer principal (vulnérabilité : strncpy ne garantit pas la null-termination)
    strncpy(buffer + 140, input, *(int *)(buffer + 136)); // Utilise une valeur du buffer pour déterminer la longueur de copie

    return;
}

void set_username(char *buffer) {
    char username[128];

    memset(username, 0, 128);

    puts(">: Enter your username");
    printf(">>: ");

    // (vulnérabilité : débordement possible si l'entrée dépasse 128 octets)
    fgets(username, 128, stdin);

    // (vulnérabilité : copie jusqu'à 40 octets sans vérification)
    for (int i = 0; i < 40; i++) {
        buffer[140 + i] = username[i];
        if (username[i] == '\0') break; // Arrêter si on rencontre un null byte
    }

    printf(">: Welcome, %s", buffer + 140);
    return;
}

int main() {
    puts("------------------------------------");

    handle_msg();

    return 0;
}