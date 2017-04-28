/**
* @file 	matriz.h
* @brief	Arquivo de corpo com a definição das funções
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author   Airton Neto (netoairton@yahoo.com.br)
* @since    28/04/2017
* @date     28/04/2017
*/

#include "matriz.h"

/**
* @brief Funcao que multiplica duas matrizes quadradas de dimensao n x n de forma iterativa
* @param A Matriz de entrada
* @param B Matriz de entrada
* @param n Dimensao das matrizes de entrada
* @return Matriz produto resultante da multiplicacao
*/
/*template <>
float **multiplicaI(float **A, float **B, int n) {
    return A;
}*/

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