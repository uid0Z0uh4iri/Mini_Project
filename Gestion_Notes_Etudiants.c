#include <stdio.h>
#include <string.h>
#include <float.h>

int main() {
    int nombre_etudiants = 0;
    float somme_notes = 0;
    float note_max = -20;
    float note_min = 20;
    char nom_max[100] = "";
    char nom_min[100] = "";
    int choix;
    char prenom[50], nom[50];
    float note;

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Afficher la moyenne\n");
        printf("3. Afficher les meilleures et moins bonnes notes\n");
        printf("4. Nombre d'étudiants au-dessus de la moyenne\n");
        printf("5. Quitter\n");
        printf("Choisissez une option (1-5): ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                printf("Entrez le prénom de l'étudiant: ");
                scanf("%s", prenom);
                printf("Entrez le nom de l'étudiant: ");
                scanf("%s", nom);
                printf("Entrez la note de l'étudiant: ");
                scanf("%f", &note);

                nombre_etudiants++;
                somme_notes += note;

                if (note > note_max) {
                    note_max = note;
                    sprintf(nom_max, "%s %s", prenom, nom);
                }
                if (note < note_min) {
                    note_min = note;
                    sprintf(nom_min, "%s %s", prenom, nom);
                }

                printf("Étudiant %s %s ajouté avec la note %.2f\n", prenom, nom, note);
                break;

            case 2:
                if (nombre_etudiants > 0) {
                    printf("La moyenne des notes est: %.2f\n", somme_notes / nombre_etudiants);
                } else {
                    printf("Aucun étudiant n'a été ajouté.\n");
                }
                break;

            case 3:
                if (nombre_etudiants > 0) {
                    printf("Meilleure note: %.2f par %s\n", note_max, nom_max);
                    printf("Moins bonne note: %.2f par %s\n", note_min, nom_min);
                } else {
                    printf("Aucun étudiant n'a été ajouté.\n");
                }
                break;

            case 4:
                if (nombre_etudiants > 0) {
                    float moyenne = somme_notes / nombre_etudiants;
                    int count_above_average = 0;
                    for (int i = 0; i < nombre_etudiants; i++) {
                        printf("Entrez à nouveau la note de l'étudiant %d: ", i+1);
                        scanf("%f", &note);
                        if (note > moyenne) {
                            count_above_average++;
                        }
                    }
                    printf("Nombre d'étudiants au-dessus de la moyenne: %d\n", count_above_average);
                } else {
                    printf("Aucun étudiant n'a été ajouté.\n");
                }
                break;

            case 5:
                printf("Au revoir!\n");
                break;

            default:
                printf("Option invalide. Veuillez choisir une option entre 1 et 5.\n");
        }
    } while (choix != 5);

    return 0;
}
