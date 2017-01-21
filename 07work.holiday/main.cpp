#include <iostream>
#include <math.h>

using namespace std;

int shortest_path(int n, int m)
{
    double **route=new double*[n+1];
    bool **gardens=new bool*[n+1];
    for (int i=0;i<=n;i++)
    {
        route[i]=new double[m+1];
        gardens[i]=new bool[m+1];
        for (int j=0; j<=m;j++)
        {
            gardens[i][j]=false;
        }
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        gardens[x][y]=true;
    }
    for(int j=0;j<=m;j++){
        route[0][j]=j*100;
    }
    for(int i=1;i<=n;i++){
        route[i][0]=i*100;
        for(int j=1;j<=m;j++){
            route[i][j]=(route[i-1][j]<route[i][j-1]?route[i-1][j]:route[i][j-1])+100;
            if (gardens[i][j] && route[i-1][j-1]+100*sqrt(2)<route[i][j]){
                route[i][j]=route[i-1][j-1]+100*sqrt(2);
            }
        }
    }
    int result=route[n][m]+0.5;
    for (int i=0;i<=n;i++){
        delete [] route[i];
        delete [] gardens[i];
    }
    delete [] route;
    delete [] gardens;
    return result;
}

int main()
{
    int n,m;
    cin >>n>>m;
    cout << shortest_path(n,m);
    return 0;
}
