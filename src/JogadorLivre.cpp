#include "JogadorLivre.h"

JogadorLivre::JogadorLivre(string n, int num):Jogador()
{
    cadJogador(n,num);
}

JogadorLivre::~JogadorLivre()
{
    //dtor
}

void JogadorLivre::getStatus()
{
    Jogador::getStatus();
}

string JogadorLivre::getClube()
{
    return Jogador::getClube();
}

string JogadorLivre::getNome()
{
    return Jogador::getNome();
}

int JogadorLivre::getRegistro()
{
    return Jogador::getRegistro();
}
