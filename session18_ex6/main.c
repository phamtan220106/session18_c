#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Để sử dụng strlen và strcspn

void student();

struct student {
    int id;
    char name[30];
    int age;
    char numberPhone[15];
};

int main() {
    student();
    return 0;
}

void student() {
    struct student st[50];
    char x='a';
    for(int i=0; i<5; i++){
        st[i].id=i+1;
        sprintf(st[i].name, "Sinh Vien %c", x++);
        st[i].age=18;
        sprintf(st[i].numberPhone, 100000+i);
    }
    for(int i = 0; i < 5; i++) {
        printf("id sv[%d]: %d\n", i + 1, st[i].id);
        printf("ten sv[%d]: %s\n", i + 1, st[i].name);
        printf("tuoi sv[%d]: %d\n", i + 1, st[i].age);
        printf("so dien thoai sv[%d]: %s\n\n", i + 1, st[i].numberPhone);
    }
    int menu, ID = 5;
    while(1) {
        printf("1. Them sinh vien.\n");
        printf("2. Thoat.\n");
        printf("Lua chon: ");
        scanf("%d", &menu);
        getchar();
        switch(menu) {
            case 1:
                if (ID < 50) {
                    printf("ten sinh vien: ");
                    fgets(st[ID].name, sizeof(st[ID].name), stdin);
                    st[ID].name[strcspn(st[ID].name, "\n")] = '\0';
                    printf("tuoi: ");
                    scanf("%d", &st[ID].age);
                    getchar();
                    printf("so dien thoai: ");
                    fgets(st[ID].numberPhone, sizeof(st[ID].numberPhone), stdin);
                    st[ID].numberPhone[strcspn(st[ID].numberPhone, "\n")] = '\0';
                    printf("id sv[%d]: %d\n", ID + 1, ID + 1);
                    printf("ten sv[%d]: %s\n", ID + 1, st[ID].name);
                    printf("tuoi sv[%d]: %d\n", ID + 1, st[ID].age);
                    printf("so dien thoai sv[%d]: %s\n\n", ID + 1, st[ID].numberPhone);
                    ID++;
                } else {
                    printf("Khong the them sinh vien moi. Danh sach day!\n");
                }
                break;
            case 2:
                return;
            default:
                printf("Khong hop le!!\n");
                break;
        }
    }
}
