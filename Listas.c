
        #include "Listas.h"

         // Função para criar uma lista encadeada vazia
         Lista* criaLista(){
         Lista* li = (Lista*) malloc(sizeof(Lista));// Aloca memória para a cabeça da lista
         if(li!=NULL)
            *li = NULL;// Inicializa a lista como vazia
         return li;
         }

            // Função para liberar a memória alocada para a lista encadeada
            void libera_Lista(Lista* li){
            if(li!= NULL){
            Item* no;
                // Percorre a lista e libera a memória de cada nó
                while((*li)!= NULL){
                    no = *li;
                    *li = (*li) -> prox;
                    free(no); // Libera a memória da cabeça da lista
                }
                free(li);
            }
         }

          //Função que verifica se a lista está cheia
          int lista_cheia(Lista* li){
             return 0;
          }

           //Função que verifica se a lista está vazia
          int lista_vazia(Lista* li){
            if(li == NULL)
                return 1;
            if(*li == NULL)
                return 1;
             return 0;

          }
