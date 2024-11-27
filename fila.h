typedef struct fila{
	struct tree *info;
	struct fila *prox;
}Fila;

char isEmptyF(Fila *f){
	return f==NULL;
}

void init(Fila **f){
	*f = NULL;
}

void enqueue(Fila **f, struct tree *info){
	
	Fila *novo = (Fila*)malloc(sizeof(Fila)),*aux;
	novo->info = info;
	novo->prox = NULL;
	
	if(isEmptyF(*f)){
		*f = novo;
	}
	else{
		aux = *f;
		while(aux->prox!=NULL)
			aux = aux->prox;
			
		aux->prox = novo;
	}
}

void dequeue(Fila **f, struct tree **info){
	
	Fila *aux;
	if(isEmptyF(*f)){
		return;
	}
	
	aux = *f;
	*f = (*f)->prox;
	
	*info = aux->info;
	free(aux);
}



