#include<stdio.h>

int main () {
	
	float pi = 3.14, r, chuvi, dientich;
	printf("Moi ban nhap vao r ");
	scanf("%f", &r);
	
	chuvi = r * 2 * pi;
	printf("chu vi hinh tron la %.2f\n", chuvi);
	
	dientich = pi * r * r;
	printf("Dien tich hinh tron la %.2f", dientich);
	
	return 0;
}