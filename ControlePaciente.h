         #include <stdbool.h>
         #include <stdio.h>
         #include<locale.h> // impress�o de texto formatado corretamente em portugu�s
         #include "Listas.h"

         //Fun��o insere cadastro na lista
         int insere_Paciente(Lista* li, struct dengue caso);

         //Fun��o remove cadastro da lista por CPF
         int remove_cadastro(Lista* li, int cpf,char *caminho);

         //Fun��o para editar dados do cadastro do paciente
         void editar_paciente(Lista *li, char *cpf,char *caminho);

         //Fun��o para preenchimento dos dados para cadastro
         void solicitar_dados_paciente(Lista *li,struct dengue *paciente);

         //Fun��o que recebe os dados para edi��o, sem a busca pelo CPF
         void editar_dados(Lista *li,struct dengue *paciente);
