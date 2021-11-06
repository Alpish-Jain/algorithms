#include <stdio.h>
#include <stdlib.h>

struct Node{
struct Node* lchild;
int data;
struct Node* rchild;
}*root=NULL;
//ITERATIVE INSERT
void insert(int key){
struct Node* p=NULL,*r;
struct Node* t=root;
if(root==NULL)
{
r=(struct Node*)malloc(sizeof(struct Node));
r->data=key;
r->lchild=r->rchild=NULL;
root=r;
return;
}
while(t!=NULL){
    p=t;
    if(key==t->data)
        return;
    if(key<t->data)
        t=t->lchild;
    else if(key>t->data)
        t=t->rchild;
}
r=(struct Node*)malloc(sizeof(struct Node*));
r->data=key;
r->lchild=r->rchild=NULL;
if(p->data<r->data)
    p->rchild=r;
else if(p->data>r->data)
    p->lchild=r;
}
//RECURSIVE INSERT
struct Node* RInsert(struct Node* p,int key){
struct Node* t;
if(p==NULL)
{
    t=(struct Node*)malloc(sizeof(struct Node*));
t->data=key;
t->lchild=t->rchild=NULL;
return t;
}
if(key<p->data)
    p->lchild=RInsert(p->lchild,key);
else if(key>p->data)
    p->rchild=RInsert(p->rchild,key);
    return p;
}
//INORDER
void Inorder(struct Node* p){
if(p){
    Inorder(p->lchild);
    printf("%d ",p->data);
    Inorder(p->rchild);
}
}
//ITERATIVE SEARCH
struct Node* search(struct Node* p,int key){
struct Node* t=root;
while(t!=NULL){
    if(t->data==key)
        return t;
    else if(t->data<key)
        t=t->rchild;
    else if(t->data>key)
        t=t->lchild;
}
return NULL;

}
//INORDER PREDECESSOR
struct Node* InPre(struct Node* p){
while(p && p->rchild!=NULL)
    p=p->rchild;
return p;
}
//INORDER SUCCESSOR
struct Node* InSuc(struct Node* p){
while(p && p->lchild!=NULL)
    p=p->lchild;
return p;
}
//HEIGHT OF A TREE
int Height(struct Node* p){
    int x,y;
if(p)
{
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;

}
return 0;
}
//DELETE A NODE
struct Node* Delete(struct Node* p,int key){
struct Node*q;
if(p==NULL)
    return NULL;
if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
if(key<p->data)
    p->lchild=Delete(p->lchild,key);
else if(key>p->data)
    p->rchild=Delete(p->rchild,key);
else{
    if(Height(p->lchild)>Height(p->rchild))
    {
        q=InPre(p->lchild);
        p->data=q->data;
        p->lchild=Delete(p->lchild,q->data);
    }
    else{
        q=InSuc(p->rchild);
        p->data=q->data;
        p->rchild=Delete(p->rchild,q->data);
    }
}
return p;
};
int main()
{
insert(10);
insert(20);
insert(30);
insert(40);
insert(50);
insert(60);
printf("%d\n ",Delete(root,50)->data);
Inorder(root);
printf("\n");
printf("%d ",search(root,40)->data);
    return 0;
}
