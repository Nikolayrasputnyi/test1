#include <iostream>
#include <vector>
using namespace std;
int prime(int n) {
vector <int> prime(n + 1);
for (int i = 0; i <= n; i++)
prime[i] = 1;
prime[0] = prime[1] = 0;
for (int i = 2; i <= n; ++i)
for (int j = i*i; j <= n; j += i)
prime[j] = 0;
if (prime[n] != 0)
return n;
else
return 0;
}
vector <int> delete_anything_primes(vector <int> Array, int &size) {
int g = 1;
int k = 0;
int h = 0;
vector <int> Array1(size);
for (int i = 0; i < size; i++) {
for (int l = 0; l < i; l++)
if (Array[i] == prime(Array[i]) && Array[i] != 0)
if (Array[i] == Array[l]) {
g = 0;
}
if (g != 0) {
Array1[i - h] = (Array[i]);
k++;
}
if (g == 0)
h++;
g = 1;
}
size = k;
return Array1;
}
int main() {
int n;
cin >> n;
vector <int> Array(n);
for (int i = 0; i < n; i++)
cin >> Array[i];
Array = delete_anything_primes(Array, n);
for (int i = 0; i < n; i++)
cout << Array[i] << " ";
return 0;
}
