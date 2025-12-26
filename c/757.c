#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Linklist{
    int data;
    struct Linklist* next;
}Linklist;

Linklist* Create(int count){
    if(count <= 0){
        return NULL;
    }
    else{
        Linklist *head = NULL;
        Linklist *tail = NULL;
        for(int i=0;i < count;i++){
            Linklist *p = (Linklist*)malloc(sizeof(Linklist));
            p->next = NULL;
            scanf("%d", &p->data);
            if(head == NULL){
                head = p;
                tail = p;
            }
            else{
                tail->next = p;
                tail = p;
            }
        }
        return head;
    }
}

Linklist* Reverse(Linklist* head){
    Linklist *cur = head;
    Linklist *next_rev = NULL;
    Linklist *pre = NULL;
    while(cur != NULL){
        next_rev = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next_rev;
    }
    return pre;
}

void Printlist(Linklist *head){
    Linklist* t = head;
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    Linklist* all_lists[50];
    Linklist* rev_lists[50];
    for(int j = 0;j < n;j++){
        int count;
        scanf("%d", &count);
        all_lists[j] = Create(count);
        rev_lists[j] = Reverse(all_lists[j]);
    }
    for(int k = 0;k < n;k++){
        Printlist(rev_lists[k]);
    }
    return 0;
}

