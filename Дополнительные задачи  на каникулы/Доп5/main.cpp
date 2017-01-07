#include <iostream>
int Del_Prost(int num,int v_darr[]);
using namespace std;

int main()
{
 std::cout <<"How many numbers you want compute?\n";
    int num;
    std::cin >> num;
     int *p_darr = new int[num];
     for (int i = 0; i < num; i++) {
        std::cout << "Enter " << i+1 << " value: ";
        std::cin >> p_darr[i];}
        cout <<"\n"<<Del_Prost(num,p_darr)<<" ";
         delete [] p_darr;
         return 0;
         }
    int Del_Prost(int n,int v_darr[])
        {int * arrNeProst = new int[n];
        for ( int x,i=0;i<n;i++)
    {
        x = v_darr[i];
        int j,f,m,k;
        k=0;
           f=0;
           m=int(x/2);
        for (j=1; j<m+1; j++)
        {
        if (x%j==0) {f=f+1;}
        }
    if (f!=1 and f!=0) {arrNeProst[k]=x; cout <<arrNeProst[k]<<" ";k++;}
    }
        return 0;
        }

