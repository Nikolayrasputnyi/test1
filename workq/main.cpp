
#include <iostream>
using namespace std;

int main() {
for (int i1 = 0; i1 < 10; i1++)
for (int i2 = 0; i2 < 10; i2++)
for (int i3 = 0; i3 < 10; i3++)
if ((i1 + i2 +i3) % 2 == 0)
for (int i4 = 0; i4 < 10; i4++)
for (int i5 = 0; i5 < 10; i5++)
for (int i6 = 0; i6 < 10; i6++)
if (i2 + i4 + i6 <= 21)
for (int i7 = 0; i7 < 10; i7++)
for (int i8 = 0; i8 < 10; i8++)
if (i2 + i4 + i6 + i8 <= 21)
for (int i9 = 0; i9 < 10; i9++)
for (int i10 = 0; i10 < 10; i10++)
if (i2 + i4 + i6 + i8 + i10 <= 21)
for (int i11 = 0; i11 < 10; i11++)
for (int i12 = 0; i12 < 10; i12++)
if (i2 + i4 + i6 + i8 + i10 + i12 == 21 && (i10 + i11 + i12) % 3 == 0 && (i3 + i6 + i9 + i12) % 11 == 0)
cout << i1 << i2 << i3 << i4 << i5 << i6 << i7 << i8 << i9 << i10 << i11 << i12 << endl;
return 0;
}
