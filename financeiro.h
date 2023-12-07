typedef struct investimento{
    int risco;        //medida comparativa, 0 é um investimento livre de perca
    float rendimento; //será dado em %
    int tempoMin;
    int tempoMax;
}investimento;

void depositarQuantia(int maxUsuario, int posicaoLoginUsuario, usuario *usuarios, float deposito);
void sacarQuantia(int maxUsuario, int posicaoLoginUsuario, usuario *usuarios, float saque);
float investir(int risco, int tempo, float rendimento, float capital);