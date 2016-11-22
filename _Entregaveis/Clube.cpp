#include "Clube.h"
Clube::Clube()
{
        this->qntJogadores = 0;
}

Clube::Clube(string n)
{
    this->nome = n;
    this->qntJogadores = 0;
}

Clube::~Clube()
{

}
void Clube::ContratarJogador(Jogador *jc)
{
    if(qntJogadores < MAX_JOGADOR)
    {
        this->j[this->qntJogadores] = jc;
        this->qntJogadores++;
    }
}
void Clube::DispensarJogador(Jogador *jc)
{

}
int Clube::getQntJogador()
{
    return this->qntJogadores;
}
string Clube::getNome()
{
    return this->nome;
}
void Clube::getListaJogador()
{
    if(qntJogadores==0)
        cout << "\tNenhum jogador encontrado" << endl;
    else
    {
        for(int i = 0; i < qntJogadores; i++)
        {
            cout << j[i]->getRegistro() << " " << j[i]->getNome() << endl;
        }
    }
}

void Clube::localizaJogador(string n)
{
    bool achou = 0;
    int jg = 0;
    string aux = "";
    for(int i = 0; i < qntJogadores; i++)
    {
        aux = j[i]->getNome(); //j[i]->getNome();
        if (aux.compare(n) == 0)
        {
            achou = 1;
            jg = i;
        }
    }
    if(!achou)
    {
        cout << "Jogador não encontrado. Verifique a grafia e tente novamente" << endl;
        exit;
    }
    cout << "Detalhes do Jogador:" << endl;
    cout << "\tNome: " << j[jg]->getNome()
         << "\n\tRegistro na CBF: " << j[jg]->getRegistro()
         << "\n\tClube: " << this->nome << endl;
}
