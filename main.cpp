#include <bits/stdc++.h>

using namespace std;
void printarr(int a[],int n){
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
//BUBBLE SORT
void bubbleSort(int a[],int n){
for(int i=0;i<n-1;i++){
    int flag=0;
    for(int j=0;j<n-1-i;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
            flag=1;
        }
    }
    if(flag==0) break;
}
printarr(a,n);
}
//INSERTION SORT
void InsertSort(int a[],int n){
for(int i=1;i<n;i++){
    int temp=a[i];
    int j=i-1;
    while(j>-1 && a[j]>temp){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=temp;
}
printarr(a,n);
}
//SELECTION SORT
void selection(int a[],int n){
for(int i=0;i<n-1;i++){
    int k=i;
    for(int j=i;j<n;j++){
        if(a[j]<a[k])
        {
            k=j;
        }
    }
    swap(a[k],a[i]);
}
printarr(a,n);
}
//QUICK SORT
int partitioner(int a[],int l,int h){
int pivot=a[l];
int i=l,j=h;
do{
    do{i++;}while(a[i]<=pivot);
    do{j--;}while(a[j]>pivot);
    if(i<j)
        swap(a[i],a[j]);
}while(i<j);
swap(a[l],a[j]);
return j;
}
void quickSort(int a[],int l,int h){
int p;
if(l<h){
    p=partitioner(a,l,h);
    quickSort(a,l,p);
    quickSort(a,p+1,h);
}
}
//MERGE SORT
//MERGE PROCEDURE
void Merge(int a[],int l,int mid,int h){
int i=l,j=mid+1,k=l;
int b[100];
while(i<=mid && j<=h){
    if(a[i]<a[j])
        b[k++]=a[i++];
    else
        b[k++]=a[j++];
}
for(;i<=mid;i++)b[k++]=a[i];
for(;j<=h;j++)b[k++]=a[j];

for(i=l;i<=h;i++)
    a[i]=b[i];
}
//TWO SEPARATE LISTS MERGING
void Mergetwo(int a[],int b[],int m,int n){
int i,j,k;
i=j=k=0;
int c[m+n];
while(i<m && j<n){
    if(a[i]<b[j])
        c[k++]=a[i++];
    else
        c[k++]=b[j++];
}
for(;i<m;i++)c[k++]=a[i];
for(;j<n;j++)c[k++]=b[j];
}
//ITERATIVE VERSION
void IterMerge(int a[],int n){
    int l,h,mid,p,i;
for(p=2;p<=n;p*=2){
    for(i=0;i+p-1<=n;i+=p){
        l=i;
        h=i+p-1;
        mid=(l+h)/2;
        Merge(a,l,mid,h);
    }
}
if(p/2<n)
    Merge(a,0,p/2,n-1);
}
//RECURSIVE MERGE
void MergeSort(int a[],int l,int h){
if(l<h){
    int mid=(l+h)/2;
MergeSort(a,l,mid);
MergeSort(a,mid+1,h);
Merge(a,l,mid,h);
}
}

//COUNT SORT
void CountSort(int a[],int n){
int max_el;
max_el=*max_element(a,a+n);
int *c,i;
c=new int[max_el+1];
for(i=0;i<max_el+1;i++)
    c[i]=0;
for(i=0;i<n;i++)
    c[a[i]]++;

int j=0;
i=0;
while(i<max_el+1){
    if(c[i]>0){
        a[j++]=i;
        c[i]--;
    }
    else
        i++;
}
}
//SHELL SORT
void shellSort(int a[],int n){
int gap,j,temp;
for(gap=n/2;gap>=1;gap=gap/2){
    for(int i=gap;i<n;i++){
        temp=a[i];
        j=i-gap;
        while(j>=0 && a[j]>temp){
            a[j+gap]=a[j];
            j=j-gap;
        }
        a[j+gap]=temp;
    }
}
}
int main()
{
    int a[]={10,9,2,5,1,6,3,7};
    int n=sizeof(a)/sizeof(a[0]);
   shellSort(a,n);
   printarr(a,n);
    return 0;
}
