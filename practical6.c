// producer consumer problem using semaphore

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include<stdlib.h>
#define MaxItems 5
#define BufferSize 5
sem_t empty;
sem_t full;
pthread_mutex_t mutex;
int in = 0;
int out = 0;
int buffer[BufferSize];
void *producer(void *pno) {
    int n;
    int item;
    n = *((int *)pno);
    for (int i = 0; i < MaxItems; i++) {
        item = 5 *n + i;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", n, buffer[in], in);
        in = (in + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cno) {
    int n;
    n = *((int *)cno);
    for (int i = 0; i < MaxItems; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumed %d: Remove Item %d from %d\n", n, item, out);
        out = (out + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
int main() {
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BufferSize);
    sem_init(&full, 0, 0);
    pthread_t pno[MaxItems], con[MaxItems];
    int nProducers, nConsumers;
    printf("Enter producers: ");
    scanf("%d", &nProducers);
    printf("Enter consumers: ");
    scanf("%d", &nConsumers);
    if (nProducers > MaxItems || nConsumers > MaxItems) {
        printf("MaxItems Error\n");
        return 1;
    }
    for (int i = 0; i < nProducers; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&pno[i], NULL, producer, arg);
    }
    for (int i = 0; i < nConsumers; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&con[i], NULL, consumer, arg);
    }
    for (int i = 0; i < nProducers; i++) {
        pthread_join(pno[i], NULL);
    }
    for (int i = 0; i < nConsumers; i++) {
        pthread_join(con[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
