#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
    char id[30];
    char name[30];
    char sex;
    struct Student *next;
}Student;

Student* Create(){
    Student *head = NULL;
    Student *new, *tail;
    char temp_name[30];
    scanf("%s", temp_name);
    while(temp_name[0] != '#'){
        new = (Student*)malloc(sizeof(Student));
        strcpy(new->name, temp_name);
        scanf("%s %c\n", new->id, &new->sex);     
        new->next = NULL;
        if(head == NULL){
            head = new;
            tail = new;
        }
        else{
            tail->next = new;
            tail = new;
        }
        scanf("%s", temp_name);
    }
    return head;
}

Student* Delete(Student *head, char target[30]){
    Student *p = head;
    Student *pre = NULL;
    while(p != NULL){
        if(strcmp(p->id, target) == 0)
        {
            if(p == head){
                head = p->next;
            }
            else{
                pre->next = p->next;
            }
            free(p);
            return head;
        }
        else{
            pre = p;
            p = p->next;
        }
    }
    return head;
}

int main(){
    Student *Linklist = Create();
    char target[30];
    scanf("%s", &target);
    Student *t = Linklist;
    int flag = 0;
    while(t != NULL){
        if(strcmp(t->id, target) == 0){
            flag = 1;
            break;
        }
        t = t->next;
    }
    Linklist = Delete(Linklist, target);
    t = Linklist;
    if(flag == 0){
        printf("No");
    }
    else{
        while(t != NULL){
            printf("%s %s %c\n", t->name, t->id, t->sex);
            t = t->next;
        }
    }
    return 0;
}

/*
试题名称	学生信息管理
时间限制:	1 秒
内存限制:	10000KB

问题描述
某班学生的信息存放在一个线性单链表中，但每学期都有学生因故退学。现要求根据退学学生的学号，将其信息从链表中删除。假设学生的数据只保存姓名、学号、性别，并采用结构体类型描述。

输入说明
输入n个学生数据(1<=n<=10)。每行一个学生信息，包括：姓名(不超过20个字符的字符串)、学号(整形)、性别(字符)，以空格分隔。学生数据以#结束，并在下一行输入退学学生的学号。

输出说明
若链表中有退学学生，输出删除该学生后的学生数据；如果链表中没有该学生,则输出错误信息No。

输入样例
例1：
LiDong 1001 M
ZhaoJian 1002 M
ChenKai 1003 M
LiXia 1004 F
WangHong 1005 F
QianLi 1006 F
ZhouQiang 1007 M
#
1003

例2：
LiDong 1001 M
ZhaoJian 1002 M
ChenKai 1003 M
LiXia 1004 F
WangHong 1005 F
QianLi 1006 F
ZhouQiang 1007 M
#
1008

输出样例
例1：
LiDong 1001 M
ZhaoJian 1002 M
LiXia 1004 F
WangHong 1005 F
QianLi 1006 F
ZhouQiang 1007 M

例2：
No
*/