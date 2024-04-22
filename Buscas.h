    #include<stdio.h>
    #include<stdlib.h>
    #include<locale.h>
    #include<unistd.h>
    #include "Tela.h"
    #include "Listas.h"
    #include "EstruturaDados.h"

       //Fun��o que busca o CPF digitado na Lista
       int busca_lista_cpf(Lista* li, char* cpf, struct dengue *de);

       //Fun��o que busca paciente por bairro e diz a quantidade
       void exibir_pacientes_por_bairro(Lista *li, char *bairro);

      //Fun��o que busca paciente por cidade e diz a quantidade
       void exibir_pacientes_por_cidade(Lista *li, char *cidade);

      //Fun��o que busca paciente por hospital e diz a quantidade
       void exibir_pacientes_por_hospital (Lista *li, char *hospital);

