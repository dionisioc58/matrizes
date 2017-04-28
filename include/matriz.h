/**
* @file 	matriz.h
* @brief	Arquivo de cabeçalho com a definição das funções
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author   Airton Neto (netoairton@yahoo.com.br)
* @since    28/04/2017
* @date     28/04/2017
*/

#ifndef MATRIZ_H
    #define MATRIZ_H

    #include <iostream>
    using std::cout;
    using std::cerr;
    using std::endl;
    using std::string;
    using std::stringstream;
    
    #include <sstream>
    
    #include <fstream>
    using std::ifstream;

    /**
    * @brief Funcao que multiplica duas matrizes quadradas de dimensao n x n de forma iterativa
    * @param A Matriz de entrada
    * @param B Matriz de entrada
    * @param n Dimensao das matrizes de entrada
    * @return Matriz produto resultante da multiplicacao
    */
    template <typename T>
    T **multiplicaI(T **A, T **B, int n) {
        int **ret = new int*[n];
        for(int i = 0; i < n; i++)
            ret[i] = new int[n];
        return ret;
    }

    /**
    * @brief Funcao que multiplica duas matrizes quadradas de dimensao n x n de forma recursiva
    * @param A Matriz de entrada
    * @param B Matriz de entrada
    * @param n Dimensao das matrizes de entrada
    * @return Matriz produto resultante da multiplicacao
    */
    template <typename T>
    T **multiplicaR(T **A, T **B, int n) {
        return A;
    }

    /**
    * @brief     	Função que carrega um arquivo de dados contendo uma matriz quadrada
    * @param[in] 	nome String com o caminho/nome do arquivo à ler
    * @param[out]   dim Dimensão da matriz
    * @return    	Retorna a matriz lida
    */
    template <typename T>
    T **loadMatriz(string nome, int &dim = 0) {
        //Abrir o arquivo
        ifstream entrada(nome);
        if(!entrada) {
            cout << "Falha de arquivo" << endl;
            return NULL;
        }

        int colunas;
        string lido = "";
        stringstream sa;
        
        //Lê a primeira linha
        entrada.clear();
        entrada.seekg(0);
        getline(entrada, lido, ' '); //Primeira parte

        sa.clear();
        sa << lido;
        sa >> dim;
        getline(entrada, lido);//Parte final da linha
        sa.clear();
        sa << lido;
        sa >> colunas;
        if(dim != colunas) {        //Se valores são diferentes não aceita
            cout << "Só aceita matrizes quadradas" << endl;
            return NULL;
        }

        int **M = new int*[dim];
        
        for(int i = 0; i < dim; i++) {              //Lê o arquivo até o final
            M[i] = new int[dim];                    //Cria as colunas da linha atual
            for(int j = 0; j < dim; j++) {          //Lê todas as colunas da linha atual
                if(j == (dim - 1))                  
                    getline(entrada, lido);         //Se última coluna, a leitura é diferente
                else
                    getline(entrada, lido, ' ');

                //Converte string para o tipo T
                sa.clear();
                sa << lido;
                sa >> M[i][j];
            }
        }

        //Encerra a função devolvendo as informações
        entrada.close();
        return M;
    }

#endif