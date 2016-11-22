#ifndef CLUBE_H
#define CLUBE_H
#include "JogadorContrato.h"
#define MAX_JOGADOR 32

class Clube
{
private:
    string nome;
    int qntJogadores;
    Jogador	*j[MAX_JOGADOR];
public:
    Clube();
    Clube(string n);
    ~Clube();
    void ContratarJogador(Jogador *jc);
    void DispensarJogador(Jogador *jc);
    int getQntJogador();
    string getNome();
    void getListaJogador();
};

#endif // CLUBE_H
