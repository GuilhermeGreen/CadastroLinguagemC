      #include<stdio.h>
      #include "Listas.h"
      #include "EstruturaDados.h"
      #include<locale.h>

       //Função usado para listar todos os pacientes da lista
       void menu();

       // Função que exibe os dados do paciente pelo número do CPF
       void exibir_paciente_cpf(struct dengue *paciente);

       //Função usado para listar todos os pacientes da lista
       void imprimir_dados_paciente(struct dengue *paciente);

       // Função que percorre a lista e exibe os dados de cada paciente
       void exibir_lista(Lista *li);

       //Função que limpa a tela
       void limpaConsole();

