#include <stdio.h>

int main () {
	int choice, n;
	int arr[n];
	int size = sizeof(arr)/sizeof(int);
	int chan = 0;
	int le = 0;
	int secondMax = -1;
	int value;
	int delet;
	int max;
	int key;
    int m;
	
	do{
		printf("\t\tMENU\n");
		printf("1. Nhap so phan tu va gia tri cho mang\n");
		printf("2. In ra cac gia tri phan tu trong mang\n");
		printf("3. Dem so luong phan tu chan le trong mang\n");
		printf("4. Tim gia tri lon thu hai trong mang (hay sap xep mang theo thu tu giam dan truoc)\n");
		printf("5. Them mot phan tu vao dau mang\n");
		printf("6. Xoa phan tu tai mot vi tri cu the\n");
		printf("7. Sap xep mang theo thu tu giam dan (Insertion sort)\n");
		printf("8. Tim kiem mot phan tu (mang phai duoc sap xep roi)\n");
		printf("9. In ra toan bo so nguyen to trong mang da duoc binh phuong.\n");
		printf("\t a. Neu khong co so nguyen to nao thi hien thi khong co so nguyen to nao trong mang.\n");
		printf("\t b. Neu co thi hien thi va binh phuong len\n");
		printf("10. Sap xep theo thu tu giam dan (bubble sort)\n");
		printf("11. Thoat\n");
		printf("Hay chon lua chon ban muon ");
		scanf("%d", &choice);	
		switch(choice){
			case 1:
				printf("Hay kich co mang ban muon ");
				scanf("%d", &n);
				printf("\n");
				for(int i = 0; i < n; i++){
					printf("Hay nhap gia tri cho phan tu vi tri thu %d = ", i);
					scanf("%d", &arr[i]);
				}
				break;
			case 2:
				for(int i = 0; i < n; i++){
					printf("Phan tu arr[%d] = %d \n", i, arr[i]);
				}
				printf("\n");
				break;
			case 3:
				for (int i = 0; i < n; i++){
					if(arr[i] % 2 == 0){
						chan += 1;
					}else if(arr[i] % 2 != 0){
						le += 1;
				}
				}printf("So luong phan tu chan la %d\n", chan);
				 printf("So luong phan tu le la %d\n", le);
				 printf("\n");
				break;
			case 4:
				secondMax = arr[1];
				printf("%d", secondMax);
				break;
			case 5:
				printf("Hay nhap gia tri ban muon them ");
				scanf("%d", &value);
				for(int i = n; i >= arr[0]; i--){
					arr[i] = arr[i - 1];
				}
					arr[0] = value;
				for (int i = 0; i < n; i++){
					printf("%d\t", arr[i]);
				}
				break;
			case 6:
				printf("Hay chon vi tri ban muon xoa phan tu ");
				scanf("%d", &delet);
				--delet;
				if(delet > n){
					printf("Khong hop le !!!");
				}else{
					for(int i = delet; i < n; i++){
						arr[i]=arr[i+1];
					}
				}
				printf("Mang sau khi xoa: \n");
				for(int i = 0; i < n; i++){
					printf("%d\t", arr[i]);
				}printf("\n");
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				for(int i = 0; i < n; i++){
					for(int j = 0; j < n - i -1; j++){
					if(arr[j] < arr[j + 1]){
						int temp;
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
				printf("Phan tu sau khi duoc sap xep: \n");
				for(int i = 0; i < n; i++){
					printf("%d\t", arr[i]);
				}printf("\n");
			break;
			case 11:
				break;
		}
	}while (choice != 11);
	return 0;
}
