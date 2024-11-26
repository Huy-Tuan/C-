#include<stdio.h>

int main () {
	
	int n = 0;
	int eventNumber = 0;
	int odd = 0;
	
	printf("Hay nhap vao 5 so nguyen \n");
	
	for (int i = 1; i <= 5; i++){
		printf("Nhap vao so nguyen thu %d: ", i);
		scanf("%d", &n);
		
		if(n % 2 != 0){
			odd++;
		}
		else{
			eventNumber++;
		}
	}
	    printf("So luong so chan la %d\n", eventNumber);
		printf("So luong so le la %d", odd);
}
