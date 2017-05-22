/**
 * @file	aluno.cpp
 * @brief	Implementacao dos metodos da classe Aluno
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	21/05/2017
 * @date	21/05/2017
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::exit;

#include "aluno.h"


Aluno::Aluno() {
	// Construtor padrao
}
Aluno::~Aluno(){
	//destrutor
}

/** @return Matricula */
int Aluno::getMatricula() {
	return matricula;
}


/** @param m Matricula */
void Aluno::setMatricula(int m){
	matricula = m;
}


/** @return Nome */
string Aluno::getNome(){
	return nome;
}


/** @param n Nome */
void Aluno::setNome(string n) {
	nome = n;
}


/** @return Total de faltas */
int Aluno::getTotalFaltas(){
	return totalFaltas;
}


/** @param tf Total de faltas */
void Aluno::setTotalFaltas(int tf) {
	totalFaltas = tf;
}


/** @return  Nota */
float Aluno::getNota(){
	return nota;
}

/** @param nt Nota */
void Aluno::setNota(float nt){
	nota = nt;
}

/** 
 * @details O operador e sobrecarregado para comparar se 
 * 			dois alunos sao iguais
 * @param	novoAluno Aluno que tera sua matricula comparada
 *			com a matricula do objeto que invoca	
 * @return	true ou false
 */
bool Aluno::operator== (const Aluno &novoAluno){
	return matricula == novoAluno.matricula;
}