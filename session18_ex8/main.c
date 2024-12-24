#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct student{
    int id;
    int age;
    char name[20];
    char phone[12];
}student;
void printStudent(struct student *sv,int *length);
void addStudent(struct student *sv,int *length);
int main()
{
    int length=5;
    srand(time(0));
    student sv[50];
    for(int i=0; i<length; i++){
        sv[i].id=i+1;
        sv[i].age=rand()%4+18;
        sprintf(sv[i].name,"%c",'a'+i);
        sprintf(sv[i].phone,"%010d",i+1);
    }
    printStudent(sv,&length);
    addStudent(sv,&length);
    printStudent(sv,&length);
    printf("Hello world!\n");
    return 0;
}
void addStudent(struct student *sv, int *length){
    printf("nhap vi tri muon them: 0->%d\n",*length);
    int index;
    scanf("%d",&index);
    getchar();
    if(index>=0 && index<=*length){
        for(int i=*length; i>=index; i--){
            sv[i]=sv[i-1];
        }
        printf("nhap thong tin sv moi:\n");
        printf("ID: ");
        scanf("%d", &sv[index].id);
        printf("Tuoi: ");
        scanf("%d", &sv[index].age);
        getchar();
        printf("Ten: ");
        fgets(sv[index].name, sizeof(sv[index].name), stdin);
        sv[index].name[strcspn(sv[index].name, "\n")] = '\0';
        printf("So dien thoai: ");
        fgets(sv[index].phone, sizeof(sv[index].phone), stdin);
        sv[index].phone[strcspn(sv[index].phone, "\n")] = '\0';
        fflush(stdin);
        (*length)++;
    }else{
        printf("khong hop le:\n");
    }
}
void printStudent(struct student *sv, int *length){
    for(int i=0; i<*length; i++){
        printf("id sv[%d]: %d\n",i+1,sv[i].id);
        printf("age sv[%d]: %d\n",i+1,sv[i].age);
        printf("ten sv[%d]: %s\n",i+1,sv[i].name);
        printf("so dien thoai sv[%d]: %s\n\n",i+1,sv[i].phone);
    }
}
