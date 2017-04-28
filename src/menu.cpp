#include "menu.h"

int showMenu() {
    cout << "(1) Cadastrar uma empresa" << endl;
    cout << "(2) Listar funcionários de uma empresa" << endl;
    cout << "(3) Apagar uma empresa" << endl;
    cout << "(0) Sair" << endl;
    
    int opcao = 0;
    do {
        opcao = recebeInt(": ", 0);
        if((opcao < 0) || (opcao > 3))
            cout << "Valor inválido!" << endl;
    } while ((opcao < 0) || (opcao > 3));
    return opcao;
}