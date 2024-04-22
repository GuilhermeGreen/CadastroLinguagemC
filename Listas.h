      #include<stdio.h>
      #include<stdlib.h>
      #include "EstruturaDados.h"



         //Protótipos das funções

         // Função para criar uma lista encadeada vazia
         Lista* criaLista();

         // Função para liberar a memória alocada para a lista encadeada
         void libera_Lista(Lista* li);

         //Função que verifica se a lista está cheia
         int lista_cheia(Lista* li);

         //Função que verifica se a lista está vazia
         int lista_vazia(Lista* li);

