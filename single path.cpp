#include <bits/stdc++.h>
using namespace std;
bool issafe(int arr[100][100]/*(int **arr)*/, int i, int j, int n, int m){
    if(i<n && j<m && arr[i][j] == 1){
        return true;
    }
    return false;
}
bool ratinamaze(int arr[100][100] /*(int **arr)*/, int i, int j, int solarr[100][100]/*(int **solarr)*/, int n, int m)
{
    if((i == (n-1)) && (j == (m-1))){
        solarr[i][j] = 1;
        return true;
    }
    
    if (issafe(arr, i, j, n, m))
    {
        solarr[i][j] = 1;

        if (ratinamaze(arr, i + 1, j, solarr, n, m))
        {
            return true;
        }
        if (ratinamaze(arr, i, j + 1, solarr, n, m))
        {
            return true;
        }
        solarr[i][j] = 0;
        return false;
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[100][100];
    /*
    Dynamically Allocating a 2D Array
    int** arr = int*[n];
    for(int i = 0; i<n; i++){
        arr[i] = new int[m];
    }
    */
    int solarr[100][100];
    memset(solarr, 0, sizeof(solarr));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    ratinamaze(arr, 0, 0, solarr, n, m);
    cout<<endl;
    cout<<"********************************"<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<solarr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
