#include <stdio.h>
#include <string.h>

#include "./clientes.h"

int loginUsuario(int maxUsuario, usuario *usuarios){

    int posicaoLoginUsuario = -1;
    char nomeAux[30];
    char senhaAux[8];

    while(posicaoLoginUsuario == -1){
        puts("Digite o seu nome:");
        scanf(" %s", nomeAux);

        for(int i = 0; i < maxUsuario; i++){
            if(strcmp(nomeAux, usuarios[i].nome) == 0){

                puts("Digite a sua senha:");
                scanf(" %s", senhaAux);

                if(strcmp(senhaAux, usuarios[i].senha) != 0){
                    puts("Senha incorreta. Tente novamente.");
                    posicaoLoginUsuario = -1;

                    break;
                }

                posicaoLoginUsuario = i;

                break;
            }else if(usuarios[i].nome[0] == '\0'){
                printf("Usuario nao encontrado no sistema.\n Tente novamente.\n");
                posicaoLoginUsuario = -1;

                break;
            }
        }
    }

    return posicaoLoginUsuario;
}

int regristrarUsuario(int maxUsuario, usuario *usuarios){
    FILE *arquivoClientes = NULL;
    FILE *arquivoSaldo = NULL;
    
    char nomeAux[30];
    int posicaoLoginUsuario;

    int flag = 1;
    
    if((arquivoClientes = fopen("../Dados clientes/clientes.txt", "a")) == NULL){
        printf("Erro ao acessar a base de dados de cadastro (A).\n");

        return -1;
    }

    if((arquivoSaldo = fopen("../Dados clientes/saldo.txt", "a")) == NULL){
        printf("Erro ao acessar a base de dados de saldo de clientes.\n");

        return -1;
    }

    flag = 1;

    while(flag != 0){
        puts("Cadastro:\n");
        printf("Digite o seu nome:\n");

        scanf("%s", nomeAux);

        for(int i = 0; i < maxUsuario; i++){
            if(strcmp(nomeAux, usuarios[i].nome) == 0){
                printf("Usuario ja cadastrado, tente novamente.");

                break;
            }else if(usuarios[i].nome[0] == '\0'){
                strcpy(usuarios[i].nome, nomeAux);
                fprintf(arquivoClientes, "%s ", usuarios[i].nome);

                puts("Digite o seu cpf:");  //Verificar a validez do cpf
                scanf("%s", usuarios[i].cpf);
                fprintf(arquivoClientes, "%s ", usuarios[i].cpf);

                puts("Digite a sua idade:");
                scanf("%d", &usuarios[i].idade);
                fprintf(arquivoClientes, "%d ", usuarios[i].idade);

                puts("Digite a sua senha:"); //Verificar a validez da senha
                scanf("%s", usuarios[i].senha);
                fprintf(arquivoClientes, "%s\n", usuarios[i].senha);

                usuarios[i].capital = 0.0;
                fprintf(arquivoSaldo, "%.2f\n", usuarios[i].capital);

                posicaoLoginUsuario = i;
                flag = 0;

                break;
            }
        }
    }

    fclose(arquivoClientes);
    fclose(arquivoSaldo);

    return posicaoLoginUsuario;
}