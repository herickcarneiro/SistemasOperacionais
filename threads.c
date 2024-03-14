//Solução do problema Produtor-Consumidor sem ultilização de sincronização conforme foi socilitado pelo professor



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 30
#define MAX_ITEMS 12
#define WORD_LENGTH 20

char buffer[BUFFER_SIZE][WORD_LENGTH];
int in = 0;
int out = 0;
int consumed_count = 0;

void* producer(void* arg) {
    int producer_id = ((int)arg);

    if(producer_id == 1){  //Verifico qual é a Thread que está enviando a função, se é a primeira, segunda, terceira ou quarta

        char item[WORD_LENGTH];
        snprintf(item, WORD_LENGTH, "Estudo"); //Envio cada palavra que será produziada ao buffer

        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;

        snprintf(item, WORD_LENGTH, "na");
        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;

        snprintf(item, WORD_LENGTH, "UFPB");
        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;

    }

    else if(producer_id == 2) {

        char item[WORD_LENGTH];
        snprintf(item, WORD_LENGTH, "Flamengo");

        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;

        snprintf(item, WORD_LENGTH, "será");
        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;

        snprintf(item, WORD_LENGTH, "campeão");
        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;

    }
else if(producer_id == 3) {
        // Removido o bloqueio do mutex

        char item[WORD_LENGTH];
        snprintf(item, WORD_LENGTH, "Gosto");

        // Removida a verificação de espaço no buffer

        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;

        snprintf(item, WORD_LENGTH, "de");
        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;


        snprintf(item, WORD_LENGTH, "SO");
        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;
    }
else {
        char item[WORD_LENGTH];
        snprintf(item, WORD_LENGTH, "Alisson");

        // Removida a verificação de espaço no buffer

        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;

        snprintf(item, WORD_LENGTH, "ensina");

        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;

        snprintf(item, WORD_LENGTH, "bem");

        strncpy(buffer[in], item, WORD_LENGTH - 1);
        buffer[in][WORD_LENGTH - 1] = '\0';
        //printf("Produced de ID %d: %s\n", producer_id, item);

        in = (in + 1) % BUFFER_SIZE;

        }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int consumer_id = ((int)arg);
    while (consumed_count < MAX_ITEMS) {  //Defini o total de palavras em MAX_ITEMs

        char item[WORD_LENGTH];  //Cada thread consumidora vai ao buffer e ler a palavra
        strncpy(item, buffer[out], WORD_LENGTH);
        printf("Consumed de ID %d: %s\n", consumer_id, item);

        out = (out + 1) % BUFFER_SIZE;

        consumed_count++;
        sleep(1);

    }

    pthread_exit(NULL);
}

int main() {

    int i = 0;

    pthread_t producerThread[4], consumerThread[4];

    int producer_id[4];
    int consumer_id[4];

    for(i=0; i<4; i++) {  //Criação de 4 threads produtora
    producer_id[i] = i + 1;
    pthread_create(&producerThread[i], NULL, producer, (void *)&producer_id[i]);
    }

    for(i=0; i<4; i++){  //Criação de 4 threads consumidoras
    consumer_id[i] = i + 1;
    pthread_create(&consumerThread[i], NULL, consumer, (void *)&consumer_id[i]);
    }

    for(i=0; i<4; i++){ //Espero pelas 4 threads produtoras terminem suas execuções
    pthread_join(producerThread[i], NULL);
    }

    for(i=0; i<4; i++){ //Espero pelas 4 threads consumidoras terminem suas execuções
    pthread_join(consumerThread[i], NULL);
    }

    return 0;
}
