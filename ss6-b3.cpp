#include<stdio.h>

int main () {
	
	int true_password = 5;
	int input_password;
	do{
	    printf("Hay nhap mat khau cua ban ");
		scanf("%d", &input_password);
		
		if (input_password != true_password){
			printf("Sai mat khau");
		    break;
		}
		
	}while(input_password != true_password);
	
	if(input_password == true_password){
		printf("Mat khau dung");
	}
}

