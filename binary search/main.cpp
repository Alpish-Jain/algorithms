#include <iostream>

using namespace std;
int Binarysearch(int a[],int low,int high,int item)
{
    if(low<high)
    {
        int mid=((low+high)/2);
        if(item==a[mid])
            return a[mid];
        else if(item<a[mid])
            return Binarysearch(a,low,mid-1,item);
        else
            return Binarysearch(a,mid+1,high,item);
    }
}
int main()
{
   int arr[]={5,1,2,3,6,8,4};
   int c=Binarysearch(arr,0,7,3);
   cout<<c<<endl;
    return 0;
}
