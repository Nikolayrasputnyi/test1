#include <iostream>

using namespace std;

void print_palindrom(int n)
{
    if (n==1)
    {
        cout<<9;
    }
    else if (n%2==0)
    {
        int m = n / 2;
        int *a= new int[m];
        for(int i=0;i<m-1;i++)
        {
            a[i]=0;
        }
        a[m-1]=1;
        int s = 1;
        while (true)
        {
            if (s%9==0)
            {
                for (int i=m-1;i>=0;i--)
                {
                    cout<<a[i];
                }
                for (int i=0;i<m;i++)
                {
                    cout<<a[i];
                }
                cout<<" ";
            }
            int i;
            for (i=0;i<m&&a[i]==9;i++)
            {
                a[i]=0;
            }
            if (i==m)
                break;
            a[i]++;
            s++;
        }
        delete[] a;
    }
    else
    {
        int m = n / 2;
        int *a= new int[m];
        for(int i=0;i<m-1;i++)
        {
            a[i]=0;
        }
        a[m-1]=1;
        int s = 2;
        while (true)
        {
            if (s%9==0)
            {
                for (int i=m-1;i>=0;i--)
                {
                    cout<<a[i];
                }
                cout<<0;
                for (int i=0;i<m;i++)
                {
                    cout<<a[i];
                }
                cout<<" ";
            }
            for (int i=m-1;i>=0;i--)
            {
                cout<<a[i];
            }
            cout<<9-s%9;
            for (int i=0;i<m;i++)
            {
                cout<<a[i];
            }
            cout<<" ";

            int i;
            for (i=0;i<m&&a[i]==9;i++)
            {
                a[i]=0;
            }
            if (i==m)
                break;
            a[i]++;
            s=s+2; //s+=2;
        }
        delete[] a;
    }
}

int main()
{
    int n;
    cin>>n;
    print_palindrom(n);
    return 0;
}
