/**
 * @file	turma.h
 * @brief	Definicao de uma estrutura Node e uma classse Turma
 * 			para representar uma lista duplamente encadeada de alunos			
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	20/05/2017
 * @date	21/05/2017
 */


#ifndef TURMA_H
#define TURMA_H

#include "aluno.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

/** 
 * @struct  Node
 * @brief	Tipo estrutura que comte campo dados com as informacoes 
 *			dos Aluno e mais dois campos do tipo ponteiro que apontam
 *			para nos
 */

struct Node {
		
	Aluno dados;				/**< dados 		*/
	Node *proximo = NULL;		/**< Proximo 	*/
	Node *anterior = NULL;		/**< Anterior 	*/
		
};

/**
 * @class 	Turma turma.h
 * @brief 	Classe que representa um lista duplamente encadeada de alunos
 * @details Os atributos da turma sao inicio e fim, que sao ponteiros
 *			do tipo Node que apontam para a cabeca e calda da lista
 * 			respectivamente
 *		
 */
class Turma {

	private:
		Node *inicio; /**< Inicio */
		Node *fim;    /**< fim    */

	public:

		/** @brief Construtor padrao */
		Turma();

		/** @brief Destrutor */
		~Turma();

		/** 
		 * @brief Insere alunos ordenadamente alunos na turma
		 * @param matricula Matricula
 		 * @param nome Nome
 		 * @param totalFaltas Total de faltas
 		 * @param nota Nota
		 */
		void inserirOrdenado(int matricula, string nome, int totalFaltas, float nota);

		/** 
		 * @brief Acessa um aluno da turma caso exista 
		 * @param matricula Matricula
		 */
		Node* acessar(int matricula);

		/**
		 * @brief Remove um aluno da turma caso exista
		 * @param matricula Matricula do aluno a ser removido 
		 */
		void remover(int matricula);

		/** @brief Imprime os dados dos alunos de uma turma */
		void imprimir();

		/** @brief Calcula a media das notas dos alunos da turma */
		float mediaAlunos();

};

#endif