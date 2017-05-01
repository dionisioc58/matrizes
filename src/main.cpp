/**
* @file     main.cpp
* @brief 	Arquivo fonte para execução do projeto
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author   Airton Neto (netoairton@yahoo.com.br)
* @since    28/04/2017
* @date     28/04/2017
*/

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::stringstream;
using std::ofstream;
using std::string;

#include <string>
#include <sstream>
#include <chrono>
#include <ctime>

#include "matriz.h"
#include "operacoes.h"

/**
* @brief    	Função que gera um arquivo de configuração gnuplot
* @param[in] 	nome Nome do arquivo de imagem que será gerado posteriormente
* @param[in] 	base Nome do arquivo de dados em que se baseia o gráfico
* @param[in] 	titulo Título que aparecerá no gráfico
* @param[in] 	max_x Maior valor no eixo X
* @param[in] 	max_y Maior valor no eixo Y
* @return    	True se conseguiu gerar o arquivo
*/
bool gerarGnuSet(string nome, string base, string titulo, double max_x, double max_y) {
	ofstream saida("./results/" + nome + ".gnuplot");
	if(!saida) return false;

	saida << "reset" << endl;
	saida << "set key on" << endl;
	saida << "set terminal png size 1280,960 enhanced font 'Helvetica,12'" << endl;
	saida << "set output './results/" + nome + ".png'" << endl;
	saida << "set title '" + titulo + "'" << endl;
	saida << "set grid" << endl;
	saida << "set xrange[0:";
	saida << max_x;
	saida << "]" << endl;
	saida << "set xtics ";
	saida << (int)(max_x/10);
	saida << endl;
    saida << "set ytics ";
    saida << (float)max_y/20;
    saida << endl;
	saida << "set xlabel 'Tamanho da matriz'" << endl;
	saida << "set ylabel 'Tempo gasto (ms)'" << endl;
	saida << "set xtic rotate by -90 scale 0" << endl;
	saida << "set yrange[0:";
	saida << (max_y);
	saida << "]" << endl;
	saida << "plot './results/" << base << "' using 1:4 title 'Tempo médio' lw 2 with lines" << endl;
	saida.close();

	//Executar o gnuplot e gerar o arquivo de imagem
	//string comando = "gnuplot -e '' ./gnuplot/" + nome + ".gnuplot";
	//system(comando.c_str());

	return true;
}

/**
* @brief        Função principal do programa
* @param[in]	argc	Quantidade de argumentos
* @param[in]    *argv[]	Argumentos
* @return		Retorno
*/
int main(int argc, char* argv[]) {
    //Testa argumentos
    if(argc < 2) {
        cerr << "Argumentos inválidos!" << endl;
        return 1;
    }

    double eI[20]; //Estatísticas para as iterações 
    double eR[20]; //Estatísticas para as recursões
    
    //Criar o arquivo de estatísticas de iterações
    ofstream statsite("./results/stats-ite.dat");
    if(!statsite) {
        cout << "Falha ao gravar stats-ite.dat" << endl;
        return 2;
    }
    statsite.close();
    
    //Criar o arquivo de estatísticas de recursões
    ofstream statsrec("./results/stats-rec.dat");
    if(!statsrec) {
        cout << "Falha ao gravar stats-rec.dat" << endl;
        return 2;
    }
    statsrec.close();
        
    
    int dimensao = 0;
        
    for(int a = 1; a < argc; a++) {
        //Prepara nomes das matrizes A e B
        stringstream ss;
        string nome, nomea, nomeb, nomec;
        
        ss.flush();
        ss.clear();
        ss << argv[a] << "x" << argv[a] << ".txt";
        ss >> nome;

        ss.clear();
        ss << "./data/A" << nome;
        ss >> nomea;
        
        ss.clear();
        ss << "./data/B" << nome;
        ss >> nomeb;
        
        //Carrega as matrizes A e B
        cout<< "Abrindo arquivo... " << nomea << endl;
        int **matriz1 = loadMatriz<int>(nomea, dimensao);
        cout<< "Abrindo arquivo... " << nomeb << endl;
        int **matriz2 = loadMatriz<int>(nomeb,  dimensao);

        //Se não carregou, sair
        if((matriz1 == NULL) || (matriz2 == NULL)) {
            cout << "Problemas na matriz: " << argv[a] << endl;
            for(int q = 0; q < dimensao; q++) {
                delete[] matriz1[q];
                delete[] matriz2[q];
            }
            delete[] matriz1;
            delete[] matriz2;
            return 3;
        }
        
        //Calcula a multiplicação utilizando iteração 20 vezes e mede o tempo
        for(int t = 0; t < 20; t++) {
            auto tIini = std::chrono::high_resolution_clock::now();                     //Registra o tempo inicial
            int **matrizci = multiplicaMatrizesI(matriz1, matriz2, dimensao);           //Executa a multiplicação
            auto tIfim = std::chrono::high_resolution_clock::now();                     //Registra o tempo final
            auto dI = tIfim - tIini;                                                    //Calcula a duração

            eI[t] = std::chrono::duration <double, std::milli> (dI).count();            //Salva no conjunto
            
            for(int q = 0; q < dimensao; q++)
                delete[] matrizci[q];
            delete[] matrizci;
        }
        //Inserir no arquivo de estatísticas de iterações
        ofstream statsite;
        statsite.open("./results/stats-ite.dat", std::ios_base::app);
        if(!statsite) {
            cout << "Falha ao gravar stats-ite.dat" << endl;
            return 2;
        }
        statsite << dimensao << "x" << dimensao << " " << max(eI, 20) << " " << min(eI, 20) << " " << avg(eI, 20) << " " << dev(eI, 20) << endl;
        statsite.close();
        
        //Calcula a multiplicação utilizando recursão 20 vezes e mede o tempo
        for(int t = 0; t < 20; t++) {
            auto tRini = std::chrono::steady_clock::now();                              //Registra o tempo inicial
            int **matrizcr = multiplicaMatrizesR(matriz1, matriz2, dimensao);           //Executa a multiplicação
            auto tRfim = std::chrono::steady_clock::now();                              //Registra o tempo final
            auto dR = tRfim - tRini;                                                    //Calcula a duração
            
            eR[t] = std::chrono::duration <double, std::milli> (dR).count();            //Salva no conjunto

            if(t == 19) {
                //Salva matriz c obtida pela recursão
                stringstream ss2;
                ss2 << "./results/C";
                ss2 << nome;
                ss2 >> nomec;
                ofstream matrizc(nomec);                                    //Abre o arquivo para salvar
                if(!matrizc)
                    cout << "Impossível gravar: " << nomec << endl;
                else {
                    matrizc << dimensao << " " << dimensao << endl;         //Primeira linha contém as dimensões da matriz
                    for(int k = 0; k < dimensao; k++) {                     //Percorre todas as linhas
                        for(int l = 0; l < (dimensao - 1); l++)             //Percorre todas as colunas, menos a última
                            matrizc << matrizcr[k][l] << " ";               
                        matrizc << matrizcr[k][dimensao - 1] << endl;                  //Salva a última coluna e encerra a linha
                    }
                    matrizc.close();                                        //Fecha o arquivo
                }
            }
            for(int q = 0; q < dimensao; q++)
                delete[] matrizcr[q];
            delete[] matrizcr;
        }
        //Inserir no arquivo de estatísticas de recursões
        ofstream statsrec;
        statsrec.open("./results/stats-rec.dat", std::ios_base::app);
        if(!statsrec) {
            cout << "Falha ao gravar stats-rec.dat" << endl;
            return 2;
        }
        statsrec << dimensao << "x" << dimensao << " " << max(eR, 20) << " " << min(eR, 20) << " " << avg(eR, 20) << " " << dev(eR, 20) << endl;
        statsrec.close();

        //Libera a memória
        for(int q = 0; q < dimensao; q++) {
            delete[] matriz1[q];
            delete[] matriz2[q];
        }
        delete[] matriz1;
        delete[] matriz2;
    }

    //Gerar gráficos
    gerarGnuSet("grafico-ite", "stats-ite.dat", "Multiplicação de matrizes (iteração)", dimensao, max(eI, 20));
    gerarGnuSet("grafico-rec", "stats-rec.dat", "Multiplicação de matrizes (recursão)", dimensao, max(eR, 20));
    
    return 0;
}   