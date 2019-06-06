/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: claudinei
 
 * Created on 4 de Junho de 2019, 20:12
 */

#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

/*
 * 
 */
int main(int argc, char** argv) {
 MYSQL SGDB;
 int res;

      mysql_init(&SGDB);
      if ( mysql_real_connect(&SGDB, "localhost", "claudinei", "123456", "Assistencia", 0, NULL, 0) )
      {
            printf("conectado com sucesso!\n");

            res = mysql_query(&SGDB,"INSERT INTO cidade(nome, uf) values('Jataí', 'GO');");
            if (!res) printf("Registros inseridos %llu\n", mysql_affected_rows(&SGDB));
            else
                printf("Erro na inserção %u : %s\n", mysql_errno(&SGDB), mysql_error(&SGDB));
            mysql_close(&SGDB);
       }
       else
       {
            printf("Falha de conexao\n");
            printf("Erro %u : %s\n", mysql_errno(&SGDB), mysql_error(&SGDB));
       }

    return (EXIT_SUCCESS);
}

