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
#define SIZE 200

int menuPrincipal();
int subMenu(const char *titulo);
void cabecalhoGeral(const char *titulo);
void InserirAparelho();
void InserirCliente();
void InserirFuncionario();
void InserirItemServico();
void InserirOrdemServico();
void InserirProduto();

#endif /* SGAT_H */
