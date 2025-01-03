#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ID_LENGTH 20
#define MAX_LENGTH_NAME 30

struct Date{
	int month, day, year;
};
struct Category{
	char CategoryId[MAX_ID_LENGTH + 1];
	char CategoryName[MAX_LENGTH_NAME + 1];
};
struct Product{
	char productId[10];
	char category[10];
	char productName[30];
	int quantity;
	int price;
};
struct Product products[100];
struct Category category[MAX_CATEGORIES];
//struct Category category[10];
int numberProduct = 0;
int numberCategory = 0;
bool checkAdminAccount(const char *email, const char *password) {
    FILE *file = fopen("admin_accounts.txt", "r");
    if (file == NULL) {
        printf("\tLoi: Khong the mo file admin_accounts.txt!\n");
        return false;
    }

    char storedEmail[100], storedPassword[100];
    while (fgets(storedEmail, sizeof(storedEmail), file) != NULL) {
        char *comma = strchr(storedEmail, ',');
        if (comma == NULL) continue;

        *comma = '\0';
        strcpy(storedPassword, comma + 1);

        storedPassword[strcspn(storedPassword, "\n")] = '\0';
        storedEmail[strcspn(storedEmail, "\n")] = '\0';

        if (strcmp(email, storedEmail) == 0 && strcmp(password, storedPassword) == 0) {
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}
bool loginAccount() {
    char email[100], password[100];
    printf("\n\n\tDANG NHAP ADMIN\n");
    printf("\t=====================\n");
    printf("\tEmail: ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    printf("\tPassword: ");
    int indexPass = 0;
    char ch;
    while ((ch = getchar()) != '\n' && indexPass < sizeof(password) - 1) {
        if (ch != '\b') { 
            password[indexPass++] = ch;
            printf("*");
        }
    }
    password[indexPass] = '\0';

    if (checkAdminAccount(email, password)) {
        printf("\n\tDang nhap thanh cong!\n");
        return true;
    } else {
        printf("\n\tSai email hoac mat khau!\n");
        return false;
    }
}

// ham in danh muc
void createAdminFileIfNotExists() {
     FILE *file = fopen("admin_accounts.txt", "r");
    if (file == NULL) { // Neu tep khong ton tai
        file = fopen("admin_accounts.txt", "w");
        if (file != NULL) {
            // Them mot tai khoan mac dinh vao tep
            fprintf(file, "admin@gmail.com,ncgh2306\n");
            printf("\tTao tep admin_accounts.txt thanh cong voi tai khoan mac dinh!\n");
        } else {
            printf("\tLoi: Khong the tao tep admin_accounts.txt\n");
        }
    } else {
        printf("\tTep admin_accounts.txt da ton tai.\n");
    }
    fclose(file);
}
// Ham kiem tra tai khoan dang nhap
int validateLogin(const char *email, const char *password) {
    FILE *file = fopen("admin_accounts.txt", "r");
    if (file == NULL) {
        printf("Loi: Tep admin_accounts.txt khong ton tai.\n");
        return 0;
    }

    char line[256];
    char storedEmail[128], storedPassword[128];

    while (fgets(line, sizeof(line), file)) {
        // Tach email va password tu dong doc duoc
        if (sscanf(line, "%127[^,],%127s", storedEmail, storedPassword) == 2) {
            // Loai bo ky tu xuong dong (neu co)
            storedPassword[strcspn(storedPassword, "\n")] = '\0';

            // So sanh email va password
            if (strcmp(email, storedEmail) == 0 && strcmp(password, storedPassword) == 0) {
                fclose(file);
                return 1; 
            }
        }
    }

    fclose(file);
    return 0;
}
// ham in danh muc
void printCategory() {
	int isEmpty = 1;
	
	for(int i = 0; i < MAX_CATEGORIES; i++){
		if(strlen(category[i].CategoryId) > 0){
			isEmpty = 0;
			break;
		}
	}
	if(isEmpty) {
		printf("\tDanh sach rong\n");
		return;
	}
    printf("\tDanh sach danh muc:\n");
    printf("\t+-----+-------------------+-------------+\n");
    printf("\t| Ma danh muc       | Ten danh muc      |\n"); 
    printf("\t+-----+-------------------+-------------+\n");
    for (int i = 0; i < 10; i++) {
        if (strlen(category[i].CategoryId) > 0) {
            printf("\t| %-17s | %-17s |\n", 
                    
                   category[i].CategoryId, 
                   category[i].CategoryName);


        }
    }
    printf("\t+-----+-------------------+-------------+\n");
}

// ham luu danh muc vao file
void saveCategoryToFile() {
    FILE *file = fopen("category.txt", "w");
    if (file == NULL) {
        printf("\tLoi: Khong the mo file!\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (strlen(category[i].CategoryId) > 0) {
            fprintf(file, "%s,%s\n", category[i].CategoryId, category[i].CategoryName);
        }
    }
    fclose(file);
    printf("\tDanh muc da duoc luu vao file.\n");
}


void addCategory() {
	int flag = 0;
	int found = 0;
    for (int i = 0; i < 10; i++) {
        if (strlen(category[i].CategoryId) == 0) {
            printf("\tThem danh muc moi:\n");
            printf("\tID danh muc: ");
            while (getchar() != '\n');
            fgets(category[i].CategoryId, sizeof(category[i].CategoryId), stdin);
            category[i].CategoryId[strcspn(category[i].CategoryId, "\n")] = '\0';
            for (int j = 0; j < i; j++) {
                if (strcmp(category[i].CategoryId, category[j].CategoryId) == 0) {
                	found = 1;
                    printf("\tID danh muc da ton tai!\n");
                    break;
                }
                if(strlen(category[i].CategoryId) <= 0){
                	flag = 1;
                	printf("\tKhong hop le!\n");
                	break;
				}
            }
            if(found) {
            	return;
			}
            if(flag) {
            	return;
			}
            printf("\tTen danh muc: ");
            fgets(category[i].CategoryName, sizeof(category[i].CategoryName), stdin);
            category[i].CategoryName[strcspn(category[i].CategoryName, "\n")] = '\0';
            printf("\tThem danh muc thanh cong!\n");
            numberCategory++;
            saveCategoryToFile();
            return;
        }
    }
    printf("\tDanh sach danh muc da day, khong the them moi!\n");
}


// ham tai danh muc
void loadCategoryFromFile() {
    FILE *file = fopen("category.txt", "r");
    if (file == NULL) {
        printf("\tLoi: Khong the mo file!\n");
        return;
    }

    int index = 0;
    while (fscanf(file, "%[^,],%[^\n]\n", category[index].CategoryId, category[index].CategoryName) == 2) {
        index++;
        if (index >= 10) break;
    }
	numberCategory++;
    fclose(file);
    printf("\tDanh muc da duoc tai len tu file.\n");
}
// Ham chinh sua danh muc
void editCategory() {
    char x[30];
    int found = 0;
    printf("\tNhap ID danh muc can sua: ");
    while (getchar() != '\n');
    fgets(x, sizeof(x), stdin);
    x[strcspn(x, "\n")] = '\0';

    for (int i = 0; i < 10; i++) {
        if (strcmp(x, category[i].CategoryId) == 0) {
            found = 1;

            printf("\tThong tin danh muc hien tai:\n");
            printf("\tID: %s\n", category[i].CategoryId);
            printf("\tTen: %s\n", category[i].CategoryName);

            printf("\tNhap thong tin sua doi:\n");

//            printf("\tID danh muc moi: ");
//            fgets(category[i].CategoryId, sizeof(category[i].CategoryId), stdin);
//            category[i].CategoryId[strcspn(category[i].CategoryId, "\n")] = '\0';

            printf("\tTen danh muc moi: ");
            fgets(category[i].CategoryName, sizeof(category[i].CategoryName), stdin);
            category[i].CategoryName[strcspn(category[i].CategoryName, "\n")] = '\0';

            printf("\tSua thong tin danh muc thanh cong!\n");
            break;
        }
    }

    if (!found) {
        printf("\tKhong tim thay ID danh muc!\n");
    } else {
        saveCategoryToFile();
    }
}
// ham xoa danh muc
void deleteCategory(){
	char x[30];
	int found = 0;
	char a[30];
	printf("\tHay nhap ID muon xoa: ");
	while(getchar() != '\n');
	fgets(x, sizeof(x),stdin);
	x[strcspn(x, "\n")] = '\0';
	for (int i = 0; i < 10; i++) {
        if (strcmp(x, category[i].CategoryId) == 0) {
            found = 1;
            break;
        }
    }
    if(!found) {
    	printf("\tKhong tim thay ID\n");
    	return;
	}
	printf("\tBan co chac chan muon xoa (yes/no): ");
	fgets(a, sizeof(a),stdin);
	a[strcspn(a, "\n")] = '\0';
	
	if(strcmp(a, "yes") == 0){
		for (int i = 0; i < 10; i++) {
        if (strcmp(x, category[i].CategoryId) == 0) {
            found = 1;
            for(int j = i; j < 10; j++){
            	category[j] = category[j + 1];
			}
		strcpy(category[9].CategoryId, "");
        strcpy(category[9].CategoryName, "");
        printf("\tDa xoa danh muc thanh cong!\n");
        break;
        }
    }
    saveCategoryToFile();
    printCategory();
  }
  else{
  	printf("\tHoan tac xoa\n");
  }
}

//ham chuyen sang chu hoa
void toupperCase(char *str){
	for(int i = 0; str[i]; i++){
		str[i] = toupper((unsigned char)str[i]);
	}
}
//ham tim kiem danh muc theo ten
void searchCategory(){
	char a[30];
	int found = 0;
	printf("\tMoi ban nhap ten danh muc muon tim: ");
	while(getchar() != '\n');
	fgets(a, sizeof(a), stdin);
	a[strcspn(a, "\n")] = '\0';
	toupperCase(a);
	for(int i = 0; i < 10; i++){
		char temp[30];
		strcpy(temp, category[i].CategoryName);
		toupperCase(temp);
		if(strcmp(a, temp) == 0){
			found = 1;
			printf("\tDa tim thay !\n");
			printf("\t+-----+-------------------+-------------+\n");
    		printf("\t| Ma danh muc       | Ten danh muc      |\n"); 
    		printf("\t+-----+-------------------+-------------+\n");
    			for (int j = i; j < 9 ; j++) {
        			if (strlen(category[i].CategoryId) > 0) {
            			printf("\t| %-17s | %-17s |\n", 
                   		 
                   		category[i].CategoryId, 
                   		category[i].CategoryName);
            printf("\t+-----+-------------------+-------------+\n");
			break;
          }
      }
	}
  }
      if(!found) {
      	printf("\tKhong tim thay!\n");
	}
}
// ham sap xep danh muc
void arrangeCategory() {
    char a[10];
    printf("\tSap xep theo ten hay chon (tang / giam): ");
    while(getchar() != '\n');
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0';
    if (strcmp(a, "tang") == 0 || strcmp(a, "giam") == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 10; j++) {
                if ((strcmp(a, "tang") == 0 && strcmp(category[i].CategoryName, category[j].CategoryName) > 0) ||
                    (strcmp(a, "giam") == 0 && strcmp(category[i].CategoryName, category[j].CategoryName) < 0)) {
                    struct Category temp = category[i];
                    category[i] = category[j];
                    category[j] = temp;
                }
            }
        }
    }
	else{
        printf("\tLua chon khong hop le. Vui long thu lai.\n");
        return;
    }
    
}

// ham menu danh muc
void menuCategory() {	
    int choice;
    do {
        printf("\t    QUAN LY DANH MUC\n");
        printf("\t===========================\n");
        printf("\t[1]. Hien thi danh sach danh muc\n");
        printf("\t[2]. Them danh muc moi\n");
        printf("\t[3]. Chinh sua danh muc\n");
        printf("\t[4]. Xoa danh muc\n");
        printf("\t[5]. Tim kiem danh muc\n");
        printf("\t[6]. Sap xep danh muc\n");
        printf("\t[0]. Quay lai menu chinh\n");
        printf("\t===========================\n");
        printf("\tNhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("\tQuay lai menu chinh.\n");
                break;
            case 1:
                printCategory();
                break;
            case 2:
                addCategory();
                break;
            case 3:
            	editCategory();
            	break;
            case 4:
            	deleteCategory();
            	break;
            case 5:
            	searchCategory();
            	break;
            case 6:
            	arrangeCategory();
            	break;
            default:
                printf("\tLua chon khong hop le!\n");
        }
    } while (choice != 0);
}
// ham tai san pham
void loadProductFromFile() {
    FILE *file = fopen("product.txt", "r");
    if (file == NULL) {
        printf("\tLoi: khong the mo file!\n");
        return;
    }
    numberProduct = 0;
    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%d\n", 
                  products[numberProduct].productId, 
                  products[numberProduct].productName, 
                  products[numberProduct].category, 
                  &products[numberProduct].quantity, 
                  &products[numberProduct].price) == 5) {
        numberProduct++;
        if (numberProduct >= 100) {
            printf("\tDanh sach san pham da day!\n");
            break;
        }
    }
    fclose(file);
    printf("\tSan pham da duoc tai len tu file.\n");
}
// ham luu san pham vao file
void saveProductToFile() {
    FILE *file = fopen("product.txt", "w");
    if (file == NULL) {
        printf("\tLoi: khong the mo file!\n");
        return;
    }
    for (int i = 0; i < numberProduct; i++) {
        fprintf(file, "%s,%s,%s,%d,%d\n", 
                products[i].productId, 
                products[i].productName, 
                products[i].category, 
                products[i].quantity, 
                products[i].price);
    }
    fclose(file);
    printf("\tSan pham da duoc luu vao file.\n");
}
// ham them san pham
void addProduct() {
    if (numberProduct >= 100) {
        printf("\tDanh sach san pham da day!\n");
        return;
    }

    struct Product newProduct;

    printf("\tNhap Ma SP: ");
    getchar();
    fgets(newProduct.productId, sizeof(newProduct.productId), stdin);
    newProduct.productId[strcspn(newProduct.productId, "\n")] = '\0';

    for (int i = 0; i < numberProduct; i++) {
        if (strcmp(products[i].productId, newProduct.productId) == 0) {
            printf("\tLoi: Ma san pham da ton tai!\n");
            return;
        }
    }

    printf("\tNhap Ten SP: ");
    fgets(newProduct.productName, sizeof(newProduct.productName), stdin);
    newProduct.productName[strcspn(newProduct.productName, "\n")] = '\0';
    
    printCategory();

    printf("\tNhap Ma Danh Muc: ");
    fgets(newProduct.category, sizeof(newProduct.category), stdin);
    newProduct.category[strcspn(newProduct.category, "\n")] = '\0';

    int validCategory = 0;
    for (int i = 0; i < 10; i++) {
        if (strcmp(category[i].CategoryId, newProduct.category) == 0) {
            validCategory = 1;
            break;
        }
    }
    if (!validCategory) {
        printf("\tLoi: Ma danh muc khong ton tai!\n");
        return;
    }

    printf("\tNhap So Luong: ");
    scanf("%d", &newProduct.quantity);
    getchar();
    if (newProduct.quantity <= 0) {
        printf("\tLoi: So luong khong hop le!\n");
       	getchar();
        return;
    }

    printf("\tNhap Gia: ");
    scanf("%d", &newProduct.price);
    getchar();
    if (newProduct.price <= 0) {
        printf("\tLoi: Gia khong hop le!\n");
        return;
    }

    products[numberProduct] = newProduct;
    numberProduct++;

    printf("\tThem san pham thanh cong!\n");
    saveProductToFile();
    return;
}
// ham in danh sach san pham
void printProduct() {
    if (numberProduct == 0) {
        printf("\tDanh sach san pham rong!\n");
        return;
    }
    printf("\t+-----+----------+--------------------+------------+----------+----------+\n");
    printf("\t| STT | Ma SP    | Ten San Pham       | Danh Muc   | So Luong | Gia      |\n");
    printf("\t+-----+----------+--------------------+------------+----------+----------+\n");
    for (int i = 0; i < numberProduct; i++) {
        printf("\t| %-3d | %-8s | %-18s | %-10s | %-8d | %-8d |\n", 
               i + 1, 
               products[i].productId, 
               products[i].productName, 
               products[i].category,
               products[i].quantity, 
               products[i].price);
    }
    printf("\t+-----+----------+--------------------+------------+----------+----------+\n");
}

void editProduct() {
	char id[10];
	int found = 0;
	printf("\tHay nhap ma SP muon sua: ");
	getchar();
	fgets(id, sizeof(id), stdin);
	id[strcspn(id, "\n")] = '\0';
	
	for(int i = 0; i < numberProduct; i++){
		if(strcmp(id, products[i].productId) == 0){
			found = 1;
			printf("\tThong tin danh muc hien tai:\n");
			printf("\tMa SP: %s\n", products[i].productId);
			printf("\tTen SP: %s\n", products[i].productName);
			printf("\tMa danh muc: %s\n", products[i].category);
			printf("\tSo luong: %d\n", products[i].quantity);
			printf("\tGia: %d\n", products[i].price);
			printf("\n");
			printf("\tSua san pham: \n");
			
//			printf("\tMa SP: ");
//			getchar();
//			fgets(products[i].productId, sizeof(products[i].productId), stdin);
//			products[i].productId[strcspn(products[i].productId, "\n")] = '\0';
					
			printf("\tTen SP: ");
			getchar();
			fgets(products[i].productName, sizeof(products[i].productId), stdin );
			products[i].productName[strcspn(products[i].productName, "\n")] = '\0';
			
			printf("\tMa danh muc: ");
			fgets(products[i].category, sizeof(products[i].category),stdin);
			products[i].category[strcspn(products[i].category, "\n")] = '\0';
			
			printf("\tSo luong: ");
			scanf("%d", &products[i].quantity);
			if(products[i].quantity < 0){
				printf("\tSo luong ko hop le!\n");
			}
			
			printf("\tGia: ");
			scanf("%d", &products[i].price);
			if(products[i].price < 0){
				printf("\t Gia khong hop le!\n");
			}
			printf("\tSua san pham thanh cong\n");
			break;
		}
	}
	if(!found) {
		printf("\tKhong tim thay ID\n");
		return;
	}else{
		saveProductToFile();
	}
}

void deleteProduct() {
	char x[10];
	char a[10];
	int found = 0;
	printf("\tHay nhap ma SP muon xoa: ");
	getchar();
	fgets(x, sizeof(x), stdin);
	x[strcspn(x, "\n")] = '\0';
	
	for(int i = 0; i < numberProduct; i++){
		if(strcmp(x, products[i].productId) == 0) {
			found = 1;
			break;
		}
	}
	if(!found) {
		printf("\tKhong tim thay ma SP\n");
		return;
	}
	printf("\tBan co chac chan muon xoa (yes/no): ");
	fgets(a, sizeof(a),stdin);
	a[strcspn(a, "\n")] = '\0';
	
	if(strcmp(a, "yes") == 0){
		for (int i = 0; i < 10; i++) {
        if (strcmp(x, products[i].productId) == 0) {
            found = 1;
            for(int j = i; j < 10; j++){
            	products[j] = products[j + 1];
			}
		strcpy(products[numberProduct - 1].productId, "");
        strcpy(products[numberProduct - 1].productName, "");
        strcpy(products[numberProduct - 1].category, "");
        products[numberProduct - 1].quantity = 0;
        products[numberProduct - 1].price = 0;
        printf("\tDa xoa danh muc thanh cong!\n");
        break;
        }
    }
    saveCategoryToFile();
  	}
  else{
  	printf("\tHoan tac xoa\n");
  }	
}
void menuProduct() {
    int choice;
    do {
        printf("\t    PRODUCT MANAGEMENT MENU\n");
        printf("\t===========================\n");
        printf("\t[1]. Them san pham moi\n");
        printf("\t[2]. Hien thi danh sach san pham\n");
        printf("\t[3]. Chinh sua san pham\n");
        printf("\t[4]. Xoa san pham\n");
        printf("\t[0]. Quay lai menu chinh\n");
        printf("\t===========================\n");
        printf("\tNhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("\tQuay lai menu chinh.\n");
                break;
            case 1:
                addProduct();
                break;
            case 2:
                printProduct();
                break;
            case 3:
            	editProduct();
            	break;
            case 4:
            	deleteProduct();
            	break;
            default:
                printf("\tLua chon khong hop le!\n");
        }
    } while (choice != 0);
}


void menuAdmin(){
	int choice;
	do{
		printf("\t	ADMIN MENU\n");
		printf("\t===========================\n");
		printf("\t[1]. Category management\n");
		printf("\t[2]. Product management\n");
		printf("\t[3]. User Guideline\n");
		printf("\t[4]. About Us\n");
		printf("\t[0]. Exit the program\n");
		printf("\t===========================\n");
		printf("\tEnter the choice: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 0:
				printf("Quay lai menu chinh\n");
				break;
			case 1:
				menuCategory();			
				break;
			case 2:
				menuProduct();
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				printf("\tLua chon khong hop le!\n");
		}
	}while (choice != 0);
}
int main () {
	createAdminFileIfNotExists();
	loadCategoryFromFile();
	loadProductFromFile();
	int choice;
	do{
		printf("***Store Management System Using C***\n");
		printf("\n");
		printf("\tCHOOSE YOUR ROLE\n");
		printf("\t=====================\n");
		printf("\t[1]. Admin\n");
		printf("\t[2]. Customer\n");
		printf("\t[0]. Exit the program\n");
		printf("\t=====================\n");
		printf("\tEnter the choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				printf("\tBan da thoat chuong trinh");
				break;
			case 1:
				menuAdmin();
//				if (loginAccount()) {
//                    menuAdmin();
//                } else {
//                    printf("\tDang nhap khong thanh cong.\n");
//                }
				break;
			case 2:
				break;
		}
	}while(choice != 0);
	
	saveCategoryToFile();
	saveProductToFile();
	return 0;
}

