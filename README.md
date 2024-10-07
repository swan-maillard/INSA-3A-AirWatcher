# AirWatcher

## Description

Cette application développée en C++ permet de traiter des données de capteurs de qualité de l'air pour fournir des statistiques sur des zones géographiques, détecter des capteurs défectueux, et bien plus encore.

Nous avons suivi une méthode de Test-Driven Development tout au long de la réalisation de ce projet.

## Fonctionnalités
Voici une liste des fonctionnalités principales de l'application :

1. **Identification des capteurs défectueux** : Analyse des capteurs pour détecter les anomalies basées sur la moyenne et l'écart-type des données des capteurs environnants. Accessible uniquement au gouvernement.
   
2. **Génération de statistiques** : Calcul de la qualité de l'air et de divers indices ATMO pour des capteurs dans une zone circulaire ou à un point précis.
   
3. **Analyse de la qualité de l'air d'un point particulier** : Triangulation des données des capteurs les plus proches pour déterminer la qualité de l'air.
   
4. **Recherche de capteurs similaires** : Identification des capteurs avec des caractéristiques de qualité d'air similaires dans une plage de temps donnée, accessible uniquement au gouvernement.
   
5. **Vérification de la fiabilité des capteurs** : Validation des données des capteurs privés en les comparant à ceux des capteurs voisins.
   
6. **Évaluation de l'efficacité des purificateurs d'air** : Comparaison des données avant et après l'installation de purificateurs d'air.


## Interface Utilisateur
L'application dispose d'une interface console où les utilisateurs peuvent se connecter et accéder aux différentes fonctionnalités par le biais de menus interactifs.

## Compilation
---
**Commandes à exécuter avec MakeFile :**

**$ `make`** pour compiler et faire l'édition des liens.

**$ `make run`** pour compiler, faire l'édition des liens et éxecuter `./app`.

**$ `make debug`** pour compiler en mode développement et faire l'édition des liens.

**$ `make fclean`** pour supprimer les fichiers objets et l'éxecutable.

**$ `make help`** pour obtenir plus d'informations sur les commandes disponibles.

## Exécution
Voici une version améliorée de la section concernant l'exécution de l'application :

---

### Exécution

Pour lancer l'application, utilisez la commande suivante depuis la racine du projet :

```bash
./app
```

L'application prend en charge les options suivantes :

- **`-t`** : Active le mode de traçage pour afficher le temps d'exécution des différentes fonctions. Cela peut être utile pour le débogage et l'optimisation des performances.

### Test
Les tests doivent être régulièrement exécutés afin de vérifier que les nouvelles fonctionnalités n'ont pas introduit d'erreur dans les anciennes.

**Exécution des tests :**
- Se placer dans le répertoire **`tests/`**
- Exécuter **$ `./mktest.sh`**

### Structure du Projet
- **data/** : Contient des fichiers .csv de données sur les capteurs, etc.
- **inclue/** : Contient les fichiers d'en-tête C++.
- **src/** : Contient les fichiers source C++.
- **tests/** : Contient le script de test.
- **Makefile** : Fichier de configuration pour la compilation et l'exécution de l'application.

## Auteurs

- Alexandre Biaud (alexandre.biaud@insa-lyon.fr)
- Clément Giraudon (clement.giraudon@insa-lyon.fr)
- Swan Maillard (maillard.swan@gmail.com)
- Hugo Warin (hugo.warin@insa-lyon.fr)

## Licence

Ce projet est sous licence MIT. Veuillez consulter le fichier `LICENSE` pour plus d'informations.
