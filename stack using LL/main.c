#include <stdio.h>
#include <stdlib.h>

struct Node{
char data;
struct Node *next;
}*top=NULL;
//PUSHING INTO STACK
void push(char x){
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
if(t==NULL)
    printf("stack overflow\n");
else{
    t->data=x;
    t->next=top;
    top=t;
}
}
//POPING FROM STACK
char pop(){
    struct Node *p;
    char x=-1;
if(top==NULL)
    printf("Stack Underflow\n");
else{
        p=top;
    x=p->data;
    top=top->next;
    free(p);
}
return x;
}
//DISPLAY
void Display(){
struct Node *p;
p=top;
while(p!=NULL)
{
    printf("%d ",p->data);
    p=p->next;
}
printf("\n");
}

int isBalanced(char *exp){
int i;
char x;
for(i=0;exp[i]!='\0';i++)
{
    if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        push(exp[i]);
    else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
    {
        if(top==NULL)
            return 0;
        x=pop();
        if(exp[i]==')' && x!='(' || exp[i]==']' && x!='[' || exp[i]=='}' && x!='{' )
            return 0;
    }
}
if(top==NULL)
    return 1;
else
    return 0;
}
int main()
{
   char *exp="{{[[(())]]}}";//for different types of parenthesis
printf("%d\n",isBalanced(exp));
//Display();
    return 0;
}
