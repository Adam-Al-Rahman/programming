#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;
    int x[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x[i][j];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (i == 0 && j < m - 1)
    //             cout << x[i][j];

    //         if (j == m - 1)
    //             cout << x[i][j];
    //     }
    // }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            cout << x[i][j];
        }
    }
}