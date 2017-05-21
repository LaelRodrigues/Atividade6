/**
 * @file	main.cpp
 * @brief	Codigo fonte principal do programa para testar as
 *			operacaoes referente a lista duplamente encadeada
 * @author	Everton Cavalcante (everton@dimap.ufrn.br)
 * @since	25/04/2017
 * @date	25/04/2017
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "lista.h"

/** @brief Funcao principal */
int main(){
	
	Lista <int> lista; //instanciando a lista

	cout << "-----Lista duplamente encadeada-----" << endl;
 	cout << endl << "Operacoes: " << endl;
 	cout << "1 - Adicionar elemento" << endl;
 	cout << "2 - Remover elemento" << endl;
 	cout << "3 - acessar elemento" << endl;
 	cout << "4 - imprimir a lista" << endl;
 	cout << "0 - Sair" << endl;

 	int escolha;		//define qual operacao sera realizada
	do {
		cout << endl << "Digite sua opcao: " << endl;
		cin >> escolha;
		int elemento; 		//varivel utilizado como para insercao, acesso, remocao
		Node<int> *acesso;   //ponteiro do tipo Node que aponta para da posicao acessada
		switch(escolha) {
			case 1:
				cout << "Digite o elemento a ser Adicionado: ";
				cin >> elemento;
				lista.inserirOrdenado(elemento);
				break;
			case 2:
				cout << "Digite o elemento a ser removido: " ;
				cin >> elemento;
				lista.remover(elemento);
				break;
			case 3:
				cout << "Digite o valor do elemento a ser acessado: ";
				cin >> elemento;
				acesso = lista.acessar(elemento);
				if(acesso) {
					cout << "o valor " << elemento << "pertence a lista ";
				}
				break;
			case 4:	
				lista.imprimir();
				break;
			case 0:
				cout << "Programa finalizado" << endl;
				break;
			default:
				cout << "Valor invalido, Digite novamente." << endl;
				break;
		}

	} while(escolha != 0); 

	return 0;
}