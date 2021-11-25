#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "../Header/menu.h"
#include "../Header/livre.h"
#include "../Header/adherant.h"
#include "../Header/emprunter.h"


void menu()
{
    printf("\n\n");
    printf("\t\t\t  +-------------- **BIBLIOTHEQUE VIRTUELLE** --------------+\n");
    printf("\t\t\t  |         - 1 - AFFICHER LA LISTE DES LIVRES             |\n");
    printf("\t\t\t  |         - 2 - ADHERER A LA BIBLIOTHEQUE                |\n");
    printf("\t\t\t  |         - 3 - EMPRUNTER UN LIVRE                       |\n");
    printf("\t\t\t  |         - 4 - DEPOSER   UN LIVRE                       |\n");
    printf("\t\t\t  +--------------------------------------------------------+\n");
}

void menu_admin()
{
    printf("\n\n");
    printf("\t\t\t  +----------------- **BIBLIOTHEQUE VIRTUELLE** -------------------+\n");
    printf("\t\t\t  |     PARTIE RESERVEE AUX ADMINISTRATEURS DE LA BIBLIOTHEQUE     |\n");
    printf("\t\t\t  |         1 - AFFICHER LA LISTE DES ADHERANTS                    |\n");
    printf("\t\t\t  |         2 - AJOUTER  UN LIVRE                                  |\n");
    printf("\t\t\t  |         3 - LISTE DES EMPRUNTS                                 |\n");
    printf("\t\t\t  |         4 - VOIR LES STATISTIQUES                              |\n");
    printf("\t\t\t  +----------------------------------------------------------------+\n");
}

void instruction(MYSQL *con)
{   
       
        menu();
        int choixMenu,admin,code;

        printf("\n\t\t\tCHOISISSEZ UNE OPTION :");
        scanf("%d", &choixMenu);
        printf("\n");
        
        switch(choixMenu)
        {
            case 1 : 
                Liste_Livre(con);
                break;

            case 2 : 
                ajouter_adherant(con);
                break;
            
            case 3 :
                emprunterUnLivre(con);
                break;

            case 4 : 
                deposer_livre(con);
                break;

            case 0 : 
                printf("\t\t\tENTRER LE CODE D'ADMINISTRATION : ");
                scanf("%d",&code);

                if(code == 5465)
                {
                    menu_admin();

                    printf("\t\t\tCHOISISSEZ UNE OPTION  :");
                    scanf("%d",&admin);
                    printf("\n");
                    switch(admin)
                    {
                            case 1 : 
                                liste_Adeherant(con);
                                break;

                            case 2 :
                                insere_livre(con);
                                break;

                            case 3 : 
                                printf("\t\t\t============ *** LISTE DES EMPRUNTS *** =============\n\n");
                                liste_emprunt(con);
                                break;

                            case 4 : 
                                printf("\t\t\t============ *** STATISTIQUES DE LA BIBLIOTHEQUE *** =============\n\n");
                                break;

                            default :
                                printf("\t\t\tERREUR DE SAISIR !!!!\n");
                                break;
                    }

                }
                else
                {
                        printf("\t\t\tCODE INCORRECTE !!! \n\n");
                }

                    break;

            default :
                printf("\t\t\tErreur de saisir reessayer !\n");
                break;

        }


}