#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "../Header/connexion.h"


void connexion(MYSQL *conn)
{
    

    if(conn == NULL)
    {
        fprintf(stderr,"%s\n",mysql_error(conn));
        exit(0);
    }
    if(mysql_real_connect(conn,"localhost","root","kader","Biblio",0,NULL,0) == NULL)
    {
        fprintf(stderr,"%s\n",mysql_error(conn));
        mysql_close(conn);
        exit(0);
    }
    else
    {
        printf("\n");

    }
    
}
