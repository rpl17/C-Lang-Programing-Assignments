#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char* argv[]){     
  
  double a = atof(argv[1]);
  double b = atof(argv[2]);
  double c = atof(argv[3]);
  double equation = b*b-4*a*c;
  double root1;
  double root2;
  // Your code here
  if(argc<2) {
  printf("Usage ./quadratic_roots root1\n");
  exit(1);
  }
  
  else if (equation > 0){
    
  root1 = (-b +sqrt(equation)) / (2*a);
  root2 = (-b -sqrt(equation)) / (2*a);
  
  printf("a: %.6f\n", a);
  printf("b: %.6f\n", b);
  printf("c: %.6f\n", c);
  printf("First root:%.6f\n", root1);
  printf("Second root:%.6f\n", root2);
  }
  else if(equation ==0){
  root2 = -b / (2*a);
  root1 = root2;
  printf("a: %.6f\n", a);
  printf("b: %.6f\n", b);
  printf("c: %.6f\n", c);
  printf("The roots are both %.6f\n", root1);
  }
  

 
  return 0;
}
