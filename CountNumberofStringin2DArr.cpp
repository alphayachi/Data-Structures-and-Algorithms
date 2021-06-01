//same solution as the next question just manipulate the direction array x, y to restrict directions in which to check.

#include <bits/stdc++.h>
using namespace std;

//Important: These two arrays represent the increments when moving
//in a particular direction. These directions cover diagonals, horiz, vert
//in both directions. for ex: consider 0th element -1,-1
// This will go in the upward left diagonal as we keep adding this to the
//x and y iterators in the 2D array.

int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// we travers the array as a 1d array by using deference op (*)
// for ex: for second row we go with *(grid+row*C+col)
int stringSearch(char *grid, int R, int C, string trgt, int r, int c)
{
    int local_strcount = 0;
    if (*(grid + r * C + c) != trgt[0])
    {
        return local_strcount;
    }

    for (int d = 0; d < 8; d++)
    {
        int i = 0;
        int r_tmp = r;
        int c_tmp = c;
        for (i = 0; i < trgt.length(); i++)
        {
            if (r_tmp >= R || c_tmp >= C || r_tmp < 0 || c_tmp < 0)
            {
                break;
            }
            if (*(grid + r_tmp * C + c_tmp) == trgt[i])
            {
                r_tmp += y[d];
                c_tmp += x[d];
            }
            else
            {
                break;
            }
        }
        if (i == trgt.length())
        {
            local_strcount++;
            cout << "Pattern Found at " << r << ", " << c << endl;
        }
    }
    return local_strcount;
}

int main()
{

    int R = 3, C = 13;
    char grid[R][C] = {"GEEKSFORGEEKS",
                       "GEEKSQUIZGEEK",
                       "IDEQAPRACTICE"};
    string targetstr = "GEEKS";

    int strcount = 0;

    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            strcount += stringSearch((char *)grid, R, C, targetstr, r, c);
        }
    }

    cout << strcount;

    return 0;
}