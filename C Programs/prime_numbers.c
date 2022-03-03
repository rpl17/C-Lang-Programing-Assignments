#include <stdio.h>
#include <stdlib.h> //atoi's header..
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
  

void *thread(void *val) {

int *ptr = (int*) val;
int value = *ptr;
int i = 2;
int sum;
int j;

printf("The following are the prime numbers up to %d: \n" ,value);
//Loop until user value
for ( sum = 2 ; i <= value ; i++) {
for ( j = 2 ; j <= i - 1 ; j++){
if ( i % j == 0 )
break;
}
if (j == i )
{
//Prints prime nunbers
printf("%d ", i);
sum++;
}
}
printf("\n\n");
}


int main(int arg, char *argv[]) {

pthread_t it;
//Argument validation
if( arg == 1 || arg > 2 ) { 
printf("\nInvalid command line argument\n");
return 0;
}

int value = atoi(argv[1]);
//Input validation
if( value < 2) {
printf("\nInvalid input!\n");
return 0;
}
//Creates thread
pthread_create(&it,NULL,thread,&value);
//Joins thread
pthread_join(it,NULL);
//Exits thread
pthread_exit(NULL);
return 0;
}
