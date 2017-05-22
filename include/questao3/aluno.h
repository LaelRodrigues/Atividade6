/**
 * @file	aluno.h
 * @brief	Definicao da classe Aluno para representar os 
 * 			dados de uma aluno
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	20/04/2017
 * @date	21/04/2017
 */


#ifndef ALUNOS_H
#define ALUNOS_H

#include <string>
using std::string;

/** 
 * @class 	Aluno aluno.h
 * @brief 	Classe que representa os dados de um aluno
 * @details Os atributos de um Aluno sao: matricula, nome, 
 *			totalFaltas e nota
 */
class Aluno {
	private:
		int matricula; 		/**< Matricula */
		string nome;		/**< Nome */
		int totalFaltas;	/**< Total de faltas */
		float nota;			/**< Nota */

	public:
		
		/** @brief Construtor padrao */
		Aluno();

		/** @brief Destrutor */
		~Aluno();

		/** @brief Retorna a matricula */
		int getMatricula();

		/** @brief Modifica a matricula */
		void setMatricula(int m);

		/** @brief Retorna o nome*/
		string getNome();

		/** @brief Modifica o nome */
		void setNome(string n);

		/** @brief Retorna o total de faltas */
		int getTotalFaltas();

		/** @brief Modifica o total de faltas */
		void setTotalFaltas(int tf);

		/** @brief Retorna a nota */
		float getNota();

		/** @brief modifica a nota */
		void setNota(float nt);

		/** @brief Sobrecarga do operador de igualdade */
		bool operator== (const Aluno &novoAluno);

};

#endif