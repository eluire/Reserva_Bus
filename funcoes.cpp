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
    char vetorbus[MAXL];
    for(int i=0; i<MAXL; i++)
    {
        vetorbus[i]=i;
    }
    for(int i=0; i<MAXL; i++)
    {
        if(i<8)
        {
            cout<<"| 0"<<vetorbus[i]+1<<" 0"<<vetorbus[i]+2<<"  0"<<vetorbus[i]+3<<" 0"<<vetorbus[i]+4<<" |"<<endl;
            i=i+3;
        }
        else
        {
            cout<<"| "<<vetorbus[i]+1<<" "<<vetorbus[i]+2<<"  "<<vetorbus[i]+3<<" "<<vetorbus[i]+4<<" |"<<endl;
            i=i+3;
        }
    }

}
void reservafinal(Onibus &bus)// nao ta funcionando o get line para o nome
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
    if(bus.ocupantes[cont-1].assento.ocupado.compare("vazio")==0)// metodo para comparar strings
    {
        cout<<"digite seu nome: ";
        cin>>bus.ocupantes[cont-1].nome;
        //getline(cin,bus.ocupantes[cont-1].nome); naoooo ta funcionandoooo
        cout<<"digite o seu RG: ";
        cin>>bus.ocupantes[cont-1].rg;
        //getline(cin,bus.ocupantes[cont-1].rg);// metodo para pegar tudo que o usuario escreveu na linha nao ta funcionandooo
        bus.ocupantes[cont-1].assento.ocupado="ocupado";
        cout<<endl;
        cout<<"passagem reservada com sucesso!"<<endl;

    }
    else
    {
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

void verificadordeassento(int &cont)
{
    while(cont>48)
    {
        cout<<"essa poltrona não existe,tente novamente: ";
        cin>>cont;

    }
}

void carregar_dados(Onibus &recM,Onibus &recN,Onibus &jpM,Onibus &jpN)
{
    string line;
    ifstream file_recifeM ("recM.txt");
    if (file_recifeM.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {
            getline (file_recifeM,line);
            recM.ocupantes[i].assento.lugar=line;
            getline (file_recifeM,line);
            recM.ocupantes[i].assento.ocupado=line;
            getline (file_recifeM,line);
            recM.ocupantes[i].nome = line;
            getline (file_recifeM,line);
            recM.ocupantes[i].rg = line;
        }
    }
    file_recifeM.close();

    ifstream file_recifeN ("recN.txt");
    if (file_recifeN.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {
            getline (file_recifeN,line);
            recN.ocupantes[i].assento.lugar=line;
            getline (file_recifeN,line);
            recN.ocupantes[i].assento.ocupado=line;
            getline (file_recifeN,line);
            recN.ocupantes[i].nome = line;
            getline (file_recifeN,line);
            recN.ocupantes[i].rg = line;

        }

    }
    file_recifeN .close();

    ifstream file_joaoPM ("jpM.txt");
    if (file_joaoPM.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {
            getline (file_joaoPM,line);
            jpM.ocupantes[i].assento.lugar=line;
            getline (file_joaoPM,line);
            jpM.ocupantes[i].assento.ocupado=line;
            getline (file_joaoPM,line);
            jpM.ocupantes[i].nome = line;
            getline (file_joaoPM,line);
            jpM.ocupantes[i].rg = line;
        }
    }
    file_joaoPM.close();

    ifstream file_joaoPN ("jpN.txt");
    if (file_joaoPN .is_open())
    {
        for(int i=0; i<MAXL; i++)
        {
            getline (file_joaoPN,line);
            jpN.ocupantes[i].assento.lugar=line;
            getline (file_joaoPN,line);
            jpN.ocupantes[i].assento.ocupado=line;
            getline (file_joaoPN,line);
            jpN.ocupantes[i].nome = line;
            getline (file_joaoPN,line);
            jpN.ocupantes[i].rg = line;
        }
    }
    file_joaoPN .close();
}

void atualizar_dados(Onibus recM,Onibus recN,Onibus jpM,Onibus jpN) //
{
    ofstream file_recifeM ("recM.txt");
    if (file_recifeM.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {

            file_recifeM<<recM.ocupantes[i].assento.lugar<< endl;
            file_recifeM<<recM.ocupantes[i].assento.ocupado<< endl;
            file_recifeM<<recM.ocupantes[i].nome<< endl;
            file_recifeM<<recM.ocupantes[i].rg<< endl;
        }
    }
    file_recifeM.close();

    ofstream file_recifeN ("recN.txt");
    if (file_recifeN.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {

            file_recifeN<<recN.ocupantes[i].assento.lugar<< endl;
            file_recifeN<<recN.ocupantes[i].assento.ocupado<< endl;
            file_recifeN<<recN.ocupantes[i].nome<< endl;
            file_recifeN<<recN.ocupantes[i].rg<< endl;
        }
    }
    file_recifeN.close();
    ofstream file_joaoPM ("jpM.txt");
    if (file_joaoPM.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {

            file_joaoPM<<jpM.ocupantes[i].assento.lugar<<endl;
            file_joaoPM<<jpM.ocupantes[i].assento.ocupado<< endl;
            file_joaoPM<<jpM.ocupantes[i].nome<< endl;
            file_joaoPM<<jpM.ocupantes[i].rg<< endl;
        }
    }
    file_joaoPM.close();

    ofstream file_joaoPN ("jpN.txt");
    if (file_joaoPN.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {

            file_joaoPN<<jpN.ocupantes[i].assento.lugar<<endl;
            file_joaoPN<<jpN.ocupantes[i].assento.ocupado<<endl;
            file_joaoPN<<jpN.ocupantes[i].nome<<endl;
            file_joaoPN<<jpN.ocupantes[i].rg<<endl;
        }
    }

    file_joaoPN.close();
}
