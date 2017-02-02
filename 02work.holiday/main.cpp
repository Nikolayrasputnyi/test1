#include <iostream>

using namespace std;
int greatest_common_divider(int a,int b)
{
    while (b!=0)
    {
        int temp=a%b;
        a=b;
        b=temp;
   }
   return a;
}

bool test_c(int a,int b,int c)
{
    int m=greatest_common_divider(a,b);
    if (m==0)
        return c==0;
    return c%m==0;
}
bool infinite(int a,int b,int c)
{
    if (a*b<0)
        return true;
    if (c==0&&a*b==0)
        return true;
    return a>0&&b==0 || a==0&&b>0;
}

bool none(int a,int b,int c)
{
    return c>0&&a<=0&&b<=0;
}
void  unusual_diofant(int a,int b,int c)
{
    if (!test_c(a,b,c))
    {
        cout<<"none\n";
        return;
    }
    if (c<0 || c==0&&a<0)
    {
        a=-a;
        b=-b;
        c=-c;
    }
    if (none(a,b,c))
    {
        cout<<"none\n";
        return;
    }
    if (infinite(a,b,c))
    {
        cout<<"inf\n";
        return;
    }
    bool exist = false;
    for (int x=0;a*x<=c;x++)
    {
        if ((c-a*x)%b==0)
        {
            cout<<x<<" "<<(c-a*x)/b<<"\n";
            exist=true;
        }
    }
    if (!exist)
    {
        cout<<"none\n";
    }
}




int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    unusual_diofant(a,b,c);
    return 0;
}
