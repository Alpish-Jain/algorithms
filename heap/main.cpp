#include <iostream>

using namespace std;
void Insert(int a[],int n){
int i=n,temp;
temp=a[i];
while(i>1 && temp>a[i/2]){
    a[i]=a[i/2];
    i=i/2;
}
a[i]=temp;
}

int Delete(int a[],int n){
int x=a[n],temp;
int val=a[1];
a[1]=a[n];
a[n]=val;
int i=1,j=i*2;
while(j<n-1){
    if(a[j+1]>a[j])
        j=j+1;
    if(a[i]<a[j])
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;

        i=j;
        j=j*2;
    }
    else
        break;

}
return val;
}
int main()
{
    int h[]={0,10,20,30,25,5,40,35};
    for(int i=2;i<=7;i++)
        Insert(h,i);

    for(int i=7;i>1;i--)
        Delete(h,i);
    for(int i=1;i<=7;i++)
        cout<<h[i]<<" ";
    return 0;
}
