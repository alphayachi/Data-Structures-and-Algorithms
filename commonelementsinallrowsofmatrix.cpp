#include <bits/stdc++.h>
using namespace std;

int commElement(int **mat, int n, int m)
{
    unordered_map<int, int> freq;

    for(int i=0; i<m; i++){
        freq[mat[0][i]]=1;
    }

    for(int r=1; r<n; r++){
        for(int c=0; c<m; c++){
            freq[mat[r][c]]++;
            if(r==n-1 && freq[mat[r][c]]==n-1){
                return mat[r][c];
            }
        }
    }
}

int main()
{

    int mat[4][5] = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };

    int ans = commElement(mat, 4, 5);
    cout<<ans;

    return 0;
}