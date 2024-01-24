Gestion d'Entrepôt en C
Description
Ce programme en langage C simule le fonctionnement d'un entrepôt pour la gestion des ressources matérielles. L'utilisateur peut effectuer les opérations suivantes :

Ajouter un produit au stock :

Saisir le code du produit et la quantité à ajouter.
Si le produit n'existe pas, il est ajouté au stock avec la quantité spécifiée.
Si le produit existe déjà, la quantité spécifiée est ajoutée à la quantité existante.
Retirer un produit du stock :

Saisir le code du produit et la quantité à retirer.
Si le produit n'existe pas, un message d'erreur est affiché.
Si le produit existe mais la quantité à retirer est supérieure à la quantité en stock, un message d'erreur approprié est affiché.
Sinon, la quantité spécifiée est retirée du stock.
Afficher le stock total :

Affiche la liste de tous les produits et leurs quantités respectives.
Quitter :

Termine l'exécution du programme.


Fonctionnement
Le programme utilise des fonctions modulaires pour organiser le code de manière claire et compréhensible. Les données sur les produits (codes et quantités) sont stockées dans des tableaux. Les scopes des variables sont gérés efficacement, assurant une durée de vie appropriée.
