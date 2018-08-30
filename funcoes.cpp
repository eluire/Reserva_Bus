#include"funcoes.h"
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
void escolher_onibus(int a,int b,Onibus &recM,Onibus &recN,Onibus &jpM,Onibus &jpN,string vetorbusrecM[MAXL],string vetorbusrecN[MAXL],string vetorbusjpM[MAXL],string vetorbusjpN[MAXL])
{
    if(a==1&&b==1)
    {
          mostrar_bus(vetorbusrecM);
          reservafinal(recM,vetorbusrecM);
    }
    else if(a==1&&b==2)
    {
        mostrar_bus(vetorbusrecN);
        reservafinal(recN,vetorbusrecN);
    }
    else if(a==2&&b==1)
    {
        mostrar_bus(vetorbusjpM);
        reservafinal(jpM,vetorbusjpM);
    }
    else
    {
          mostrar_bus(vetorbusjpN);
          reservafinal(jpN,vetorbusjpN);
    }
}

void mostrar_bus(string vetorbus[MAXL])
{
    cout<<" ___________ "<<endl;
    cout<<"| "<<vetorbus[0]<<" "<<vetorbus[1]<<"   "<<vetorbus[2]<<" "<<vetorbus[3]<<" |"<<endl;
    cout<<"| "<<vetorbus[4]<<" "<<vetorbus[5]<<"   "<<vetorbus[6]<<" "<<vetorbus[7]<<" |"<<endl;
    cout<<"| "<<vetorbus[8]<<" "<<vetorbus[9]<<"   "<<vetorbus[10]<<" "<<vetorbus[11]<<"|"<<endl;
    cout<<"|"<<vetorbus[12]<<" "<<vetorbus[13]<<"  "<<vetorbus[14]<<" "<<vetorbus[15]<<"|"<<endl;
    cout<<"|"<<vetorbus[16]<<" "<<vetorbus[17]<<"  "<<vetorbus[18]<<" "<<vetorbus[19]<<"|"<<endl;
    cout<<"|"<<vetorbus[20]<<" "<<vetorbus[21]<<"  "<<vetorbus[22]<<" "<<vetorbus[23]<<"|"<<endl;
    cout<<"|"<<vetorbus[24]<<" "<<vetorbus[25]<<"  "<<vetorbus[26]<<" "<<vetorbus[27]<<"|"<<endl;
    cout<<"|"<<vetorbus[28]<<" "<<vetorbus[29]<<"  "<<vetorbus[30]<<" "<<vetorbus[31]<<"|"<<endl;
    cout<<"|"<<vetorbus[32]<<" "<<vetorbus[33]<<"  "<<vetorbus[34]<<" "<<vetorbus[35]<<"|"<<endl;
    cout<<"|"<<vetorbus[36]<<" "<<vetorbus[37]<<"  "<<vetorbus[38]<<" "<<vetorbus[39]<<"|"<<endl;
    cout<<"|"<<vetorbus[40]<<" "<<vetorbus[41]<<"  "<<vetorbus[42]<<" "<<vetorbus[43]<<"|"<<endl;
    cout<<"|"<<vetorbus[44]<<" "<<vetorbus[45]<<"  "<<vetorbus[46]<<" "<<vetorbus[47]<<"|"<<endl;
    cout<<"|____________|"<<endl;
}
void reservafinal(Onibus &bus,string vetorbus[MAXL])
{
h:
    int cont;
    cout<<""<<endl;
    cout<<"Reserve sua poltrona: "<<endl;
    cout<<endl;
    cout<<" Digite o numero da sua poltrona: ";
    cin>>cont;
    verificadordeassento(cont);
    cout<<endl;
    cin.ignore();
    if(bus.ocupantes[cont].assento.ocupado.compare("vazio") == 0)// metodo para comparar strings
    {
        cout<<"digite seu nome: ";
        getline(cin,bus.ocupantes[cont].nome);
        cout<<"digite o seu RG: ";
        getline(cin,bus.ocupantes[cont].rg);// metodo para pegar tudo que o usuario escreveu na linha nao ta funcionandooo
        bus.ocupantes[cont].assento.ocupado="ocupado";
        cout<<endl;
        cout<<"passagem reservada com sucesso!"<<endl;
        vetorbus[cont]='x';
    }
    else
    {
        cout<<"lugar ocupado! tente outra poltrona"<<endl;
        sleep(1);
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
    ifstream file_recifeM;
    file_recifeM.open("recM.txt");
    if (file_recifeM.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {
            getline(file_recifeM,line);
            recM.ocupantes[i].assento.lugar=line;
            getline(file_recifeM,line);
            recM.ocupantes[i].assento.ocupado=line;
            getline(file_recifeM,line);
            recM.ocupantes[i].nome = line;
            getline(file_recifeM,line);
            recM.ocupantes[i].rg = line;
        }
    }
    file_recifeM.close();

    ifstream file_recifeN;
    file_recifeN.open("recN.txt");
    if (file_recifeN.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {
            getline(file_recifeN,line);
            recN.ocupantes[i].assento.lugar=line;
            getline(file_recifeN,line);
            recN.ocupantes[i].assento.ocupado=line;
            getline(file_recifeN,line);
            recN.ocupantes[i].nome = line;
            getline(file_recifeN,line);
            recN.ocupantes[i].rg = line;

        }

    }
    file_recifeN.close();

    ifstream file_joaoPM;
    file_joaoPM.open("jpM.txt");
    if (file_joaoPM.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {
            getline(file_joaoPM,line);
            jpM.ocupantes[i].assento.lugar=line;
            getline(file_joaoPM,line);
            jpM.ocupantes[i].assento.ocupado=line;
            getline(file_joaoPM,line);
            jpM.ocupantes[i].nome = line;
            getline(file_joaoPM,line);
            jpM.ocupantes[i].rg = line;
        }
    }
    file_joaoPM.close();

    ifstream file_joaoPN;
    file_joaoPN.open("jpN.txt");
    if (file_joaoPN .is_open())
    {
        for(int i=0; i<MAXL; i++)
        {
            getline(file_joaoPN,line);
            jpN.ocupantes[i].assento.lugar=line;
            getline(file_joaoPN,line);
            jpN.ocupantes[i].assento.ocupado=line;
            getline(file_joaoPN,line);
            jpN.ocupantes[i].nome = line;
            getline(file_joaoPN,line);
            jpN.ocupantes[i].rg = line;
        }
    }
    file_joaoPN.close();
}

void atualizar_dados(Onibus &recM,Onibus &recN,Onibus &jpM,Onibus &jpN)
{

    ofstream file_recifeM;
    file_recifeM.open("recM.txt", ofstream::out);
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

    ofstream file_recifeN;
    file_recifeN.open("recN.txt", ofstream::out);
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
    ofstream file_joaoPM;
    file_joaoPM.open("jpM.txt", ofstream::out);
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

    ofstream file_joaoPN;
    file_joaoPN.open("jpN.txt", ofstream::out);
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
void atualizar_bus(string vetorbusrecM[MAXL],string vetorbusrecN[MAXL],string vetorbusjpM[MAXL],string vetorbusjpN[MAXL])
{
    ofstream file_busrecM;
    file_busrecM.open("vetorbusrecM.txt", ofstream::out);
    if (file_busrecM.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {
       file_busrecM<<vetorbusrecM[i]<<endl;
        }
    }
    file_busrecM.close();
    ofstream file_busrecN;
    file_busrecN.open("vetorbusrecN.txt", ofstream::out);
    if (file_busrecN.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {

            file_busrecN<<vetorbusrecN[i]<<endl;
        }
    }
    file_busrecN.close();
    ofstream file_busjpM;
    file_busjpM.open("vetorbusjpM.txt", ofstream::out);
    if (file_busjpM.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {

            file_busjpM<<vetorbusjpM[i]<<endl;
        }
    }
    file_busjpM.close();
    ofstream file_busjpN;
    file_busjpN.open("vetorbusjpN.txt", ofstream::out);
    if (file_busjpN.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {

            file_busjpN<<vetorbusjpN[i]<<endl;
        }
    }
    file_busjpN.close();
}

void caregar_bus(string vetorbusrecM[MAXL],string vetorbusrecN[MAXL],string vetorbusjpM[MAXL],string vetorbusjpN[MAXL])
{
    string line;
    ifstream file_busrecM;
    file_busrecM.open("vetorbusrecM.txt");
    if (file_busrecM.is_open())
    {
        for(int i=0; i<MAXL; i++)
        {
            getline(file_busrecM,line);
            vetorbusrecM[i]=line;
        }
        file_busrecM.close();
        ifstream file_busrecN;
        file_busrecN.open("vetorbusrecN.txt");
        if (file_busrecN.is_open())
        {
            for(int i=0; i<MAXL; i++)
            {
                getline(file_busrecN,line);
                vetorbusrecN[i]=line;
            }
        }
        file_busrecN.close();
        ifstream file_busjpM;
        file_busjpM.open("vetorbusjpM.txt");
        if (file_busjpM.is_open())
        {
            for(int i=0; i<MAXL; i++)
            {
                getline(file_busjpM,line);
                vetorbusjpM[i]=line;
            }
        }
        file_busjpM.close();
        ifstream file_busjpN;
        file_busjpN.open("vetorbusjpN.txt");
        if (file_busjpN.is_open())
        {
            for(int i=0; i<MAXL; i++)
            {
                getline(file_busjpN,line);
                vetorbusjpN[i]=line;
            }
        }
        file_busjpN.close();
}
}
