#include <stdio.h>

int main (){
	
	int arr[5];
	int i;
	
	/*printf("Nhap phan tu thu nhat ");
	scanf("%d", &arr[0]);
	printf("Nhap phan tu thu hai ");
	scanf("%d", &arr[1]);*/
	
	for (i = 0; i < 5; i++){
		printf("Nhap arr[%d] : ",i );
		scanf("%d", &arr[i]);
	}
    printf("Phan tu vua nhap la: \n");
    for(i = 0; i < 5; i++){
    	printf("Phan tu thu %d la %d\n", i + 1, arr[i]);
	}
}
	
