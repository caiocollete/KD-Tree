#define K 2

struct tree{
	struct tree *esq, *dir;
	int ponto[K];
}; typedef struct tree Tree;

Tree *CriaNo(int pontos[]){
	Tree *no= (Tree*)malloc(sizeof(Tree));
	no->ponto[0]=pontos[0];
	no->ponto[1]=pontos[1];
	no->esq=NULL;
	no->dir=NULL;
	
	return no;
}

void ordena(int pontos[][K], int inicio, int fim, int d) {
    for (int i = inicio; i < fim - 1; i++) {
        for (int j = inicio; j < fim - i + inicio - 1; j++) {
            if (pontos[j][d] > pontos[j + 1][d]) {
                for (int k = 0; k < K; k++) { 
                    int temp = pontos[j][k];
                    pontos[j][k] = pontos[j + 1][k];
                    pontos[j + 1][k] = temp;
                }
            }
        }
    }
}

void inserirBalanceada(Tree **root, int pontos[][K], int inicio, int fim, int n){
	int d, meio;
	if(inicio<=fim){
		d=n%K;
		ordena(pontos,inicio,fim,d);
		meio=(inicio+fim)/2;
		*root = CriaNo(pontos[meio]);
		inserirBalanceada(&(*root)->esq, pontos, inicio, meio-1, n+1);
		inserirBalanceada(&(*root)->dir, pontos, meio+1, fim, n+1);
	}
}

void printarArvoreFormatada(Tree *raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }
    printarArvoreFormatada(raiz->dir, nivel + 1);
    for (int i = 0; i < nivel; i++) {
        printf("\t");
    }
    printf("(%d, %d)\n", raiz->ponto[0], raiz->ponto[1]);
    printarArvoreFormatada(raiz->esq, nivel + 1);
}
