/**
* @file 	funcoes.cpp
* @brief	Arquivo de corpo com a definição de funções auxiliares para a entrada de dados
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    11/03/2017
* @date     02/04/2017
*/

#include "funcoes.h"

/**
* @brief        Função que coleta um valor float maior que zero pela entrada validando-o
* @param[in]	msg String com a mensagem à exibir
* @param[in]	min Int com o valor mínimo aceitável
* @return       Float capturado
*/
float recebeFloat(string msg, int min) {
	float valor = -1;
	while(valor < min) {
		cout << msg;
		cin >> valor;
		if (cin.fail() || cin.get() != '\n') {
			cout << "Valor inválido!" << endl;
			cin.clear(); /**< limpar o bit de falha do cin */
			while (cin.get() != '\n') ; /** < receber todos dados digitados até o fim da linha para esvaziar */
			valor = -1;
		} else if(valor < min)
				cout << "Valor inválido!" << endl;
	}
	return valor;
}

/**
* @brief        Função que coleta um valor inteiro maior ou igual à zero pela entrada validando-o
* @param[in]    msg String com a mensagem à exibir
* @param[in]	min Int com o valor mínimo aceitável
* @return       Int capturado
*/
int recebeInt(string msg, int min) {
	int valor = -1;
	while(valor < min) {
		cout << msg;
		cin >> valor;
		if (cin.fail() || cin.get() != '\n') {
			cout << "Valor inválido!" << endl;
			cin.clear(); /**< impar o bit de falha do cin */
			while (cin.get() != '\n') ; /**< receber todos dados digitados até o fim da linha para esvaziar */
			valor = -1;
		} else if(valor < min)
				cout << "Valor inválido!" << endl;
	}
	return valor;
}