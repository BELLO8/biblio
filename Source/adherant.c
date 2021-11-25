#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "../Header/adherant.h"

void liste_Adeherant(MYSQL *connexion)
{
    MYSQL_RES *resultat;
    MYSQL_ROW  ligne;

    mysql_query(connexion,"SELECT * FROM adherant");

    resultat = mysql_store_result(connexion);
     
    printf("\t\t\tid\tnom \tprenom\t Code d'emprunt\n\n");
    while((ligne = mysql_fetch_row(resultat)))
    {
        
        printf("\t\t\t%s\t%s\t%s\t%s\n", ligne[0] , ligne[1] , ligne[2] , ligne[3]);

    }
    
    mysql_free_result(resultat);
    mysql_close(connexion);
    
}

void ajouter_adherant(MYSQL *con)
{

    char nom_adh[255];
    char prenom_adh[255];
    int  code_emp;
    char requetes[255];

    printf("\t\t\t+--------------------------------------------------------+n");
    printf("\t\t\t|              **BIENVENUE NOUVEAU ADHERANT**            |\n");
    printf("\t\t\t+--------------------------------------------------------+\n\n");

    printf("\t\t\tENTRER VOTRE NOM :");
    scanf("%s",&nom_adh);
    printf("\n\t\t\tENTRER VOTRE PRENOM :");
    scanf("%s",&prenom_adh);
    printf("\n\t\t\tENTRER UN CODE A 4 CHIFFRES POUR EMPRUNTER UN LIVRE : ");
    scanf("%d",&code_emp);
    printf("\n");

    sprintf(requetes,"INSERT INTO adherant (nom_adh,prenom,code_emp) VALUES('%s','%s',%d)",nom_adh,prenom_adh,code_emp);
    
    if(mysql_query(con,requetes))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    else
    {      
        printf("\t\t\t  +--------------------------------------------+\n");
        printf("\t\t\t  |            ADHERER AVEC SUCCES !!!         |\n");
        printf("\t\t\t  +--------------------------------------------+\n");

    }

    mysql_close(con);

}