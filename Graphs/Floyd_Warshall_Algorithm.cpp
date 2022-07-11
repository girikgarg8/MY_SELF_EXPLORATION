#include <iostream>
#include <vector>
#define INF 10000
using namespace std;
vector<vector<int>> floyd_algorithm(vector<vector<int>> input)
{
    vector<vector<int>> dist(input); //Initialise the distance 2-d array/matrix with the input 2-d array/matrix
    int V = input.size();            //Number of vertices
    for (int k = 0; k < V; k++)
    { //There is DP becuase of the outermost for loop
        for (int i = 0; i < V; i++)
        { //DP Based approach
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}
int main()
{
    vector<vector<int>> v1 = {{0, INF, -2, INF}, {4, 0, 3, INF}, {INF, INF, 0, 2}, {INF, -1, INF, 0}}; //Adjacency matrix
    vector<vector<int>> output = floyd_algorithm(v1);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output.size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}