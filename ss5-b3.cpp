#include<stdio.h>

int main () {
	
	int n, sum = 0;
	
	    printf("Hay nhap vao mot so nguyen duong ");
	    scanf("%d", &n);
	
	for(int i = 1; i <= n ; i++){
		sum += i;
	}
	    printf("Tong tu 1 den %d la %d", n, sum);
	    
	return 0;
}