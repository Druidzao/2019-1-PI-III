/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SGAT.c
 * Author: claudinei
 * 
 * Created on 4 de Junho de 2019, 23:31
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include "SGAT.h"

MYSQL SGBD;
int res;

struct Aparelho{
    char vAparelho[20];
    char vMarca[20];
    char vModelo[20];
    char vSerie[20];    
}sAparelho;

struct Cliente{
    char vNome[50];
    char vEndereco[50];
    char vTelefone[17];    
    char vCelular[17];
}sCliente;

struct Funcionario{
    char vNome[50];
    char vFuncao[20];
}sFuncionario;

struct ItemServico{
    int vQuantidade;
    float vValor;
    int vF_Produto;
    int vF_OrdemServico;
}sItemServico;

struct OrdemServico{
    char vDataAbertura[10];
    char vDataFechamento[10];
    char vSituacao[1];
    char vDefeitoReclamado[255];
    char vObservacao[255];
    char vLaudo[255];
    float vVlr_Mo;
  //  float vVlr_Total;
    int vF_Funcionario;
    int vF_Aparelho;
    int vF_Cliente;
}sOrdemServico;

struct Produto{
    char vNome[50];
    int  vQuantidade;
    float vValor;    
}sProduto;

void InserirAparelho(){ 
    char vInsercao[255];
    cabecalhoGeral("INSERÇÃO DE APARELHO");
    printf("NOME: "); 
    fgets(sAparelho.vAparelho, sizeof(sAparelho.vAparelho), stdin); 
    printf("MARCA: ");
    fgets(sAparelho.vMarca, sizeof(sAparelho.vMarca), stdin);    
    printf("MODELO: ");
    fgets(sAparelho.vModelo, sizeof(sAparelho.vModelo), stdin);    
    printf("SERIE: ");
    fgets(sAparelho.vSerie, sizeof(sAparelho.vSerie), stdin); 
    mysql_init(&SGBD);
    if ( mysql_real_connect(&SGBD, "localhost", "claudinei", "123456", "Assistencia", 0, NULL, 0) ){
        printf("conectado com sucesso!\n");
            sprintf(vInsercao, "INSERT INTO aparelho(nome, marca, modelo, serie) values('%s', '%s', '%s', '%s');", 
                sAparelho.vAparelho, sAparelho.vMarca, sAparelho.vModelo, sAparelho.vSerie);
        res = mysql_query(&SGBD, vInsercao);

        if (!res) printf("Registros inseridos %llu\n", mysql_affected_rows(&SGBD));
        else
            printf("Erro na inserção %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
            mysql_close(&SGBD);
    }else{
        printf("Falha de conexao\n");
        printf("Erro %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
    }
}
void InserirCliente(){ 
    char vInsercao[255];
    cabecalhoGeral("INSERÇÃO DE CLIENTE");
    printf("NOME: "); 
    fgets(sCliente.vNome, sizeof(sCliente.vNome), stdin); 
    printf("ENDEREÇO: ");
    fgets(sCliente.vEndereco, sizeof(sCliente.vEndereco), stdin);    
    printf("TELEFONE: ");
    fgets(sCliente.vTelefone, sizeof(sCliente.vTelefone), stdin);    
    printf("CELULAR: ");
    fgets(sCliente.vCelular, sizeof(sCliente.vCelular), stdin); 
    mysql_init(&SGBD);
    if ( mysql_real_connect(&SGBD, "localhost", "claudinei", "123456", "Assistencia", 0, NULL, 0) ){
        printf("conectado com sucesso!\n");
            sprintf(vInsercao, "INSERT INTO cliente(nome, endereco, telefone, celular) values('%s', '%s', '%s', '%s');", 
                sCliente.vNome, sCliente.vEndereco, sCliente.vTelefone, sCliente.vCelular);
        res = mysql_query(&SGBD, vInsercao);

        if (!res) printf("Registros inseridos %llu\n", mysql_affected_rows(&SGBD));
        else
            printf("Erro na inserção %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
            mysql_close(&SGBD);
    }else{
        printf("Falha de conexao\n");
        printf("Erro %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
    }
}

void InserirFuncionario(){
    char vInsercao[255];
    cabecalhoGeral("INSERÇÃO DE FUNCIONARIO");
    printf("NOME: "); 
    fgets(sFuncionario.vNome, sizeof(sFuncionario.vNome), stdin); 
    printf("FUNÇÃO: ");
    fgets(sFuncionario.vFuncao, sizeof(sFuncionario.vFuncao), stdin);
    sprintf(vInsercao, "INSERT INTO funcionario(nome, funcao) values('%s', '%s');", 
                       sFuncionario.vNome, sFuncionario.vFuncao);
    mysql_init(&SGBD);
    if ( mysql_real_connect(&SGBD, "localhost", "claudinei", "123456", "Assistencia", 0, NULL, 0) ){
        printf("conectado com sucesso!\n");
        res = mysql_query(&SGBD, vInsercao);
        if (!res) printf("Registros inseridos %llu\n", mysql_affected_rows(&SGBD));
        else
            printf("Erro na inserção %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
            mysql_close(&SGBD);
    }else{
        printf("Falha de conexao\n");
        printf("Erro %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
    }    
}

void InserirItemServico(){
    char vInsercao[255];
    cabecalhoGeral("INSERÇÃO DE ITEM SERVIÇO");
    printf("COD ORDEM SERVÇO: ");
    scanf("%i", &sItemServico.vF_OrdemServico);
    printf("COD PRODUTO: "); 
    scanf("%i", &sItemServico.vF_Produto); 
    printf("QUANTIDADE: ");
    scanf("%i", &sItemServico.vQuantidade);
    printf("VALOR: ");
    scanf("%f", &sItemServico.vValor);
    sprintf(vInsercao, "INSERT INTO item_servico(f_ordem_servico, f_produto, quantidade, valor) values('%i', '%i', '%i','%f');", 
                       sItemServico.vF_OrdemServico, sItemServico.vF_Produto, sItemServico.vQuantidade, sItemServico.vValor);
    mysql_init(&SGBD);
    if ( mysql_real_connect(&SGBD, "localhost", "claudinei", "123456", "Assistencia", 0, NULL, 0) ){
        printf("conectado com sucesso!\n");
        res = mysql_query(&SGBD, vInsercao);
        if (!res) printf("Registros inseridos %llu\n", mysql_affected_rows(&SGBD));
        else
            printf("Erro na inserção %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
            mysql_close(&SGBD);
    }else{
        printf("Falha de conexao\n");
        printf("Erro %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
    }    
}

void InserirOrdemServico(){ 
    char vInsercao[255];
    cabecalhoGeral("INSERÇÃO DE ORDEM SERVIÇO");
    printf("DATA EMISSÂO: "); 
    fgets(sOrdemServico.vDataAbertura, sizeof(sOrdemServico.vDataAbertura), stdin); 
    printf("SITUAÇÃO: ");
    fgets(sOrdemServico.vSituacao, sizeof(sOrdemServico.vSituacao), stdin);    
    printf("COD FUNCIONARIO: ");
    scanf("%i", &sOrdemServico.vF_Funcionario);
    printf("COD CLIENTE: ");
    scanf("%i", &sOrdemServico.vF_Cliente); 
    printf("COD APARELHO: "); 
    scanf("%i", &sOrdemServico.vF_Aparelho);
    printf("DEFEITO RECLAMADO: ");
    fgets(sOrdemServico.vDefeitoReclamado, sizeof(sOrdemServico.vDefeitoReclamado), stdin);    
    printf("OBSERVAÇÃO: ");
    fgets(sOrdemServico.vObservacao, sizeof(sOrdemServico.vObservacao), stdin);    
    printf("LAUDO: ");
    fgets(sOrdemServico.vLaudo, sizeof(sOrdemServico.vLaudo), stdin); 
    printf("VLR MÃO DE OBRA: "); 
    scanf("%f", &sOrdemServico.vVlr_Mo); 
    printf("DATA FECHAMENTO: ");
    fgets(sOrdemServico.vDataFechamento, sizeof(sOrdemServico.vDataFechamento), stdin);    
    mysql_init(&SGBD);
    if ( mysql_real_connect(&SGBD, "localhost", "claudinei", "123456", "Assistencia", 0, NULL, 0) ){
        printf("conectado com sucesso!\n");
        sprintf(vInsercao, "INSERT INTO ordem_servico(data_abertura, sts, f_funcionario, f_cliente, f_aparelho, defeito_reclamado, observacao, laudo, vlr_mo, data_fechamento) values('%s', '%s', '%i', '%i', '%i', '%s', '%s', '%s', '%f', '%s');", 
                sOrdemServico.vDataAbertura, sOrdemServico.vSituacao, sOrdemServico.vF_Funcionario, sOrdemServico.vF_Cliente, sOrdemServico.vF_Aparelho,
                sOrdemServico.vDefeitoReclamado, sOrdemServico.vObservacao, sOrdemServico.vLaudo, sOrdemServico.vVlr_Mo, sOrdemServico.vDataFechamento);
        res = mysql_query(&SGBD, vInsercao);

        if (!res) printf("Registros inseridos %llu\n", mysql_affected_rows(&SGBD));
        else
            printf("Erro na inserção %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
            mysql_close(&SGBD);
    }else{
        printf("Falha de conexao\n");
        printf("Erro %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
    }
}

void InserirProduto(){
    char vInsercao[255];
    cabecalhoGeral("INSERÇÃO DE PRODUTO");
    printf("PRODUTO: "); 
    fgets(sProduto.vNome, sizeof(sProduto.vNome), stdin); 
    printf("QUANTIDADE: ");
    scanf("%i", &sProduto.vQuantidade);
    printf("VALOR: ");
    scanf("%f", &sProduto.vValor);
    sprintf(vInsercao, "INSERT INTO produto(nome, quantidade, valor) values('%s', '%i', '%f');", 
                       sProduto.vNome, sProduto.vQuantidade, sProduto.vValor);
    mysql_init(&SGBD);
    if ( mysql_real_connect(&SGBD, "localhost", "claudinei", "123456", "Assistencia", 0, NULL, 0) ){
        printf("conectado com sucesso!\n");
        res = mysql_query(&SGBD, vInsercao);
        if (!res) printf("Registros inseridos %llu\n", mysql_affected_rows(&SGBD));
        else
            printf("Erro na inserção %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
            mysql_close(&SGBD);
    }else{
        printf("Falha de conexao\n");
        printf("Erro %u : %s\n", mysql_errno(&SGBD), mysql_error(&SGBD));
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
    }while(!strchr("acfiops", *s));
    return (*s);
}

int subMenu(const char *titulo){
    char s[80];
    do{
        system("clear");
        printf("##############################################################################\n");
        printf("#                                    SGAT                                    #\n");
        printf("#                  SISTEMA GERENCIAL DE ASSISTÊNCIA TÉCNICA                  #\n");
        printf("##############################################################################\n");
        printf("                                MENU %s                               \n", titulo);
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
    }while(!strchr("imcev", *s));
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
