#include<stdio.h>
 void fun(int *p);
 
 int main()
 {
    int x=4;
    printf("%d\n",x);
    fun(&x);
    printf("%d\n",x);
    



 }
 void fun(int *p){
    *p =*p/2+13;
 }