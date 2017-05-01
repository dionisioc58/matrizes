/**
* @file 	operacoes.cpp
* @brief	Arquivo cabeçalho com a definição de funções para operações de estatísticas
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author   Airton Neto (netoairton@yahoo.com.br)
* @since    10/04/2017
* @date     01/05/2017
*/

#include "operacoes.h"

/**
* @brief    	Função que calcula os maiores valores de cada elemento de um vetor stats
* @param[in] 	*dados Vetor com os valores
* @param[in]    elementos Quantidade de elementos no vetor
* @return    	Maior valor
*/
double max(double *dados, int elementos) {
    double retorno = dados[0];
    for(int i = 1; i < (elementos - 1); i++)
        if(dados[i] > retorno)
            retorno = dados[i];
    
    return retorno;
}

/**
* @brief    	Função que calcula os menores valores de cada elemento de um vetor stats
* @param[in] 	*dados Vetor com os valores
* @param[in]    elementos Quantidade de elementos no vetor
* @return    	Menor valor
*/
double min(double *dados, int elementos) {
    double retorno = dados[0];
    for(int i = 1; i < (elementos - 1); i++)
        if(dados[i] < retorno)
            retorno = dados[i];
    
    return retorno;
}

/**
* @brief    	Função que calcula os valores médios de cada elemento de um vetor stats
* @param[in] 	*dados Vetor com os valores
* @param[in]    elementos Quantidade de elementos no vetor
* @return    	Média
*/
float avg(double *dados, int elementos) {
    float retorno = dados[0];
    for(int i = 1; i < (elementos - 1); i++)
        retorno += dados[i];
    
    return retorno / elementos;
}

/**
* @brief    	Função que calcula os valores de desvio padrão  de cada ano
* @param[in] 	*dados Vetor com os valores
* @param[in]    elementos Quantidade de elementos no vetor
* @return    	Desvio padrão
*/
float dev(double *dados, int elementos) {
    float retorno = 0;
    for(int i = 0; i < (elementos -1); i++)
        retorno +=pow((dados[i] - avg(dados, elementos)), 2);
    retorno = sqrt(retorno * (((float)1 / (elementos - 1))));
    
    return retorno;
}