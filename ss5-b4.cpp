#include<stdio.h>

int main () {
	int n;
	int core;
	
	printf("Hay nhap vao mot so nguyen tu 1-10: ");
	scanf("%d", &n);
	
	if(n>=1 && n<=10) {
		printf("Bang cuu chuong cua %d la ", n);
	
	   for(int i = 0; i <= 10; i++) {
		core == n * i;
		printf("%d x %d = %d \n", n, i, core);
	}
}   else {
	printf("So ko hop le !!!");
}
}