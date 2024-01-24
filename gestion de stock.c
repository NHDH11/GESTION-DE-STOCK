#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUITS 100

// Fonction pour trouver l'indice d'un produit dans le tableau
int IndiceDeproduit(int codes[], int numProduits, int code) {
    for (int i = 0; i < numProduits; i++) {
        if (codes[i] == code) {
            return i;
        }
    }
    return -1;
}

// Fonction pour ajouter un produit au stock
void AjouterProduits(int codes[], int quantite[], int *numProduits, int code, int Quantite) {
    int indice = IndiceDeproduit(codes, *numProduits, code);

    if (indice != -1) {
        // Le produit existe, ajouter à la quantité existante
        quantite[indice] += Quantite;
        printf("Quantite ajoutee au stock du produit %d.\n", code);
    } else {
        // Le produit n'existe pas, l'ajouter au stock
        if (*numProduits < MAX_PRODUITS) {
            codes[*numProduits] = code;
            quantite[*numProduits] = Quantite;
            (*numProduits)++;
            printf("Produit ajoute au stock.\n");
        } else {
            printf("Le stock est plein. Impossible d'ajouter un nouveau produit.\n");
        }
    }
}

// Fonction pour retirer un produit du stock
void SupprimerProduits(int codes[], int quantite[], int numProduits, int code, int Quantite) {
    int indice = IndiceDeproduit(codes, numProduits, code);

    if (indice != -1) {
        // Le produit existe
        if (quantite[indice] >= Quantite) {
            // La quantité spécifiée peut être retirée du stock
            quantite[indice] -= Quantite;
            printf("Quantite retiree du stock du produit %d.\n", code);
        } else {
            // La quantité spécifiée est supérieure à la quantité en stock
            printf("Erreur : La quantite à retirer est superieure à la quantite en stock pour le produit %d.\n", code);
        }
    } else {
        // Le produit n'existe pas
        printf("Erreur : Le produit %d n'existe pas dans le stock.\n", code);
    }
}

// Fonction pour afficher le stock total
void AfficherStock(int codes[], int quantite[], int numProduits) {
    printf("Stock total :\n");
    for (int i = 0; i < numProduits; i++) {
        printf("Produit %d : %d\n", codes[i], quantite[i]);
    }
}

int main() {
    int CodeProduit[MAX_PRODUITS];
    int QuantiteProduit[MAX_PRODUITS];
    int numProduits = 0;

    int choix;
    do {
        printf("\nMenu :\n");
        printf("1. Ajouter un produit au stock\n");
        printf("2. Retirer un produit du stock\n");
        printf("3. Afficher le stock total\n");
        printf("4. Quitter\n");

        printf("Choix : ");
        scanf(" %d", &choix);

        switch (choix) {
            case 1:
                {
                    int code, Quantite;
                    printf("Code du produit : ");
                    scanf("%d", &code);
                    printf("Quantite a ajouter : ");
                    scanf("%d", &Quantite);
                    AjouterProduits(CodeProduit, QuantiteProduit, &numProduits, code, Quantite);
                    break;
                }
            case 2:
                {
                    int code, Quantite;
                    printf("Code du produit : ");
                    scanf("%d", &code);
                    printf("Quantite a retirer : ");
                    scanf("%d", &Quantite);
                    SupprimerProduits(CodeProduit, QuantiteProduit, numProduits, code, Quantite);
                    break;
                }
            case 3:
                AfficherStock(CodeProduit, QuantiteProduit, numProduits);
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

    } while (choix != 4);

    return 0;
}









