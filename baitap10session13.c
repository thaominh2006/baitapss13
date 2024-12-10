#include <stdio.h>

int arr[100]; 
int soPhanTu = 0;    
void displayMenu();
void nhapMang();
void inMang();
void themPhanTu();
void suaPhanTu();
void xoaPhanTu();
void sapXepTangDan();
void sapXepGiamDan();
void timKiemTuyenTinh();
void timKiemNhiPhan();

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                nhapMang();
                break;
            case 2:
                inMang();
                break;
            case 3:
                themPhanTu();
                break;
            case 4:
                suaPhanTu();
                break;
            case 5:
                xoaPhanTu();
                break;
            case 6: {
                int luaChonCon;
                printf("\na. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Lua chon cua ban (1: Giam dan, 2: Tang dan): ");
                scanf("%d", &luaChonCon);
                if (luaChonCon == 1)
                    sapXepGiamDan();
                else
                    sapXepTangDan();
                inMang();
                break;
            }
            case 7: {
                int luaChonCon;
                printf("\na. Tim kiem tuyen tinh.\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Lua chon cua ban (1: Tuyen tinh, 2: Nhi phan): ");
                scanf("%d", &luaChonCon);
                if (luaChonCon == 1)
                    timKiemTuyenTinh();
                else {
                    sapXepTangDan();
                    timKiemNhiPhan();
                }
                break;
            }
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}
void displayMenu(){
    printf("\n------MENU------\n");
	printf("1. Nhap so phan tu can nhap va gia tri cac phan tu.\n");
	printf("2. In ra cac gia tri phan tu dang quan li.\n");
	printf("3. Them mot phan tu vao vi tri chi dinh.\n");
	printf("4. Sua mot phan tu o vi tri chi dinh.\n");
	printf("5. Xoa  mot phan tu o vi tri chi dinh.\n");
	printf("6. Sap xep cac phan tu.\n");
	printf("7. Tim kiem phan tu nhap vao.\n");
	printf("8. Thoat.\n");
	printf("\nLua chon cua ban la: ");
}
void nhapMang() {
    printf("Nhap so phan tu: ");
    scanf("%d", &soPhanTu);
    for (int i = 0; i < soPhanTu; i++) {
        printf("Nhap phan tu [%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void inMang() {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < soPhanTu; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themPhanTu() {
    int position, giaTri;
    printf("Nhap vi tri ban muon them (1-%d): ", soPhanTu + 1);
    scanf("%d", &position);
    printf("Moi ban nhap gia tri muon them: ");
    scanf("%d", &giaTri);
    for (int i = soPhanTu; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = giaTri;
    soPhanTu++;
    printf("Them phan tu thanh cong.\n");
}

void suaPhanTu() {
    int position, giaTri;
    printf("Nhap vi tri muon sua (1-%d): ", soPhanTu);
    scanf("%d", &position);
    if (position < 1 || position > soPhanTu) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &giaTri);
    arr[position - 1] = giaTri;
    printf("Sua phan tu thanh cong.\n");
}

void xoaPhanTu() {
    int position;
    printf("Nhap vi tri muon xoa (1-%d): ", soPhanTu);
    scanf("%d", &position);
    for (int i = position - 1; i < soPhanTu - 1; i++) {
        arr[i] = arr[i + 1];
    }
    soPhanTu--;
    printf("Xoa phan tu thanh cong.\n");
}

void sapXepTangDan() {
    for (int i = 0; i < soPhanTu - 1; i++) {
        for (int j = i + 1; j < soPhanTu; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sapXepGiamDan() {
    for (int i = 0; i < soPhanTu - 1; i++) {
        for (int j = i + 1; j < soPhanTu; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void timKiemTuyenTinh() {
    int x;
    int check=-1;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < soPhanTu; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d duoc tim thay o vi tri %d.\n", x, i + 1);
            check =1;
        }
    }
    if (check==-1){
        printf("Phan tu %d khong ton tai.\n", x);
    }
    
}

void timKiemNhiPhan() {
    int x, start = 0, end = soPhanTu - 1;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == x) {
            printf("Phan tu %d duoc tim thay o vi tri %d.\n", x, mid + 1);
            return;
        }
        if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    printf("Phan tu khong ton tai.\n", x);
}
