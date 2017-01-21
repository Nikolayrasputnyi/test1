#include <iostream>

using namespace std;

void incredible_sort(int N, int k)
{
    int *a=new int[k];
    for(int i=0;i<k;i++)
    {
        a[i]=0;
    }
    for (int i=0;i<N;i++)
    {
        int x;
        cin >>x;
        a[x-1]++;
    }
    for (int i=k-1;i>=0;i--)
    {
        for (int j=a[i];j>0;j--)
        {
            cout<<i+1<<" ";
        }
    }
    delete[] a;
}

int main()
{
    int k,N;
    cin >>N>>k;
    incredible_sort(N, k);
    return 0;
}
