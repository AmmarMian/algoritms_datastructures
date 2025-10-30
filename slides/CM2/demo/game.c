/**
 * Mini jeu pour démonstration CM2
 * Représentation mémoire des variables
 *
 * Compilation : gcc -g game.c -o game
 * Lancement :   ./game
 *
 * Dans un autre terminal :
 * lldb -p <PID>
 * (lldb) memory read <adresse>
 * (lldb) memory write <adresse> 0xFF
 */

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

// Fonction pour afficher un nombre en binaire
void print_binary(unsigned int n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0 && i > 0) printf(" ");  // Espace tous les 4 bits
    }
}

int main() {
    // Variables du "jeu"
    int32_t gold = 10;
    int32_t health = 100;

    // Afficher le PID pour lldb
    printf("========================================\n");
    printf("      Mini RPG - Demo CM2\n");
    printf("========================================\n");
    printf("\nPID du processus : %d\n", getpid());
    printf("\nAdresses mémoire :\n");
    printf("  - gold   : %p\n", (void*)&gold);
    printf("  - health : %p\n\n", (void*)&health);
    printf("========================================\n\n");

    printf("Instructions :\n");
    printf("1. Dans un autre terminal, lancer :\n");
    printf("   lldb -p %d\n\n", getpid());
    printf("2. Modifier la mémoire avec :\n");
    printf("   (lldb) memory write %p 0xFF\n\n", (void*)&gold);
    printf("3. Observer le changement ci-dessous !\n\n");
    printf("========================================\n\n");

    // Boucle d'affichage
    while(1) {
        // Clear screen (ANSI escape code)
        printf("\033[2J\033[H");

        printf("========================================\n");
        printf("      Mini RPG - Demo CM2\n");
        printf("========================================\n\n");

        // Afficher Gold avec toutes les représentations
        printf("💰 Gold : %d\n", gold);
        printf("   - Décimal  : %d\n", gold);
        printf("   - Hexa     : 0x%08X\n", (unsigned int)gold);
        printf("   - Binaire  : ");
        print_binary((unsigned int)gold, 32);
        printf("\n");
        printf("   - Adresse  : %p\n\n", (void*)&gold);

        // Afficher Health
        printf("❤️  Health : %d\n", health);
        printf("   - Décimal  : %d\n", health);
        printf("   - Hexa     : 0x%08X\n", (unsigned int)health);
        printf("   - Binaire  : ");
        print_binary((unsigned int)health, 32);
        printf("\n");
        printf("   - Adresse  : %p\n\n", (void*)&health);

        printf("========================================\n");
        printf("En attente de modifications mémoire...\n");
        printf("(Ctrl+C pour quitter)\n");
        printf("========================================\n");

        // Attendre 2 secondes
        sleep(2);
    }

    return 0;
}
