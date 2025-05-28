/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//For MUTEX LOCK()/UNLOCK() 
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
long balance = 0;//Shared, Global Variable


void * credit(void * arg){
   int amount = (int) arg;
   printf("Credit : balance = balance + %d\n",(int)arg);
   for(long i=0;i<5000000;i++){
	     pthread_mutex_lock(&mut);
		 balance = balance + amount;
		pthread_mutex_unlock(&mut);
   }
   
   pthread_exit(NULL);
}
void * debit(void * arg){
   int amount = (int) arg;
  printf("Dedit : balance = balance - %d\n",(int)arg);
   for(long i=0;i<5000000;i++){
	     pthread_mutex_lock(&mut);
		 balance = balance - amount;
		pthread_mutex_unlock(&mut);
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