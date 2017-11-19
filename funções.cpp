#include"funções.h"
using namespace std;

void bem_vindo()
{
    cout<<"          ******  ****** **    **          **    ** ** **   ** *****   *****   "<<endl;
    cout<<"          **  *** **     ***  ***          **    ** ** ***  ** **  ** **   **  "<<endl;
    cout<<"          ******  *****  ** ** **   ****   **    ** ** ** * ** **  ** **   **  "<<endl;
    cout<<"          **  *** **     **    **           **  **  ** **  *** **  ** **   **  "<<endl;
    cout<<"          ******  ****** **    **             **    ** **   ** *****   *****   "<<endl;
    cout<<""<<endl;
    cout<<""<<endl;

    cout<<"Digite qualquer tecla para continuar"<<endl;
    getchar();
    system("clear");
}
void verificador(int &var)
{
    while(var!=1 && var!=2)
    {
        cout << "Digite uma opção válida "<<endl;
        cin >> var;
    }
}
void inicializador()
{
    cout<<"Olá! meu nome é Maurício,seu assistente virtual...vamos começar?"<<endl;
    cout<<"o sistema de reservas funciona da seguinte forma: "<<endl;

    cout<<"1º selecione o seu destino:"<<endl;

    cout<<"2º selecione o horário de sua preferência"<<endl;

    cout<<"3º veja a disponibilidade de lugares no onibus e reserve sua poltrona"<<endl;

    cout<<"Pronto!!! seu lugar já está reservado..."<<endl;

    cout<<""<<endl;
    cout<<"vamos lá! "<<endl;
    cout<<"Digite qualquer tecla para continuar"<<endl;
    getchar();
    system("clear");
}
void cidade(int &a)
{
    cout << "Destinos disponiveis: \n";
    cout<<"1-Recife"<<endl;
    cout<<"2-Joao Pessoa"<<endl;
    cout<<"Selecione o seu destino: ";
    cin>>a;
    verificador(a);
}
void horario(int &b)
{
    cout << "Hoararios disponiveis: \n";
    cout<<"1- 7:00"<<endl;
    cout<<"2- 19:00"<<endl;
    cout<<"Selecione seu horário: ";
    cin>>b;
    verificador(b);
}
void escolher_onibus(int a,int b,Onibus recM,Onibus recN,Onibus jpM,Onibus jpN)
{
    if(a==1&&b==1)
    {
        reservafinal(recM);
    }
    else if(a==1&&b==2)
    {
        reservafinal(recN);
    }
    else if(a==2&&b==1)
    {
        reservafinal(jpM);
    }
    else
    {
        reservafinal(jpN);
    }
}

void mostrar_bus()
{
    for(int i=0; i<MAXL; i++)
    {
        if(i<8)
        {
            cout<<"| 0"<<i+1<<" 0"<<i+2<<"  0"<<i+3<<" 0"<<i+4<<" |"<<endl;
            i=i+3;
        }
        else
        {
            cout<<"| "<<i+1<<" "<<i+2<<"  "<<i+3<<" "<<i+4<<" |"<<endl;
            i=i+3;
        }
    }
}
int reservafinal(Onibus bus)
{
    h:
    int cont;
    cout<<""<<endl;
    cout<<"Reserve sua poltrona:"<<endl;
    cout<<endl;
    cout<<" Digite o numero da sua poltrona:";
    cin>>cont;
    verificadordeassento(cont);
    cout<<""<<endl;
    if(bus.ocupantes[cont].assento.ocupado==false){
    cout<<"digite seu nome: ";
    cin>>bus.ocupantes[cont].nome;
    cout<<"digite o seu RG: ";
    cin>>bus.ocupantes[cont].rg;
    bus.ocupantes[cont].assento.ocupado=true;
    cout<<endl;
    cout<<"passagem reservada com sucesso!"<<endl;
    }
    else{
    cout<<"lugar ocupado! tente outra poltrona"<<endl;
    system("clear");
    goto h;
    }
}
int voltar_menu()
{
    int g;
    cout<<" Para reservar outra passagem digite 1"<<endl;
    cout<<" Para sair digite 2"<<endl;
    cin>>g;
    verificador(g);
    if(g==1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void verificadordeassento(int &cont){
while(cont>48){
cout<<"essa poltrona não existe,tente novamente: ";
cin>>cont;

}
}

