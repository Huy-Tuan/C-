#include <stdio.h>

int main () {
	
	int numbers[5] = {3,7,1,9,11};
	int chan;
	int length = sizeof(numbers) / sizeof(numbers[0]);
	
	for(int i = 0; i < 5; i++){
		if(numbers[i] % 2 == 0){
			printf("%d la so chan\n", numbers[i]);
		}else{
			chan++;
		}
    }if(chan >= length){
    	printf("Khong co phan tu chan nao");
	}
}
