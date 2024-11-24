#include<stdio.h>

int main() {
	int num1, num2, num3;
	printf("Moi ban nhap so nguyen thu nhat ");
	scanf("%d", &num1);
	
	printf("Moi ban nhap so nguyen thu hai ");
	scanf("%d", &num2);
	
	printf("Moi ban nhap so nguyen thu ba ");
	scanf("%d", &num3);
	
	if ( num3 > num1 && num3 < num2){
	    printf("So %d nam trong khoang %d va %d",num3, num1, num2);
		}
	else if ( num3 < num1 && num3 > num2){
	    printf("So %d nam trong khoang %d va %d ",num3, num2, num1);
		}
	else {
		
	}
}