
//Moore's voting algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(int a[], int size)
    {

        int count = 1;
        int star = a[0];
        for (int i = 1; i < size; i++)
        {
            if (a[i] != star)
            {
                count--;
            }
            else
            {
                count++;
            }
            if (count == 0)
            {
                star = a[i];
                count++;
            }
        }
        count = 0;
        for (int i = 0; i < size; i++)
        {
            if (a[i] == star)
            {
                count++;
            }
        }
        if (count > size / 2)
        {
            return star;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
