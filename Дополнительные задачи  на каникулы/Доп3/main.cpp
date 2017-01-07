#include <iostream>
#include <math.h>
int calc_cube(int x);
int calc_sum(int * arrayOfValues, int arrSize);
int main()
{
    std::cout <<"How many numbers you want compute?\n";
    int arrSize;
    std::cin >> arrSize;
    int * arrNum = new int[arrSize];
    for (int i=0; i<arrSize; ++i)
    {
        std::cout << "Enter " << i+1 << " value: ";
        std::cin >> arrNum[i];
    }
    int * arrCubes = new int[arrSize];

     for ( int x, i=0;i<arrSize;i++)
    {
        x = arrNum[i];
    int j,f,m;
           f=0;
           m=int(x/2);
        for (j=1; j<m+1; j++)
        {
        if (x%j==0) {f=f+1;}
        }
    if (f==1) {arrCubes[i] = calc_cube(x);}
        else {arrCubes[i] = 0;}
    }

    std::cout << "\nSum of cubes is: " << calc_sum(arrCubes, arrSize);
    std::cout << std::endl;

    delete [] arrNum;
    delete [] arrCubes;

    return 0;
}
int calc_cube(int x)
{
    return x * x * x;
}
int calc_sum(int * arrayOfValues, int arrSize)
{
    int sum = 0;
    for (int i=0; i<arrSize; ++i)
        sum += arrayOfValues[i];
    return sum;
}
