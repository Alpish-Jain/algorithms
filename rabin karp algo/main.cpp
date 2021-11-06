#include <bits/stdc++.h>
#define d 256
using namespace std;
void karp(char txt[],char pat[],int q){
int m=strlen(pat);
int n=strlen(txt);
int p=0;
int t=0;
int h=1;
int i,j;
for(i=0;i<m-1;i++)
    h=(h*d)%q;

for(i=0;i<m;i++){
    p=(p*d+pat[i])%q;
    t=(t*d+txt[i])%q;
}
for(i=0;i<n-m;i++){
    if(p==t){
        for(j=0;j<m;j++)
            if(txt[i+j]!=pat[j])
                break;
        if(j==m)
            cout<<"Pattern found at index"<<i<<endl;
    }
    if(i<n-m)
        t=((t-txt[i]*h)*d+txt[i+m]%q);
    if(t<0)
        t=t+q;
}
}
void print(string s){

}
int main()
{
    string s;
    cin>>s;
    print(s);
    return 0;
}
