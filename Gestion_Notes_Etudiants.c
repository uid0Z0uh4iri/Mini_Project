#include<stdio.h>
#include<string.h>


int main()
{
    int choix;
    char nom[20], prenom[20];
    float note;
    char nom_max[20], nom_min[20];
    float note_max = 0, note_min = 100;
    float moyenne = 0;
    int compteur_etudiants = 0;
    float somme_notes = 0;

    // Tableaux pour stocker les donn�es de tous les �tudiants
    char noms[20];
    float notes[100];

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un �tudiant\n");
        printf("2. Afficher la moyenne\n");
        printf("3. Afficher les meilleures et moins bonnes notes avec les noms d'�tudiants\n");
        printf("4. Nombre d'�tudiants au-dessus de la moyenne\n");
        printf("5. Quitter\n");
        printf("Choisissez une option (1-5): ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:

                    printf("Donner le pr�nom d'�tudiant: ");
                    scanf("%s", prenom);
                    printf("Donner le nom d'�tudiant: ");
                    scanf("%s", nom);
                    printf("Donner la note: ");
                    scanf("%f", &note);

                    notes[compteur_etudiants] = note;
                    compteur_etudiants++;
                    somme_notes += note;

                    if (note < note_min) {
                        note_min = note;
                        strcpy(nom_min, nom);
                    }
                    if (note > note_max) {
                        note_max = note;
                        strcpy(nom_max, nom);
                    }

                    moyenne = somme_notes / compteur_etudiants;
                    printf("�tudiant ajout� avec succ�s!\n");

                break;
            case 2:
                if (compteur_etudiants > 0) {
                    printf("La moyenne est : %.2f\n", moyenne);
                                             }
                else {
                    printf("Aucun �tudiant n'a �t� ajout�.\n");
                     }
                break;
            case 3:
                if (compteur_etudiants > 0) {
                    printf("La note la plus basse est %.2f (�tudiant: %s)\n", note_min, nom_min);
                    printf("La meilleure note est %.2f (�tudiant: %s)\n", note_max, nom_max);
                                            }
                 else {
                    printf("Aucun �tudiant n'a �t� ajout�.\n");
                      }
                break;
            case 4:
                if (compteur_etudiants > 0) {
                    int etudiants_superieur_a_moyenne = 0;
                    for (int i = 0; i < compteur_etudiants; i++) {
                        if (notes[i] > moyenne) {
                            etudiants_superieur_a_moyenne++;
                                                }
                                                                 }
                    printf("Le nombre d'�tudiants qui on une note sup�rieur � la moyenne est : %d\n", etudiants_superieur_a_moyenne);
                                            }
                else {
                    printf("Aucun �tudiant n'a �t� ajout�.\n");
                     }
                break;
            case 5:
                printf("Au revoir!\n");
                break;
            default:
                printf("Option invalide. Veuillez choisir un nombre entre 1 et 5.\n");
                                  }
                       }
         while (choix != 5);

              return 0;
     }
