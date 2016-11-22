#ifndef JOGADORCONTRATO_H
#define JOGADORCONTRATO_H
#include "Jogador.h"

class JogadorContrato : public Jogador
{
private:
    string clube;
public:
    JogadorContrato(string n, int num, string c);
    ~JogadorContrato();
    void getStatus();
    int getVinculo();
    string getClube();
    string getNome();
};

#endif // JOGADORCONTRATO_H
