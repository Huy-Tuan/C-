#include<stdio.h>

int main() {
	int number1, number2, choice;
	
	printf("Hay nhap mot so bat ki ");
	scanf("%d", &number1);
	
	printf("Hay nhap mot so bat ki ");
	scanf("%d", &number2);
	
	do{
		printf("Caculator\n");
		printf("1. Tong 2 so\n");
		printf("2. Hieu 2 so\n");
		printf("3. Tich 2 so\n");
		printf("4. Thuong 2 so\n");
		printf("5. Thoat\n");
		printf("Lua chon cua ban la: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("%d + %d = %d \n",number1, number2, number1 + number2);
				break;
			case 2:
			    printf("%d - %d = %d \n", number1, number2, number1 - number2);
				break;
			case 3:
			    printf("%d x %d = %d \n", number1, number2, number1 * number2);
			case 4:
			    printf("%d / %d = %d \n", number1, number2, number1 / number2);
				break;
			case 5:
				printf("Thoat chuong trinh");
			    break;
			default :
			    printf("Khong hop le !!!");	
		}
	}while(choice!=5);
}