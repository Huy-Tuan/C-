#include <stdio.h>

int main () {
   int n, i;
   
   printf("Hay nhap vao mot so nguyen ");
   scanf("%d", &n);
   
   if (n == 0){
   	   printf("So 0 co vo so uoc");
   }
       printf("Cac uoc cua %d la \n", n);
   
   for (i = 1; i <= n; i++){
       if(n % i == 0){
       	printf("%d\n",i);
	   }
}
}
