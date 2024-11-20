#include<stdio.h>

int main() {
	
	int a, b, tong, hieu, tich, thuong;
	printf("Moi ban nhap vao so a \n");
	scanf("%d",&a);
	
	printf("Moi ban nhap vao so b \n");
	scanf("%d",&b);
	
	tong = a + b;
	hieu = a - b;
	tich = a * b;
	thuong = a / b;
	printf("Tong cua a + b = %d\n",tong);
	printf("Hieu cua a - b = %d\n",hieu);
	printf("Tich cua a * b = %d\n",tich);
	printf("Thuong cua a / b = %d\n",thuong);
	return 0;
}