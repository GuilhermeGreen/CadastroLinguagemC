      #include<stdio.h>
      #include "Listas.h"
      #include "EstruturaDados.h"
      #include<locale.h>

       //Fun��o usado para listar todos os pacientes da lista
       void menu();

       // Fun��o que exibe os dados do paciente pelo n�mero do CPF
       void exibir_paciente_cpf(struct dengue *paciente);

       //Fun��o usado para listar todos os pacientes da lista
       void imprimir_dados_paciente(struct dengue *paciente);

       // Fun��o que percorre a lista e exibe os dados de cada paciente
       void exibir_lista(Lista *li);

       //Fun��o que limpa a tela
       void limpaConsole();

