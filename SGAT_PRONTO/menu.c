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
#include <stdlib.h>
#include <mysql/mysql.h>
#include "SGAT.h"

/*
 * 
 */


int main(int argc, char** argv) {
    int vMenuPrincipal, vSubMenu, vSimNao, vInteiraGlobal;
    char vStringGeral[255];
    do{
        vMenuPrincipal = menuPrincipal();
        switch(vMenuPrincipal){
            case 'A': do{
                 vSubMenu = subMenu("APARELHO");
                 switch(vSubMenu){
                    case 'I': do{
                              cabecalhoGeral("INSERÇÃO DE APARELHO");
                              printf("NOME: "); 
                              fgets(sAparelho.vAparelho, sizeof(sAparelho.vAparelho), stdin); 
                              setbuf(stdin, NULL);
                              printf("MARCA: ");
                              fgets(sAparelho.vMarca, sizeof(sAparelho.vMarca), stdin); 
                              setbuf(stdin, NULL);   
                              printf("MODELO: ");
                              fgets(sAparelho.vModelo, sizeof(sAparelho.vModelo), stdin); 
                              setbuf(stdin, NULL);   
                              printf("SERIE: ");
                              fgets(sAparelho.vSerie, sizeof(sAparelho.vSerie), stdin); 
                              sprintf(vStringGeral, "insert into aparelho(nome, marca, modelo, serie) values('%s', '%s', '%s', '%s');", 
                              sAparelho.vAparelho, sAparelho.vMarca, sAparelho.vModelo, sAparelho.vSerie);
                              InserirRegistro(vStringGeral);
                              printf("DESEJA INSERIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                         }while(vSimNao == 1); break;                              
                    case 'M': do{
                              cabecalhoGeral("ATUALIZAÇÃO DE APARELHO");
                              printf("DIGITE O CODIGO DO REGISTRO A SER ATUALIZADO: ");
                              scanf("%i", &vInteiraGlobal);
                              setbuf(stdin, NULL);
                              printf("NOME: "); 
                              fgets(sAparelho.vAparelho, sizeof(sAparelho.vAparelho), stdin); 
                              setbuf(stdin, NULL);
                              printf("MARCA: ");
                              fgets(sAparelho.vMarca, sizeof(sAparelho.vMarca), stdin); 
                              setbuf(stdin, NULL);   
                              printf("MODELO: ");
                              fgets(sAparelho.vModelo, sizeof(sAparelho.vModelo), stdin); 
                              setbuf(stdin, NULL);   
                              printf("SERIE: ");
                              fgets(sAparelho.vSerie, sizeof(sAparelho.vSerie), stdin); 
                              sprintf(vStringGeral, "update aparelho set nome = '%s', marca = '%s', modelo = '%s', serie = '%s' where p_codigo = %i;", 
                              sAparelho.vAparelho, sAparelho.vMarca, sAparelho.vModelo, sAparelho.vSerie, vInteiraGlobal);
                              EditarRegistro(vStringGeral);
                              printf("DESEJA ATUALIZAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                          }while(vSimNao == 1); break;
                    case 'C': do{
                                 cabecalhoGeral("CONSULTA DE APARELHO");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER CONSULTADO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "select * from aparelho where p_codigo = %i;", vInteiraGlobal);
                                 ConsultarRegistro(vStringGeral); 
                                 printf("DESEJA CONSULTAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'E': do{
                                 cabecalhoGeral("EXCLUSÂO DE APARELHO");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER EXCLUIDO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "delete from aparelho where p_codigo = %i;", vInteiraGlobal);
                                 ExcluirRegistro(vStringGeral); 
                                 printf("DESEJA EXCLUIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'V': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;

            case 'C': do{
                 vSubMenu = subMenu("CLIENTE");
                 switch(vSubMenu){
                    case 'I': do{
                              cabecalhoGeral("INSERÇÃO DE CLIENTE");
                              printf("NOME: "); 
                              fgets(sCliente.vNome, sizeof(sCliente.vNome), stdin); 
                              setbuf(stdin, NULL);
                              printf("ENDEREÇO: ");
                              fgets(sCliente.vEndereco, sizeof(sCliente.vEndereco), stdin); 
                              setbuf(stdin, NULL);   
                              printf("TELEFONE: ");
                              fgets(sCliente.vTelefone, sizeof(sCliente.vTelefone), stdin); 
                              setbuf(stdin, NULL);   
                              printf("CELULAR: ");
                              fgets(sCliente.vCelular, sizeof(sCliente.vCelular), stdin); 
                              sprintf(vStringGeral, "insert into cliente(nome, endereco, telefone, celular) values('%s', '%s', '%s', '%s');", 
                              sCliente.vNome, sCliente.vEndereco, sCliente.vTelefone, sCliente.vCelular);
                              InserirRegistro(vStringGeral);
                              printf("DESEJA INSERIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                         }while(vSimNao == 1); break;                              
                    case 'M': do{
                              cabecalhoGeral("ATUALIZAÇÃO DE CLIENTE");
                              printf("DIGITE O CODIGO DO REGISTRO A SER ATUALIZADO: ");
                              scanf("%i", &vInteiraGlobal);
                              setbuf(stdin, NULL);
                              printf("NOME: "); 
                              fgets(sCliente.vNome, sizeof(sCliente.vNome), stdin); 
                              setbuf(stdin, NULL);
                              printf("ENDERECO: ");
                              fgets(sCliente.vEndereco, sizeof(sCliente.vEndereco), stdin); 
                              setbuf(stdin, NULL);   
                              printf("TELEFONE: ");
                              fgets(sCliente.vTelefone, sizeof(sCliente.vTelefone), stdin); 
                              setbuf(stdin, NULL);   
                              printf("CELULAR: ");
                              fgets(sCliente.vCelular, sizeof(sCliente.vCelular), stdin); 
                              sprintf(vStringGeral, "update cliente set nome = '%s', endereco = '%s', telefone = '%s', celular = '%s' where p_codigo = %i;", 
                              sCliente.vNome, sCliente.vEndereco, sCliente.vTelefone, sCliente.vCelular, vInteiraGlobal);
                              EditarRegistro(vStringGeral);
                              printf("DESEJA ATUALIZAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                          }while(vSimNao == 1); break;
                    case 'C': do{
                                 cabecalhoGeral("CONSULTA DE CLIENTE");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER CONSULTADO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "select * from cliente where p_codigo = %i;", vInteiraGlobal);
                                 ConsultarRegistro(vStringGeral); 
                                 printf("DESEJA CONSULTAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'E': do{
                                 cabecalhoGeral("EXCLUSÂO DE CLIENTE");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER EXCLUIDO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "delete from cliente where p_codigo = %i;", vInteiraGlobal);
                                 ExcluirRegistro(vStringGeral); 
                                 printf("DESEJA EXCLUIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'V': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;

            case 'F': do{
                 vSubMenu = subMenu("FUNCIONÁRIO");
                 switch(vSubMenu){
                    case 'I': do{
                              cabecalhoGeral("INSERÇÃO DE FUNCIONÁRIO");
                              printf("NOME: "); 
                              fgets(sFuncionario.vNome, sizeof(sFuncionario.vNome), stdin); 
                              setbuf(stdin, NULL);
                              printf("FUNÇÃO: ");
                              fgets(sFuncionario.vFuncao, sizeof(sFuncionario.vFuncao), stdin);
                              sprintf(vStringGeral, "insert into funcionario(nome, funcao) values('%s', '%s');", 
                              sFuncionario.vNome, sFuncionario.vFuncao);
                              InserirRegistro(vStringGeral);
                              printf("DESEJA INSERIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                         }while(vSimNao == 1); break;                              
                    case 'M': do{
                              cabecalhoGeral("ATUALIZAÇÃO DE FUNCIONÁRIO");
                              printf("DIGITE O CODIGO DO REGISTRO A SER ATUALIZADO: ");
                              scanf("%i", &vInteiraGlobal);
                              setbuf(stdin, NULL);
                              printf("NOME: "); 
                              fgets(sFuncionario.vNome, sizeof(sFuncionario.vNome), stdin); 
                              setbuf(stdin, NULL);
                              printf("FUNÇÃO: ");
                              fgets(sFuncionario.vFuncao, sizeof(sFuncionario.vFuncao), stdin);
                              sprintf(vStringGeral, "update funcionario set nome = '%s', funcao = '%s' where p_codigo = %i;", 
                              sFuncionario.vNome, sFuncionario.vFuncao, vInteiraGlobal);
                              EditarRegistro(vStringGeral);
                              printf("DESEJA ATUALIZAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                          }while(vSimNao == 1); break;
                    case 'C': do{
                                 cabecalhoGeral("CONSULTA DE FUNCIONÁRIO");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER CONSULTADO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "select * from funcionario where p_codigo = %i;", vInteiraGlobal);
                                 ConsultarRegistro(vStringGeral); 
                                 printf("DESEJA CONSULTAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'E': do{
                                 cabecalhoGeral("EXCLUSÂO DE FUNCIONÁRIO");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER EXCLUIDO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "delete from funcionario where p_codigo = %i;", vInteiraGlobal);
                                 ExcluirRegistro(vStringGeral); 
                                 printf("DESEJA EXCLUIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'V': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;

            case 'I': do{
                 vSubMenu = subMenu("ITEM DE SERVIÇO");
                 switch(vSubMenu){
                    case 'I': do{
                              cabecalhoGeral("INSERÇÃO DE ITEM DE SERVIÇO");
                              printf("CÓDIGO DE SERVIÇO: "); 
                              scanf("%i", &sItemServico.vF_OrdemServico); 
                              setbuf(stdin, NULL);
                              printf("CÓDIGO DO PRODUTO: ");
                              scanf("%i", &sItemServico.vF_Produto); 
                              setbuf(stdin, NULL);   
                              printf("QUANTIDADE: ");
                              scanf("%i", &sItemServico.vQuantidade);  
                              setbuf(stdin, NULL);   
                              printf("VALOR: ");
                              scanf("%f", &sItemServico.vValor); 
                              sprintf(vStringGeral, "insert into item_servico(f_ordem_servico, f_produto, quantidade, valor) values('%i', '%i', '%i', '%f');", 
                              sItemServico.vF_OrdemServico, sItemServico.vF_Produto, sItemServico.vQuantidade, sItemServico.vValor);
                              InserirRegistro(vStringGeral);
                              printf("DESEJA INSERIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                         }while(vSimNao == 1); break;                              
                    case 'M': do{
                              cabecalhoGeral("ATUALIZAÇÃO DE ITEM DE SERVIÇO");
                              printf("DIGITE O CODIGO DO REGISTRO A SER ATUALIZADO: ");
                              scanf("%i", &vInteiraGlobal);
                              setbuf(stdin, NULL);
                              printf("CÓDIGO DE SERVIÇO: "); 
                              scanf("%i", &sItemServico.vF_OrdemServico); 
                              setbuf(stdin, NULL);
                              printf("CÓDIGO DO PRODUTO: ");
                              scanf("%i", &sItemServico.vF_Produto); 
                              setbuf(stdin, NULL);   
                              printf("QUANTIDADE: ");
                              scanf("%i", &sItemServico.vQuantidade);  
                              setbuf(stdin, NULL);   
                              printf("VALOR: ");
                              scanf("%f", &sItemServico.vValor); 
                              sprintf(vStringGeral, "update item_servico set f_ordem_servico = '%i', f_produto = '%i', quantidade = '%i', valor = '%f' where p_codigo = %i;", 
                              sItemServico.vF_OrdemServico, sItemServico.vF_Produto, sItemServico.vQuantidade, sItemServico.vValor, vInteiraGlobal);
                              EditarRegistro(vStringGeral);
                              printf("DESEJA ATUALIZAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                          }while(vSimNao == 1); break;
                    case 'C': do{
                                 cabecalhoGeral("CONSULTA DE ITEM DE SERVIÇO");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER CONSULTADO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "select * from item_servico where p_codigo = %i;", vInteiraGlobal);
                                 ConsultarRegistro(vStringGeral); 
                                 printf("DESEJA CONSULTAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'E': do{
                                 cabecalhoGeral("EXCLUSÂO DE ITEM DE SERVIÇO");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER EXCLUIDO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "delete from item_servico where p_codigo = %i;", vInteiraGlobal);
                                 ExcluirRegistro(vStringGeral); 
                                 printf("DESEJA EXCLUIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'V': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;

            case 'O': do{
                 vSubMenu = subMenu("ORDEM DE SERVIÇO");
                 switch(vSubMenu){
                    case 'I': do{
                              cabecalhoGeral("INSERÇÃO DE ORDEM DE SERVIÇO");
                              printf("CÓDIGO FUNCIONARIO: ");
                              scanf("%i", &sOrdemServico.vF_Funcionario); 
                              setbuf(stdin, NULL);   
                              printf("CÓDIGO CLIENTE: ");
                              scanf("%i", &sOrdemServico.vF_Cliente); 
                              setbuf(stdin, NULL);   
                              printf("CÓDIGO APARELHO: ");
                              scanf("%i", &sOrdemServico.vF_Aparelho); 
                              setbuf(stdin, NULL);  
                              printf("DATA EMISSÃO: "); 
                              fgets(sOrdemServico.vDataAbertura, sizeof(sOrdemServico.vDataAbertura), stdin); 
                              setbuf(stdin, NULL);
                              printf("SITUAÇÃO: ");
                              fgets(sOrdemServico.vSituacao, sizeof(sOrdemServico.vSituacao), stdin); 
                              setbuf(stdin, NULL);   
                              printf("DEFEITO RECLAMADO: ");
                              fgets(sOrdemServico.vDefeitoReclamado, sizeof(sOrdemServico.vDefeitoReclamado), stdin); 
                              setbuf(stdin, NULL);   
                              printf("OBSERVAÇÕES GERAIS: ");
                              fgets(sOrdemServico.vObservacao, sizeof(sOrdemServico.vObservacao), stdin); 
                              setbuf(stdin, NULL);
                              sprintf(vStringGeral, "insert into ordem_servico(f_funcionario, f_cliente, f_aparelho, data_abertura, sts, defeito_reclamado, observacao) values('%i', '%i', '%i', '%s', '%s', '%s', '%s');", 
                              sOrdemServico.vF_Funcionario, sOrdemServico.vF_Cliente, sOrdemServico.vF_Aparelho, sOrdemServico.vDataAbertura, sOrdemServico.vSituacao, sOrdemServico.vDefeitoReclamado, sOrdemServico.vObservacao);
                              InserirRegistro(vStringGeral);
                              printf("DESEJA INSERIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                         }while(vSimNao == 1); break;                              
                    case 'M': do{
                              cabecalhoGeral("ATUALIZAÇÃO DE ORDEM DE SERVIÇO");
                              printf("DIGITE O CODIGO DO REGISTRO A SER ATUALIZADO: ");
                              scanf("%i", &vInteiraGlobal);
                              setbuf(stdin, NULL);
                              printf("CÓDIGO FUNCIONARIO: ");
                              scanf("%i", &sOrdemServico.vF_Funcionario); 
                              setbuf(stdin, NULL);   
                              printf("CÓDIGO CLIENTE: ");
                              scanf("%i", &sOrdemServico.vF_Cliente); 
                              setbuf(stdin, NULL);   
                              printf("CÓDIGO APARELHO: ");
                              scanf("%i", &sOrdemServico.vF_Aparelho); 
                              setbuf(stdin, NULL);  
                              printf("DATA EMISSÃO: "); 
                              fgets(sOrdemServico.vDataAbertura, sizeof(sOrdemServico.vDataAbertura), stdin); 
                              setbuf(stdin, NULL);
                              printf("SITUAÇÃO: ");
                              fgets(sOrdemServico.vSituacao, sizeof(sOrdemServico.vSituacao), stdin); 
                              setbuf(stdin, NULL);   
                              printf("DEFEITO RECLAMADO: ");
                              fgets(sOrdemServico.vDefeitoReclamado, sizeof(sOrdemServico.vDefeitoReclamado), stdin); 
                              setbuf(stdin, NULL);   
                              printf("OBSERVAÇÕES GERAIS: ");
                              fgets(sOrdemServico.vObservacao, sizeof(sOrdemServico.vObservacao), stdin); 
                              setbuf(stdin, NULL);
                              sprintf(vStringGeral, "update ordem_servico set f_funcionario = '%i',  f_cliente = '%i', f_aparelho = '%i', data_abertura = '%s', sts = '%s', defeito_reclamado = '%s', observacao = '%s';", 
                              sOrdemServico.vF_Funcionario, sOrdemServico.vF_Cliente, sOrdemServico.vF_Aparelho, sOrdemServico.vDataAbertura, sOrdemServico.vSituacao, sOrdemServico.vDefeitoReclamado, sOrdemServico.vObservacao, vInteiraGlobal);
                              EditarRegistro(vStringGeral);
                              printf("DESEJA ATUALIZAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                          }while(vSimNao == 1); break;
                    case 'C': do{
                                 cabecalhoGeral("CONSULTA DE ORDEM DE SERVIÇO");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER CONSULTADO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "select * from ordem_servico where p_codigo = %i;", vInteiraGlobal);
                                 ConsultarRegistro(vStringGeral); 
                                 printf("DESEJA CONSULTAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'E': do{
                                 cabecalhoGeral("EXCLUSÂO DE ORDEM DE SERVIÇO");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER EXCLUIDO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "delete from ordem_servico where p_codigo = %i;", vInteiraGlobal);
                                 ExcluirRegistro(vStringGeral); 
                                 printf("DESEJA EXCLUIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'V': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;

            case 'P': do{
                 vSubMenu = subMenu("PRODUTO");
                 switch(vSubMenu){
                    case 'I': do{
                              cabecalhoGeral("INSERÇÃO DE PRODUTO");
                              printf("NOME: "); 
                              fgets(sProduto.vNome, sizeof(sProduto.vNome), stdin); 
                              setbuf(stdin, NULL);
                              printf("QUANTIDADE: ");
                              scanf("%i", &sProduto.vQuantidade);
                              setbuf(stdin, NULL);   
                              printf("VALOR: ");
                              scanf("%f", &sProduto.vValor);
                              sprintf(vStringGeral, "insert into produto(nome, quantidade, valor) values('%s', '%i', '%f');", 
                              sProduto.vNome, sProduto.vQuantidade, sProduto.vValor);
                              InserirRegistro(vStringGeral);
                              printf("DESEJA INSERIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                         }while(vSimNao == 1); break;                              
                    case 'M': do{
                              cabecalhoGeral("ATUALIZAÇÃO DE PRODUTO");
                              printf("DIGITE O CODIGO DO REGISTRO A SER ATUALIZADO: ");
                              scanf("%i", &vInteiraGlobal);
                              setbuf(stdin, NULL);
                              printf("NOME: "); 
                              fgets(sProduto.vNome, sizeof(sProduto.vNome), stdin); 
                              setbuf(stdin, NULL);
                              printf("QUANTIDADE: ");
                              scanf("%i", &sProduto.vQuantidade);
                              setbuf(stdin, NULL);   
                              printf("VALOR: ");
                              scanf("%f", &sProduto.vValor);
                              sprintf(vStringGeral, "update produto set nome = '%s', quantidade = '%i', valor = '%f' where p_codigo = %i;", 
                              sProduto.vNome, sProduto.vQuantidade, sProduto.vValor, vInteiraGlobal);
                              EditarRegistro(vStringGeral);
                              printf("DESEJA ATUALIZAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                              scanf("%i", &vSimNao);
                              setbuf(stdin, NULL);
                          }while(vSimNao == 1); break;
                    case 'C': do{
                                 cabecalhoGeral("CONSULTA DE PRODUTO");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER CONSULTADO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "select * from produto where p_codigo = %i;", vInteiraGlobal);
                                 ConsultarRegistro(vStringGeral); 
                                 printf("DESEJA CONSULTAR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'E': do{
                                 cabecalhoGeral("EXCLUSÂO DE PRODUTO");
                                 printf("DIGITE O CODIGO DO REGISTRO A SER EXCLUIDO: ");
                                 scanf("%i", &vInteiraGlobal);
                                 sprintf(vStringGeral, "delete from produto where p_codigo = %i;", vInteiraGlobal);
                                 ExcluirRegistro(vStringGeral); 
                                 printf("DESEJA EXCLUIR OUTRO REGISTRO?\n(1)SIM (2)NÃO\n");
                                 scanf("%i", &vSimNao);
                          }while(vSimNao == 1); break;
                    case 'V': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;
            
            case 'S': vMenuPrincipal = 8;
            break;
        }
    }while(vMenuPrincipal != 8);
            
    return (EXIT_SUCCESS);
}