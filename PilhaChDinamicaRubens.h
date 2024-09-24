//Pilhas Dinamicas
//Rubens Rodrigues Maranesi

#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"

#define Max 101
#define sinal 0 //Usado pra mostrar o inicio da pilha
#define Fantasma 36

typedef struct{
	int topo;
	unsigned char Vetor[Max];
}PilhaChd;

typedef PilhaChd *PilhaCh;

//Interface

PilhaCh criarPilha();
bool pilhaVazia(PilhaCh);
char acessarPilha(PilhaCh);
void pushPilha(PilhaCh, char);
void popPilha(PilhaCh);
void esvaziar(PilhaCh);
int obterProfundidade(PilhaCh);
void mostrarPilha(PilhaCh);
void inverter(PilhaCh);               // fazer como usuário e como desenvolvedor
void copiarPilha(PilhaCh, PilhaCh); // fazer como usuário e como desenvolvedor

//Implementacao

PilhaCh criarPilha(){
	
	PilhaCh P = (PilhaCh) malloc(sizeof(PilhaCh));
	P->topo = sinal;
	P->Vetor[0] = Max - 1;
	
	return P;
}

bool pilhaVazia(PilhaCh P){
	
	bool ok = TRUE;
	if(P->topo != sinal)
		ok = FALSE;
	return ok;
	
}

char acessarPilha(PilhaCh P){
	
	char r;
	
	if(P->topo != sinal){
		r = P->Vetor[P->topo];
	}
	else
		r = Fantasma;
			
	return r;
}

void pushPilha(PilhaCh P,char r){
	
	if(P->topo < P->Vetor[0]){
		P->topo++;
		P->Vetor[P->topo] = r;
	}
}

void popPilha(PilhaCh P){
	
	if(P->topo != sinal){
		P->topo--;
	}
}

void esvaziar(PilhaCh P){
	
	if(P->topo != sinal){
		P->topo = sinal;
	}
}

int obterProfundidade(PilhaCh P){
	
	int t;
	t = P->topo;
	
	return t;
}

void mostrarPilha(PilhaCh P){
	
	int i;
	
	if(P->topo == sinal){
		printf("Pilha Vazia!");
	}
	else
		for(i = P->topo; i != sinal; i--){
			printf("\n%c", P->Vetor[i]);
		}
	
}
/*
void inverter(PilhaCh P){
	
	char r;
	PilhaCh aux, temp;
	
	aux = criarPilha();
	temp = criarPilha();
	
	while(!pilhaVazia(P)){
	
		r = acessarPilha(P);
		pushPilha(aux, r);
		popPilha(P);
		}
		
	while(!pilhaVazia(aux)){
		
		r = acessarPilha(aux);
		pushPilha(temp, r);
		popPilha(aux);
	}
	
	while(!pilhaVazia(temp)){
		r = acessarPilha(aux);
		pushPilha(P, r);
		popPilha(temp);
	}
	
}
*/

//Como desenvolvedor

void inverter(PilhaCh P){
	
	int i, j;
	char aux;
	i = 1;
	j = P->topo;
	
	for(i = 1; i <= (P->topo / 2); i++){
		aux = P->Vetor[i];
		P->Vetor[i] = P->Vetor[j];
		P->Vetor[j] = aux;
		j--;
	}
	
}


void copiarPilha(PilhaCh P, PilhaCh T){
	
	char r;
	
	PilhaCh A;
	A = criarPilha();
	
	while(!pilhaVazia(P)){
		
		r = acessarPilha(P);
		pushPilha(A, r);
		popPilha(P);
		
	}
	
	while(!pilhaVazia(A)){
		r = acessarPilha(A);
		pushPilha(P, r);
		pushPilha(T, r);
		popPilha(A);
	}
	
}


















