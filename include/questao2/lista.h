/**
 * @file	lista.h
 * @brief	Definicao de uma estrutura Node e uma classe Lista 
 * 			para representar uma lista duplamente encadeada generica			
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	16/05/2017
 * @date	21/05/2017
 */

#ifndef LISTA_H
#define LISTA_H


#include <iostream>

using std::cout;
using std::endl;

/** 
 * @struct  Node
 * @brief	Tipo estrutura que  comtem um campo dado generico
 *			e mais dois campos do tipo ponteiros genericos proximo e anterior 
 *			que apontam para nos 
 */
template <typename T>
struct Node {
		
	T dado;						/**< Dado */
	Node<T> *proximo = NULL;	/**< Proximo */
	Node<T> *anterior = NULL;	/**< Anterior */
		
};

/**
 * @class 	Lista lista.h
 * @brief 	Classe que representa um lista duplamente encadeada
 * @details Os atributos da lista sao inicio e fim, que sao ponteiros
 *			genericos do tipo Node que apontam para a cabeca e calda 
 * 			da lista respectivamente		
 */
template <typename T> 
class Lista {

	private:
		Node<T> *inicio; /**< Inicio  */
		Node<T> *fim;    /**< Fim */

	public:
		/** @brief Construtor padrao */
		Lista();

		/** @brief Destrutor */
		~Lista();

		/** @brief Insere elementos ordenados na lista */
		void inserirOrdenado(T elemento);

		/** @brief Acessa elemntos da lista */
		Node<T>* acessar(T elemento);

		/** @brief Remove elementos da lista */
		void remover(T elemento);

		/** @brief imprimir elementos da lista */
		void imprimir();

};

//Construtor padrao
template <typename T>
Lista <T> :: Lista() {
	inicio = NULL;
	fim = NULL;
}

//Destrutor
template<typename T>
Lista <T>:: ~Lista() {

	Node<T> *temp = NULL; 
	while(inicio != NULL) {
		temp = inicio;
		inicio = inicio -> proximo;
		delete temp;
	}
}

 /**
  * @param elemento Elemento a ser adicionado a lista
  */
template <typename T>
void  Lista <T> :: inserirOrdenado(T elemento) {

	Node<T> *iterador = inicio;
	Node<T> *novoNode = new Node<T>;
	novoNode->dado = elemento;

	if(inicio == NULL && fim == NULL){
		inicio = novoNode;
		fim = novoNode;
		novoNode -> proximo = NULL;
		novoNode -> anterior = NULL;
	}

	else {


		while(iterador && elemento > iterador->dado && iterador->proximo ) {
			iterador = iterador->proximo;
		}
		if(iterador == inicio && elemento < iterador->dado){

			iterador->anterior = novoNode;
			novoNode->proximo = iterador;
			novoNode->anterior = NULL;
			inicio = novoNode;
		}

		else if(iterador == fim && elemento > fim->dado) {
			fim ->proximo = novoNode;
		   	(fim-> proximo)->anterior = fim;
		   	fim = fim -> proximo;
			fim ->proximo = NULL;
		}

		else {

			novoNode->proximo = iterador;
			(iterador->anterior)-> proximo = novoNode;
			novoNode->anterior = iterador->anterior;
			iterador->anterior = novoNode;
		}
	} 
}

/**
 * @details Caso o usuario tente acessar um elemento que nao esteja 
 *			presente na lista o programa exibe uma messagem de erro
 * @param	elemento Elemento a ser acessado		
 */
template <typename T>
Node<T>* Lista<T> ::acessar(T elemento){

	Node <T> *iterador = NULL;
	Node <T> *temp = NULL;

	if(inicio == NULL) {
		cout << endl << "Lista vazia." << endl;
		cout << "Erro: nao existe elemento a ser acessado." << endl;
		return temp;
	}

	iterador = inicio;

	while(iterador != NULL){
		if(iterador -> dado == elemento) {
			temp = iterador;
			return temp;
		}
		iterador = iterador->proximo;
	}

	cout << endl <<"Erro: o elemento nao pode ser acessado, pois nao esta na lista." << endl;
	return temp;
}

/**
 * @details Caso o usuario tente remover um elemento que nao esteja 
 *			na lista ou a lista estaja vazia programa exibi uma messagem de erro
 * @param	elemento Elemento a ser removido da lista			
 */
template <typename T>
void Lista<T>:: remover(T elemento) {

	Node <T> *iterador = NULL;

	if(inicio == NULL) {
		cout << endl << "Lista vazia." << endl;
		cout << "Erro: nao existe elemento a ser removidos." << endl;
		return;
	}

	iterador = inicio;

	while(iterador !=  NULL){
		if(iterador->dado == elemento){
			break;
		}
		iterador = iterador->proximo;
	}

	if(iterador == NULL) {
		cout << endl <<"Erro: o elemento nao foi removido, pois nao esta na lista." << endl;
	}
	else if(iterador == inicio && iterador->proximo) {
		inicio = inicio->proximo;
		inicio->anterior = NULL;
		delete iterador;
		return;
	}
	else if(iterador == inicio && iterador->proximo == NULL) {
		delete iterador;
		inicio = NULL;
		fim = NULL;
		return;
	}
	else if(iterador == fim){
		fim = fim->anterior;
		fim -> proximo = NULL;
		delete iterador;
		return;
	}
	else {
		(iterador->anterior)-> proximo = iterador->proximo;
		(iterador->proximo)->anterior = iterador->anterior;
		delete iterador;
		return;
	}
}

//Imprimir elementos
template <typename T>
void Lista<T> :: imprimir(){

	if(inicio == NULL) {
		cout << "Nao existe elemento(s) a ser impresso." << endl;
		return;
	}
	cout << "Elementos da lista: ";
	Node<T> *iterador = inicio;
	while(iterador != NULL){
		cout << iterador-> dado << " ";
		iterador = iterador-> proximo; 
	}
	cout << endl;
}


#endif
