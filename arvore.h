#ifndef _arvore_h
#define _arvore_h

typedef struct _carro_{
    char *marca;
    int pot;
    int nPortas;
    float preco;
    long int placa;
}Carro;

typedef struct _TNode_{
	struct _TNode_ *l,*r;
	void *data;
}TNode;

typedef TNode Tree;

#ifndef _arvore_c
	Tree *TCreate();
	int cmpPlaca(void *key,void *elem);
	int cmpMarca(void *key,void *elem);
	int cmp(void *key1,void *key2);
	int cmpPreco(void* key,void *elem);
	TNode *abpInsert(TNode *t,void *data,int (*cmp)(void*,void*));
	void* abpMaior(TNode *t);
	TNode *abpRemove(TNode *t,void *key,void **data,int(*cmp)(void*,void*));
	void *abRecMaior(TNode *t,int(*cmp)(void*,void*));
	void *abpQuery(TNode *t,void *key,void *key2);
	int abDestroy(TNode *t);
	void imprimirCarro(Carro *c1);
#else
	extern Tree *TCreate();
	extern int cmpPlaca(void *key,void *elem);
	extern int cmpMarca(void *key,void *elem);
	extern int cmp(void *key1,void *key2);
	extern int cmpPreco(void* key,void *elem);
	extern TNode *abpInsert(TNode *t,void *data,int (*cmp)(void*,void*));
	extern void* abpMaior(TNode *t);
	extern TNode *abpRemove(TNode *t,void *key,void **data,int(*cmp)(void*,void*));
	extern void *abRecMaior(TNode *t,int(*cmp)(void*,void*));
	extern void *abpQuery(TNode *t,void *key,void *key2);
	extern int abDestroy(TNode *t);
	extern void imprimirCarro(Carro *c1);
#endif





#endif