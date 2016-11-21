#ifndef JOGADORLIVRE_H
#define JOGADORLIVRE_H
#include "Jogador.h"

class JogadorLivre : public Jogador
{
public:
    JogadorLivre(string n, int num);
    ~JogadorLivre();
private:
    void getStatus();
    string getClube();
    string getNome();
    int getRegistro();
};

#endif // JOGADORLIVRE_H
