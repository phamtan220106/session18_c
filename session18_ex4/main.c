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
        int id;
        char name[30];
        int age;
        char numberPhone[15];
    };
    struct student st[5];
    for(int i=0; i<5; i++){
        st[i].id=i+1;
        printf("id sv[%d]: %d\n",i+1,i+1);
        printf("nhap ten sv[%d] :",i+1);
        fgets(st[i].name,sizeof(st[i].name),stdin);
        st[i].name[strcspn(st[i].name, "\n")] = '\0';
        printf("tuoi sv[%d]: ",i+1);
        scanf("%d",&st[i].age);
        getchar();
        printf("so dien thoai sv[%d]: ",i+1);
        fgets(st[i].numberPhone,sizeof(st[i].numberPhone),stdin);
        st[i].numberPhone[strcspn(st[i].numberPhone,"\n")]='\0';
    }
    for(int i=0; i<5; i++){
        printf("id sv[%d]: %d\n",i,i+1);
        printf("ten sv[%d] : %s",i+1,st[i].name);
        printf("tuoi sv[%d]: %d\n",i+1,st[i].age);
        printf("so dien thoai sv[%d]: %s\n\n",i+1,st[i].numberPhone);
    }
}
