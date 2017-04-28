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

    int **matriz1;
    int **matriz2;
    int **matrizci;
    int **matrizcr;
    int dimensao = 0;
    stringstream ss;
        
    for(int a = 1; a < argc; a++) {
        //Prepara nomes das matrizes A e B
        string nome1, nome2;

        ss.clear();
        ss << "./data/A" << argv[a] << "x" << argv[a] << ".txt";
        ss >> nome1;
        
        ss.clear();
        ss << "./data/B" << argv[a] << "x" << argv[a] << ".txt";
        ss >> nome2;
        
        //Carrega as matrizes A e B
        cout<< "Abrindo arquivo... " << nome1 << endl;
        matriz1 = loadMatriz<int>(nome1, dimensao);
        cout<< "Abrindo arquivo... " << nome2 << endl;
        matriz2 = loadMatriz<int>(nome2,  dimensao);
        
        //Se não carregou, sair
        if((matriz1 == NULL) || (matriz2 == NULL)) {
            delete[] matriz1;
            delete[] matriz2;
            return 2;
        }
        
        //Calcula a multiplicação utilizando iteração
        matrizci = multiplicaI(matriz1, matriz2, dimensao);
        //Calcula a multiplicação utilizando recursão
        matrizcr = multiplicaR(matriz1, matriz2, dimensao);

        //Imprime I
        for(int i = 0; i < dimensao; i++) {
            for(int j = 0; j < dimensao; j++)
                cout << matrizci[i][j] << " ";
            cout << endl;
        }

        //Imprime R
        for(int i = 0; i < dimensao; i++) {
            for(int j = 0; j < dimensao; j++)
                cout << matrizcr[i][j] << " ";
            cout << endl;
        }
    }

    delete[] matriz1;
    delete[] matriz2;
    delete[] matrizci;
    delete[] matrizcr;

    return 0;
}