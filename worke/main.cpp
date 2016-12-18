
#include <memory>
#include <iostream>
#include <vector>
using namespace std;
vector <int> a(100);
void quickSort(int l, int r){
int x = a[(r + l) / 2];
int i = l;
int j = r;
while(i <= j){
while(a[i] < x)
i++;
while(a[j] > x)
j--;
if(i <= j){
swap(a[i], a[j]);
i++;
j--;
}
}
if (i<r)
quickSort(i, r);
if (l<j)
quickSort(l, j);
}
int main(){
int n;
cin >> n;
for(int i = 0; i < n; i++)
cin >> a[i];
quickSort(0, n-1);
for(int i = n-1; i >= 0; i--)
cout << a[i] <<" ";
return 0;
}
