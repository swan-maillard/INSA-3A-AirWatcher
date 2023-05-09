#**********************************************************************************#
#                          MakeFile  -  description
#                            -------------------
#   début                : 01/2023
#   copyright            : (C) 2023 par Hugo WARIN et Clément Giraudon
#   e-mail               : hugo.warin@insa-lyon.fr & clement.giraudon@insa-lyon.fr
#**********************************************************************************#

# Pour compiler le programme
# $make
# Pour effacer les fichiers objets et executables
# $make clean
# Code source dans le dossier ./sourceCode
# Fichiers objets dans le dossier ./objects
# Executable généré dans le répertoire courant
DEBUG=non
ECHO = echo -e

ifeq ($(DEBUG),oui)
	CPPFLAGS=-ansi -pedantic -Wall -Wextra -std=c++11 -g -DMAP
	LDFLAGS=
else
	CPPFLAGS=-ansi -pedantic -Wall -std=c++11
	LDFLAGS=
endif

SRCDIR=./sourceCode
OBJDIR=./objects
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS :=$(subst $(SRCDIR), $(OBJDIR), $(SOURCES:.cpp=.o))
EXECUTABLE=trajet

all: $(EXECUTABLE)
ifeq ($(DEBUG),oui)
	@$(ECHO) "\n----------Attention, le mode debug est activé !----------"
else
	@$(ECHO) "\n----------Mode debug désactivé----------"
endif
	
$(EXECUTABLE): $(OBJECTS)
	@$(ECHO) "\n----------Edition des liens----------\néxécutable : $(EXECUTABLE)"
	g++ -o $@ $^ $(LDFLAGS)
	@$(ECHO) "\n----------Executable correctement compilé----------"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(ECHO) "\n----------Compilation du fichier de $<----------"
	g++ -c $< -o $@  $(CPPFLAGS)

clean:
	@$(ECHO) "\n----------Nettoyage des fichiers compilés/éxécutables----------"
	rm $(EXECUTABLE) $(OBJDIR)/*.o
