      #include<stdio.h>
      #include<stdlib.h>
      #include "EstruturaDados.h"



         //Prot�tipos das fun��es

         // Fun��o para criar uma lista encadeada vazia
         Lista* criaLista();

         // Fun��o para liberar a mem�ria alocada para a lista encadeada
         void libera_Lista(Lista* li);

         //Fun��o que verifica se a lista est� cheia
         int lista_cheia(Lista* li);

         //Fun��o que verifica se a lista est� vazia
         int lista_vazia(Lista* li);

