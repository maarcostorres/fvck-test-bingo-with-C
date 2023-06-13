#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MAX_PARTICIPANTS 10

// Estrutura para armazenar informações do participante
typedef struct {
    char name[20];
    int card[SIZE][SIZE];
} Participant;

// Função para embaralhar os números do Bingo
void shuffle(int *array, int size) {
    int i, j, temp;
    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Função para imprimir a cartela de Bingo
void printCard(int card[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
}

// Função para marcar um número na cartela de Bingo
void markNumber(int card[][SIZE], int num) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (card[i][j] == num) {
                card[i][j] = -1;
                return;
            }
        }
    }
}

// Função para verificar se houve um Bingo
int checkBingo(int card[][SIZE]) {
    int i, j, bingo;

    // Verificar linhas
    for (i = 0; i < SIZE; i++) {
        bingo = 1;
        for (j = 0; j < SIZE; j++) {
            if (card[i][j] != -1) {
                bingo = 0;
                break;
            }
        }
        if (bingo) return 1;
    }

    // Verificar colunas
    for (i = 0; i < SIZE; i++) {
        bingo = 1;
        for (j = 0; j < SIZE; j++) {
            if (card[j][i] != -1) {
                bingo = 0;
                break;
            }
        }
        if (bingo) return 1;
    }

    // Verificar diagonais
    bingo = 1;
    for (i = 0; i < SIZE; i++) {
        if (card[i][i] != -1) {
            bingo = 0;
            break;
        }
    }
    if (bingo) return 1;

    bingo = 1;
    for (i = 0; i < SIZE; i++) {
        if (card[i][SIZE - 1 - i] != -1) {
            bingo = 0;
            break;
        }
    }
    if (bingo) return 1;

    return 0;
}

int main() {
    int i, j, count = 1;
    int numbers[SIZE * SIZE];
    int numParticipants;

    // Solicitar o número de participantes
    printf("Digite o número de participantes (máximo %d): ", MAX_PARTICIPANTS);
    scanf("%d", &numParticipants);

    if (numParticipants < 1 || numParticipants > MAX_PARTICIPANTS) {
        printf("Número de participantes inválido.\n");
        return
