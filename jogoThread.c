#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

char *a;
int tamArray = 86;
int posArray = 41;
int q1;
int q2;
long t;
void *incposArray(void*arg);
void *decposArray(void*arg);
pthread_t totheStart;
pthread_t totheEnd;
pthread_mutex_t buffer_mutex;


void *incposArray(void*arg){
    while(1) {
        if((posArray + 2) != 84) {
            pthread_mutex_lock(&buffer_mutex);
            a[posArray] = '_';
            a[posArray + 1] = 'L';
            a[posArray + 2] = 'M';
            a[posArray + 3] = 'M';
            posArray++;
            pthread_mutex_unlock(&buffer_mutex);
            usleep(t);
        }
    }
}

void *decposArray(void*arg){
while(1) {
        if((posArray + 2) != 84) {
            pthread_mutex_lock(&buffer_mutex);
            a[posArray] = 'L';
            a[posArray + 1] = 'M';
            a[posArray + 2] = 'M';
            a[posArray + 3] = '_';
            posArray--;
            pthread_mutex_unlock(&buffer_mutex);
            usleep(t);
        }
    }

}


int main(){
a = (char *) malloc(tamArray * sizeof(char));

    for(int i = 0; i<= 85; i++){
        a[i] = '_';
    }

a[posArray] = 'L';
a[posArray + 1] ='M';
a[posArray + 2] = 'M';
a[85] = '\0';

srand48(time(0));
t = (long) (drand48() * 201910652/67.0);
q1 = (int)(drand48()*(21 - 9 + 1)) + 9;
q2 = (int) (drand48()*(21 - 9 + 1)) + 9;


pthread_mutex_init(&buffer_mutex, NULL);


    for(int i = 0; i < q1; i++) {
        pthread_create(&totheStart, NULL, decposArray, NULL);
        }
    for(int i = 0; i < q2; i++) {
        pthread_create(&totheEnd, NULL,incposArray, NULL);
        }



    while(1){
        system("clear");
        printf("tothestart: %d totheend: %d\n", q1, q2);
        printf("%s\n", a);

    if(posArray <= 0){
        printf("totheStart ganhou!");
                break;
            }
            else if(posArray >= 82){
                printf("totheEnd ganhou!");
                break;
            }
usleep(100);
}
}
