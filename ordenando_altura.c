#include <stdio.h>

#define TAM 10

void imprimirVetor(int vetor[]) {
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int bubbleSort(int vetor[]) {
    int trocas = 0;
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocas++;
            }
        }
    }
    return trocas;
}

int insertionSort(int vetor[]) {
    int trocas = 0;
    for (int i = 1; i < TAM; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
            trocas++;
        }
        vetor[j + 1] = chave;
    }
    return trocas;
}

int selectionSort(int vetor[]) {
    int trocas = 0;
    for (int i = 0; i < TAM - 1; i++) {
        int min = i;
        for (int j = i + 1; j < TAM; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = temp;
            trocas++;
        }
    }
    return trocas;
}

void copiarVetor(int origem[], int destino[]) {
    for (int i = 0; i < TAM; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int alturas[TAM] = {172, 158, 165, 180, 174, 160, 169, 155, 178, 162};
    int vetorBubble[TAM], vetorInsertion[TAM], vetorSelection[TAM];

    printf("Vetor original:\n");
    imprimirVetor(alturas);

    copiarVetor(alturas, vetorBubble);
    int trocasBubble = bubbleSort(vetorBubble);
    printf("\nBubble Sort:\n");
    imprimirVetor(vetorBubble);
    printf("Trocas realizadas: %d\n", trocasBubble);

    copiarVetor(alturas, vetorInsertion);
    int trocasInsertion = insertionSort(vetorInsertion);
    printf("\nInsertion Sort:\n");
    imprimirVetor(vetorInsertion);
    printf("Trocas realizadas: %d\n", trocasInsertion);

    copiarVetor(alturas, vetorSelection);
    int trocasSelection = selectionSort(vetorSelection);
    printf("\nSelection Sort:\n");
    imprimirVetor(vetorSelection);
    printf("Trocas realizadas: %d\n", trocasSelection);

    return 0;
}
