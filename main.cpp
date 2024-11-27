#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvKd.h"
#include "fila.h"


void pontosProximos(Tree *R, int parametros[], int pontosProx[][K],int *TL, int raio){
	int soma;
	Fila *F;
	init(&F);
	enqueue(&F,R);
	while(!isEmptyF(F)){
		dequeue(&F,&R);
		if(R!=NULL){
			soma=0;
			for(int i=0;i<K;i++){
				soma+=pow((R->ponto[i]-parametros[i]),2);
			}
			soma+=sqrt(soma);
			
			if(soma<=raio){
				(*TL)++;
				pontosProx[*TL][0]=R->ponto[0];
				pontosProx[*TL][1]=R->ponto[1];
			}
			
			enqueue(&F,R->esq);
			enqueue(&F,R->dir);
		}
	}
}

int main(){
	int pontos[][K] = {
        {3, 6},
        {17, 15},
        {13, 15},
        {6, 12},
        {9, 1},
        {2, 7},
        {10, 19},
        {5, 25},
        {10, 12}
    };
    int TF = (sizeof(pontos) / sizeof(pontos[0]))-1;
    
    int target[K] = {8,10};
    int pontosProx[TF][K];
    int TL=-1;
    
    Tree *R=NULL;
    
    inserirBalanceada(&R, pontos, 0, TF, 1);
    printarArvoreFormatada(R, 0);
    
    pontosProximos(R, target, pontosProx, &TL, 10);
    
    if(TL!=-1){
    	printf("Pontos Proximos:\n");
    	for(int i=0;i<=TL;i++){
    		printf("%d : {%d, %d}\n",i,pontosProx[i][0],pontosProx[i][1]);
    	}
    }
    else printf("nenhum ponto encontrado");

	
	return 0;
}
