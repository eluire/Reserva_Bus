#include"funções.h"
#include <string>
using namespace std;


int main()
{
    int a,b;
    char vetorbus[MAXL];
    //declaração de structs
    Onibus recM;
    Onibus recN;
    Onibus jpM;
    Onibus jpN;
    bem_vindo();
    m:
    carregar_dados(recM,recN,jpM,jpN);
    inicializador();
    cidade(a);
    system("clear");
    horario(b);
    system("clear");
    mostrar_bus();
    escolher_onibus(a,b,recM,recN,jpM,jpN);
    int buy_again=voltar_menu();
    if(buy_again==1)
    {
    atualizar_dados(recM,recN,jpM,jpN);
        goto m;
    }
    else
    {
     atualizar_dados(recM,recN,jpM,jpN);
        exit(0);
    }



    return 0;
}

