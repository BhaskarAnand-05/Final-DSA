#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to calculate the squared distance of a point from the origin
int calculateDistance(vector<int> point)
{
    int diff1 = point[0];
    int diff2 = point[1];

    int squaredSum = pow(diff1, 2) + pow(diff2, 2);

    return squaredSum;
}

// Function to find the k closest points to the origin
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    // Create a vector to store pairs of points and their distances
    vector<pair<vector<int>, int>> distances;

    // Calculate distances for each point and store them in the vector
    for (int i = 0; i < points.size(); i++)
    {
        int dist = calculateDistance(points[i]);
        pair<vector<int>, int> p = make_pair(points[i], dist);
        distances.push_back(p);
    }

    // Sort the distances vector based on distances
    sort(distances.begin(), distances.end(), [](const pair<vector<int>, int> &a, const pair<vector<int>, int> &b)
         { return a.second < b.second; });

    // Create a vector to store the k closest points
    vector<vector<int>> result;

    // Add the first k points from the sorted distances vector to the result
    for (int i = 0; i < k; i++)
    {
        result.push_back(distances[i].first);
    }

    return result;
}

int main()
{
    // Input points and value of k
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    // Find k closest points
    vector<vector<int>> closestPoints = kClosest(points, k);

    // Print the k closest points
    for (int i = 0; i < closestPoints.size(); i++)
    {
        for (int j = 0; j < closestPoints[i].size(); j++)
        {
            cout << closestPoints[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
