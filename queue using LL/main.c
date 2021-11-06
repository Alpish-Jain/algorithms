#include <stdio.h>
#include <stdlib.h>

struct Node{
int data;
struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
if(t==NULL)
    printf("Queue is full\n");
else{
    t->data=x;
    t->next=NULL;
    if(front==NULL)
        front=rear=t;
    else
    {
        rear->next=t;
        rear=t;
    }
}
}

int dequeue(){
    int x=-1;
    struct Node *p;
if(front==NULL)
    printf("Queue is Empty\n");
else{
    p=front;
    x=p->data;
    front=front->next;
    free(p);
}
    return x;
}
void display(){
struct Node *p=front;
while(p!=NULL)
{
    printf("%d ",p->data);
    p=p->next;
}
printf("\n");
}

int main()
{
    enqueue(10);
     enqueue(20);
     enqueue(30);
      enqueue(40);
       enqueue(50);
       display();
       printf("%d",dequeue());
    return 0;
}
