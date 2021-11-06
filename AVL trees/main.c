#include <stdio.h>
#include <stdlib.h>

struct Node {
struct Node* lchild;
struct Node* rchild;
int height;
int data;
}*root=NULL;
//PREORDER
void preOrder(struct Node* p){
printf("%d ",p->data);
preOrder(p->lchild);
preOrder(p->rchild);
}
//HEIGHT OF A NODE
int NodeHeight(struct Node* p){
int hl,hr;
hl=p && p->lchild?p->lchild->height:0;
hr=p && p->rchild?p->rchild->height:0;
return hl>hr?hl+1:hr+1;
}
//BALANCE FACTOR
int BalanceFactor(struct Node *p)
{
int hl,hr;
hl=p && p->lchild?p->lchild->height:0;
hr=p && p->rchild?p->rchild->height:0;
return hl-hr;
}
//LL ROTATION
struct Node* LLRotation(struct Node* p){
struct Node* pl=p->lchild;
struct Node* plr=pl->rchild;

pl->rchild=p;
p->lchild=plr;
p->height=NodeHeight(p);
pl->height=NodeHeight(pl);

if(root==p)
    root=pl;
return pl;
}
//LR ROTATION
struct Node* LRRotation(struct Node* p){
    struct Node* pl=p->lchild;
struct Node* plr=pl->rchild;

pl->rchild=plr->lchild;
p->lchild=plr->rchild;
plr->lchild=pl;
plr->rchild=p;

pl->height=NodeHeight(pl);
p->height=NodeHeight(p);
plr->height=NodeHeight(plr);

if(root==p)
    root=plr;
return plr;
}
//RR ROTATION
struct Node* RRRotation(struct Node* p){
    struct Node* pr=p->rchild;
struct Node* prl=pr->lchild;
pr->lchild=p;
p->rchild=prl;
p->height=NodeHeight(p);
pr->height=NodeHeight(pr);

if(root==p)
    root=pr;
return pr;
}
//RL ROTATION
struct Node* RLRotation(struct Node* p){
    return NULL;
}
//INSERTION
struct Node* RInsert(struct Node* p,int key){
struct Node* t=NULL;
if(p==NULL)
{
    t=(struct Node*)malloc(sizeof(struct Node));
    t->lchild=t->rchild=NULL;
    t->data=key;
    t->height=1;
    return t;
}
else if(key<p->data)
    p->lchild=RInsert(p->lchild,key);
else if(key>p->data)
    p->rchild=RInsert(p->rchild,key);

    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);

    return p;
}
int main()
{
    root=RInsert(root,10);
    RInsert(root,20);
    RInsert(root,30);
    preOrder(root);
    return 0;
}
