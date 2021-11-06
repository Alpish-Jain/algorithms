#include <bits/stdc++.h>
using namespace std;

int nextpowerof2(int k)
{
    return pow(2, int(ceil(log2(k))));
}
void display(vector<vector<int> > &matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != 0)
            {
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void add(vector<vector<int> > &A, vector<vector<int> > &B, vector<vector<int> > &C, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(vector<vector<int> > &A, vector<vector<int> > &B, vector<vector<int> > &C, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void STRASSEN_algorithmA(vector<vector<int> > &A, vector<vector<int> > &B, vector<vector<int> > &C, int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        int m = n / 2;
        vector<int> z(m);
        vector<vector<int> >
            a11(m, z), a12(m, z), a21(m, z), a22(m, z),
            b11(m, z), b12(m, z), b21(m, z), b22(m, z),
            c11(m, z), c12(m, z), c21(m, z), c22(m, z),
            p1(m, z), p2(m, z), p3(m, z), p4(m, z),
            p5(m, z), p6(m, z), p7(m, z),
            aResult(m, z), bResult(m, z);

int i, j;

//dividing the matrices into sub-matrices:
for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + m];
                a21[i][j] = A[i + m][j];
                a22[i][j] = A[i + m][j + m];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + m];
                b21[i][j] = B[i + m][j];
                b22[i][j] = B[i + m][j + m];
            }
}

        add(a11, a22, aResult, m);     // a11 + a22
        add(b11, b22, bResult, m);    // b11 + b22
        STRASSEN_algorithmA(aResult, bResult, p1, m);
        // p1 = (a11+a22) * (b11+b22)

        add(a21, a22, aResult, m); // a21 + a22
        STRASSEN_algorithmA(aResult, b11, p2, m);

        sub(b12, b22, bResult, m);      // b12 - b22
        STRASSEN_algorithmA(a11, bResult, p3, m);
        // p3 = (a11) * (b12 - b22)

        sub(b21, b11, bResult, m);       // b21 - b11
        STRASSEN_algorithmA(a22, bResult, p4, m);
        // p4 = (a22) * (b21 - b11)

        add(a11, a12, aResult, m);      // a11 + a12
        STRASSEN_algorithmA(aResult, b22, p5, m);
        // p5 = (a11+a12) * (b22)

        sub(a21, a11, aResult, m);      // a21 - a11
        add(b11, b12, bResult, m);
        // b11 + b12
        STRASSEN_algorithmA(aResult, bResult, p6, m);
        // p6 = (a21-a11) * (b11+b12)

        sub(a12, a22, aResult, m);      // a12 - a22
        add(b21, b22, bResult, m);
        // b21 + b22
        STRASSEN_algorithmA(aResult, bResult, p7, m);
        // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 e c22:

        add(p3, p5, c12, m); // c12 = p3 + p5
        add(p2, p4, c21, m); // c21 = p2 + p4

        add(p1, p4, aResult, m);       // p1 + p4
        add(aResult, p7, bResult, m);  // p1 + p4 + p7
        sub(bResult, p5, c11, m); // c11 = p1 + p4 - p5 + p7

        add(p1, p3, aResult, m);       // p1 + p3
        add(aResult, p6, bResult, m);  // p1 + p3 + p6
        sub(bResult, p2, c22, m); // c22 = p1 + p3 - p2 + p6

        // Grouping the results obtained in a single matrix:
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + m] = c12[i][j];
                C[i + m][j] = c21[i][j];
                C[i + m][j + m] = c22[i][j];
            }
        }
    }
}
void STRASSEN_algorithm(vector<vector<int> > &A, vector<vector<int> > &B, int m, int n, int a, int b)
{
    int k = max(m, max(n, max(a, b)));

    int s = nextpowerof2(k);

    vector<int> z(s);
    vector<vector<int> > Aa(s, z), Bb(s, z), Cc(s, z);

    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            Aa[i][j] = A[i][j];
        }
    }
    for (unsigned int i = 0; i < a; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            Bb[i][j] = B[i][j];
        }
    }
    STRASSEN_algorithmA(Aa, Bb, Cc, s);
    vector<int> temp1(b);
    vector<vector<int> > C(m, temp1);
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            C[i][j] = Cc[i][j];
        }
    }
    display(C, m, b);
}

bool check(int n, int a)
{
    if (n == a)
        return true;
    else
        return false;
}

int main()
{
    int m, n, a, b;
    cout << "Matrix Multiplication using Strassen algorithm" << endl;
    cout << "Enter rows and columns of first matrix" << endl;
    cin >> m >> n;
    cout << "enter values into first matrix" << endl;
    vector<vector<int> > A;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int i;
            cin >> i;
            temp.push_back(i);
        }
        A.push_back(temp);
    }
    cout << "Enter rows and columns of second matrix" << endl;
    cin >> a >> b;
    cout << "enter values into second matrix" << endl;
    vector<vector<int> > B;
    for (int i = 0; i < a; i++)
    {
        vector<int> temp;
        for (int j = 0; j < b; j++)
        {
            int i;
            cin >> i;
            temp.push_back(i);
        }
        B.push_back(temp);
    }

    bool k = check(n, a);
    if (k)
    {
        STRASSEN_algorithm(A, B, m, n, a, b);
    }
    else
    {
        cout << "martrix multiplication not possible";
    }
    return 0;
}
