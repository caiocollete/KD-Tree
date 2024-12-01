#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "arvKd.h"
#include "fila.h"

void gerarPontos(int pontos[][K], int TF){
	int i=0;
	srand(0); //Mudar pra srand(time(NULL)); caso queira resultados variados
	while(i<TF){
		pontos[i][0] = rand()%30;
		pontos[i][1] = rand()%30;
		i++;
	}
}


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
			soma=sqrt(soma);
			
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

void exibePontosProx(int pontosProx[][K], int TL){
	
	if(TL!=-1){
		printf("\n");
    	printf("Pontos Proximos:\n");
    	for(int i=0;i<=TL;i++){
    		printf("%d : {%d, %d}\n",i,pontosProx[i][0],pontosProx[i][1]);
    	}
    }
    else printf("nenhum ponto encontrado");
}

void exibirPontos(int pontos[][K], int TF){
	
	int j = 0;
	
	printf("\n");
	for(int i = 0; i<TF; i++){
		j = 0;	
		printf("\n PONTO: X-%d Y-%d",pontos[i][j],pontos[i][++j]);
	}
	printf("\n");
}

int main(){
	
	 Tree *R=NULL;
	
	// pontos estaticos que serao inseridos na arvores dps
	int pontos[10][K];
	int TF=10;
        
    int target[K] = {8,10}; // ponto que sera o parametro para medir a distancia
    int pontosProx[TF][K]; // array de pontos onde sera retornado por parametro
    int TL=-1; // tl do array pontosProx
    
    gerarPontos(pontos,TF);
    
    inserirBalanceada(&R, pontos, 0, TF-1, 0);
    printarArvoreFormatada(R, 0);
    pontosProximos(R, target, pontosProx, &TL, 10);
    
    exibePontosProx(pontosProx, TL);
    
    
    printf("\n\nFEITO POR:\n\t- Caio Collete Silva, 262318709\n\t- Vinicius Araujo Messias, 262319527\n");

	
	return 0;
}
