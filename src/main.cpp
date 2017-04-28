#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include "matriz.h"
#define linhas 2
#define colunas 3

int main(int argc, char* argv[]) {
    //Define as duas matrizes
    int *matriz1 = new int[linhas * colunas];
    int *matriz2 = new int[linhas * colunas];
    
    //Calcula a multiplicação utilizando iteração
    int *matriz3 = multiplicaMatrizesI(matriz1, (linhas * colunas), matriz2, (linhas * colunas));

    //Calcula a multiplicação utilizando recursão
    int *matriz4 = multiplicaMatrizesR(matriz1, (linhas * colunas), matriz2, (linhas * colunas));

    //Imprime
    cout << matriz3[0] << endl;

    return 0;
}