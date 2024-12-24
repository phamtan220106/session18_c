#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct Student {
    int id;
    int age;
    char name[2];
    char phone[12];
}Student;
void deleteStudent(struct Student *sv,int *length);
void printStudent(struct Student *sv,int *length);
int main()
{
    int length=5;
    srand(time(0));
    Student sv[50];
    for(int i=0; i<5; i++){
        sv[i].id=i+1;
        sv[i].age=(rand()%4)+18;
        sprintf(sv[i].name,"%c",'a'+i);
        sprintf(sv[i].phone,"%010d",i+1);
    }
    printStudent(sv,&length);
    deleteStudent(sv,&length);
    printStudent(sv,&length);
    printf("Hello world!\n");
    return 0;
}
void deleteStudent(struct Student *sv, int *length){
    printf("nhap ten sv muon xoa:\n");
    char name[30];
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]='\0';
    for(int i=0; i<*length; i++){
        if(strcmp(sv[i].name,name)==0){
            printf("sv sep %c o vi tri thu %d da bi xoa.\n",sv[i].name,i+1);
            for(int j=i; j<*length; j++){
                sv[j]=sv[j+1];
            }
            (*length)--;
            return ;
        }
    }
    printf("sv khong ton tai.\n");
}
void printStudent(struct Student *sv, int *length){
    for(int i=0; i<*length; i++){
        printf("id sv[%d]: %d\n",i+1,sv[i].id);
        printf("age sv[%d]: %d\n",i+1,sv[i].age);
        printf("ten sv[%d]: %s\n",i+1,sv[i].name);
        printf("so dien thoai sv[%d]: %s\n\n",i+1,sv[i].phone);
    }
}
