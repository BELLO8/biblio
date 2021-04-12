#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "../Header/emprunter.h"

void emprunterUnLivre(MYSQL *conn)
{            
        int id_adh , id_livre;
        char nom_adh[255];
        char requete[255];
        MYSQL_RES *resultat;
        MYSQL_ROW  ligne;

        mysql_query(conn,"SELECT * FROM livre");

        resultat = mysql_store_result(conn);
        printf("\n\t\t\t*** Liste des livres ***\n");
        printf("\t\t\tid\tTitre\tDate de Parution\n");

        while((ligne = mysql_fetch_row(resultat)))
        {
            
            printf("\t\t\t%s\t%s\t%s\n", ligne[0] , ligne[1] , ligne[2]);

        }
        
        mysql_free_result(resultat);

        printf("\t\t\t=============================\n");
        printf("\n\n\t\t\tENTRER VOTRE CODE d'EMPRUNT SVP!!! : ");
        scanf("%d",&id_adh);
        printf("\t\t\tENTRER ID DU LIVRE A EMPRUNTER SVP!!! :  ");
        scanf("%d",&id_livre);

        sprintf(requete,"INSERT INTO emprunter(code_emp_adh,id_livre,date_emp,deposer) VALUES( %d,%d,NOW(),'non')",id_adh,id_livre);
        if(mysql_query(conn,requete))
        {
            printf("\t\t\t +--------------------------------------------------------------+\n");
            fprintf(stderr,"\t\t\t | Desolé vous ne pouvez pas effectué deux emprunts             |\n", mysql_error(conn));
            printf("\t\t\t +--------------------------------------------------------------+\n");

            mysql_close(conn);
            exit(1);
        }
        else
        {
            printf("\t\t\t     +---------------------------------------------------------------------------+\n");
            printf("\t\t\t     |      **EMPRUNT EFFECTUEE AVEC SUCCES**                                    |\n");
            printf("\t\t\t     |      A VOTRE ATTENTION : les emprunts ne dure que 2 semaines au plus      |\n");
            printf("\t\t\t     +---------------------------------------------------------------------------+\n");
        }
        mysql_close(conn);
            
}


void deposer_livre(MYSQL *conn)
{          

            int id_adh,id_livre;
            char requete[255];

            printf("\t\t\t====================== **DEPOSER UN LIVRE** =====================");

            printf("\n\n\t\t\tEntrer votre code d'emprunt pour déposer le livre : ");
            scanf("%d",&id_adh);
            printf("\t\t\tEntrer l'id du livre à deposer  :  ");
            scanf("%d",&id_livre);

            sprintf(requete,"UPDATE emprunter SET deposer = 'oui' , date_dep = NOW() WHERE code_emp_adh = %d",id_adh);

            if(mysql_query(conn,requete))
            {
                fprintf(stderr,"%s\n",mysql_error(conn));
                mysql_close(conn);
                exit(1);

            }
            else
            {    

                printf("\t\t\t  +----------------------------------------------------------+\n");
                printf("\t\t\t  |                DEPOT EFFECTUEE AVEC SUCCES               |\n");
                printf("\t\t\t  +----------------------------------------------------------+\n");

            }
            mysql_close(conn);

}


void liste_emprunt(MYSQL *conn)
{
    MYSQL_RES *result;
    MYSQL_ROW ligne;

    mysql_query(conn,"SELECT*FROM emprunter");

    result = mysql_store_result(conn);

    printf("id \t\t code \t\t id_livre \t date d'emprunt \t\tdeposer \tdate de depot \n\n");

    while((ligne = mysql_fetch_row(result)))
    {

        printf("%s \t\t %s \t\t %s \t\t %s \t\t %s \t\t%s \n ", ligne[0] , ligne[1] , ligne[2] , ligne[3] , ligne[4] , ligne[5] );

    }

    mysql_free_result(result);
    mysql_close(conn);
}