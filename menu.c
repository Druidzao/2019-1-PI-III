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
#define TRUE 1
#define FALSE 0

/*
 * 
 */


int main(int argc, char** argv) {
    int vMenuPrincipal, vSubMenu;
    char vInsercao[255];
    do{
        vMenuPrincipal = menuPrincipal();
        switch(vMenuPrincipal){
            case 'a': do{
                 vSubMenu = subMenu("APARELHO");
                 switch(vSubMenu){
                    case 'i': InserirAparelho(); break;
                    case 'm': printf("MANUTENCAO\n"); break;
                    case 'c': printf("CONSULTA\n"); break;
                    case 'e': printf("EXCLUSAO\n"); break;
                    case 'v': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;
            
            case 'c': do{
                 vSubMenu = subMenu("CLIENTE");
                 switch(vSubMenu){
                    case 'i': InserirCliente(); break;
                    case 'm': printf("MANUTENCAO\n"); break;
                    case 'c': printf("CONSULTA\n"); break;
                    case 'e': printf("EXCLUSAO\n"); break;
                    case 'v': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;
            
            case 'f': do{
                 vSubMenu = subMenu("FUNCIONARIO");
                 switch(vSubMenu){
                    case 'i': InserirFuncionario(); break;
                    case 'm': printf("MANUTENCAO\n"); break;
                    case 'c': printf("CONSULTA\n"); break;
                    case 'e': printf("EXCLUSAO\n"); break;
                    case 'v': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;
            
            case 'i': do{
                 vSubMenu = subMenu("ITEM SERVICO");
                 switch(vSubMenu){
                    case 'i': InserirItemServico(); break;
                    case 'm': printf("MANUTENCAO\n"); break;
                    case 'c': printf("CONSULTA\n"); break;
                    case 'e': printf("EXCLUSAO\n"); break;
                    case 'v': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;
            
            case 'o': do{
                 vSubMenu = subMenu("ORDEM SERVICO");
                 switch(vSubMenu){
                    case 'i': InserirOrdemServico(); break;
                    case 'm': //Criar;
                    case 'c': //Criar;
                    case 'e': //Criar;
                    case 'v': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;
            
            case 'p': do{
                 vSubMenu = subMenu("PRODUTO");
                 switch(vSubMenu){
                    case 'i': InserirProduto(); break;
                    case 'm': printf("MANUTENCAO\n"); break;
                    case 'c': printf("CONSULTA\n"); break;
                    case 'e': printf("EXCLUSAO\n"); break;
                    case 'v': vSubMenu = 5; break;  
                 }                
            }while(vSubMenu != 5);
            break;
            
            case 's': vMenuPrincipal = 8;
            break;
        }
    }while(vMenuPrincipal != 8);
            
    return (EXIT_SUCCESS);
}
