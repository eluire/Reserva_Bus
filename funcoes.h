#ifndef FUNÇÕES_H_INCLUDED
#define FUNÇÕES_H_INCLUDED
#define MAXL 48
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<fstream>


using namespace std;

struct Cadeira //estrutura para pegar a fileira e o numero da poltrona
{
    string lugar;
    string ocupado;
};
struct Pessoa // estrutura do cadastro do passageiro
{
   string nome,rg;
   Cadeira assento;
};
struct Onibus //estrutura para ver se está ocupado ou nao o lugar
{
    Pessoa ocupantes[MAXL];


};

void bem_vindo();
void verificador(int &var);
void inicializador();
void cidade(int &a);
void horario(int &b);
void escolher_onibus(int a,int b,Onibus recM,Onibus recN,Onibus jpM,Onibus jpN);
void mostrar_bus();
void reservafinal(Onibus &bus);
int voltar_menu();
void verificadordeassento(int &cont);//função para verificar se a poltrona digitada existe
void carregar_dados(Onibus &recM,Onibus &recN,Onibus &jpM,Onibus &jpN);
void atualizar_dados(Onibus recM,Onibus recN,Onibus jpM,Onibus jpN);




#endif // FUNÇÕES_H_INCLUDED
