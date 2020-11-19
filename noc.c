#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int inf;
    struct nodo * next;
}NODO;

typedef NODO * LISTA_ENC_NC;

void cria_lista(LISTA_ENC_NC *);
int eh_vazia(LISTA_ENC_NC);
int tam(LISTA_ENC_NC);
void ins(LISTA_ENC_NC, int, int);
int recup(LISTA_ENC_NC, int);
void ret(LISTA_ENC_NC, int);
void destruir(LISTA_ENC_NC);
void imprimir(LISTA_ENC_NC);
void writeToFile(LISTA_ENC_NC l);

int main(){

LISTA_ENC_NC lista;

cria_lista(&lista);
ins(lista, 10, 1);
ins(lista, 20, 2);
ins(lista, 5, 3);
ins(lista, 2, 4);
ins(lista, 40, 5);
imprimir(lista);
printf("\n\n");
writeToFile(lista);


printf("entrou");

return 0;

}

void cria_lista(LISTA_ENC_NC *pl){
    *pl=(NODO *)malloc(sizeof(NODO));
    if (!*pl){
        printf("Memoria insuficiente\n");
        exit(1);
    }
    (*pl)->inf=0;
    (*pl)->next=NULL;
}

int eh_vazia(LISTA_ENC_NC l){
    return (l->inf==0);
}

void ins(LISTA_ENC_NC l, int info, int posi){
    NODO *novo, *aux;
    if(posi <1 || posi> l->inf +1 ){
        printf("Posicao invalida\n");
        exit(2);
    }
    novo = (NODO *)malloc(sizeof(NODO));
    if (!novo){
        printf("Erro! Memoria insuficiente\n");
        exit(3);
    }
     novo ->inf = info;
     for(aux=l;posi>1;aux=aux->next,posi--);
     novo->next=aux->next;
     aux->next=novo;
     l->inf++;
}

int recup(LISTA_ENC_NC l, int posi){
    if(posi <1 || posi > l->inf){
        printf("Erro. COnsulta invalida\n");
        exit(4);
    }
    for(;posi>0;posi--)
        l=l->next;
    return (l->inf);
}

void ret(LISTA_ENC_NC l, int posi){
    NODO *aux, *aux2;
    if(posi<1 || posi > l->inf){
        printf("Posicao invalida\n");
        exit(5);
    }
    for (aux=l;posi>1;posi--, aux=aux->next);
    aux2=aux->next;
    aux->next=aux2->next;
    free(aux2);
    l->inf--;
}

void destruir(LISTA_ENC_NC l){
    
    while (l) /*enquanto tem elementos na lista*/
    {
        free(l);
        l=l->next;
        
    }
}

void imprimir(LISTA_ENC_NC l){
    LISTA_ENC_NC aux;
    for(aux=l->next;aux!=NULL;aux=aux->next)
        printf("info: %d\n", aux->inf);
}

void writeToFile(LISTA_ENC_NC l)
{
    FILE * fptr;
    fptr = fopen("infos.txt", "w");
    LISTA_ENC_NC aux = l->next;

    if(fptr==NULL)
    {
        printf("Error\n");
    }

    else
    {
        while(aux!= NULL)
        {
            fprintf(fptr, "\nInfo: %d\n", aux->inf);
            aux= aux->next;
        }
    }

    fclose(fptr);
    }
