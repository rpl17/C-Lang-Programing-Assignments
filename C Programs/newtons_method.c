#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {    
  double number = atof(argv[1]);
  double guess = atof(argv[2]);
  double sqrtNumber = sqrt(number);
  printf("Your initial guess is: %.2f\n", guess);
  printf("Your input number to be square rooted: %.0f\n", number);
  printf("The approximate square root is: %.5f\n", sqrtNumber);
  return 0; 
}
