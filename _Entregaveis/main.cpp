/***********************************************
    Programacao para Software Basico - 2016/2
    Trabalho 3 - C++
    Eurico Neto
    Daniel Lopes
************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include "Clube.h"
#include "JogadorLivre.h"
#include "JogadorContrato.h"

using namespace std;

int op = 0;
int op_sub = 0;
int qntJ;
int qntC;
ifstream bd_rd;
ofstream bd_wr;
stringstream ss_data_rd;
string BD = "BD.txt";

void conta_jog_clb()
{
    bd_rd.open(BD);
    string aux = "";
    do
    {
        if(!bd_rd.eof())
        {
            aux = "";
            getline(bd_rd,aux);
            if (!isdigit(aux[0]))
            {
                //if(aux.compare("SIAPERGS") != 0)
                    qntC++;
            }
            else
            {
                if (aux.compare("") != 0)
                    qntJ++;
            }
        }
    }
    while(!bd_rd.eof());
    bd_rd.close();
}

int main()
{
    conta_jog_clb();

    Jogador	*j[qntJ];
    Clube	*c[qntC];

    /** Carrega BD **/

    bd_rd.open(BD);
    string aux = "";
    string nm_j = "";
    string nm_c = "";
    string cd = "";
    string cl_aux = "";
    int cod_j = 0;
    int cl = 0;

    do
    {
        if(!bd_rd.eof())
        {
            aux = "";
            getline(bd_rd,aux);
            if (!isdigit(aux[0]) /*&& aux.compare("SIAPERGS") != 0*/ && aux.compare("") != 0)
            {
                nm_c = aux;

                c[cl] = new Clube(aux);
                cl++;
            }
            /*else if(aux.compare("SIAPERGS") == 0)
            {
                cl_aux = "SIAPERGS";
            }*/

            else //if(aux.compare("") != 0 /*&& aux.compare("SIAPERGS") != 0*/ && cl_aux.compare("SIAPERGS") != 0)
            {
                cd = aux.substr(0,6);
                cod_j = atoi(cd.c_str());

                nm_j = aux.substr(7,aux.length()-1);
                c[cl-1]->ContratarJogador(new JogadorContrato(nm_j, cod_j, nm_c));
            }
            /*else
            {
                if(aux.compare("") != 0)
                {cd = aux.substr(0,6);
                cod_j = atoi(cd.c_str());

                nm_j = aux.substr(7,aux.length()-1);

                c[qntC-1]->ContratarJogador(new JogadorLivre(nm_j,cod_j));
                }
            }*/

        }
    }
    while(!bd_rd.eof());

    bd_rd.close();

    cout << "\n\tSisReJ - Sistema de Registro de Jogadores\n" << endl;

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
        {
            char n[30];

            cout << "Informe o nome do clube com letra  MAIÚSCULA:" << endl;
            cin.ignore();
            cin.getline(n, sizeof(n));

            bool achou = 0;
            int id_cl = 0;
            for(int i = 0; i < qntC -1; i++)
            {
                aux = c[i]->getNome();
                if (aux.compare(n) == 0)
                {
                    achou = 1;
                    id_cl = i;
                }
            }
            if(!achou)
            {
                cout << "Clube não encontrado. Verifique a grafia e tente novamente" << endl;
                break;
            }
            do
            {
                cout << "-----------------------------------------------\n" << endl;
                cout << "Clube selecionado: " << c[id_cl]->getNome() << endl;
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
                case 1:
                    cout << "\tLista de jogares vinculados ao clube" << endl;
                    c[id_cl]->getListaJogador();
                    break;
                case 2:
                    cout << "\tDetalhes do Jogador" << endl;
                    cout << "Informe o nome do Jogador com letra  MAIÚSCULA:" << endl;
                    cin.ignore();
                    cin.getline(n, sizeof(n));
                    c[id_cl]->localizaJogador(n);
                    break;
                case 3:
                    cout << "Quantidade de jogadores registrados pelo "
                         << c[id_cl]->getNome() << ": " << c[id_cl]->getQntJogador() << endl;
                    break;
                case 4:
                    break;
                case 5:
                    break;
                }
            }
            while(op_sub!=6);
            op_sub = 0;
            break;
        }
        case 2:
            cout << "\tListagem de Clubes da FGF" << endl;
            for(int i = 0; i < qntC -1; i++)
            {
                cout << c[i]->getNome() << endl;
            }
            break;
        case 3:
            cout << "\tLista de jogadores sem clube" << endl;
            c[qntC-1]->getListaJogador();
            break;
        }
    }
    while(op!=4);
    op = 0;

    /** Fecha e salva**/
    bd_wr.open(BD);
    if (!bd_wr.is_open()) // Se houver erro, sai do programa
        return 0;

    for(int p = 0; p < qntC; p++)
    {
        bd_wr << c[p]->getNome()  << endl;
        for(int k = 0; k < qntJ; k++)
        {
            bd_wr << j[k]->getRegistro() << " " << j[k]->getNome()  << endl;
        }
        if(bd_wr.fail())
        {
            cout << "Erro na gravação!" << endl;
            exit(1);
        }
    }
    bd_wr.close();
    return 0;
}
