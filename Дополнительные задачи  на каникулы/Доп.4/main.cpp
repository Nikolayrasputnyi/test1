#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int num;
 int bubble(int* items,int count);
 int srednee(int* items, int count);
      cout << "Enter integer value: ";
      cin >> num;
      int *p_darr = new int[num];
      for (int i = 0; i < num; i++) {
          int k;
      cin >> k;
            p_darr[i]=k;
               cout << "Value of " << i << " element is " << p_darr[i] << endl;

    }

cout <<" Mediana is: "<<bubble(p_darr,num);
cout <<"\n Srednee arifmeticheskoe is: "<<srednee(p_darr,num);
cout <<"\n Raznitsa is: "<<bubble(p_darr,num)-srednee(p_darr,num);
    delete [] p_darr; // очистка памяти
    return 0;

      }
  int bubble(int* items,int count)
  {
      int a,b,t;
      for (a=1;a<count ;++a)
        for (b=count-1;b>=a;--b)
      {
          if (items [b-1]>items [b])
          {
              t=items[b-1];
              items[b-1]=items[b];
              items[b]=t;
          }
      }
  return items[(count-1)/2];
  }
  int srednee(int* items, int count)
  {
      int i,sum;
      sum=0;
      for (i=0;i<count;i++){
        sum=sum+items[i];
      }
      return sum/count;
  }
