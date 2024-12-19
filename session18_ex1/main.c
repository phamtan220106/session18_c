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
    strcpy(st1.name,"pham nhat tan");
    st1.age=18;
    strcpy(st1.numberPhone,"8254284");
    printf("ten: %s\n",st1.name);
    printf("tuoi: %d\n",st1.age);
    printf("so dien thoai: %s\n",st1.numberPhone);
}
