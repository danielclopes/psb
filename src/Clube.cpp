#include "Clube.h"
Clube::Clube()
{
}

Clube::Clube(string n)
{
    this->nome = n;
}

Clube::~Clube()
{

}
void Clube::ContratarJogador(Jogador *jc)
{
    this->j[this->qntJogadores] = jc;
    this->qntJogadores++;
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

}
