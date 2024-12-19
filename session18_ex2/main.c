#include <stdio.h>
#include <stdlib.h>
void student();
int main()
{
    student();
    return 0;
}
void student(){
    struct student {
        char name[30];
        int age;
        char numberPhone[15];
    };
    struct student st1;
    printf("Ten sinh vien:\n");
    fgets(st1.name,sizeof(st1.name),stdin);
    printf("Tuoi:\n");
    scanf("%d",&st1.age);
    getchar();
    printf("so dien thoai:\n");
    fgets(st1.numberPhone,sizeof(st1.numberPhone),stdin);
    printf("ten: %s",st1.name);
    printf("tuoi: %d\n",st1.age);
    printf("so dien thoai: %s",st1.numberPhone);
}
