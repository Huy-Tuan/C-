#include<stdio.h>

int main() {
	int m;
	printf("Moi ban nhap vao thang ");
	scanf("%d", &m);
	
	switch(m){
	    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	        printf("Thang nay co 31 ngay\n");
	        break;
	    case 4: case 6: case 9: case 11:
	        printf("Thang nay co 30 ngay\n");
	        break;
	    case 2:
	        printf("Thang nay co 28 ngay\n");
	        break;
	    
	    default:
		printf("Du lieu khong hop le");
	}
	
}