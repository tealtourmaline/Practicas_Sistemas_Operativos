#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUM 4

void *acumulado(void *args){
    char *msg;
    msg = (char *)args;
    int acc=0;
    for (int i=0;i<5;i++){
        acc+=i;
        printf("thread [%s]: %d\n", msg, acc);
        sleep(5);
    }   
}

void *productoria(void *args){
    char *msg;
    msg = (char *)args;
    int prod=1;
    for (int i=1;i<10;i++){
        prod*=i;
        printf("thread [%s]: %d\n", msg, prod);
        sleep(5);
    }   
}

void *exponencial(void *args){
    char *msg;
    msg = (char *)args;
    int exp=0;
    for (int i=0;i<10;i++){
        exp=pow(2,i);
        printf("thread [%s]: %d\n", msg, exp);
        sleep(5);
    }   
}

void *fibonacci(void *args){
    char *msg;
    msg = (char *)args;
    printf("thread [%s]: 0\n", msg);
    sleep(5);
    printf("thread [%s]: 1\n", msg);
    sleep(5);

    int prev=0, curr=1,tmp;

    for (int i=2;i<10;i++){
        
        tmp=curr;
        curr=prev+curr;
        prev=tmp;

        printf("thread [%s]: %d\n", msg, curr);
        sleep(5);
    }    
}

int main(){

    pthread_t thread[THREAD_NUM];
    char *msg1 = "Acumulada";
    char *msg2 = "Productoria";
    char *msg3 = "Exponencial 2^n";
    char *msg4 = "Fibonacci";
    int i;

    printf("Función principal PID: %d\n", getpid());

    for(i=0; i<THREAD_NUM; i++){
        switch(i){
            case 0:
                pthread_create(&thread[i], NULL, acumulado, (void *)msg1);
                break;
            case 1:
                pthread_create(&thread[i], NULL, productoria, (void *)msg2);
                break;
            case 2:
                pthread_create(&thread[i], NULL, exponencial, (void *)msg3);
                break;
            case 3:
                pthread_create(&thread[i], NULL, fibonacci, (void *)msg4);
        }
    }

    for(i=0; i<THREAD_NUM; i++){
        pthread_join(thread[i],NULL);
    }
    
    return 0;
}