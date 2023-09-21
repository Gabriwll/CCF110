#include <string.h>
#include <math.h>

int main(){
    //cadastro do cleinte
    int opcao;
    int num_clientes = 0;
    char nome_cliente[100][50];
    int idade_cliente[100];

    while(1){
        printf("\n MENU DE CADASTRO DE CLIENTES\n");
        printf("1. Cadastrar clientes\n");
        printf("2. Listar clientes\n");
        printf("3. Mostrar Aplicaçoes por clientes\n");
        printf("4. Sair\n");
        printf(" Escolha uma opção\n");
        scanf("%d", &opcao);


    switch(opcao) {
        case 1:
            if(num_clientes < 100 ){
            printf("Informe o nome do cliente: ");
            scanf("%s", nome_cliente[num_clientes]);
            printf("\n");
            printf("Informe a idade do cliente: ");
            scanf("%d",&idade_cliente[num_clientes]);
            num_clientes++;
            printf("Clientes cadastrado com sucesso!\n");
            }
            else{
                printf("Limite maximo de clientes atingido!\n");
            }
            break;
            

        case 2:
            printf("CLIENTES CADASTRADOS: \n");
            for(int i = 0; i < num_clientes; i++){
            printf("Nome: %s, Idade: %d\n" , nome_cliente[i], idade_cliente[i]);
            }
            printf("\nTotal de clientes: %d\n" , num_clientes);
            break;

        case 3:
            printf("em construção");
            break;

        case 4:
            printf("Saindo do programa.\n");
            return 0;
        
        default:
            printf("Invalido digite outra opçao.\n");
        

    }
    
    
    
    }

 
    return 0;
}