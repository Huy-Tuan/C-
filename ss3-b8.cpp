#include<stdio.h>

int main () {
	
	int number, reverse;
	printf("Moi ban nhap vao so nguyen co 4 chu so ");
	scanf("%d", &number);
	
	int nghin = number / 1000;
	int tram = number % 1000 / 100;
	int chuc = number % 100 / 10;
	int dvi = number % 10;
	
	printf("%d%d%d%d", dvi, chuc, tram, nghin);
	
	
}