#include <bits/stdc++.h>
using namespace std;
void Merge(int a[],int p1,int q1,int r1)
{
    int c,d;
   int n1=q1-p1+1;
    int n2=r1-q1;
    int l[n1+1],r[n2+1];
    for(int i=0;i<n1;i++)
    {
        l[i]=a[p1+i];//for the original position of the element in the array
    }
    for(int j=0;j<n2;j++)
    {
        r[j]=a[q1+j+1];
    }
    l[n1+1]=100000;
    r[n2+1]=101000;
    c=0;
    d=0;
    for(int k=p1;k<r1+1;k++)
    {
        if(l[c]<=r[d])
        {
            a[k]=l[c];
            c=c+1;
        }
        else
        {
            a[k]=r[d];
            d=d+1;
        }
    }
}
Mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=floor((l+r)/2);
        //cout<<"m is "<<m;
        Mergesort(arr,l,m);
        Mergesort(arr,m+1,r);
        Merge(arr,l,m,r);
    }

}
int main()
{
    int n,p,q,r;
    scanf("%d %d %d",&n,&p,&r);
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    Mergesort(a,p,r);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
