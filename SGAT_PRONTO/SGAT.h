/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SGAT.h
 * Author: claudinei
 *
 * Created on 4 de Junho de 2019, 23:31
 */

#ifndef SGAT_H
#define SGAT_H
#define HOSPEDEIRO "localhost"
#define USUARIO "claudinei"
#define SENHA "123456"
#define BDADOS "Assistencia"

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
    char vDataAbertura[15];
    char vDataFechamento[15];
    char vSituacao[15];
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

int menuPrincipal();
int subMenu(const char *titulo);
void cabecalhoGeral(const char *titulo);
void InserirRegistro(const char *s);
void EditarRegistro(const char *s);
void ConsultarRegistro(const char *s);
void ExcluirRegistro(const char *s);

#endif /* SGAT_H */
