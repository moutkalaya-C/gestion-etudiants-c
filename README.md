# Gestionnaire d'Étudiants en C

Application console développée en langage C permettant de gérer une base de données d'étudiants (ajout, affichage, recherche) avec sauvegarde automatique dans un fichier texte.

## Objectifs techniques
- Manipulation des **structures (`struct`)** et tableaux.
- Gestion de la **persistance des données** via les fichiers (`fopen`, `fprintf`, `fscanf`).
- Traitement sécurisé des chaînes de caractères (`fgets`, `strcspn`).

## Fonctionnalités
- Chargement automatique des données au démarrage (`etudiants.txt`).
- Ajout d'un nouvel étudiant (ID, Nom, Filière, Moyenne).
- Affichage formaté de la liste complète.
- Recherche rapide par identifiant unique.
