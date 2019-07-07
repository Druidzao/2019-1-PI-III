/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menu.c
 * Author: claudinei
 *
 * Created on 26 de Junho de 2019, 23:28
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include "SGAT.h"

/*
 * 
 */

MYSQL SGBD;
MYSQL_RES *resp;
MYSQL_ROW linhas;
MYSQL_FIELD *campos;
int res;

void InserirRegistro(const char *s){ 
    mysql_init(&SGBD);
    if ( mysql_real_connect(&SGBD, HOSPEDEIRO, USUARIO, SENHA, BDADOS, 0, NULL, 0) ){
        res = mysql_query(&SGBD, s);
        if (!res) printf("REGISTRO INSERIDO COM SUCESSO!\n");
        else
            printf("ERRO NA INSERÇÃO DO REGISTRO %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
            mysql_close(&SGBD);
    }else{
        printf("FALHA DE CONEXÃO\n");
        printf("ERRO %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
    }
}

void EditarRegistro(const char *s){
    mysql_init(&SGBD);
    if ( mysql_real_connect(&SGBD, HOSPEDEIRO, USUARIO, SENHA, BDADOS, 0, NULL, 0) ){
        res = mysql_query(&SGBD, s);
        if (!res) printf("REGISTRO ATUALIZADO COM SUCESSO!\n");
        else
            printf("ERRO NA ATUALIZAÇÃO DO REGISTRO %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
            mysql_close(&SGBD);
    }else{
        printf("FALHA DE CONEXÃO\n");
        printf("ERRO %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
    }
}

void ExcluirRegistro(const char *s){
  mysql_init(&SGBD);
    if ( mysql_real_connect(&SGBD, HOSPEDEIRO, USUARIO, SENHA, BDADOS, 0, NULL, 0) ){
        res = mysql_query(&SGBD, s);
        if (!res) printf("REGISTRO EXCLUIDO COM SUCESSO!\n");
        else
            printf("ERRO NA EXCLUSÃO DO REGISTRO %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
            mysql_close(&SGBD);
    }else{
        printf("FALHA DE CONEXÃO\n");
        printf("ERRO %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
    }
}

void ConsultarRegistro(const char *s){
   mysql_init(&SGBD);
   if ( mysql_real_connect(&SGBD, HOSPEDEIRO, USUARIO, SENHA, BDADOS, 0, NULL, 0) ){
      if (mysql_query(&SGBD, s))
         printf("ERRO: %s\n",mysql_error(&SGBD));
      else
      {
         resp = mysql_store_result(&SGBD);
        if (resp) 
        {
           campos = mysql_fetch_fields(resp);
           for(int conta = 0; conta<mysql_num_fields(resp); conta++){
              printf("%s ",(campos[conta]).name);
              if (mysql_num_fields(resp)>1)
                  printf("\t");
              }
        
              printf("\n");  
              while ((linhas=mysql_fetch_row(resp)) != NULL)
              {
                 for (int conta = 0; conta<mysql_num_fields(resp); conta++)
                    printf("%s\t ",linhas[conta]);
                printf("\n");
              }
          }
          mysql_free_result(resp);
        }
        mysql_close(&SGBD);
   }
   else
   {
      printf("FALHA DE CONEXÃO\n");
      if (mysql_errno(&SGBD))
         printf("ERRO %d : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
   }
}

int menuPrincipal(){
    char s[80], vPeso; 
    do{
        system("clear");
        printf("##############################################################################\n");
        printf("#                                    SGAT                                    #\n");
        printf("#                  SISTEMA GERENCIAL DE ASSISTÊNCIA TÉCNICA                  #\n");
        printf("##############################################################################\n");
        printf("                                MENU PRINCIPAL                                \n");
        printf("##############################################################################\n");
        printf("#                               (A)PARELHO                                   #\n");
        printf("#                               (C)LIENTE                                    #\n");   	
        printf("#                               (F)UNCIONARIO                                #\n");
        printf("#                               (I)TEM SERVIÇO                               #\n"); 
        printf("#                               (O)RDEM SERVIÇO                              #\n"); 
        printf("#                               (P)RODUTO                                    #\n"); 
        printf("#                               (S)AIR                                       #\n"); 	
        printf("##############################################################################\n");
        printf("#                     PROJETO INTERDISCIPLINAR III 2019-1                    #\n");
        printf("##############################################################################\n");
        printf("Escolha: "); 
       // s =  toupper(s);
        fgets(s, sizeof(s), stdin);
    }while(!strchr("ACFIOPS", *s));
    return (*s);
}

int subMenu(const char *vTitulo){
    char s[80];
    do{
        system("clear");
        printf("##############################################################################\n");
        printf("#                                    SGAT                                    #\n");
        printf("#                  SISTEMA GERENCIAL DE ASSISTÊNCIA TÉCNICA                  #\n");
        printf("##############################################################################\n");
        printf("                                MENU %s                               \n", vTitulo);
        printf("##############################################################################\n");
        printf("#                                 (I)NCLUSÃO                                 #\n");
        printf("#                                 (M)ANUTENÇÃO                               #\n");   	
        printf("#                                 (C)ONSULTA                                 #\n");
        printf("#                                 (E)XCLUSÃO                                 #\n"); 
        printf("#                                 (V)OLTAR                                   #\n"); 	
        printf("##############################################################################\n");
        printf("#                     PROJETO INTERDISCIPLINAR III 2019-1                    #\n");
        printf("##############################################################################\n");
        printf("Escolha: ");
        fgets(s, sizeof(s), stdin);
    }while(!strchr("IMCEV", *s));
    return (*s);
}

void cabecalhoGeral(const char *vTitulo){
        system("clear");
        printf("##############################################################################\n");
        printf("#                                    SGAT                                    #\n");
        printf("#                  SISTEMA GERENCIAL DE ASSISTÊNCIA TÉCNICA                  #\n");
        printf("##############################################################################\n");
        printf("                             %s\n", vTitulo);
        printf("##############################################################################\n");
}