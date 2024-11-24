#include<stdio.h>

int main (){

    int a, b, c;
    
    printf ("Moi ban nhap vao canh a \n");
    scanf("%d", &a);
    
    printf ("Moi ban nhap vao canh b \n");
    scanf("%d", &b);
    
    printf ("Moi ban nhap vao canh c \n");
    scanf("%d", &c);
    
    if ( a + b > c ){
    	printf("Ba canh nay co the tao thanh tam giac");
	}
    else{
    	printf("Ba canh nay khong the tao thanh tam giac");
	}
}