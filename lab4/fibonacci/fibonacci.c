#include<stdio.h> 
int fib(int n);
int main () 
{ 
  int n;
  printf("Enter the number of terms in the fibonacci sequence: ");
  scanf("%d", &n);
  printf("Following is the Fibonacci Sequence up to %d terms:\n", n);
  for(int i = 0; i <= n; i++)
  printf("%d ", fib(i)); 
  printf("\n");
  return 0; 
} 
int fib(int n) 
{ 
   if (n <= 1) 
      return n; 
   return fib(n-1) + fib(n-2); 
} 
  
