#include<stdio.h>

int main () {
	
	float a, b, c, tongDiem, diemTB;
	printf("Moi ban nhap vao diem toan ");
	scanf("%f", &a);
	
	printf("Moi ban nhap vao diem van ");
	scanf("%f",&b);

	printf("Moi ban nhap vao diem anh ");
	scanf("%f",&c);
	
	tongDiem = a + b + c;
	printf("Tong diem = %.2f\n", tongDiem);
	
	diemTB = tongDiem / 3;
	printf("Diem trung binh = %.2f", diemTB);
	
	return 0;
	
}