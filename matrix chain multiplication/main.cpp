#include <bits/stdc++.h>

using namespace std;

void matrix_order(int p[],int n)
{
    int c[n][n],split[n][n];
    for(int i=1;i<n;i++)
    {
        c[i][i]=0;
    }
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j=i+l-1;
            c[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int q=c[i][k]+c[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<c[i][j])
                {
                    c[i][j]=q;
                    split[i][j]=k;
                }

            }
        }
    }
    cout<<"the maximum number of multiplications are "<<'\n';
    cout<<c[1][n-1];
}

int main()
{
    int n;
    cout<<"enter the number of matrices"<<'\n';
    cin>>n;
    int p[n+1];
    cout<<"enter the distinct dimensions of matrices"<<'\n';
    for(int i=0;i<n+1;i++)
    {
        cin>>p[i];
    }
    matrix_order(p,n+1);
    return 0;
}
