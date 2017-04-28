/**
* @file     main.cpp
* @brief 	Arquivo fonte para execução do projeto
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author   Airton Neto (netoairton@yahoo.com.br)
* @since    28/04/2017
* @date     28/04/2017
*/

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::stringstream;

#include <sstream>

#include "matriz.h"

int main(int argc, char* argv[]) {
    //Testa argumentos
    if(argc < 2) {
        cerr << "Argumentos inválidos!" << endl;
        return 1;
    }

    //Testa arquivo do argumento
    cout<< "Abrindo arquivo... ";
    string msg = "";
    int dimensao = 0;
    
    stringstream ss;
    string nome1, nome2;
    ss << "./data/A" << argv[1] << "x" << argv[1] << ".txt";
    ss >> nome1;
    ss.clear();
    ss << "./data/B" << argv[1] << "x" << argv[1] << ".txt";
    ss >> nome2;
    int **matriz1 = loadMatriz<int>(nome1, dimensao);
    int **matriz2 = loadMatriz<int>(nome2,  dimensao);
    
    if((matriz1 != NULL) || (matriz2 != NULL)) {
        delete[] matriz1;
        delete[] matriz2;
        return 2;
    }

    //Calcula a multiplicação utilizando iteração
    //int **mint3 = multiplicaI(mint1, mint2, dimensao);
    
    //Calcula a multiplicação utilizando recursão
    //int **mint4 = multiplicaR(mint1, mint2, dimensao);

    //Imprime
    for(int i = 0; i < dimensao; i++) {
        for(int j = 0; j < dimensao; j++)
            cout << matriz1[i][j] << " ";
        cout << endl;
    }

    delete[] matriz1;

    return 0;
}