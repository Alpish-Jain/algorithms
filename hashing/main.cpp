#include <bits/stdc++.h>

using namespace std;
struct Node{
int data;
struct Node* next;
};
//Inserting in a sorted manner
void SortedInsert(struct Node **h,int key){

struct Node *t,*q;
struct Node *p=*h;
t=(struct Node *)malloc(sizeof(struct Node));
t->data=key;
t->next=NULL;
if(*h==NULL){
    *h=t;
}
else{
    while(p && p->data<key){
            q=p;
        p=p->next;
    }
    if(p==*h){
        t->next=*h;
        *h=t;
    }
    else{
    t->next=q->next;
    q->next=t;
    }

}
}
//Searching the value in provided Node of hash table
struct Node* Search(struct Node *p,int key){
while(p!=NULL){
    if(p->data==key)
        return p;
    else
        p=p->next;
}
return NULL;
};
//Hash Function
int hasher(int key){
return key%10;
}
//Main Insert Function
void Insert(struct Node *ht[],int key){
int index=hasher(key);
SortedInsert(&ht[index],key);
}
//MAIN
int main()
{
    struct Node *HT[10];
    struct Node *temp;
    for(int i=0;i<10;i++)
        HT[i]=NULL;
    Insert(HT,12);
Insert(HT,22);
Insert(HT,42);
temp=Search(HT[hasher(22)],22);
printf("%d ",temp->data);
    return 0;
}
