#include<stdio.h>

int main() {
	int n;
	printf("Moi ban nhap mot so nguyen ");
	scanf("%d",&n);
	if(n % 3 == 0){
		printf("Day la so chia het cho 3");
	}
	else if (n % 5 == 0){
		printf("Day la so chia het cho 5");
	}
	else if (n % 3 == 0 && n % 5 == 0){
		printf("Day la so chia het cho ca 3 va 5");
	}
}