//Pilhas normais
//Rubens Rodrigues Maranesi

#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#include <time.h>

#define Max 10
#define sinal 0 //Usado pra mostrar o inicio da pilha
#define Fantasma 36

typedef struct{
	int topo;
	unsigned char Vetor[Max];
}PilhaCh;

//Interface

PilhaCh criarPilhaCh();
PilhaCh construirPilhaCh(int);
bool pilhaVazia(PilhaCh);
char acessarPilha(PilhaCh);
PilhaCh pushPilhaCh(PilhaCh, char);
PilhaCh popPilhaCh(PilhaCh);
PilhaCh esvaziar(PilhaCh);
int obterProfundidade(PilhaCh);
void mostrarPilhaCh(PilhaCh);
PilhaCh inverter(PilhaCh);
PilhaCh copiarPilha(PilhaCh);
void swap(int *x, int *y);
void shuffleArray(int array[], int n);


//Implementacao

PilhaCh construirPilhaCh(int t){
	
	PilhaCh P;
	P = criarPilhaCh();
	
	int array[t], i;
	
	for (i = 0; i < t; i++)
		array[i] = i + 1;
		
		
	shuffleArray(array, t);
	
	
	for (i = 0; i < t; i++) {
        pushPilhaCh(P, array[i]);
    }

    return P;
	
	
}

PilhaCh criarPilhaCh(){
	
	PilhaCh P;
	P.topo = sinal;
	P.Vetor[0] = Max - 1;
	return P;
	
}

bool pilhaVazia(PilhaCh P){
	
	bool ok = TRUE;
	
	if (P.topo != sinal)
		ok = FALSE;
	return ok;
}

char acessarPilha(PilhaCh P){
	
	char r;
	if (P.topo != sinal){
		r = P.Vetor[P.topo];
		}
	else 
		r = Fantasma;
	return r;
}

PilhaCh pushPilhaCh(PilhaCh P, char r){
	
	if (P.topo < P.Vetor[0]){
		P.topo++;
		P.Vetor[P.topo] = r;
	}
	
	return P;
}

PilhaCh popPilhaCh(PilhaCh P){
	
	if (P.topo != sinal)
		P.topo--;
	return P;
}


PilhaCh esvaziar(PilhaCh P){
	
	if (P.topo != sinal)
		P.topo = sinal;
	return P;
}


int obterProfundidade(PilhaCh P){
	
	int t;
	t = P.topo;
	return t;
}

void mostrarPilhaCh(PilhaCh P){
	
	int i;
	
	for (i = P.topo; i > sinal; i--){
		printf("\n%d", P.Vetor[i]);
	}
	

}

//Metodo Desenvolvedor
/*
PilhaCh inverter(Pilha P){
	
	int i, j;
	char aux;
	
	i = 1;
	j = P.topo;
	
	for (i = 1; i <= (P.topo / 2); i ++){
		aux = P.Vetor[i];
		P.Vetor[i] = P.Vetor[j];
		P.Vetor[j] = aux;
		j--;
		}
	
	return P;
}
*/

//Metodo do usuario
PilhaCh inverter(PilhaCh P){
	
	char ch;
	PilhaCh Aux;
	Aux = criarPilhaCh();
	
	while (!pilhaVazia(P)){
		
		ch = acessarPilha(P);
		Aux = pushPilhaCh(Aux, ch);
		P = popPilhaCh(P);
		
	}
		
		
	return Aux;
}


PilhaCh copiarPilha(PilhaCh P){
	
	return P;
}

void shuffleArray(int array[], int n){
	
	int i;
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    for (i = n - 1; i > 0; i--) {
        // Escolhe um índice aleatório entre 0 e i (inclusive)
        int j = rand() % (i + 1);

        // Troca os elementos nas posições i e j
        swap(&array[i], &array[j]);
    }
	
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
























