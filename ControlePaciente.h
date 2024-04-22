         #include <stdbool.h>
         #include <stdio.h>
         #include<locale.h> // impressão de texto formatado corretamente em português
         #include "Listas.h"

         //Função insere cadastro na lista
         int insere_Paciente(Lista* li, struct dengue caso);

         //Função remove cadastro da lista por CPF
         int remove_cadastro(Lista* li, int cpf,char *caminho);

         //Função para editar dados do cadastro do paciente
         void editar_paciente(Lista *li, char *cpf,char *caminho);

         //Função para preenchimento dos dados para cadastro
         void solicitar_dados_paciente(Lista *li,struct dengue *paciente);

         //Função que recebe os dados para edição, sem a busca pelo CPF
         void editar_dados(Lista *li,struct dengue *paciente);
