#include <iostream>
using namespace std;

int main(){
{  int k,j;
    int num;
    int m,i;
    cout << "Enter integer value: ";
    cin >> num;

    int *p_darr = new int[num];

for ( i = 0; i < num; i++) {cin >> *(p_darr+i);
                               cout << "Value of " << i << " element is " << p_darr[i] << endl;
}
for ( i = 0; i < num; i++) {k=0;
        m = int (*(p_darr+i)/2);
    for (j=2; j<=m ;j++)

{if (*(p_darr+i)%j==0) k=k+1;
}
if (k==2) cout <<"We found number(s) "<<p_darr[i] << endl;
}
delete [] p_darr;
}
return 0;
}
