#include <stdio.h>

int main() {
    double a, b, c, delta, x1, x2;

    printf("Nhap he so a, b, c cua phuong trinh bac hai \n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Phuong trinh vo so nghiem.\n");
            } else {
                printf("Phuong trình vo nghiem.\n");
            }
        } else {
            x1 = -c / b;
            printf("Phuong trinh bac nhat co mot nghiem duy nhat: x = %.2lf\n", x1);
        }
    } else {
        delta = b * b - 4 * a * c;
        
        if (delta > 0) {
            x1 = (-b + delta) / (2 * a);
            x2 = (-b - delta) / (2 * a);
            printf("Phuong trinh có hai nghiem phan biet: x1 = %.2lf và x2 = %.2lf\n", x1, x2);
        } else if (delta == 0) {
            x1 = -b / (2 * a);
            printf("Phuong trinh có nghiem kep: x = %.2lf\n", x1);
        } else {
            printf("Phuong trinh vo nghiem.\n");
        }
    }

    return 0;
}

