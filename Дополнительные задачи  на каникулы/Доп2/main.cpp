
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void  sq(int* p_darr, int k, int i0, int j0)
{
    int i,j,m,c;
    if (k%2==0) m=k/2;
    else m=k/2+1;
    c=0;
    while (c<m)
        {for (i=i0+c;i<i0+k-c; i++) {
        for (j=j0+c;j<j0+k-c; j++){
            *(p_darr+i*2*k+j)=(*(p_darr+i*2*k+j))+1;}
        }
        c=c+1;
}
}
int main(){
int i,j,k,c;
cout << "Enter integer N: ";
cin >> k;
int *p_darr = new int[4*k*k*sizeof(int)];
for (i=0;i<2*k;i++){
    for (j=0;j<2*k;j++){
        *(p_darr+i*2*k+j)=0;
}
}
sq(p_darr,k,0,0);
sq(p_darr,k,0,k);
sq(p_darr,k,k,0);
sq(p_darr,k,k,k);
for (i=0;i<2*k;i++) {
 for (j=0;j<2*k;j++){
        cout<<*(p_darr+i*2*k+j);
    }
    cout<<"\n";
}
}
