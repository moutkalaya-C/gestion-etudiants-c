#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100
#define FICHIER_DB "etudiants.txt"

typedef struct {
    int id;
    char nom[50];
    char filiere[30];
    float moyenne;
} Etudiant;

Etudiant liste[MAX_ETUDIANTS];
int nbEtudiants = 0;

void chargerDonnees() {
    FILE *f = fopen(FICHIER_DB, "r");
    if (f == NULL) return;
    while (fscanf(f, "%d;%49[^;];%29[^;];%f\n", 
                  &liste[nbEtudiants].id, 
                  liste[nbEtudiants].nom, 
                  liste[nbEtudiants].filiere, 
                  &liste[nbEtudiants].moyenne) == 4) {
        nbEtudiants++;
    }
    fclose(f);
}

void sauvegarderDonnees() {
    FILE *f = fopen(FICHIER_DB, "w");
    if (f == NULL) {
        printf("Erreur lors de la sauvegarde.\n");
        return;
    }
    for (int i = 0; i < nbEtudiants; i++) {
        fprintf(f, "%d;%s;%s;%.2f\n", 
                liste[i].id, liste[i].nom, liste[i].filiere, liste[i].moyenne);
    }
    fclose(f);
}

void ajouterEtudiant() {
    if (nbEtudiants >= MAX_ETUDIANTS) {
        printf("Capacite maximale atteinte.\n");
        return;
    }
    Etudiant e;
    printf("ID : ");
    scanf("%d", &e.id);
    getchar(); // Nettoyer le buffer
    printf("Nom complet : ");
    fgets(e.nom, sizeof(e.nom), stdin);
    e.nom[strcspn(e.nom, "\n")] = 0;

    printf("Filiere : ");
    fgets(e.filiere, sizeof(e.filiere), stdin);
    e.filiere[strcspn(e.filiere, "\n")] = 0;

    printf("Moyenne (/20) : ");
    scanf("%f", &e.moyenne);

    liste[nbEtudiants++] = e;
    sauvegarderDonnees();
    printf("Etudiant ajoute et sauvegarde avec succes !\n");
}

void afficherEtudiants() {
    if (nbEtudiants == 0) {
        printf("\nAucun etudiant enregistre.\n");
        return;
    }
    printf("\n--- Liste des Etudiants (%d) ---\n", nbEtudiants);
    for (int i = 0; i < nbEtudiants; i++) {
        printf("[%d] %s | Filiere: %s | Moyenne: %.2f/20\n", 
               liste[i].id, liste[i].nom, liste[i].filiere, liste[i].moyenne);
    }
}

void rechercherEtudiant() {
    int idRecherche;
    printf("Entrez l'ID a rechercher : ");
    scanf("%d", &idRecherche);
    for (int i = 0; i < nbEtudiants; i++) {
        if (liste[i].id == idRecherche) {
            printf("Trouve -> %s | Filiere: %s | Moyenne: %.2f/20\n", 
                   liste[i].nom, liste[i].filiere, liste[i].moyenne);
            return;
        }
    }
    printf("Aucun etudiant trouve avec l'ID %d.\n", idRecherche);
}

int main() {
    chargerDonnees();
    int choix;
    do {
        printf("\n=== GESTIONNAIRE ETUDIANTS ===\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher tous les etudiants\n");
        printf("3. Rechercher par ID\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterEtudiant(); break;
            case 2: afficherEtudiants(); break;
            case 3: rechercherEtudiant(); break;
            case 0: printf("Fermeture...\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);
    return 0;
}
