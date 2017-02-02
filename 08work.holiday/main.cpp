#include <iostream>

using namespace std;

int Migraine_minimization(int N)
{
    int *migraine=new int[N+1];
    migraine[0]=0;
    for (int i=1;i<=N;i++)
    {
        for (int a=1;a*a<=i;a++)
        {
            migraine[i]=i*4;
            if(migraine[i-a*a]+4<migraine[i])
            {
                migraine[i]=migraine[i-a*a]+4;
            }
        }
    }
    int result=migraine[N];
    delete[] migraine;
    return result;
}

int main()
{
    int N;
    cin>>N;
    cout<<Migraine_minimization(N);
    return 0;
}
