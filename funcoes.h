#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
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

void bem_vindo();//função que recebe o usuario com um bem vindo
void verificador(int &var);// verifica se o numero digitado está nos parâmetros
void inicializador();//mostra o passo a passo que o usuário deverá seguir para reservar sua passagem
void cidade(int &a);//mostra os destinos
void horario(int &b);//mostra os horários para cada destino
void escolher_onibus(int a,int b,Onibus &recM,Onibus &recN,Onibus &jpM,Onibus &jpN,  string vetorbusrecM[MAXL],string vetorbusrecN[MAXL],string vetorbusjpM[MAXL],string vetorbusjpN[MAXL]);//relaciona o destino e horário com um determinado onibus
void mostrar_bus(string vetorbus[MAXL]);//mostra as poltronas do onibus
void reservafinal(Onibus &bus,string vetorbus[MAXL]);//vê a disponibilidade da poltrona escolhida e salva os dados do usuário
int voltar_menu();//oferece ao usuário 2 opções: se ele quer continuar comprandou ou sair do sistema
void verificadordeassento(int &cont);//função para verificar se a poltrona digitada existe
void carregar_dados(Onibus &recM,Onibus &recN,Onibus &jpM,Onibus &jpN);//carrega os arquivos de cada onibus para dentro de suas respectivas estruturas
void atualizar_dados(Onibus &recM,Onibus &recN,Onibus &jpM,Onibus &jpN);//atualiza os arquivos com as mudanças feitas nas respecitivas estruturas
void caregar_bus(string vetorbusrecM[MAXL],string vetorbusrecN[MAXL],string vetorbusjpM[MAXL],string vetorbusjpN[MAXL]);//carrega os arquivos de cada array de disponibilidade das poltronas na  main
void atualizar_bus(string vetorbusrecM[MAXL],string vetorbusrecN[MAXL],string vetorbusjpM[MAXL],string vetorbusjpN[MAXL]);// atualiza os arquivos de disponibilidade das poltronas




#endif // FUNCOES_H_INCLUDED
