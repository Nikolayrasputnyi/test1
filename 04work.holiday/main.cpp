#include <iostream>

using namespace std;

void outer_points(int n, int m)
{
    int *begins=new int[n];
    int *finish=new int[n];
    for (int i=0;i<n;i++)
    {
        cin>>begins[i]>>finish[i];
    }
    for (int i=0;i<m;i++)
    {
        int point;
        cin>>point;
        int counter=0;
        for (int j=0;j<n;j++)
        {
            if (point<begins[j] || point>finish[j])
                counter++;
        }
        cout<<counter<<" ";
    }

    delete[] begins;
    delete[] finish;
}

int main()
{
    int n,m;
    cin >>n>>m;
    outer_points(n,m);
    return 0;
}
