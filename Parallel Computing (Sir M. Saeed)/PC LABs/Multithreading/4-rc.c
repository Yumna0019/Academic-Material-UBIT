#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


long balance = 0;//Shared, Global Variable

void * credit(void * arg){
   int amount = (int) arg;
   printf("Credit : balance = balance + %d\n",(int)arg);
   for(long i=0;i<5000000;i++){
		 balance = balance + amount;
   }
   
   pthread_exit(NULL);
}
void * debit(void * arg){
   int amount = (int) arg;
  printf("Dedit : balance = balance - %d\n",(int)arg);
   for(long i=0;i<5000000;i++){
		 balance = balance - amount;
    }
   pthread_exit(NULL);
}


int main(){
    pthread_t t1, t2;
    pthread_create(&t1, NULL, credit,(void *)5);
    pthread_create(&t2, NULL, debit,(void *)5);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Value of balance is :%ld\n", balance);
    return 0;
 }