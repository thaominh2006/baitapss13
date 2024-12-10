#include <stdio.h>
int timUcln(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main() {
    int number1, number2;
    printf("Nhap so nguyen thu nhat: ");
    scanf("%d", &number1);
    printf("Nhap so nguyen thu hai: ");
    scanf("%d", &number2);
    int ucln = timUcln(number1, number2);
    printf("Uoc chung lon nhat cua %d va %d la: %d\n", number1, number2, ucln);

    return 0;
}
