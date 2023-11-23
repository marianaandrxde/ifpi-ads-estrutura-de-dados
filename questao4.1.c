/* 4.1 simule a execução do codigo a seguir e indique a saida exebida em video:
Fila F = fila(5);
enfileira(1, F);
enfileira(2, F);
enfileira(3, F);
enfileira(desenfileira(F), F);
enfileira(desenfileira(F), F);
printf("%d\n", desenfileira(F));*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

Queue createQueue() {
    Queue queue;
    queue.front = 0;
    queue.rear = -1;
    queue.size = 0;
    return queue;
}

void enqueue(int element, Queue *queue) {
    if (queue->size >= MAX_SIZE) {
        printf("Erro: Fila cheia\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = element;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->size == 0) {
        printf("Erro: Fila vazia\n");
        return -1;
    }
    int removed = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return removed;
}

int main() {
    Queue F = createQueue();

    // Adicionando os números 1, 2 e 3 na fila
    enqueue(1, &F);
    enqueue(2, &F);
    enqueue(3, &F);

    // Pegando os dois primeiros números e colocando de volta na fila
    enqueue(dequeue(&F), &F);
    enqueue(dequeue(&F), &F);

    // Exibindo o primeiro elemento restante na fila
    printf("%d\n", dequeue(&F));

    return 0;
}

/*Cria uma fila vazia.
Adiciona os números 1, 2 e 3 à fila. Agora a fila é [1, 2, 3].
Retira os dois primeiros números (1 e 2) e os colocamos de volta na fila. Agora a fila é [3, 1, 2].
Exibi o primeiro elemento restante na fila, que é 3.
Portanto, a saída exibida será 3.
*/