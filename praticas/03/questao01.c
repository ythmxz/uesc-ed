#include <stdio.h>

typedef struct {
    int intervaloInicio;
    int intervaloFim;
} Intervalo;

Intervalo intervalos[10];
int tamanho = 0; // Intervalos cadastrados

void menu();
void adicionarIntervalo();
void verificarPonto();

int main() {
    menu();
    return 0;
}

void menu() {
    int opcao = 0;

    do {
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            adicionarIntervalo();
            break;
        
        case 2:
            verificarPonto();
            break;

        case 0:
            return;

        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (opcao != 0);
}

void adicionarIntervalo() {
    scanf("%d %d", &intervalos[tamanho].intervaloInicio, &intervalos[tamanho].intervaloFim);
    
    // Troca se inicio for maior que fim
    if (intervalos[tamanho].intervaloInicio > intervalos[tamanho].intervaloFim) {
        int aux = intervalos[tamanho].intervaloInicio;
        intervalos[tamanho].intervaloInicio = intervalos[tamanho].intervaloFim;
        intervalos[tamanho].intervaloFim = aux;
    }

    // Verifica intervalos iguais
    for (int i = 0; i < tamanho; i++) {
        if (intervalos[i].intervaloInicio == intervalos[i + 1].intervaloInicio && intervalos[i].intervaloFim == intervalos[i + 1].intervaloFim) {
            printf("Intervalo já existe\n");
            return;
        }
    }

    tamanho++;
}

void verificarPonto() {
    int ponto = 0;
    int achou = 0;

    scanf("%d", &ponto);

    for (int i = 0; i < tamanho; i++) {
        if (ponto >= intervalos[i].intervaloInicio && ponto <= intervalos[i].intervaloFim) {
            achou++;
            printf("Dentro do intervalo [%d, %d]\n",intervalos[i].intervaloInicio, intervalos[i].intervaloFim);
        }
    }

    if (!achou)
        printf("Fora de todos os intervalos\n");
}
