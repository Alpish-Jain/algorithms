#include <stdio.h>
#include <stdlib.h>

struct Stack{
int top;
int size;
int * S;
};
//Create a stack
void create(struct Stack *st){
printf("Enter size\n");
scanf("%d",&st->size);
st->top=-1;
st->S=(int *)malloc(st->size*sizeof(int));
}
//Display stack
void Display(struct Stack st){
int i;
for(i=st.top;i>=0;i--)
    printf("%d ",st.S[i]);
printf("\n");
}
//PUSHING INTO STACK
void push(struct Stack *st,int x){
if(st->top==st->size-1)
    printf("Stack is full");
else{
        st->top++;
    st->S[st->top]=x;
}
}
//POPING A VALUE FROM THE STACK
int pop(struct Stack *st){
int x=-1;
if(st->top==-1)
    printf("Stack Underflow\n");
else
    x=st->S[st->top--];
return x;
}
//PEEK operation
int peek(struct Stack st,int index){
if(st.top-index+1<0)
    printf("Invalid index\n");
else
    return st.S[st.top-index+1];
}
//CHECKING IF STACK IS EMPTY
int isEmpty(struct Stack st)
{
if(st.top==-1)
return 1;
return 0;
}
//CHECKING IF STACK IS FULL
int isFull(struct Stack st)
{
return st.top==st.size-1;
}
//RETURNING THE TOP OF THE STACK
int stackTop(struct Stack st)
{
if(!isEmpty(st))
return st.S[st.top];
return -1;
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    Display(st);
    pop(&st);
    Display(st);
    return 0;
}
