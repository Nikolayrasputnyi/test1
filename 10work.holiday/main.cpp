#include <iostream>

using namespace std;

struct Segment
{
    int left, right, number;
};

void sort(Segment *segments,int n)
{
    if (n<=1)
    {
        return;
    }
    int left=0;
    int right=n-1;
    Segment key=segments[n/2];
    while (true)
    {
        while (segments[left].left<key.left)
        {
            left++;
        }
        while (segments[right].left>key.left)
        {
            right--;
        }
        if (right<left)
        {
            break;
        }
        Segment temp=segments[left];
        segments[left]=segments[right];
        segments[right]=temp;
        left++;
        right--;
    }
    sort(segments, right+1);
    sort(segments+left, n-left);
}

void embedded_segments(int n)
{
    Segment *segments=new Segment[n];
    for (int i=0;i<n;i++)
    {
        cin>>segments[i].left;
        cin>>segments[i].right;
        segments[i].number=i+1;
    }
    sort(segments,n);
    int *length=new int[n];
    int *next=new int[n];
    int index_max=0;
    for (int i=0;i<n;i++)
    {
        length[i]=0;
        next[i]=-1;
        for (int j=0;j<i;j++)
        {
            if (segments[j].left<segments[i].left && segments[j].right>segments[i].right && length[j]>length[i])
            {
                length[i]=length[j];
                next[i]=j;
            }
        }
        length[i]++;
        if (length[i]>length[index_max])
        {
            index_max=i;
        }
    }
    cout<<length[index_max]<<"\n";
    for (int i=index_max;i!=-1;i=next[i])
    {
        cout<<segments[i].number<<" ";
    }
    delete[] segments;
    delete[] length;
    delete[] next;
}

int main()
{
    int n;
    cin>>n;
    embedded_segments(n);
    return 0;
}
