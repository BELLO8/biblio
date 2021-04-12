#ifndef EMPRUNTER_H 
#define EMPRUNTER_H

void emprunterUnLivre(MYSQL *conn);

void deposer_livre(MYSQL *conn);

void liste_emprunt(MYSQL *conn);

#endif // !