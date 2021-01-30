#variable pour le compilateur
CC = gcc
OPT = -Wall -pedantic -Wunused-but-set-variable -Wmissing-prototypes -g2 `pkg-config glib-2.0 --cflags --libs` -lm 

#Wunused-but-set-parameter -Wunused-but-set-variable -ansi -pedantic -Wno-variadic-macros `sdl-config --cflags --libs` -lSDL -lSDL_ttf -lm -Werror -Wfatal-errors

#variable pour les répertoires
SRCDIR = ./src/
BINDIR = ./bin/
DOCDIR = ./doc/
SAVDIR = ./save/
#variable des fichiers
SRC = $(wildcard $(SRCDIR)*.c)
HEAD = $(filter main.h,$(SRC:.c=.h))
OBJ = $(subst $(SRCDIR),$(BINDIR),$(SRC:.c=.o))
TITLE = detectSim
#variable pour les commandes suppmémentaires
RM = rm -rf
CP = cp

all : $(TITLE)

debug : OPT += -g -pg -D __DEBUG__
debug : $(TITLE)
	@echo --- Mode Debug ---

$(TITLE) : $(OBJ)
	$(CC) $(OPT) $^ -o $@

./bin/main.o : ./src/main.c
	$(CC) $(OPT) -c ./src/main.c -o ./bin/main.o

./bin/%.o : ./src/%.c ./src/%.h
	$(CC) $(OPT) -c $< -o $@

.PHONY : clean mrproper save restore doc

doc :
	doxygen Doxyconf

clean :
	@$(RM) $(OBJ) */*~ */\#*\# *~ \#*\# html
	@echo --- Projet Nettoye ---

mrproper: clean
	$(RM) $(TITLE)

save :
	rsync -arv ./src/ ./save/

restore :
	rsync -arv ./save/ ./src/
run :
	clear
	./detectSim
