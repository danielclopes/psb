#include "Jogador.h"

Jogador::Jogador()
{
}

Jogador::Jogador(string n, int num)
{
    cadJogador(n, num);
}

Jogador::~Jogador()
{

}

string Jogador::getNome()
{
    return this->nome_apelido;
}

void Jogador::cadJogador(string n, int num)
{
    this->nome_apelido = n;
    this->num_cbf = num;
}

int Jogador::getRegistro()
{
    return this->num_cbf;
}

void Jogador::getStatus()
{

}

string Jogador::getClube()
{
    return "Não implementado";
}
