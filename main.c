#include <stdio.h>
#include <string.h>

/*Tipo de execução define se o sistema executará em um dos modos a seguir:
* Usuário comum == 1:
* - Acesso a cadastro, login e investimentos.
* 
* Usuário administrador == 0:
* - Acesso a edição de investimentos disponíveis.
*/
#define TIPO_EXECUCAO 1

/*
Fazer um arquivo para essa funcionalidade talvez seria melhor, uma vez que o usuário alteraria o valor sem
precisar abrir o código fonte
*/

/*Quantidade máxima de usuários a serem registrados no sistema.
* 
* Essa constante deverá ser substituida futuramente por um sistema de alocação dinâmica
*/
#define MAX_USUARIO 50

struct usuario{
    char nome[30];
    char senha[8]; //o ideal seria ter essa senha criptografada
    char cpf[11];
    int idade; //o ideal seria utilizar a data de nascimento para atualizar a idade de forma dinâmica
};

int main(){
    FILE *arquivoClientes = NULL;

    struct usuario usuarios[MAX_USUARIO];
    char nomeAux[30], senhaAux[8];
    char cadastroCliente;

    int flag;

    for(int i = 0; i < MAX_USUARIO; i++){
        usuarios[i].nome[0] = '\0';
    }

    if((arquivoClientes = fopen("../Dados cadastrais/clientes.txt", "r")) == NULL){
        printf("Erro ao acessar a base de dados de cadastro (R).\n");

        return 1;
    }

    for(int i = 0; i < MAX_USUARIO; i++){
        if(fscanf(arquivoClientes, "%s;%s;%d;%s;\n", &usuarios[i].nome, &usuarios[i].cpf, &usuarios[i].idade, &usuarios[i].senha) == EOF){
            break;
        }
        printf("Usuario %d:\n%s\n%s\n%d\n%s\n", (i + 1), usuarios[i].nome, usuarios[i].cpf, usuarios[i].idade, usuarios[i].senha);
    }

    fclose(arquivoClientes);

    if(TIPO_EXECUCAO == 1){
        printf("Deseja fazer o login ou se cadastrar? ('L' = Login e 'C' = Cadastrar)\n");
        scanf(" %c", &cadastroCliente);

        switch(cadastroCliente){    //substituir futuramente por um sistema único que busca nos arquivos um usuário e caso não encontre pergunte se deseja cadastrar um novo cliente
            case 'L':
                flag = 1;

                while (flag != 0){
                    puts("Digite o seu nome:");
                    scanf(" %s", &nomeAux);

                    for(int i = 0; i < MAX_USUARIO; i++){
                        if(nomeAux == usuarios[i].nome){
                            puts("Digite a sua senha:");
                            scanf(" %s", &senhaAux);

                            if(senhaAux != usuarios[i].senha){
                                puts("Senha incorreta. Tente novamente.");
                                flag = 1;

                                break;
                            }

                            flag = 0;

                            break;
                        }else if(usuarios[i].nome[0] == '\0'){
                            printf("Usuario nao encontrado no sistema.\n Tente novamente.\n");
                            flag = 1;
                            
                            break;
                        }
                    }
                }

                break;

            case 'C':
                if((arquivoClientes = fopen("../Dados cadastrais/clientes.txt", "a")) == NULL){
                    printf("Erro ao acessar a base de dados de cadastro (A).\n");

                    return 1;
                }
                
                //Para que o bloco a seguir funcione, os dados do arquivo devem preencher a struct a partir da linha 27

                flag = 1;

                while(flag != 0){
                    puts("Cadastro:\n");
                    printf("Digite o seu nome:\n");
                
                    scanf("%s", &nomeAux);

                    for(int i = 0; i < MAX_USUARIO; i++){
                        if(usuarios[i].nome == nomeAux){
                            printf("Usuario ja cadastrado, tente novamente.");

                            break;
                        } else if(usuarios[i].nome[0] == '\0'){
                            strcpy(usuarios[i].nome, nomeAux);
                            fprintf(arquivoClientes, "%s;", usuarios[i].nome);

                            puts("Digite o seu cpf:");  //Verificar a validez do cpf
                            scanf("%s", &usuarios[i].cpf);
                            fprintf(arquivoClientes, "%s;", usuarios[i].cpf);

                            puts("Digite a sua idade:");
                            scanf("%d", &usuarios[i].idade);
                            fprintf(arquivoClientes, "%d;", usuarios[i].idade);
                            
                            puts("Digite a sua senha:"); //Verificar a validez da senha
                            scanf("%s", &usuarios[i].senha);
                            fprintf(arquivoClientes, "%s;\n", usuarios[i].senha);

                            flag = 0;
                            break;
                        }
                    }
                }
                

                
                fclose(arquivoClientes);

                break;

            default:
                printf("Entrada inválida.");

                return 1;
        }
    }

    return 0;
}