#include"funções.h"
using namespace std;

int main()
{
    int a,b; //declaração de structs
    Onibus recM;
    Onibus recN;
    Onibus jpM;
    Onibus jpN;
    bem_vindo();
    m:
    inicializador();
    cidade(a);
    system("clear");
    horario(b);
    system("clear");
    mostrar_bus();
    escolher_onibus(a,b,recM,recN,jpM,jpN);
    FILE*arquivo;
    int buy_again=voltar_menu();
    if(buy_again==1)
    {
        goto m;
    }
    else
    {
        exit(0);
    }



    return 0;
}














