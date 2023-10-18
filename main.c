#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100

int main(){
    //cadastro do cleinte
    int opcao;
    int numClientes = 0;
    int cliente, tempo;
    char nomeCliente[MAX_CLIENTES][50];
    int idadeCliente[MAX_CLIENTES];
    float capitalInical[MAX_CLIENTES], rendimento[MAX_CLIENTES];

    while(1){
        printf("\n MENU DE CADASTRO DE CLIENTES\n");
        printf("1. Cadastrar clientes;\n");
        printf("2. Listar clientes;\n");
        printf("3. Mostrar Aplicaçoes por clientes;\n");
        printf("4. Realizar um investimento;\n");
        printf("5. Sair.\n");
        printf(" Escolha uma opcao\n");
        scanf("%d", &opcao);


    switch(opcao) {
        case 1:
            //cadastrar clientes

            if(numClientes <= MAX_CLIENTES){
            printf("Informe o nome do cliente: ");
            scanf("%s", nomeCliente[numClientes]);
            printf("\n");
            printf("Informe a idade do cliente: ");
            scanf("%d",&idadeCliente[numClientes]);
            numClientes++;
            printf("Clientes cadastrado com sucesso!\n");
            }
            else{
                printf("Limite maximo de clientes atingido!\n");
            }
            break;
            

        case 2:
            //listar clientes

            printf("CLIENTES CADASTRADOS: \n");
            for(int i = 0; i < numClientes; i++){
            printf("Id: %d Nome: %s, Idade: %d\n" , (i + 1), nomeCliente[i], idadeCliente[i]);
            }

            printf("\nTotal de clientes: %d\n" , numClientes);
            break;

        case 3:
            //mostrar aplicações por clientes

            for(int i = 0; i <= numClientes; i++){
                printf("%d | %s: %.2f\n", (i + 1), nomeCliente[i], rendimento[i]);
            }
            
            break;

        case 4:
            //realizar um investimento

                if(numClientes > 0){
                    
                    printf(" MENU DE INVESTIMENTO!\n");
                    printf("Selecione o cliente (id): \n");
                    scanf("%d", &cliente);

                    cliente--;

                    printf("Bem-vindo %s\n", nomeCliente[cliente]);
                    printf("\nInsira um capital inicial: \n");
                    scanf("%f", &capitalInical[cliente]);

                    printf("Defina o tempo de rendimento: \n");
                    scanf("%d", &tempo);

                    rendimento[cliente] = capitalInical[cliente];

                    for(int i = 0; i < tempo; i++){
                        rendimento[cliente] = (((capitalInical[cliente]) * 0.01) + rendimento[cliente]);
                    }

                    printf("Valor final: R$ %.2f", rendimento[cliente]);

                }else{
                    printf("Cadastre um cliente primeiro.\n");
                }
                

            break;

        case 5:
            //sair

            printf("Saindo do programa.\n");
            return 0;

            break;
        
        default:
            //exceções

            printf("Invalido digite outra opçao.\n");

            break;
        

    }
    
    }

    return 0;
}