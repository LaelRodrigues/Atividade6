/**
 * @file	main.cpp
 * @brief	Arquivo corpo para a verificacao se uma palavra
 			e um palindromo ou nao
 * @author	LaelRodrigues (laelrodrigues7@gmail.com)
 * @since	10/05/2017
 * @date	14/05/2017
 */	

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;
using std::getline;

#include <cctype>
using std::ispunct;
using std::tolower;

#include "pilha.h"


/** @brief Funcao principal */
int main(){

	string palindromo, direita, esquerda;

	cout << "Digite uma palavra: ";
	getline(cin, palindromo);


	Pilha <char> pilha(palindromo.size());

	//remover espacos da string
	for (int i = 0; i < (int)palindromo.size(); i++) {
		if (palindromo[i] == ' ' || palindromo[i] == '\t' || palindromo[i] == '\n') {
			palindromo.erase(i, 1);
			i--;
		}
	}

	//remover sinais de pontuacao da string 
	for(int i = 0; i < (int)palindromo.size(); i++) {
		if (ispunct(palindromo[i])) {
			palindromo.erase(i, 1);
		}
	}

	//converter para minusculo os caracteres da string
	for(int i = 0; i < (int)palindromo.size(); i++) {
		palindromo[i] = tolower(palindromo[i]);
		pilha.push(palindromo[i]);
	}
	
	for(int i = 0; i < (int)palindromo.size()/2; i++) {
		direita[i] = palindromo[i];
		esquerda[i] = pilha.top();
		pilha.pop();
	}

	int contador = 0;
	for(int i = 0; i < (int)palindromo.size()/2; i++) {
		if(direita[i] == esquerda[i]) {
			contador++;
		}
	} 

	if(contador == (int)palindromo.size()/2) {
		cout << "A palavra " << palindromo <<" e um palindromo" << endl;
	}
	else {
		cout << "A palavra " << palindromo << " nao e palindromo" << endl;

	}
	return 0;
}
