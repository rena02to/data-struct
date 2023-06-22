#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//implememta a estrutura de no de forma que em cada no esteja armazenada informacao e um ponteiro para o proximo no da lista
typedef struct NO{
    int info;
    struct NO *next;
}NO;

//funcao que implementa o ponteiro do proximo no da lista como NULL
void point(NO **new)
{
    (*new) -> next = NULL;
}

//funcao para inserir no no final da lista
void insert_finish(NO **new, int *size)
{
    int value = 0;
    NO *x;
    NO *aux;

    printf("Digite o valor a ser inserido: ");
    scanf("%d", &value);

    x = (NO *)malloc(sizeof(NO));
    x -> info = value;
    x -> next = NULL;

    if((*new) -> next == NULL){
        (*new) -> next = x;
    }else{
        aux = (*new) -> next;

        while(aux -> next != NULL){
            aux = aux -> next;
        }
        aux -> next = x;
    }

    *size = *size + 1;
}

//funcao para inserir no no inicio da lista
void insert_start(NO **new, int *size)
{
    int value;
    NO *x;
    x = (NO *)malloc(sizeof(NO));
    
    printf("\nDigite o valor a ser inserido: ");
    scanf("%d", &value);

    x -> info = value;
    x -> next = (*new) -> next;
    (*new) -> next = x;
    *size = *size + 1;
}

//funcao para remover o ultimo elemento da lista
void remove_finish(NO **new, int *size)
{
    NO *x, *y;
    int assistant;
    x = (*new) -> next;

    if((*new) -> next != NULL){
        if(*size == 1){
            (*new) -> next = NULL;
            free(x);
        }else{
            while(x -> next != NULL){
                assistant = x -> info;
                x = x -> next;
            }

            x = (*new) -> next;
            while(x -> info != assistant)
            {
                x = x -> next;
            }
            y = x -> next;
            x -> next = NULL;
            free(y);
            *size = *size - 1;
        }
    }
}

//funcao para remover o primeiro elemento da lista
void remove_start(NO **new, int *size)
{
    NO *x;
    x = (*new) -> next;

    if((*new) -> next != NULL){
        (*new) -> next = x -> next;
        free(x);
        *size = *size - 1;
    }

}

//funcao para remover o no de uma posicao especifica
void remove_specific(NO **new, int *size)
{
    NO *x, *y;
    int assistant = 0, dado = 0;
    x = (*new) -> next;

    if((*new) -> next != NULL){
        printf("Digite o elemento que deseja remover: ");
        scanf("%d", &dado);
        printf("\n");

        for(int i = 0; i <= *size; i++){
            if(i == *size){
                printf("\nELEMENTO NAO ENCONTRADO!\n");
                break;
            }else{
                if(dado == x -> info){
                    if(*size == 1){
                        (*new) -> next = NULL;
                        free(x);
                    }else{
                        y = (*new) -> next;
                        while(y -> info != assistant)
                        {
                            y = y -> next;
                        }
                        y -> next = x -> next;
                        free(x);
                        *size = *size - 1;
                    }
                    
                    break;
                }
            }
            assistant = x -> info;
            x = x -> next;
        }
    }
}

//funcao para inserir no em uma posicao especifica na lista
void insert_specific(NO **new, int *size)
{
    int element = 0, among = 0;
    NO *x, *y, *z;
    x = (*new) -> next;

    if((*new) -> next != NULL){
        printf("Digite apos qual elemento voce quer inserir o novo: ");
        scanf("%d", &among);
        printf("Agora digite o elemento que voce quer inserir: ");
        scanf("%d", &element);
        printf("\n");

        for(int i = 0; i <= *size; i++){
            if(i == *size){
                printf("\nELEMENTO NAO ENCONTRADO!\n");
            }else{
                if(x -> info == among){
                    y = (NO *)malloc(sizeof(NO));
                    y -> info = element;
                    y -> next = x -> next;
                    x -> next = y;
                    *size = *size + 1;
                    break;
                }
            }
            x = x -> next;
        }
    }
}

//funcao para printar a arvore
void print(NO **new, int *size)
{
    NO *x;
    x = (NO *)malloc(sizeof(NO));
    x = (*new) -> next;
    
    if(x == NULL){
        printf("\nLISTA VAZIA!\n");
    }else{
        printf("\nSua lista tem tamanho %d e é a seguinte: ", *size);

        printf("[ ");
        while(x != NULL)
        {
            printf("%d ", x -> info);
            x = x -> next;
        }printf("]");
    }
}

int main()
{
    int size = 0, amount = 0, option = 13, element = 0;
    
    //declara ponteiros para a estrutura no
    NO *list;
    NO *z;

    //aloca o espaco de memoria necessario para p no e armazena na variavel list o endereco para o local de memoria alocada
    list = malloc(sizeof(NO));

    //similar a linha anterior, porem converte o valor do endereco de memoria para uma variavel do tipo no
    z = (NO *)malloc(sizeof(NO));
    
    //chama a funcao que define o ponteiro do proximo elemento da lista encadeada como NULL
    point(&list);

    if(z == NULL){
        printf("\n\nMemoria nao alocada corretamente.\n");
        return 0;
    }else{
        printf("\n\nDigite a quantidade de elementos de sua lista: ");
        scanf("%d", &amount);

        //vai inserindo os elementos um apos o outro
        for(int i = 0; i < amount; i++)
        {
            insert_finish(&list, &size);
        }
        print(&list, &size);

        while(option != 0)
        {
            printf("\n\nDIGITE UMA OPCAO:\n   1 - Inserir no inicio\n   2 - Inserir no fim\n   3 - Inserir em uma posicao especifica\n   4 - Remover ultimo elemento\n   5 - Remover primeiro elemento\n   6 - Remover um elemento especifico\n   0 - Encerrar\n      Opcao: ");
            scanf("%d", &option);
            printf("\n");

            if(option == 1){
                insert_start(&list, &size);
                print(&list, &size);
            }else if(option == 2){
                insert_finish(&list, &size);
                print(&list, &size);
            }else if(option == 3){
                insert_specific(&list, &size);
                print(&list, &size);
            }else if(option == 4){
                remove_finish(&list, &size);
                print(&list, &size);
            }else if(option == 5){
                remove_start(&list, &size);
                print(&list, &size);
            }else if(option == 6){
                remove_specific(&list, &size);
                print(&list, &size);
            }else if(option == 0){
                printf("\n--------------------\nPROGRAMA ENCERRADO!\n--------------------\n\n");
            }else{
                printf("\nOpcao invalida!\n");
            }
        }
    }
}