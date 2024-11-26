#include<stdio.h>

int main () {
	
	int n = 0;
    int sum = 0;
	
	printf("Hay nhap vao 5 so nguyen \n");
	
	for(int i = 1; i <= 5; i++){
		
		printf("Hay nhap vao so nguyen thu %d ", i);
		scanf("%d", &n);
		
		if(n % 2 != 0){
		sum += n;
	}
		
	}
	printf("Tong cac so le la %d", sum);
	
	return 0;
}

