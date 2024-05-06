#include <bits/stdc++.h>
using namespace std;
ifstream inFile;
ofstream outFile;
class Graph
{
public:
    int nodes;
    int edges;
    vector<vector<int>> g;
    Graph(int nodes = 0, int edges = 0)
    {
        this->nodes = nodes;
        this->edges = edges;
        g.resize(10000);
    }
    void add_edge(int u, int v)
    {
        this->g[u].push_back(v);
    }
    vector<pair<int, int>> BFS(int source)
    {
        vector<bool> visited;
        visited.resize(10000, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        vector<pair<int, int>> vect;
        outFile << "The List of Verticies for BFS are: " << endl;
        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            outFile << current << " ";
            for (int child : g[current])
            {
                if (!visited[child])
                {
                    visited[child] = true;
                    q.push(child);
                    vect.push_back(make_pair(current, child));
                }
            }
        }
        outFile << endl;
        outFile << "Printing BFS Sub Tree:   " << endl;
        return vect;
    }
    vector<pair<int, int>> DFS(int vertex)
    {
        vector<bool> visited;
        visited.resize(10000, false);
        vector<pair<int, int>> traverse;
        outFile << "The List Of Vertices for DFS Are: " << endl;
        iteration(vertex, visited, traverse);
        outFile << endl;
        outFile << "Printing DFS Sub Tree:   " << endl;
        return traverse;
    }
    void iteration(int vertex, vector<bool> &visited, vector<pair<int, int>> &traverse)
    {
        visited[vertex] = true;
        outFile << vertex << " ";
        for (int child : g[vertex])
        {
            if (visited[child])
                continue;
            traverse.push_back(make_pair(vertex, child));
            if (!visited[child])
            {
                iteration(child, visited, traverse);
            }
        }
    }
    void print(vector<pair<int, int>> vect)
    {
        outFile << "--------------------------------------------" << endl;
        for (int i = 0; i < vect.size(); i++)
        {
            outFile << vect[i].first << " ---> "
                    << vect[i].second << endl;
        }
        outFile << "---------------------------------------------" << endl;
    }
};
int main()
{
    inFile.open("input.txt");
    outFile.open("output.txt");
    int n, m;
    inFile >> n >> m;
    Graph graph(n, m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        inFile >> u >> v;
        graph.add_edge(u, v);
    }
    int source;
    inFile >> source;
    vector<pair<int, int>> v1 = graph.BFS(source);
    graph.print(v1);
    vector<pair<int, int>> v2 = graph.DFS(source);
    graph.print(v2);
    inFile.close();
    outFile.close();
}

// 7 8
// 1 2
// 1 3
// 2 4
// 3 4
// 3 5
// 5 7
// 4 7
// 4 6
// 1