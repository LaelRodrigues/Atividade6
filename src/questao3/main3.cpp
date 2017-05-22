/**
 * @file	main3.cpp
 * @brief	Codigo fonte principal do programa para testar as
 *			operacaoes referente classe turma e aluno
 * @author	LaelRodrigues (laelRodrigues7@gmail.com)
 * @since	21/05/2017
 * @date	21/05/2017
 */

#include "turma.h"
#include "aluno.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

/** @brief Funcao principal */
int main() {

	//numero de turmas a ser instanciadas
	int numTurmas; 
	cout << "---------Cadastramento de turmas----------" << endl;
	cout << "Digite o numero de turmas: " << endl;
	cin >> numTurmas;

	if(numTurmas < 1) {
		cout <<	 "Erro: numero de turma e invalido." << endl;
		return 0;
	}

	Turma *turma = new Turma[numTurmas]; 				//turmas instanciadas
	cout << endl << "Operacoes: " << endl;
	cout << "1 - para adicionar um aluno a turma" << endl;
	cout << "2 - para remover um aluno da turma" << endl; 
	cout << "3 - para acessar os dados do aluno da turma" << endl;
	cout << "4 - imprimir os dados da turma" << endl;
	cout << "0 - Sair" << endl;;

	int escolha; 							// Define qual operacao sera realizada
	for(int i = 0; i < numTurmas; i++) {
		
		cout << endl << "Turma " << i+1 << endl;
		do {
			cout << endl <<"Digite sua opcao: ";
			cin >> escolha; 
			// Variaveis ultilizadas para operacoes na turma
			int matricula, totalFaltas; 
			string nome;
			float nota;
			// Ponteiro do tipo Node que aponta para um aluno que se deseja acessar
			Node *acesso;
			int imprimirTurma;                // Define qual a turma que tera os dados impressos  								
			switch(escolha) {
				case 1:
					cout << "Digite o numero da matricula: ";
					cin >> matricula;
					cout << "Digite o nome: ";
					cin.ignore();
					getline(cin, nome);
					cout << "Digite o total de faltas: ";
					cin >> totalFaltas;
					cout << "Digite a nota: ";
					cin >> nota;
					turma[i].inserirOrdenado(matricula, nome, totalFaltas, nota);
					break;
				case 2:
					cout << "Digite o numero da matricula do aluno: ";
					cin >> matricula;
					turma[i].remover(matricula);
					break;
				case 3:
					cout << "Digite o valor da matricula do aluno: ";
					cin >> matricula;
					acesso = turma[i].acessar(matricula);
					if(acesso) {
						cout << "-----------------------------" << endl;
						cout << "matricula: " << acesso -> dados.getMatricula() << endl;
						cout << "Nome: " << acesso-> dados.getNome() << endl;
						cout << "Total de faltas: " << acesso->dados.getTotalFaltas() << endl;
						cout << "Nota: " << acesso->dados.getNota() << endl;
						cout << "-----------------------------------" << endl;
					}
					break;
				case 4:
					for(int j = 0; j < numTurmas; j++) {
						if(numTurmas == 1) {
							cout << endl << "Turma " << j+1 << endl;
							turma[j].imprimir();
							break;
						}
						cout << endl << "Digite o numero da turma que deseja imprimir: " << endl;
						cin >> imprimirTurma;
						if(imprimirTurma < 0 || imprimirTurma > numTurmas){
							cout << "Erro: o numero da turma e invalido" << endl;
							break;
						}
						cout << "Turma " << imprimirTurma << endl;
						turma[imprimirTurma-1].imprimir();
						break;
					}
					break;
				case 0: 
					break;
				default:
					cout << endl <<"Opcao invalida, Digite novamente." << endl;
					break;
				}
		} while(escolha != 0);
	}
	cout << "Programa finalizado." << endl;
	return 0;
}
