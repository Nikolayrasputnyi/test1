#include <iostream>

using namespace std;

struct Lecture
{
    int s,f;
};

void sort(Lecture *lectures,int n)
{
    if (n<=1)
    {
        return;
    }
    int left=0;
    int right=n-1;
    Lecture key=lectures[n/2];
    while (true)
    {
        while (lectures[left].f<key.f)
        {
            left++;
        }
        while (lectures[right].f>key.f)
        {
            right--;
        }
        if (right<left)
        {
            break;
        }
        Lecture temp=lectures[left];
        lectures[left]=lectures[right];
        lectures[right]=temp;
        left++;
        right--;
    }
    sort(lectures, right+1);
    sort(lectures+left, n-left);
}

void shedule(int n)
{
    Lecture *lectures=new Lecture[n];
    for (int i=0; i<n; i++)
    {
        cin >>lectures[i].s;
        cin>>lectures[i].f;
    }
    sort(lectures, n);
    int counter=1;
    int i=0;
    while (true)
    {
        int j;
        for (j=i+1; j<n&&lectures[j].s<lectures[i].f; j++);
        if (j == n)
        {
            cout << counter;
            return;
        }
        counter++;
        i=j;
    }
}

int main()
{
    int n;
    cin >> n;
    shedule(n);
    return 0;
}
