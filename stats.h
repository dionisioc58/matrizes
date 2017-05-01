/**
* @file 	stats.h
* @brief	Arquivo cabeçalho com a definição de estruturas
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @author   Airton Neto (netoairton@yahoo.com.br)
* @since    10/04/2017
* @date     01/05/2017
*/

#ifndef STATS_H
    #define STATS_H

    #include <iostream>
    using std::string;

    /** 
    * @struct Stats
    * @brief Estrutura para armazenar os dados de um município
    */
    struct Stats {
        string codigo;      /**< Código do município */
        string nome;        /**< Nome do município */
        int nascimentos[21];/**< Número de nascimentos em cada ano contabilizado */
    };

    /** 
    * @struct Taxa
    * @brief Estrutura para armazenar a taxa de crescimento
    */
    struct Taxa {
        string codigo; /**< Código do município */
        string nome;   /**< Nome do município */
        float taxa;    /**< Taxa de crescimento */
    };

#endif