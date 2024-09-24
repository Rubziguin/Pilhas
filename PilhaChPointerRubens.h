//Pilhas Pointer
//Rubens Rodrigues Maranesi

#include <stdio.h>
#include "Booleano.h"

#define Max 10
#define sinal 0 //Usado pra mostrar o inicio da pilha
#define Fantasma 36

typedef struct{
	int topo;
	unsigned char Vetor[Max];
}PilhaCh;


//Interface

void criarPilha(PilhaCh*);
bool pilhaVazia(PilhaCh*);
char acessarPilha(PilhaCh *);
void pushPilha(PilhaCh *, char);
void popPilha(PilhaCh*);
void esvaziarPilha(PilhaCh*);
int obterProfundidade(PilhaCh*);
void mostrarPilha(PilhaCh*);
void inverter(PilhaCh*);
void copiarPilha(PilhaCh*, PilhaCh*);

//Implementacao

void criarPilha(PilhaCh *P){
	
	P->topo = sinal;
	P->Vetor[0] = Max - 1;
	
}

bool pilhaVazia(PilhaCh *P){
	
	bool ok = TRUE;
	
	if (P->topo != sinal){
		ok = FALSE;
	}
	
	return ok;
}

char acessarPilha(PilhaCh *P){
	
	char r;
	if(P->topo != sinal)
		r = P->Vetor[P->topo];
	else
		r = Fantasma;
	return r;
}

void pushPilha(PilhaCh *P, char r){
	
	if(P->topo < P->Vetor[0]){
		P->topo++;
		P->Vetor[P->topo] = r;
	}
		
}

void popPilha(PilhaCh *P){
	
	if(P->topo != sinal){
		P->topo--;
	}
	
}

void esvaziarPilha(PilhaCh *P){
	
	if(P->topo != sinal)
		P->topo = sinal;
}

int obterProfundidade(PilhaCh *P){
	
	int t;
	t = P->topo;
	return t;
}

void mostrarPilha(PilhaCh *P){
	
	int i;
	if(P->topo == sinal)
		printf("Pilha vazia!");
	else
		for(i = P->topo; i != sinal; i--){
			printf("\n%c", P->Vetor[i]);
		}
	
}


//Metodo desenvolvedor
/*
void inverter(PilhaCh *P){
	
	int i, j;
	char aux;
	
	i = 1;
	j = P->topo;
	
	for (i = 1; i <= (P->topo / 2); i ++){
		aux = P->Vetor[i];
		P->Vetor[i] = P->Vetor[j];
		P->Vetor[j] = aux;
		j--;
		}
	
}
*/

//Metodo Usuario
void inverter(PilhaCh *P){
	
	char r;
	PilhaCh aux, temp;
	
	criarPilha(&aux);
	criarPilha(&temp);
	
	while(!pilhaVazia(P)){
		
		r = acessarPilha(P);
		pushPilha(&aux, r);
		popPilha(P);
	}
	
	while(!pilhaVazia(&aux)){
		
		r = acessarPilha(&aux);
		pushPilha(&temp, r);
		popPilha(&aux);
	}
	
	while(!pilhaVazia(&temp)){
		
		r = acessarPilha(&temp);
		pushPilha(P, r);
		popPilha(&temp);
	}
	
}

void copiarPilha(PilhaCh *P, PilhaCh *T){
	
	char r;
	PilhaCh A;
	criarPilha(&A);
	
	while(!pilhaVazia(P)){
		r = acessarPilha(P);
		pushPilha(&A, r);
		popPilha(P);
	}
	
	while(!pilhaVazia(&A)){
		r = acessarPilha(&A);
		pushPilha(P, r);
		pushPilha(T, r);
		popPilha(&A);
	}
}
	




























