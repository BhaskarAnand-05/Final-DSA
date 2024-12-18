#include "Headerfile.h"

// APPLICATION OF GRAPH USING ADJACENCY LIST
template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adjl;
    void addedge(int u, int v, int direction)
    {
        // direction = 0 means undirected
        // direction = 1 means directed

        adjl[u].push_back(v);

        if (direction == 0)
        {
            adjl[v].push_back(u);
        }
    }

    void print_graph()
    {
        for (auto it : adjl)
        {
            cout << it.first << " ->";
            for (auto i : it.second)
            {
                cout << i << " , ";
            }
            cout << endl;
        }
    }
};

//  APPLICATION USING THE ADJACENCY MATRIX
// class Graph
// {
// public:
//     int m, n;
//     T adjm[m][n];
//     void addedge_Graph(int u, int v, int direction)
//     {
//         // direction = 0 means undirected
//         // direction = 1 means directed

//         adjm[u][v] = 1;

//         if (direction == 0)
//         {
//             adjm[v][u] = 1;
//         }
//     }

//     void print_Graph()
//     {
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cout << adjm[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }
// };

int main()
{
    int m, n;

    cin >> m >> n;
    graph<int> g;

    //  ENTER IN GRAPH
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 1);
    }

    //  PRINT THE GRAPH
    g.print_graph();

    return 0;
}