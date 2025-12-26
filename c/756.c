#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Kids{
    int height;
    struct Kids *next;
}Kids;

Kids* Create(int *m){
    Kids *head = NULL;
    Kids *tail = NULL;
    int N, add_height;
    scanf("%d %d", &N, m);
    for(int num = 0;num < N; num++){
        Kids *new = (Kids*)malloc(sizeof(Kids));
        new->next = NULL;
        scanf("%d", &new->height);
        if(head == NULL){
            head = new;
            tail = new;
        }
        else{
            tail->next = new;
            tail = new;
        }
    }
    return head;
}

int main(){
    int add_height_main;
    Kids *head = Create(&add_height_main);
    Kids *p = (Kids*)malloc(sizeof(Kids));
    p->height = add_height_main;
    p->next = NULL;
    Kids *check = head;
    Kids *pre = NULL;
    while(check != NULL && check->height < add_height_main){
        pre = check;
        check = check->next;
    }
    if(pre == NULL){
        p->next = head;
        head = p;
    }
    else{
        pre->next = p;
        p->next = check;
    }
    Kids *pull = head;
    while(pull != NULL){
        printf("%d ", pull->height);
        pull = pull->next;
    }
    return 0;
}

/*
试题名称	递增链表的插入
时间限制:	1 秒
内存限制:	10000KB

问题描述
幼儿园小朋友要玩老鹰捉小鸡的游戏，老师把在场的小朋友按身高递增的顺序排好了队，这时有一位小朋友来晚了，老师需要把他按照身高插入到排好的队列中，请你帮助幼儿园老师把这位晚到的小朋友插入到队列中合适的位置。

输入说明
输入的第1行包含原队列长度N（任意int范围内的非负整数）与待插入的小朋友的身高值M（单位为cm）；第2行包含N个递增的小朋友的身高值代表原递增数列。

输出说明
根据此递增数列，构造出递增链表，然后将M插入到链表中，输出插入后的链表对应的数列。数字间隔一个空格，但末尾不能有空格。

输入样例
6 100
99 102 104 105 107 110

输出样例
99 100 102 104 105 107 110

*/