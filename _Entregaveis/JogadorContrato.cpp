#include "JogadorContrato.h"

JogadorContrato::JogadorContrato(string n, int num, string c) : Jogador()
{
    cadJogador(n, num);
    this->clube = c;
}

JogadorContrato::~JogadorContrato()
{
    //dtor
}

void JogadorContrato::getStatus()
{
    Jogador::getStatus();
}

string JogadorContrato::getClube()
{
    return this->clube;
}

string JogadorContrato::getNome()
{
    return Jogador::getNome();
}

