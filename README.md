# Manuel d'utilisation

## 1. Motivation
---
AirWatcher est une application qui permet de traiter des données sur la qualité de l'air.
Ces données proviennent de capteur installés a de nombreux endroits.
L'application permet entre autre d'afficher la liste des capteurs, avoir des informations plus précise sur
un capteur particulier, d'identifier un capteur dysfonctionnel ou encore de tester l'éfficacité d'un
purificateur d'air.

Certaines fonctionnalités nécessitent d'avoir un compte gouvernement.

## 2. Compilation
---
**Commandes à exécuter avec MakeFile :**

**$ `make`** pour compiler et faire l'édition des liens.

**$ `make run`** pour compiler, faire l'édition des liens et éxecuter `./app`.

**$ `make debug`** pour compiler en mode développement et faire l'édition des liens.

**$ `make fclean`** pour supprimer les fichiers objets et l'éxecutable.

**$ `make help`** pour obtenir plus d'informations sur les commandes disponibles.

## 3. Exécution
---
**Commandes à exécuter pour lancer l'application :**
L'application est lancé en tapant la commande **./app** depuis la racine du dossier (AirWatcher/)

...

**Les différentes [options] sont les suivantes :**
[-t] : permet d'afficher le temps d'execution des differentes fonctions

...

## 4. Tests
---
Les tests doivent être régulièrement exécutés afin de vérifier que les nouvelles fonctionnalités n'ont pas introduit d'erreur dans les anciennes.

**Exécution des tests :**
- Se placer dans le répertoire **`tests/`**
- Exécuter **$ `./mktest.sh`**
