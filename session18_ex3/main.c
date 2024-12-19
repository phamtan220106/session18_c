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
    struct student st[5];
    for(int i=0; i<5; i++){
        printf("nhap ten sv[%d] :",i+1);
        fgets(st[i].name,sizeof(st[i].name),stdin);
        printf("tuoi sv[%d]: ",i+1);
        scanf("%d",&st[i].age);
        printf("so dien thoai sv[%d]: ",i+1);
        fflush(stdin);
        fgets(st[i].numberPhone,sizeof(st[i].numberPhone),stdin);
    }
    for(int i=0; i<5; i++){
        printf("ten sv[%d] : %s",i+1,st[i].name);
        printf("tuoi sv[%d]: %d\n",i+1,st[i].age);
        printf("so dien thoai sv[%d]: %s\n",i+1,st[i].numberPhone);
    }
}
