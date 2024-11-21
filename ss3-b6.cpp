#include<stdio.h>

int main () {
	
	float h, a, dientich;
	printf("Moi ban nhap chieu cao cua tam giac ");
	scanf("%f", &h);
	
	printf("Moi ban nhap vao chieu dai canh tam giac ");
	scanf("%f", &a);
	
	dientich = a * h / 2 ;
	printf("Dien tich tam giac la %.2f", dientich);
	
	return 0;
}