/***********************************************
    Programacao para Software Basico - 2016/2
    Trabalho 3 - C++
    Eurico Neto
    Daniel Lopes
************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Clube.h"
#include "JogadorLivre.h"
#include "JogadorContrato.h"
#define AUX_MAX 3

using namespace std;

int op = 0;
int op_sub = 0;
int qntJ;
int qntC;
ifstream bd_rd;
ofstream bd_wr;
stringstream ss_data_rd;

void conta_jog_clb()
{
    bd_rd.open("BD.txt");
    string aux = "";
    do
    {
        if(!bd_rd.eof())
        {
            aux = "";
            getline(bd_rd,aux);
            if (!isdigit(aux[0]))
            {
                if(aux.compare("SIAPERGS") != 0)
                    qntC++;
            }
            else
            {
                qntJ++;
            }

        }
    }
    while(!bd_rd.eof());
    bd_rd.close();
}

/*void carrega_bd()
{
    bd_rd.open("BD.txt");
    string aux = "";
    string nm_j = "";
    string nm_c = "";
    int cod = 0;
    int cl = 0;
    int jg = 0;
    do
    {
        if(!bd_rd.eof())
        {
            aux = "";
            getline(bd_rd,aux);
            if (!isdigit(aux[0]))
            {
                nm_c = aux;
                j[cl] = new Clube(nm_c);
            }
            else
            {
                qntJ++;
            }

        }
    }
    while(!bd_rd.eof());
    bd_rd.close();
}*/

void submenu()
{
    do
    {
        cout << "-----------------------------------------------\n" << endl;
        cout << "1 - Lista de jogadores" << endl;
        cout << "2 - Detalhes do jogador" << endl;
        cout << "3 - Quantidade de jogadores" << endl;
        cout << "4 - Contratar jogador" << endl;
        cout << "5 - Dispensar jogador" << endl;
        cout << "6 - Volta ao menu principal\n" << endl;
        cout << "-----------------------------------------------" << endl;
        cin >> op_sub;

        switch (op_sub)
        {
            /*case 1:
              cout << "Digite o Nome, Matricula e o Saldo no seguinte formato (n m s):";
                cin >> n >> m >> s;
                clube[qntSocio].setNome(n);
              clube[qntSocio].setMatricula(m);
              clube[qntSocio].setSaldo(s);
              qntSocio++;
              break;
            case 2:
              cout << "Digite a matricula voce quer remover:";
                cin >> m;
                rem = -1;
              for(i=0;i<qntSocio;i++){
                if (m == clube[i].getMatricula())
                        rem = i;
              }
                if(rem != -1){
                    for(i=rem;i<(qntSocio-1);i++){
                        clube[i].setNome(clube[i+1].getNome());
                      clube[i].setMatricula(clube[i+1].getMatricula());
                      clube[i].setSaldo(clube[i+1].getSaldo());
                    }
                    qntSocio--;
                }
              break;
            case 3:
              for(i=0;i<qntSocio;i++)
                    clube[i].imprime();
              break;*/
        }
    }
    while(op_sub!=6);
    op_sub = 0;
}

/*void menu()
{
    do
    {
        cout << "-----------------------------------------------\n" << endl;
        cout << "1 - Escolha o clube" << endl;
        cout << "2 - Mostrar clubes" << endl;
        cout << "3 - Mostrar jogadores sem clube" << endl;
        cout << "4 - Sair do programa\n" << endl;
        cout << "-----------------------------------------------" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            submenu();
            break;
        case 2:
            //cout << "Mostrar lista dos clubes não implementado\n" << endl;
            mostra_clube();
            break;
        case 3:
            cout << "Mostrar lista de jogadores sem clube não implementado" << endl;
            break;
        }
    }
    while(op!=4);
    op = 0;
}*/

int main()
{
    conta_jog_clb();

    Jogador	*j[qntJ];
    Clube	*c[qntC];


    /**
        Carrega BD
    **/

    bd_rd.open("BD.txt");
    string aux = "";
    string nm_j = "";
    string nm_c = "";
    int cod_j = 0;
    int cl = 0;
    int jg = 0;
    do
    {
        if(!bd_rd.eof())
        {
            aux = "";
            getline(bd_rd,aux);
            if (!isdigit(aux[0]) && aux.compare("SIAPERGS") != 0)
            {
                nm_c = aux;
                c[cl] = new Clube(aux);
                //cout << c[cl]->getNome() << endl;
                cl++;
            }
            else
            {
                //getline(bd_rd,aux);
                bd_rd >> cod_j;
                bd_rd >> nm_j;

                c[cl-1]->ContratarJogador(new JogadorContrato(nm_j, cod_j, nm_c));
                cout << "Clube: " << c[cl-1]->getNome() << "\tQtd Jog: " << c[cl-1]->getQntJogador() << endl;
                cout << cod_j << " - " << nm_j << endl;
                //getline(bd_rd,aux);


            }
        }
    }
    while(!bd_rd.eof());
    bd_rd.close();

    cout << "\tSisReJ - Sistema de Registro de Jogadores\n" << endl;

//menu();
    do
    {
        cout << "-----------------------------------------------\n" << endl;
        cout << "1 - Escolha o clube" << endl;
        cout << "2 - Mostrar clubes" << endl;
        cout << "3 - Mostrar jogadores sem clube" << endl;
        cout << "4 - Sair do programa\n" << endl;
        cout << "-----------------------------------------------" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            submenu();
            break;
        case 2:
            cout << "\tListagem de Clubes da FGF" << endl;
            for(int i = 0; i < qntC; i++)
            {
                cout << c[i]->getNome() << endl;
            }
            break;
        case 3:
            cout << "Mostrar lista de jogadores sem clube não implementado" << endl;
            break;
        }
    }
    while(op!=4);
    op = 0;

    cout << "Clubes: \t" << qntC << endl;
    cout << "Atletas:\t" << qntJ << endl;
    cout << "\n";

    cout << "Programa finalizado!" << endl;
    return 0;
}
