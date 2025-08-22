#include <stdio.h>

// Troca e impressão
void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void imprime_int(const int *v, int n, const char *titulo) {
    printf("%s [", titulo);
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? ", " : ""));
    }
    printf("]\n");
}

// Bubble Sort (ordem decrescente)
void bubble_desc(int *v, int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        for (int i = 0; i < n - 1 - pass; i++) {
            if (v[i] < v[i + 1]) {  // Troca se v[i] for menor que v[i+1]
                swap_int(&v[i], &v[i + 1]);
            }
        }
    }
}

// Insertion Sort (ordem decrescente)
void insertion_desc(int *v, int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] < chave) {  
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

// Selection Sort (ordem decrescente)
void selection_desc(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx_max = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] > v[idx_max]) {
                idx_max = j;
            }
        }
        if (idx_max != i) {
            swap_int(&v[i], &v[idx_max]);
        }
    }
}

int main() {
    // Pontuações dos jogadores
    int pontuacoes[] = {1200, 3000, 1500, 2500, 1800, 2100, 5000, 2200, 1000, 1900, 4500, 1600};
    int n = sizeof(pontuacoes) / sizeof(pontuacoes[0]);
    
    // Exibe lista original
    imprime_int(pontuacoes, n, "Pontuacoes (original)");

    // Ordenando com Bubble Sort
    int pontuacoes_bubble[12];
    for (int i = 0; i < n; i++) pontuacoes_bubble[i] = pontuacoes[i];
    bubble_desc(pontuacoes_bubble, n);
    imprime_int(pontuacoes_bubble, n, "Bubble Sort (decrescente)");

    // Ordenando com Insertion Sort
    int pontuacoes_insertion[12];
    for (int i = 0; i < n; i++) pontuacoes_insertion[i] = pontuacoes[i];
    insertion_desc(pontuacoes_insertion, n);
    imprime_int(pontuacoes_insertion, n, "Insertion Sort (decrescente)");

    // Ordenando com Selection Sort
    int pontuacoes_selection[12];
    for (int i = 0; i < n; i++) pontuacoes_selection[i] = pontuacoes[i];
    selection_desc(pontuacoes_selection, n);
    imprime_int(pontuacoes_selection, n, "Selection Sort (decrescente)");

    // Encontrar maior pontuação
    int maior_pontuacao = pontuacoes[0];
    int posicao = 0;
    for (int i = 1; i < n; i++) {
        if (pontuacoes[i] > maior_pontuacao) {
            maior_pontuacao = pontuacoes[i];
            posicao = i;
        }
    }

    printf("Jogador com maior pontuacao: %d (Posicao %d)\n", maior_pontuacao, posicao + 1);
    return 0;
}
