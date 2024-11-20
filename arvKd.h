#define K 2;

struct kdTree{
	struct kdTree *esq, *dir;
	int ponto[K];
}; typedef struct kdTree Tree;

Tree *CriaNo(int pontos[]){
	Tree *no= (Tree*)malloc(sizeof(Tree));
	no->ponto[0]=pontos[0];
	no->ponto[1]=pontos[1];
	no->esq=NULL;
	no->dir=NULL;
	
	return no;
}

//void insereKD(Tree **root, int pontos[], int n){
//	int d;
//	if(*root==NULL){
//		*root=CriaNo(pontos);
//	}
//	else{
//		d=n%K;
//		if((*root)->ponto[d]>pontos[d]){
//			insereKD(&(*root)->esq,pontos,n+1);
//		}
//		else insereKD(&(*root)->dir,pontos,n+1);
//	}
//}

void ordena(int pontos[][], inicio, fim, d){
        for (int i = inicio; i < fim - 1; i++) {
            for (int j = inicio; j < fim - i - 1; j++) {
                if (vetor[j][d] > vetor[j + 1][d]) {
                    int temp = vetor[j][d];
                    vetor[j][d] = vetor[j + 1][d];
                    vetor[j + 1][d] = temp;
                }
            }
        }
 }

void inserirBalanceada(Tree **root, int pontos[][], int inicio, int fim, int n){
	int d, meio;
	if(inicio<=fim){
		d=n%K;
		ordena(pontos,inicio,fim,d);
		meio=(inicio+fim)/2;
		*root = CriaNo(pontos[meio]);
		inserirBalanceada(&(*root)->esq, pontos, inicio, meio-1, int n+1);
		inserirBalanceada(&(*root)->dir, pontos, meio+1, fim, int n+1);
	}
}

void printarArvore(Tree *raiz){  //funcao pra printar a arvore, mas nao em formato de arvore
	if(raiz!=NULL){
		if(raiz->esq == NULL && raiz->dir == NULL){
			printf("\n(%d, %d)",raiz->ponto[0],raiz->ponto[1]);
		}
	
		printarArvore(raiz->esq);
		printarArvore(raiz->dir);
	}
}

