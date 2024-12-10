#include <stdio.h>
#include <stdbool.h>

bool laSoNguyenTo(int num);
void nhapMaTran(int maTran[][100], int n, int m);
void inMaTran(int maTran[][100], int n, int m);
void inGocMaTran(int maTran[][100], int n, int m);
void inDuongBien(int maTran[][100], int n, int m);
void inDuongCheo(int maTran[][100], int n, int m);
void inSoNguyenTo(int maTran[][100], int n, int m);
void displayMenu();
int main() {
    int n, m;
    int maTran[100][100];
    int luaChon;
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", &n);
    printf("Nhap so cot cua mang tran: ");
    scanf("%d", &m);

    do {
        displayMenu();
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                nhapMaTran(maTran, n, m);
                break;
            case 2:
                inMaTran(maTran, n, m);
                break;
            case 3:
                inGocMaTran(maTran, n, m);
                break;
            case 4:
                inDuongBien(maTran, n, m);
                break;
            case 5:
                inDuongCheo(maTran, n, m);
                break;
            case 6:
                inSoNguyenTo(maTran, n, m);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (luaChon != 7);

    return 0;
}

void displayMenu(){
    printf("\nMENU\n");
    printf("1. Nhap gia tri cac phan tu cua ma tran.\n");
    printf("2. In gia tri cac phan tu cua ma tran theo ma tran.\n");
    printf("3. In ra cac phan tu o goc theo ma tran.\n");
    printf("4. In ra cac phan tu nam tren duong bien theo ma tran.\n");
    printf("5. In ra cac phan tu nam tren duong cheo chinh va duong cheo phu theo ma tran.\n");
    printf("6. In ra cac phan tu la so nguyen to theo ma tran.\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}

void nhapMaTran(int maTran[][100], int n, int m) {
    printf("Nhap gia tri cac phan tu cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("maTran[%d][%d] = ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }
}


void inMaTran(int maTran[][100], int n, int m) {
    printf("Ma tran hien tai:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", maTran[i][j]);
        }
        printf("\n");
    }
}


void inGocMaTran(int maTran[][100], int n, int m) {
    printf("Cac phan tu o goc cua ma tran la:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == m - 1) ||
                (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
                printf("%3d ", maTran[i][j]);
            } else {
                printf("  0 ");
            }
        }
        printf("\n");
    }
}


void inDuongBien(int maTran[][100], int n, int m) {
    printf("Cac phan tu nam tren duong bien cua ma tran la:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("%3d ", maTran[i][j]);
            } else {
                printf("  0 ");
            }
        }
        printf("\n");
    }
}


void inDuongCheo(int maTran[][100], int n, int m) {
    printf("Cac phan tu nam tren duong cheo chinh va cheo phu la:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j || i + j == n - 1) {
                printf("%3d ", maTran[i][j]);
            } else {
                printf("  0 ");
            }
        }
        printf("\n");
    }
}


void inSoNguyenTo(int maTran[][100], int n, int m) {
    printf("Cac phan tu la so nguyen to trong ma tran la:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num = maTran[i][j];
            int laSoNguyenTo = 1; 

            if (num < 2) {
                laSoNguyenTo = 0; 
            } else {
                for (int k = 2; k * k <= num; k++) {
                    if (num % k == 0) {
                        laSoNguyenTo = 0; 
                        break;
                    }
                }
            }

            if (laSoNguyenTo) {
                printf("%3d ", num); 
            } else {
                printf("  0 "); 
            }
        }
        printf("\n");
    }
}
