#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    struct student st[50];
    char x='a';
    for(int i=0; i<50; i++){
            st[i].id=i+1;
        }
    for(int i=0; i<5; i++){
        st[i].id=i+1;
        sprintf(st[i].name, "Sinh Vien %c", x++);
        st[i].age=18;
        sprintf(st[i].numberPhone, 100000+i);
    }
    for(int i=0; i<5; i++){
        printf("id sv[%d]: %d\n",i,st[i].id);
        printf("ten sv[%d] : %s\n",i+1,st[i].name);
        printf("tuoi sv[%d]: %d\n",i+1,st[i].age);
        printf("so dien thoai sv[%d]: %s\n\n",i+1,st[i].numberPhone);
    }
    int id;
    printf("sinh vien muon sua: id=  ");
    scanf("%d",&id);
    getchar();
    for(int i=0; i<50; i++){
        if(st[i].id==id){
            fflush(stdin);
            printf("ten sv moi : ");
            fgets(st[i].name,sizeof(st[i].name),stdin);
            st[i].name[strcspn(st[i].name,"\n")]='\0';
            printf("tuoi moi: ");
            scanf("%d",&st[i].age);
            printf("tem moi cua sv[%d] : %s\n",i+1,st[i].name);
            printf("tuoi cua sv[%d]: %d\n",i+1,st[i].age);
            break;
        }
    }

}
