#include <iostream>
using namespace std;
int phi(int n) {
int b = 0;
int c = 0;
for (int i = 2; i < n; i++) {
for (int l = 2; l < i; l++)
if (i % l == 0)
c = 1;
if (n % i == 0 && c == 0)
b++;
c = 0;
}
return b;
}
int main() {
int proizv = 1;
int n;
cin >> n;
int k;
for (int i = 0; i < n; i++){
cin >> k;
if (phi(k) <= 2 && phi(k) >= 1)
proizv *= k;
}
cout << proizv;
return 0;
}
