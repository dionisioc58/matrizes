#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

#include "matriz.h"
const int dimensao = 2;

int main(int argc, char* argv[]) {
    //Define as duas matrizes
    int **mint1 = new int*[dimensao]; //Matriz de inteiros 1
    int **mint2 = new int*[dimensao]; //Matriz de inteiros 2

    for(int i = 0;i < dimensao; ++i) {
        mint1[i] = new int[dimensao];
        mint2[i] = new int[dimensao];
    }
    
    //Calcula a multiplicação utilizando iteração
    int **mint3 = multiplicaI(mint1, mint2, dimensao);
    
    //Calcula a multiplicação utilizando recursão
    int **mint4 = multiplicaR(mint1, mint2, dimensao);

    //Imprime
    cout << mint3[0][0] << endl;
    cout << mint4[0][0] << endl;

    delete[] mint1;
    delete[] mint2;
    delete[] mint4;
    delete[] mint3;

    return 0;
}