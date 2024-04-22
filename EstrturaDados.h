            // #include "Listas.h"

            // struct.h
            #ifndef STRUCT_H
            #define STRUCT_H

           //Estrutura que define os dados do paciente
            struct dengue {
            char cpf[13];
            char nome[50];
            int idade;
            char cidade[20];
            char bairro[50];
            char rua[50];
            int numero_casa;
            char data_diagnostico[20];
            char data_inicio_sintomas[20];
            char hospital_tratamento[50];
            char tipo_dengue[20];
            char sintomas[200];
        };

          typedef struct item {  //estrutura de dados para criar uma lista
          struct dengue dados;   // encadeada de pacientes com dengue
          struct item *prox;
         } Item;

         typedef Item* Lista; //cabeça da lista

            #endif
