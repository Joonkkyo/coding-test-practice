#include <iostream>
#include <algorithm>
#define MAX 101
#define INF 1000000000
using namespace std;


int arr1[MAX][MAX], arr2[MAX][MAX];
int arr3[MAX][MAX][MAX], arr4[MAX][MAX][MAX];

int main()
{
    int noCases;
    cin >> noCases;
    while (noCases--)
    {
        int i, j, k, l, m, n, o, p;
        int res;
        cin >> n >> m >> o >> p;
        for (i = 0; i < n; i++)
        {
            for (j = 1; j < m; j++)
            {
                cin >> arr1[i][j];
            }
        }

        for (i = 1; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> arr2[i][j];
            }
        }

        for (k = 0; k < n + m; k++)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    arr3[i][j][k] = arr4[i][j][k] = INF;
                    if (!i && !j)
                    {
                        arr3[i][j][k] = arr4[i][j][k] = 0;
                    }
                    if (i)
                    {
                        arr3[i][j][k] = min(arr3[i][j][k], arr3[i - 1][j][k] + arr2[i][j]);
                        if (k)
                        {
                            arr3[i][j][k] = min(arr3[i][j][k], arr4[i - 1][j][k - 1] + arr2[i][j]);
                        }
                    }
                    if (j)
                    {
                        arr4[i][j][k] = min(arr4[i][j][k], arr4[i][j - 1][k] + arr1[i][j]);
                        if (k)
                        {
                            arr4[i][j][k] = min(arr4[i][j][k], arr3[i][j - 1][k - 1] + arr1[i][j]);
                        }
                    }
                }
            }
            if (arr3[n - 1][m - 1][k] <= p || arr4[n - 1][m - 1][k] <= p)
                break;
        }
        if (k < n + m)
        {
            res = k + (n + m - 2) * o;
        }
        else
            res = -1;

        cout << res << '\n';
    }
}