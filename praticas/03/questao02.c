#include <stdio.h>
#include <string.h>

typedef struct {
    char placa[8];
    char modelo[20];
    int ano;
} Veiculo;

Veiculo veiculos[150];
int tamanho = 0; // Veículos cadastrados

void menu();
void registrarVeiculo();
void listarveiculos();
void buscarVeiculo();
void removerVeiculo();
void formatarPlaca(char placa[]);

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
            registrarVeiculo();
            break;
        
        case 2:
            listarveiculos();
            break;

        case 3:
            buscarVeiculo();
            break;

        case 4:
            removerVeiculo();
            break;

        case 0:
            return;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);
}

void registrarVeiculo() {
    scanf("%s %s %d", veiculos[tamanho].placa, veiculos[tamanho].modelo, &veiculos[tamanho].ano);

    formatarPlaca(veiculos[tamanho].placa);

    if (tamanho >= 150) {
        printf("Limite de veículos atingido\n");
        return;
    }

    // Verifica placas iguais
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(veiculos[i].placa, veiculos[i + 1].placa) == 0) {
            return;
        }
    }

    tamanho++;
}

void listarveiculos() {
    for (int i = 0; i < tamanho; i++)
        printf("%s %s %d\n", veiculos[i].placa, veiculos[i].modelo, veiculos[i].ano);
}

void buscarVeiculo() {
    char placa[7];

    scanf("%s", placa);
    formatarPlaca(placa);

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(veiculos[i].placa, placa) == 0) {
            printf("%s %s %d\n", veiculos[i].placa, veiculos[i].modelo, veiculos[i].ano);
            return;
        }
    }
}

void removerVeiculo() {
    char placa[7];

    scanf("%s", placa);
    formatarPlaca(placa);

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(veiculos[i].placa, placa) == 0) {
            for (int j = i; j < tamanho - 1; j++) {
                veiculos[j] = veiculos[j + 1];
            }

            printf("Veículo removido\n");
            tamanho--;
            return;
        }
    }
}

// Converte placa para maiúsculo
void formatarPlaca(char placa[]) {
    for (int i = 0; i < strlen(placa); i++) {
        if (placa[i] >= 'a' && placa[i] <= 'z')
            placa[i] -= 32;
    }
}
