#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
  TNode *t = NULL;
  TNode *verify;
  Carro *c;
  Carro *res;
  void *remov;
  long int placa;
  char *marca;
  int verif;
  marca = (char*)malloc(sizeof(char)*100);
  int opc=1,n,i;
  do{
    printf("###################### MENU ####################\n");
    printf("[1] - criar uma arvore\n");
    printf("[2] - destruir a arvore\n");
    printf("[3] - inserir dados de uma estrutura do tipo T em uma arvore\n");
    printf("[4] - consultar uma estrutura do tipo T identificada pelo campo F que esta na arvore\n");
    printf("[5] - remover uma estrutura do tipo T identifcada pelo campo F que esta na arvore\n");
    printf("[6] - arvorer todas as estruturas armazenadas na arvore\n");
    printf("[0] - Sair do programa.\n");
    printf("#################### MENU ####################\n");
    scanf("%d",&opc);
    switch(opc){
      	case 1:
			if(t==NULL){
				//t = TCreate();
				if(t==NULL){
					printf("Sua arvore foi criada com sucesso.\n");
				}else{
					printf("Nao foi possivel criar sua arvore.\n");
				}
			}else{
				printf("Voce deve excluir a arvore ja existente.\n");
			}
			fflush(stdin);
			break;
      	case 2:
			if(t!=NULL){
				int opc = 0;
				printf("Para destruir teremos que restirar todos os elementos da arvore.\n");
				printf("Gostaria de continuar com a operação.[1]Sim [0]Nao.\n");
				scanf("%d",&opc);
				if(opc == 1){
					verif = abDestroy(t);
					if(verif == true){
						t = NULL;
						printf("Sua arvore foi destruida com sucesso.\n");
					}else{
						printf("Nao foi possivel destruir sua arvore.\n");
					}
				}
			}else{
				printf("Nao existe arvore para destruir.\n");
			}
			break;
      	case 3:
			if(t!=0){
				c = (Carro*)malloc(sizeof(Carro));
				if(c!=NULL){
					c->marca = (char*)malloc(sizeof(char)*100);
					if(c->marca!=NULL){
						printf("Digite a marca do carro:\n");
						scanf("%s",(c->marca));
						fflush(stdin);
						printf("Digite a potencia do carro:\n");
						scanf("%d",&(c->pot));
						fflush(stdin);
						printf("Digite o numero de portas do carro:\n");
						scanf("%d",&(c->nPortas));
						fflush(stdin);
						printf("Digite o preco do carro:\n");
						scanf("%f",&(c->preco));
						fflush(stdin);
						printf("Digite a placa do carro:\n");
						scanf("%ld",&(c->placa));
						fflush(stdin);
					}
					verify = abpInsert(t,(void*)c,cmp);
					if(verify!=NULL){
						imprimirCarro(c);
						printf("Os elementos foram inseridos com sucesso.\n");
					}else{
						printf("Os elementos não foram inseridos.\n");
					}
				}
			}else{
				printf("Não arvore para inserir elementos.\n");
			}
			break;
      	case 4:
			if(t!=NULL){
				printf("Digite a placa do carro a ser pesquisado.\n");
				scanf("%ld",&placa);
				printf("Digite a marca do carro a ser pesquisado.\n");
				scanf("%s",marca);
				res = (Carro*)abpQuery(t,(void*)placa,(void*)marca);
				if(res!=NULL){
					printf("O Carro foi encontrado.\n");
					imprimirCarro(res);
				}else{
					printf("Este Carro nao esta na arvore.\n");
				}
			}else{
				printf("Nao existe arvore para procurar o elemento.\n");
			}
			break;
      	/*case 5:
			if(t!=NULL){
				if(t->first!=NULL){	
					printf("Digite a placa do carro a ser removido.\n");
					scanf("%ld",&placa);
					printf("Digite a marca do carro a ser removido.\n");
					scanf("%s",marca);
					remov = sllRemoveSpec(l,(void*)marca,(void*)placa);
					if(remov!=NULL){
						imprimirCarro(remov);
						printf("O elemento foi removido.\n");
					}
				}else{
					printf("Nao tem elementos na arvore.\n");
				}
			}else{
				printf("Nao tem elementos na arvore.\n");
			}
			break;
      	case 6:
			if(l!=NULL){
				if(l->first!=NULL){
					imprimirarvore(l);
				}else{
					printf("Nao tem elementos para imprimir.\n");
				}
			}else{
			printf("Nao tem arvore para imprimir.\n");
			}
			break;*/
		}
	}while(opc!=0);
}
       
