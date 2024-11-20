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

void printarArvoreFormatada(Tree *raiz, int nivel) { //funcao pra printar a arvore em formato de arvore
    if (raiz == NULL) {
        return;
    }

    // Primeiro, imprime o nó da direita (subárvore direita)
    printarArvoreFormatada(raiz->dir, nivel + 1);

    // Imprime o nó atual com o deslocamento correspondente ao nível
    for (int i = 0; i < nivel; i++) {
        printf("\t"); // Tabulação para deslocar o nó
    }
    printf("(%s, %d)\n", raiz->string, raiz->freqArv);

    // Depois, imprime o nó da esquerda (subárvore esquerda)
    printarArvoreFormatada(raiz->esq, nivel + 1);
}
