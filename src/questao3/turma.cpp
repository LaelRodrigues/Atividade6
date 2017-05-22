/**
 * @file	turma.cpp
 * @brief	Implementacao dos metodos da classe Turma
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	20/05/2017
 * @date	21/05/2017
 */

#include "turma.h"

// Construtor padrao
Turma :: Turma() {
	inicio = NULL;
	fim = NULL;
}
/**
 * @details Caso o valor fornecido para matricula, total de faltas  
 *			ou nota seja invalido o programa exibe uma menssagem de erro
 * @param matricula Matricula
 * @param nome Nome
 * @param totalFaltas Total de faltas
 * @param nota Nota
 */
void Turma :: inserirOrdenado(int matricula, string nome, int totalFaltas, float nota) {

	Node *iterador = inicio;
	Node *novoNode = new Node;
	if(matricula <= 0) {
		cout << endl << "Erro: o numero de matricula e invalido." << endl;
		return;
	}
	if(totalFaltas < 0) {
		cout << endl << "Erro: o numero do total de faltas e invalido." << endl;
		return;
	}
	if(nota < 0 || nota > 10) {
		cout << endl << "Erro: o numero da nota e invalido." << endl;
		return;
	}
	novoNode-> dados.setMatricula(matricula); 
	novoNode-> dados.setNome(nome);
	novoNode-> dados.setTotalFaltas(totalFaltas);
	novoNode-> dados.setNota(nota);

	while(iterador){
		if(iterador-> dados == novoNode->dados){
			cout << endl <<"Erro: nao e possivel adicinar um aluno a turma duas(ou mais vezes)." << endl;
			delete novoNode;
			return;
		}
		iterador = iterador->proximo;
	}

	iterador = inicio;
	
	if(inicio == NULL && fim == NULL){
		inicio = novoNode;
		fim = novoNode;
		novoNode -> proximo = NULL;
		novoNode -> anterior = NULL;
	}

	else {


		while(iterador && matricula > iterador-> dados.getMatricula() && iterador->proximo ) {
			iterador = iterador->proximo;
		}
		if(iterador == inicio  && matricula < iterador-> dados.getMatricula()){

			iterador->anterior = novoNode;
			novoNode->proximo = iterador;
			novoNode->anterior = NULL;
			inicio = novoNode;
		}

		else if(iterador == fim && matricula > fim -> dados.getMatricula()) {
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
 * @details Caso o usuario tente acessar as informacoes de uma aluno 
 *			que nao esta presente na turma ou turma esteja vazia
 *			o programa exibe uma messagem de erro
 * @param	matricula Matricula		
 */
Node* Turma ::acessar(int matricula){

	Node *iterador = NULL;
	Node *temp = NULL;

	if(inicio == NULL) {
		cout << "Lista vazia." << endl;
		cout << endl <<"Erro: nao existe aluno(s) cadastrados para acessar os dados." << endl;
		return temp;
	}

	iterador = inicio;

	while(iterador != NULL){
		if(iterador -> dados.getMatricula() == matricula) {
			temp = iterador;
			return temp;
		}
		iterador = iterador->proximo;
	}

	cout << endl << "Erro: aluno nao pertence a lista." << endl;
	return temp;
}
/**
 * @details Caso o usuario tente remover um Aluno que nao esteja na 
 *			turma ou a turma estaja vazia programa exibi uma messagem de erro
 * @param	matricula Matricula do aluno a ser removido			
 */
void Turma:: remover(int matricula) {

	Node *iterador = NULL;
	//Node <T> *temp = NULL;

	if(inicio == NULL) {
		cout << endl << "Lista vazia." << endl;
		cout << "Erro: nao existe aluno(s) cadastrados para remover." << endl;
		return;
	}

	iterador = inicio;

	while(iterador !=  NULL){
		if(iterador-> dados.getMatricula() == matricula){
			break;
		}
		iterador = iterador->proximo;
	}

	if(iterador == NULL) {
		cout << endl << "Erro: aluno nao pertence a lista." << endl;
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
/** return media da notas dos alunos */
float Turma::mediaAlunos() {

	float media;
	float soma = 0.0;
	int cont = 0;
	Node *iterador = inicio;
	while(iterador) {
		soma += iterador->dados.getNota();
		iterador = iterador -> proximo;
		cont++;
	}
	media = (float)soma / cont;
	return media;
}

//imprimir dados da turma
void Turma :: imprimir(){

	int cont = 1;
	Node *iterador = inicio;

	if(iterador == NULL) {
		cout << "Nao existe dados referentes a turma a ser impresso." << endl;
		return;
	}

	while(iterador != NULL){
		cout << "-----------------------------------" << endl;
		cout << "Dados aluno " << cont  << ": " << endl;
		cout << "matricula: " << iterador->dados.getMatricula() << endl;
		cout << "Nome: " << iterador->dados.getNome() << endl;
		cout << "Total de faltas: " << iterador->dados.getTotalFaltas() << endl;
		cout << "Nota: " << iterador->dados.getNota() << endl;
		cout << "-----------------------------------" << endl;
		iterador = iterador-> proximo;
		cont++; 
	}
	cout << "Quantidade de alunos: " << cont-1 << endl;
	cout << "Media dos alunos: " << Turma::mediaAlunos() << endl;
}

//Destrutor
Turma :: ~Turma() {

	Node *temp = NULL; 
	while(inicio != NULL) {
		temp = inicio;
		inicio = inicio -> proximo;
		delete temp;
	}

}