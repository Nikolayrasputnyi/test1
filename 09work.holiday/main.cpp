#include <iostream>

using namespace std;

void darts_game(int n, int **&ans_numbers, int **&ans_coefs, int &ans_amount)
{
    const int M=20, D=M*3+3;
    int numbers[D];
    int coefs[D];
    for (int i=1;i<=M;i++)
    {
        numbers[i-1]=i;
        coefs[i-1]=1;
        numbers[i-1+M]=i;
        coefs[i-1+M]=2;
        numbers[i-1+2*M]=i;
        coefs[i-1+2*M]=3;
    }
    numbers[3*M]=25;
    coefs[3*M]=1;
    numbers[3*M+1]=25;
    coefs[3*M+1]=2;
    numbers[D-1]=0;
    coefs[D-1]=0;

    int result_numbers[D*D][3];
    int result_coefs[D*D][3];
    ans_amount=0;
    for(int i=0;i<D;i++)
    {
        for(int j=0;j<D;j++)
        {
            int number=n-numbers[i]*coefs[i]-numbers[j]*coefs[j];
            if ((number>=2 && number<=40 && number%2==0 || number==50) && (numbers[i]*coefs[i]!=0||numbers[j]*coefs[j]==0))
            {
                result_numbers[ans_amount][0]=numbers[i];
                result_coefs[ans_amount][0]=coefs[i];
                result_numbers[ans_amount][1]=numbers[j];
                result_coefs[ans_amount][1]=coefs[j];
                result_numbers[ans_amount][2]=number/2;
                result_coefs[ans_amount][2]=2;
                ans_amount++;
            }
        }
    }

    ans_numbers=new int*[ans_amount];
    ans_coefs=new int*[ans_amount];
    for (int i=0;i<ans_amount;i++)
    {
        ans_numbers[i]=new int[3];
        ans_coefs[i]=new int[3];
        for(int j=0;j<3;j++)
        {
           ans_numbers[i][j]=result_numbers[i][j];
           ans_coefs[i][j]=result_coefs[i][j];
        }
    }
}

int main()
{
    int n,**numbers, **coefs, amount;
    cin>>n;
    darts_game(n, numbers, coefs, amount);
    cout<<amount<<"\n";
    for (int i=0;i<amount;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (coefs[i][j]==2)
            {
                cout<<"D";
            }
            else if (coefs[i][j]==3)
            {
                cout<<"T";
            }
            if (numbers[i][j]!=0)
            {
                cout<<numbers[i][j]<<" ";
            }
        }
        cout<<"\n";
        delete[] numbers[i];
        delete[] coefs[i];
    }
    delete[] numbers;
    delete[] coefs;
    return 0;
}
