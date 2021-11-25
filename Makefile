cc = gcc
exec = test
all:$(exec)

$(exec) : adherant.o connexion.o emprunter.o livre.o Main.o menu.o
	@$(cc) -o $(exec) adherant.o connexion.o emprunter.o livre.o Main.o menu.o -lmysqlclient
adherant.o : Source/adherant.c  Header/adherant.h
	@$(cc) -c Source/adherant.c -lmysqlclient
connexion.o : Source/connexion.c  Header/connexion.h
	@$(cc) -c Source/connexion.c -lmysqlclient
emprunter.o : Source/emprunter.c  Header/emprunter.h
	@$(cc) -c Source/emprunter.c -lmysqlclient
livre.o : Source/livre.c  Header/livre.h
	@$(cc) -c Source/livre.c -lmysqlclient
Main.o : Source/Main.c  Header/menu.h Header/connexion.h
	@$(cc) -c Source/Main.c -lmysqlclient
menu.o : Source/menu.c  Header/menu.h
	@$(cc) -c Source/menu.c -lmysqlclient
clean : 
	@rm -rf *.o
mrproper : clean 
	@rm -rf test
execute : $(exec)
	@./test