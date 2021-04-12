#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "../Header/menu.h"
#include "../Header/connexion.h"

int main()
{
    
   char rep;
    
   do
   {   
       MYSQL *conn = mysql_init(NULL);

       connexion(conn);    

       instruction(conn);

       do
       {
           printf("\n\t\t\t Souhaitez-vous continuer ? (y/n) :");
           scanf("%c",&rep);
           printf("\n\n");
           /* code */
       } while (rep != 'y' && rep != 'n');
       /* code */

   } while (rep == 'y');
   
   printf("\n\t\t\tFin du programme\n\n");
        
   return 0;

}