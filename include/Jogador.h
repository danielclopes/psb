#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
#include <iostream>

using namespace std;

class Jogador
{
    private:
        string nome_apelido;
        int num_cbf;
    public:
        Jogador();
        Jogador(string n, int num);
        ~Jogador();
    void cadJogador(string n, int num);
        virtual void getStatus();
        int getVinculo();
        virtual string getClube();
        virtual string getNome();
        virtual int getRegistro();
};

#endif // JOGADOR_H
