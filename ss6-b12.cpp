#include<stdio.h>

int main () {
	
	int n, i, fibonaci, num1, num2;
        printf("Hay nhap vao n so fibonaci dau tien ");
        scanf("%d", &n);
        
    for (i = 0; i < n; i++){
    	if(i == 0){
    		num1 = 0;
    		printf("%d\n", num1);
		}
    	else if (i == 1) {
    		num2 = i;
    		printf("%d\n", num2);
		}
		else {
			fibonaci = num1 + num2;
			printf("%d\n", fibonaci);
			num1 = num2;
		    num2 = fibonaci;
		
	}
  }
}
	
    
