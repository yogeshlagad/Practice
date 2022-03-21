/*
//1-Functions can return any type except array and functions

//2.
#include <stdio.h>
int main()
{
  printf("%d", main);  
  return 0;
}
//op-4199264 .Name of the function is actually a pointer variable to 
//the function and prints the address of the function. Symbol table is implemented like this.

//2.

#include <stdio.h>
 int fun(int n);
int main()
{
    int (*ptr)(int ) = fun;
    (*ptr)(3);

    return 0;
}
 
int fun(int n)
{
  //for(;n > 0; n--)
   for(;n >= 0; n--)
    printf("GeeksQuiz ");
  return 0;
}//op-compile time error  function is not declared


#include<stdio.h>
 
void dynamic(int s, ...)
//void dynamic(int s,int p,int q,int r)
{
    printf("%d ", s);
   // printf("%d %d %d %d ",s,p,q,r);
     //printf("%d %d %d % ",s,p,q);
}
 
int main()
{
    dynamic(2, 4, 6, 8);
    dynamic(3, 6, 9);
    return 0;//In c three continuous dots is known as ellipsis 
    //which is variable number of arguments of function.
     //The values to parameters are assigned one by one.
      //Now the question is how to access other arguments.
       //See this for details.
}//op-2 3

#include <stdio.h>
int main()
{
    void demo();
    void (*fun)();
    fun = demo;
    (*fun)();
    fun();
    return 0;
}
 
void demo()
{
    printf("GeeksQuiz ");
}
// op-GeeksQuiz GeeksQuiz 
//This is a simple program with function pointers. fun is assigned to point to demo. 
//So the two statements "(*fun)();" and "fun();" mean the same thing.

#include <stdio.h>
#include <stdarg.h>
int fun(int n, ...)
{
    int i, j = 1, val = 0;
    va_list p;
    va_start(p, n);
    for (; j < n; ++j)
    {
        i = va_arg(p, int);
        val += i;
    }
    va_end(p);
    return val;
}
int main()
{
    printf("%dn", fun(4, 1, 2, 3));
    return 0;
}
*/
#include <stdarg.h>
#include <stdio.h>
  
// this function returns minimum of integer numbers passed.  First 
// argument is count of numbers.
int min(int arg_count, ...)
{
  int i;
  int min, a;
    
  // va_list is a type to hold information about variable arguments
  va_list ap; 
  
  // va_start must be called before accessing variable argument list
  va_start(ap, arg_count); 
     
  // Now arguments can be accessed one by one using va_arg macro
  // Initialize min as first argument in list   
  min = va_arg(ap, int);
     
  // traverse rest of the arguments to find out minimum
  for(i = 2; i <= arg_count; i++) {
    if((a = va_arg(ap, int)) < min)
    min = a;
  }   
  
  //va_end should be executed before the function returns whenever
  // va_start has been previously used in that function 
  va_end(ap);   
  
  return min;
}
  
int main()
{
   int count = 5;
     // Find minimum of 5 numbers: (12, 67, 6, 7, 100)
   printf("Minimum value is %d", min(count, 12, 67, 6, 7, 100));
   getchar();
   return 0;
}

































































