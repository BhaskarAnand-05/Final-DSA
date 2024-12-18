// Solution Using DFS

#include "Headerfile.h"

void flood_fill(vector<vector<int>> &image, int m, int n, int sr, int sc, int currcol, int newcol)
{
    // base case
    if (sr >= m || sc >= n || sr < 0 || sc < 0)
    {
        // cout << endl
        //      << "Out of scope " << endl;
        return;
    }

    if (image[sr][sc] != currcol)
    {
        // cout << endl
        //  << "Curr Col is Not Correct or it is already coloured " << endl;
        return;
    }

    image[sr][sc] = newcol;
    flood_fill(image, m, n, sr + 1, sc, currcol, newcol);
    flood_fill(image, m, n, sr - 1, sc, currcol, newcol);
    flood_fill(image, m, n, sr, sc + 1, currcol, newcol);
    flood_fill(image, m, n, sr, sc - 1, currcol, newcol);
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int m = 3;
    int n = 3;

    int sr = 1;
    int sc = 1;

    int currcol = image[1][1];
    int newcol = 2;

    flood_fill(image, m, n, sr, sc, currcol, newcol);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}