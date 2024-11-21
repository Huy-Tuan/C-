#include<stdio.h>

int main() {
	
	float celsius, fahrenheit;
	printf("Moi ban nhap do C ");
	scanf("%f", &celsius);
	
	fahrenheit = celsius * 1.8 + 32;
	printf("Do F la %.2f", fahrenheit);
	
	return 0;
}