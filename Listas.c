
        #include "Listas.h"

         // Fun��o para criar uma lista encadeada vazia
         Lista* criaLista(){
         Lista* li = (Lista*) malloc(sizeof(Lista));// Aloca mem�ria para a cabe�a da lista
         if(li!=NULL)
            *li = NULL;// Inicializa a lista como vazia
         return li;
         }

            // Fun��o para liberar a mem�ria alocada para a lista encadeada
            void libera_Lista(Lista* li){
            if(li!= NULL){
            Item* no;
                // Percorre a lista e libera a mem�ria de cada n�
                while((*li)!= NULL){
                    no = *li;
                    *li = (*li) -> prox;
                    free(no); // Libera a mem�ria da cabe�a da lista
                }
                free(li);
            }
         }

          //Fun��o que verifica se a lista est� cheia
          int lista_cheia(Lista* li){
             return 0;
          }

           //Fun��o que verifica se a lista est� vazia
          int lista_vazia(Lista* li){
            if(li == NULL)
                return 1;
            if(*li == NULL)
                return 1;
             return 0;

          }
