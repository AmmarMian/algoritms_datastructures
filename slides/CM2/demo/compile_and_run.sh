#!/bin/bash

# Script de compilation et lancement du mini-jeu de démonstration

echo "========================================="
echo " Compilation du mini-jeu de démonstration"
echo "========================================="

# Compilation avec symboles de débogage
gcc -g -O0 game.c -o game

if [ $? -eq 0 ]; then
    echo "✓ Compilation réussie !"
    echo ""
    echo "========================================="
    echo " Lancement du jeu"
    echo "========================================="
    echo ""
    echo "Le programme va afficher son PID et les adresses"
    echo "mémoire. Utilisez ces informations dans un autre"
    echo "terminal pour modifier la mémoire avec lldb."
    echo ""
    echo "Appuyez sur Entrée pour continuer..."
    read

    # Lancement
    ./game
else
    echo "✗ Erreur de compilation"
    exit 1
fi
