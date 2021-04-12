#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "../Header/livre.h"

void Liste_Livre(MYSQL *connexion)
{

    MYSQL_RES *resultat;
    MYSQL_ROW  ligne;

    mysql_query(connexion,"SELECT * FROM livre");

    resultat = mysql_store_result(connexion);

    printf("\t\t\tid\tTitre\tDate de Parution\n\n");

    while((ligne = mysql_fetch_row(resultat)))
    {
        
        printf("\t\t\t%s\t%s\t%s\n", ligne[0] , ligne[1] , ligne[2]);

    }
    
    mysql_free_result(resultat);
    mysql_close(connexion);
}

void insere_livre(MYSQL *conn)
{
   
    char titre_livre[255];
    char annee_livre[255];
    char req[255];
   
    printf("\t\t\t======== AJOUTER UN LIVRE ==========\n\n");

    printf("\t\t\tENTRER LE TITRE DU LIVRE :");
    scanf("%s",&titre_livre);
    printf("\n\t\t\tENTRER LA DATE DE PARUTION DU LIVRE (au format yyyy/mm/jj):"); 
    scanf("%s",&annee_livre);
    printf("\t\t\t==============================================================");
    
    sprintf(req,"INSERT INTO livre (titre,annee_parution) VALUES('%s','%s')",titre_livre,annee_livre);
            
    if(mysql_query(conn,req))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }
    else
    {      
            printf("\t\t\t  +---------------------------------------------------+\n");
            printf("\t\t\t  |          INSERTION EFFECTUEE AVEC SUCCES !!       | \n");
            printf("\t\t\t  +---------------------------------------------------+\n");

    }
    mysql_close(conn);

}
