#include <stdio.h>
#include <string.h>

int main() {
    char var_78[100];  // Buffer de taille 0x64 (100) octets
    int var_14 = 0;    // Initialisation de var_14 (non utilisé dans ce snippet)
    int var_14_1 = 0;  // Compteur pour parcourir la chaîne

    // Lecture de l'entrée utilisateur
    fgets(var_78, sizeof(var_78), stdin);

    // Boucle principale pour traiter chaque caractère
    while (1) {
        // Calcul de la longueur de la chaîne
        int len = strlen(var_78);

        // Sortie de la boucle si on a atteint la fin de la chaîne
        if (var_14_1 >= len) {
            break;
        }

        // Vérification si le caractère est une majuscule (A-Z)
        if (var_78[var_14_1] > 'A' && var_78[var_14_1] <= 'Z') {
            // Conversion en minuscule
            var_78[var_14_1] ^= 0x20;
        }

        var_14_1++;
    }


    return 0;
}
