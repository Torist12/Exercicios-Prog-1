/*
Feito Por: William Daudt Penna
Compilador: GCC
feito no Linux: NixOS
OBS: Compilar via GCC ou MinGW (Dev-C++)

Crie um programa em C que tenha as seguintes funcionalidades::
a) Calcule o enésimo termo de uma P.A.:
b) Calcule a soma de n termos de uma P.A.:
c) interpole k números em uma P.A.:
d) Gere uma P.A. de segunda ordem a partir de uma sequência de 8 termos. Use um vetor para
armazenas a sequência original.
O programa deve ter um menu onde o usuário escolha o que quer fazer. O programa poderá ter
funções para cada funcionalidade. Envie o arquivo .c no AVA.
*/

#include <stdio.h>

#define MAX_TERMOS 8

/* Protótipos de todas as funções */
float calcularTermo(float a1, float r, int n);
float calcularSoma(float a1, float r, int n);
void calcularTermoPA(void);    
void calcularSomaPA(void);       
void interpolarTermos(void);
void gerarPA2Ordem(void);
void exibirMenu(void);
void limparBuffer(void); // Limpeza de buffer

int main() {
    int opcao;
    
    do {
        exibirMenu();
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
    limparBuffer();
    opcao = -1;   // Faz cair no 1 do switch
}
        
        switch(opcao) {
            case 1:
                calcularTermoPA();
                break;
            case 2:
                calcularSomaPA();
                break;
            case 3:
                interpolarTermos();
                break;
            case 4:
                gerarPA2Ordem();
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
        printf("\n");
    } while(opcao != 0);
    
    return 0;
}

/* ==================== MENU ==================== */
void exibirMenu() {
    printf("\n==================================\n");
    printf("    PROGRESSAO ARITMETICA (P.A.)\n");
    printf("==================================\n");
    printf("1 - Calcular o enesimo termo\n");
    printf("2 - Calcular a soma de n termos\n");
    printf("3 - Interpolar k numeros\n");
    printf("4 - Gerar P.A. de 2a ordem\n");
    printf("0 - Sair\n");
    printf("==================================\n");
}

/* Calcula o enésimo termo de uma P.A */
float calcularTermo(float a1, float r, int n) {
    return a1 + (n - 1) * r; // Formula do enésimo termo da P.A
}

void calcularTermoPA() {
    float a1, r, an;
    int n;
    
    printf("\n--- CALCULAR ENESIMO TERMO ---\n");
    printf("Digite o primeiro termo (a1): ");
    scanf("%f", &a1);
    printf("Digite a razao (r): ");
    scanf("%f", &r);
    printf("Digite a posicao do termo (n): ");
    scanf("%d", &n);

    if (n <= 0) {
    printf("\nErro: a posicao/quantidade de termos deve ser maior que zero, Tente de novo!\n");
    return; // Verifica se N é igual a 0
}
    
    an = calcularTermo(a1, r, n);
    printf("\nO %d o termo da P.A. e: %.2f\n", n, an);
}

/* Calcula a soma de n termos de uma P.A */
float calcularSoma(float a1, float r, int n) {
    float an = a1 + (n - 1) * r;
    return (n * (a1 + an)) / 2.0; //formula da soma de P.A
}

void calcularSomaPA() {
    float a1, r, soma;
    int n;
    
    printf("\n--- CALCULAR SOMA DE N TERMOS ---\n");
    printf("Digite o primeiro termo (a1): ");
    scanf("%f", &a1);
    printf("Digite a razao (r): ");
    scanf("%f", &r);
    printf("Digite a quantidade de termos (n): ");
    scanf("%d", &n);

    if (n <= 0) {
    printf("\nErro: a posicao/quantidade de termos deve ser maior que zero, Tente de novo!\n");
    return; // Verifica se N é igual a 0
}
    
    soma = calcularSoma(a1, r, n);
    printf("\nA soma dos %d primeiros termos e: %.2f\n", n, soma);
}

/* interpole k números em uma P.A.*/
void interpolarTermos() {
    float a1, an, razao, termo;
    int k, totalTermos, i;
    
    printf("\n--- INTERPOLACAO DE K TERMOS ---\n");
    printf("Digite o primeiro termo (a1): ");
    scanf("%f", &a1);
    printf("Digite o ultimo termo (an): ");
    scanf("%f", &an);
    printf("Digite quantos termos deseja interpolar (k): ");
    scanf("%d", &k);

    if (a1 == an) {
    printf("\nAviso: os extremos sao iguais, a razao sera zero.\n");
} // Avisa que a razão vai ser 0
    
    if(k <= 0) {
        printf("\nErro: k deve ser maior que zero, Tente de novo!\n");
        return; // Verifica se K é igual a 0
    }
    
    totalTermos = k + 2;
    razao = (an - a1) / (k + 1); // Formula para calcular a razão da P.A. com k termos
    
    printf("\nRazao encontrada: %.2f\n", razao);
    printf("P.A. com %d termos:\n", totalTermos);
    
    for(i = 1; i <= totalTermos; i++) {
        termo = a1 + (i - 1) * razao; // Formula do enésimo termo da P.A.
        printf("%.2f", termo);
        if(i < totalTermos) printf(" -> ");
    }
    printf("\n");
}

/* Gera uma P.A. de segunda ordem a partir de uma sequência de 8 termos */
void gerarPA2Ordem() {
    float sequencia[MAX_TERMOS];
    float dif1[MAX_TERMOS - 1];
    float dif2[MAX_TERMOS - 2];
    int i, extras;
    float constante, ultimaDif1, proximoTermo;
    
    printf("\n--- GERAR P.A. DE 2A ORDEM ---\n");
    printf("Digite os %d termos da sequencia:\n", MAX_TERMOS);
    
    for(i = 0; i < MAX_TERMOS; i++) {
        printf("Termo %d: ", i+1);
        scanf("%f", &sequencia[i]);
    }
    
    // Primeira diferença
    for(i = 0; i < MAX_TERMOS - 1; i++) {
        dif1[i] = sequencia[i+1] - sequencia[i];
    }
    
    // Segunda diferença
    for(i = 0; i < MAX_TERMOS - 2; i++) {
        dif2[i] = dif1[i+1] - dif1[i];
    }
    
    printf("\nSequencia original: ");
    for(i = 0; i < MAX_TERMOS; i++) printf("%.2f ", sequencia[i]);
    printf("\n");
    
    printf("Primeira diferenca: ");
    for(i = 0; i < MAX_TERMOS - 1; i++) printf("%.2f ", dif1[i]);
    printf("\n");
    
    printf("Segunda diferenca: ");
    for(i = 0; i < MAX_TERMOS - 2; i++) printf("%.2f ", dif2[i]);
    printf("\n");
    
    // Verifica se é P.A. de 2ª ordem
    constante = dif2[0];
    for(i = 1; i < MAX_TERMOS - 2; i++) {
        if(dif2[i] != constante) {
            printf("\nATENCAO: As segundas diferencas nao sao constantes!\n");
            printf("A sequencia NAO e uma P.A. de 2a ordem.\n");
            return;
        }
    }
    
    printf("\nA sequencia e uma P.A. de 2a ordem valida!");
    printf("\nConstante da segunda diferenca: %.2f\n", constante);
    
    printf("\nQuantos termos extras deseja gerar? ");
    scanf("%d", &extras);
    
    if(extras <= 0) {
        printf("\nNenhum termo extra gerado.\n");
        return;
    }
    
    ultimaDif1 = dif1[MAX_TERMOS - 2];
    proximoTermo = sequencia[MAX_TERMOS - 1];
    
printf("\nNovos termos gerados:\n");
for(i = 0; i < extras; i++) {
    ultimaDif1 += constante;
    proximoTermo += ultimaDif1;
    printf("  Termo %d: %.2f\n", MAX_TERMOS + i + 1, proximoTermo);
}
    printf("\n");
}

/* Limpa o buffer de entrada */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}