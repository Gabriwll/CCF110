#include <stdio.h>
#include <stdlib.h>

#include "./financeiro.h"
#include "./clientes.h"

void depositarQuantia(int maxUsuario, int posicaoLoginUsuario, usuario *usuarios, float deposito){
    FILE *arquivoSaldo = NULL;

    usuarios[posicaoLoginUsuario].capital += deposito;
    
    if((arquivoSaldo = fopen("../Dados clientes/saldo.txt", "w")) == NULL){
        printf("Erro ao acessar a base de dados do saldo.\n");
    }

    for(int i = 0; i < maxUsuario; i++){
        if(usuarios[i].nome[0] == '\0'){
            break;
        }

        fprintf(arquivoSaldo, "%.2f\n", usuarios[i].capital);
    }

    fclose(arquivoSaldo);
}
/*Atenção ao utilizar essa função,
* a struct com os dados dos clientes já deve estar preenchida.
* Caso isso não aconteça o capital de todos os clientes será perdido.
*/

void sacarQuantia(int maxUsuario, int posicaoLoginUsuario, usuario *usuarios, float saque){
    FILE *arquivoSaldo = NULL;

    if((usuarios[posicaoLoginUsuario].capital - saque) >= 0){
        usuarios[posicaoLoginUsuario].capital -= saque;
    }else{
        printf("Saldo insuficiente.\n");

       return;
    }
    
    if((arquivoSaldo = fopen("../Dados clientes/saldo.txt", "w")) == NULL){
        printf("Erro ao acessar a base de dados do saldo.\n");
    }

    for(int i = 0; i < maxUsuario; i++){
        if(usuarios[i].nome[0] == '\0'){
            break;
        }

        fprintf(arquivoSaldo, "%.2f\n", usuarios[i].capital);
    }

    fclose(arquivoSaldo);
}
/*Atenção ao utilizar essa função,
* a struct com os dados dos clientes já deve estar preenchida.
* Caso isso não aconteça o capital de todos os clientes será perdido.
*/

float investir(int risco, int tempo, float rendimento, float capital){
    float saldo = 0;

    if(risco == 0){
        saldo = (capital * pow(rendimento / 100, (tempo-1))); //dessa forma, teremos o valor final, apenas

    }else{
        for(int i = 0; i < tempo; i++){
            if((rand() % 1) == 0){
                saldo += (capital * ((rand() % risco) / 100));

            }else{
                saldo -= (capital * ((rand() % risco / 100)));
                
            }
        }
    }

    return saldo;
}