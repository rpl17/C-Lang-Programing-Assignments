#include<stdio.h>

int main(int argc, char *argv[]){
  
  // Your code here 
    char forward [100];
    fgets(forward, 100, stdin);
    printf("You entered: %s\n", forward);
    printf("The reversed string is: ");
    reverse(forward);
    return 0;
}
 void reverse(char *ptr){
   if(ptr[0] == '\0'){
     return;
   }
   else{
     reverse(&ptr[1]);
     putchar(ptr[0]);
     
   }
 }
