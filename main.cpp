#include"funcoes.h"
#include <string>
using namespace std;


int main()
{
    int a,b;
    //declaração dos arrays de disponibilidade de poltronas
    string vetorbusrecM[MAXL];
    string vetorbusrecN[MAXL];
    string vetorbusjpM[MAXL];
    string vetorbusjpN[MAXL];
    // declaração das estruturas
    Onibus recM;
    Onibus recN;
    Onibus jpM;
    Onibus jpN;
    bem_vindo();
m:
    caregar_bus(vetorbusrecM,vetorbusrecN,vetorbusjpM,vetorbusjpN);
    carregar_dados(recM,recN,jpM,jpN);
    inicializador();
    cidade(a);
    system("clear");
    horario(b);
    system("clear");
    escolher_onibus(a,b,recM,recN,jpM,jpN,vetorbusrecM,vetorbusrecN,vetorbusjpM,vetorbusjpN);
    atualizar_dados(recM,recN,jpM,jpN);
    atualizar_bus(vetorbusrecM,vetorbusrecN,vetorbusjpM,vetorbusjpN);
    int buy_again=voltar_menu();
    if(buy_again==1)
    {
        goto m;
    }
    else
    {
        return 0;
    }
}
