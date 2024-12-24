#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Dish {
    int id;
    char name[20];
    int price;
} Dish;
void swap(Dish *a, Dish *b);
void softT(Dish *menu, int *length);
void softG(Dish *menu, int *length);
void MENU();
void printMenu(Dish *menu, int *length);
void addMenu(Dish *menu, int *length);
void correct(Dish *menu, int *length);
void deleteMenu(Dish *menu, int *length);
void search(Dish *menu,int *length,char x);
int main() {
    srand(time(0));
    int options, length = 5;
    char AorB;
    Dish menu[100];
    for (int i = 0; i < 5; i++) {
        menu[i].id = i + 1;
        sprintf(menu[i].name, "mon %c", 'a' + i);
        menu[i].price = rand() % 50 + 50;
    }
    while (1) {
        printf("\n");
        MENU();
        scanf("%d", &options);
        getchar();
        switch (options) {
            case 1:
                printf("\n");
                printMenu(menu, &length);
                break;
            case 2:
                printf("\n");
                addMenu(menu, &length);
                break;
            case 3:
                printf("\n");
                correct(menu, &length);
                break;
            case 4:
                printf("\n");
                deleteMenu(menu, &length);
                break;
            case 5:
                printf("a. Sap xep tang dan theo price.\n");
                printf("b. Sap xep giam dan theo price.\n");
                printf("Lua chon cua ban: ");
                scanf("%c", &AorB);
                if (AorB == 'a'){
                    printf("\n");
                    softT(menu, &length);
                }
                else if (AorB == 'b'){
                    printf("\n");
                    softG(menu, &length);
                }
                else printf("Khong hop le\n");
                break;
            case 6:
                printf("a. tim kiem tuyen tinh.\n");
                printf("b. tim kiem nhi phan.\n");
                printf("Lua chon cua ban: ");
                scanf("%c", &AorB);
                getchar();
                if (AorB == 'a'){
                    printf("\n");
                    search(menu,&length,AorB);
                }
                else if (AorB == 'b'){
                    printf("\n");
                    search(menu,&length,AorB);
                }
                else printf("Khong hop le\n");
                break;
            case 7:
                return 0;
            default:
                printf("Khong hop le\n");
                break;
        }
    }
    return 0;
}

void MENU() {
    printf("MENU\n");
    printf("1. In ra gia tri cac phan tu co trong menu mon an.\n");
    printf("2. Them mot phan tu vao vi tri chi dinh\n");
    printf("3. Sua mot phan tu o vi tri chi dinh\n");
    printf("4. Xoa mot phan tu o vi tri chi dinh\n");
    printf("5. Sap xep cac phan tu.\n");
    printf("6. Thoat\n");
    printf("Lua chon cua ban: ");
}
void printMenu(Dish *menu, int *length) {
    for (int i = 0; i < *length; i++) {
        printf("%d. %s: %d vnd\n", i + 1, menu[i].name, menu[i].price);
    }
}
void addMenu(Dish *menu, int *length) {
    int index;
    printf("Nhap vi tri muon them: 1->%d\n", *length);
    scanf("%d", &index);
    getchar();
    if (index >= 1 && index <= *length + 1) {
        for (int i = *length; i >= index; i--) menu[i] = menu[i - 1];
        printf("Nhap thong tin mon moi:\n");
        printf("ID: ");
        scanf("%d", &menu[index - 1].id);
        printf("Gia: ");
        scanf("%d", &menu[index - 1].price);
        getchar();
        printf("Ten mon an: ");
        fgets(menu[index - 1].name, sizeof(menu[index - 1].name), stdin);
        menu[index - 1].name[strcspn(menu[index - 1].name, "\n")] = '\0';
        (*length)++;
    } else printf("Khong hop le\n");
}
void correct(Dish *menu, int *length) {
    int id;
    printf("Nhap id muon sua: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < *length; i++) {
        if (menu[i].id == id) {
            printf("Nhap thong tin moi:\n");
            printf("ID: ");
            scanf("%d", &menu[i].id);
            printf("Gia: ");
            scanf("%d", &menu[i].price);
            getchar();
            printf("Ten mon an: ");
            fgets(menu[i].name, sizeof(menu[i].name), stdin);
            menu[i].name[strcspn(menu[i].name, "\n")] = '\0';
            return;
        }
    }
    printf("Mon an khong co trong menu\n");
}
void deleteMenu(Dish *menu, int *length) {
    int id;
    printf("Nhap id muon xoa: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < *length; i++) {
        if (menu[i].id == id) {
            for (int j = i; j < *length - 1; j++){
                menu[j]=menu[j + 1];
            }
            (*length)--;
            return;
        }
    }
    printf("Khong hop le\n");
}
void swap(Dish *a, Dish *b) {
    Dish temp = *a;
    *a = *b;
    *b = temp;
}
void softT(Dish *menu, int *length) {
    for (int i = 0; i < *length - 1; i++) {
        for (int j = 0; j < *length - 1 - i; j++) {
            if (menu[j].price > menu[j + 1].price){
                swap(&menu[j], &menu[j + 1]);
            }
        }
    }
}
void softG(Dish *menu, int *length) {
    for (int i = 0; i < *length - 1; i++) {
        for (int j = 0; j < *length - 1 - i; j++) {
            if (menu[j].price < menu[j + 1].price){
                swap(&menu[j], &menu[j + 1]);
            }
        }
    }
}
void search(Dish *menu,int *length,char x){
    printf("nhap id muon tim kiem. ");
    int id;
    scanf("%d",&id);
    getchar();
    if(x=='a'){
        for(int i=0; i<*length; i++){
            if(menu[i].id==id){
                printf("mon ban can tim la:\n");
                printf("%d. %s: %d vnd\n", i + 1, menu[i].name, menu[i].price);
                break;
            }
        }
    }else if(x=='b'){
        softT(&menu,*length);
        int left=0;
        int right=*length-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(menu[mid].id==id){
                printf("mon ban can tim la:\n");
                printf("%d. %s: %d vnd\n", mid + 1, menu[mid].name, menu[mid].price);
                break;
            }
            if(menu[mid].id>id){
                right=mid-1;
            }else if(menu[mid].id<id){
                left=mid+1;
            }
        }
    }
}
