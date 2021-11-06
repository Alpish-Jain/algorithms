#include <iostream>
#define SIZE 10
using namespace std;
//INITIAL HASH FUNCTION
int hasher(int key){
return key%10;
}
//MODIFIED HASH FUNCTION
int probe(int ht[],int key){
int index=hasher(key);
int i=0;
while(ht[(index+i)%SIZE]!=0)
    i++;
return (index+i)%SIZE;
}
//INSERT FUNCTION
void Insert(int ht[],int key){
    int index=hasher(key);
    if(ht[index]!=0)
        index=probe(ht,key);
    ht[index]=key;
}
//SEARCHING
int Search(int ht[],int key){
    int index=hasher(key);
int i=0;
while(ht[(index+i)%SIZE]!=key)
    i++;
return (index+i)%SIZE;
}
//FOR  Quadretic probing replace by (index+i*i)%SIZE
int main()
{
    int ht[SIZE]={0};
    Insert(ht,10);
    Insert(ht,20);
    Insert(ht,23);
    Insert(ht,25);
    Insert(ht,65);
    cout<<"KEY is found at "<<Search(ht,65);
    for(int i=0;i<10;i++)
        cout<<ht[i]<<endl;

    return 0;
}
