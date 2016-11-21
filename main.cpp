#include <iostream>
#include "Jogador.h"
#include "JogadorLivre.h"
#include "JogadorContrato.h"
#define AUX_MAX 3

using namespace std;

int main()
{
    Jogador *j[AUX_MAX];
    j[0] = new JogadorLivre("Daniel", 15);
    j[1] = new Jogador("Marcelo", 29);
    j[2] = new JogadorContrato("Vilson", 10, "Grêmio");

    for(int i = 0; i < AUX_MAX; i++)
    {
        cout << "Nome: " << j[i]->getNome();
        cout << "\t - Número: " << j[i]->getRegistro() << endl;
        if(i==2)
            cout << "\t\t - Clube: " << j[i]->getClube();
    }
    return 0;
}
