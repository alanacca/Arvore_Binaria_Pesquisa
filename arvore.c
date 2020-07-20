#ifndef _arvore_c
#define _arvore_c
#include "arvore.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int abDestroy(TNode *t){
	int remL, remR;
	if(t!=0){
		free(t);
		remL = abDestroy(t->l);
		remR = abDestroy(t->r);
		t->l = NULL;
		t->r = NULL;
		return true;
	}
	return false;
}

int cmpPlaca(void *key,void *elem){//COMPARANDO A PLACA
   long int ik = (long int)key;
   Carro *Aelem = (Carro*)elem;
   if(ik==Aelem->placa){
        return true;
    }else{
        return false;
    }
}

int cmpMarca(void *key,void *elem){//COMPARANDO A MARCA
  char *ik = (char*)key;
  Carro *Aelem = (Carro*)elem;
  if(strcmp(ik,Aelem->marca)==0){
    return true;
  }else{
    return false;
  }
}

int cmp(void *key1,void *key2){//COMPARANDO OS VALORES
	int ikey1 = (int)key1;
	int ikey2 = (int)key2;
	if(ikey1<ikey2){
		return -1;
	}else if(ikey1>ikey2){
		return 1;
	}else{
		return 0;
	}
}

int cmpPreco(void* key,void *elem){//COMPARANDO O PREÇO
	if(cmp(key,elem)>0){
		return true;
	}else{
		return false;
	}
}

TNode *abpInsert(TNode *t,void *data,int(*cmp)(void*,void*)){//INSERÇÃO
	int stat;
	TNode *newt;
	if(t!=NULL){
		stat = cmp(data,t->data);
		if(stat<0){
			t->l = abpInsert(t->l,data,cmp);
		}else{
			t->r = abpInsert(t->r,data,cmp);
		}
		return t;
	}else{
		newt = (TNode*)malloc(sizeof(TNode));
		if(newt!=NULL){
			newt->data = data;
			newt->l=NULL;
			newt->r=NULL;
			return newt;
		}
	}
	return NULL;
}

void *abpQuery(TNode *t,void *key,void *key2){//PROCURA
	int stat,stat2;
	if(t!=NULL){
		stat = cmpPlaca(key,t->data);
		stat2 = cmpMarca(key2,t->data);
		if(stat==true && stat2==true){
			return t->data;
		}else if(stat==false || stat2==false){
			return abpQuery(t->l,key,cmp);
		}
	}
	return NULL;
}

void* abpMaior(TNode *t){//PROCURANDO O MAIOR VALOR
	if(t!=NULL){
		if(t->l!=NULL){
			return abpMaior(t->l);
		}else{
			return t->data;
		}
	}
	return t->data;
}

TNode *abpRemove(TNode *t,void *key,void **data,int(*cmp)(void*,void*)){//REMOÇÃO
	int stat;
	void *data2;
	void *maior;
	TNode *curt;
	if(t!=NULL){
		stat = cmp(key,t->data);
		if(stat < 0){
			t->l = abpRemove(t->l,key,data,cmp);
			return t;
		}else if(stat > 0){
			t->r = abpRemove(t->r,key,data,cmp);
			return t;
		}else{
			*data = t->data;
			if(t->l==NULL && t->r==NULL){
				free(t);
				return NULL;
			}else if(t->l==NULL && t->r!=NULL){
				curt = t->r;
				free(t);
				return curt;
			}else if(t->l!=NULL && t->r==NULL){
				curt = t->l;
				free(t);
				return curt;
			}else{
				maior = abpMaior(t->l);
				t->data = maior;
				abpRemove(t->l,maior,&data2,cmp);
				return t;
			}
		}
	}
	return NULL;
}

void imprimirCarro(Carro *c1){//IMPRIMIR A ESTRUTURA DO CARRO
  if(c1!=NULL){
    printf("Placa:%ld\nPotencia:%d\nPreco:%.2f\nNumero de Portas:%d\nMarca:%s\n------------------------\n",c1->placa,c1->pot,c1->preco,c1->nPortas,c1->marca);
    }
}



#endif