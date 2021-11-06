#include <stdio.h>
#include <stdlib.h>

struct Node
{
struct Node *lchild;
int data;
struct Node *rchild;
};

struct Queue
{
int size;
int front;
int rear;
struct Node **Q;
};
struct Node *root=NULL;
//create queue
void create(struct Queue *q,int size)
{
q->size=size;
q->front=q->rear=0;
q->Q=(struct Node **)malloc(q->size*sizeof(struct
Node *));
}
//ENQUEUE
void enqueue(struct Queue *q,struct Node *x)
{
if((q->rear+1)%q->size==q->front)
printf("Queue is Full");
else
{
q->rear=(q->rear+1)%q->size;
q->Q[q->rear]=x;
}
}
//DEQUEUE
struct Node * dequeue(struct Queue *q)
{
struct Node* x=NULL;
if(q->front==q->rear)
printf("Queue is Empty\n");
else
{
q->front=(q->front+1)%q->size;
x=q->Q[q->front];
}
return x;
}
//CHECK IF QUEUE IS EMPTY
int isEmpty(struct Queue q)
{
return q.front==q.rear;
}

//creating tree
void TreeCreate(){
struct Node *p,*t;
int x;
struct Queue q;
create(&q,100);
printf("enter root value\n");
scanf("%d",&x);
root=(struct Node *)malloc(sizeof(struct Node));
root->data=x;
root->lchild=root->rchild=0;
enqueue(&q,root);
while(!isEmpty(q)){
        p=dequeue(&q);
printf("Enter the left child of %d",p->data);
scanf("%d",&x);
if(x!=-1)
{
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->lchild=t->rchild=0;
    p->lchild=t;
    enqueue(&q,t);
}
printf("Enter the right child of %d",p->data);
scanf("%d",&x);
if(x!=-1)
{
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->lchild=t->rchild=0;
    p->rchild=t;
    enqueue(&q,t);
}
}
}
//PREORDER TRAVERSAL
void Preorder(struct Node *p)
{
if(p)
{
printf("%d ",p->data);
Preorder(p->lchild);
Preorder(p->rchild);
}
}
//INORDER TRAVERSAL
void Inorder(struct Node *p)
{
if(p)
{
Inorder(p->lchild);
printf("%d ",p->data);
Inorder(p->rchild);
}
}
//POSTORDER TRAVERSAL
void Postorder(struct Node *p)
{
if(p)
{
Postorder(p->lchild);
Postorder(p->rchild);
printf("%d ",p->data);
}
}
//LEVEL ORDER TRAVERSAL
void levelorder(struct Node *p)
{
struct Queue q;
create(&q,100);
printf("%d ",p->data);
enqueue(&q,p);
while(!isEmpty(q)){
    p=dequeue(&q);
    if(p->lchild){
        printf("%d ",p->lchild->data);
        enqueue(&q,p->lchild);
    }
    if(p->rchild){
        printf("%d ",p->rchild->data);
        enqueue(&q,p->rchild);
    }
}
}
//COUNTING THE NODES IN THE TREE
int count(struct Node* p){
int x,y;
if(p!=NULL)
    return count(p->lchild)+count(p->rchild)+1;
return 0;
}
//COUNTING THE HEIGHT OF THE TREE


//SUM OF ALL THE NODES
int add(struct Node* p){
if(p!=NULL)
    return add(p->lchild)+p(p->rchild)+p->data;
return 0;
}

int main()
{
    TreeCreate();
levelorder(root);
printf("\nPost Order ");
Postorder(root);
    return 0;
}
