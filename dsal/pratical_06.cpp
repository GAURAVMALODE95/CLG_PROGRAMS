#include <iostream>
#include <stack>
using namespace std;
int cost[10][10], i, j, k, visited[10], queue[10], visited1[10], list[10];
int n;
struct node
{
    int vertex;
    struct node *next;

} *head[10];
void adj_matrix()
{
    int m;
    cout << "Enter the no of vertices : " << endl;
    cin >> n;
    cout << "Enter the no of edges : " << endl;
    cin >> m;
    for (k = 1; k <= m; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
    cout << "Adjacency matrix : " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
}

void DFS()
{
    for (i = 0; i < 10; i++)
    {
        visited[i] = 0;
    }
    stack<int> s;
    int v;
    cout << "Enter the starting vertex : " << endl;
    cin >> v;
    cout << v << " ";
    visited[v] = 1;
    k = 1;
    while (k < n)
    {
        for (j = 1; j <= n; j++)
        {
            if (cost[v][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                s.push(j);
            }
        }
        v = s.top();
        cout << v << " ";
        visited[v] = 1;
        s.pop();

        k++;
    }
}

void BFS()
{
    int front = -1, rear = -1;
    for (i = 0; i < 10; i++)
    {
        visited1[i] = 0;
    }
    int v;
    cout << "Enter the starting vertex : " << endl;
    cin >> v;
    cout << v << " ";
    visited1[v] = 1;
    k = 1;
    while (k < n)
    {
        for (j = 1; j <= n; j++)
        {
            if (cost[v][j] == 1 && visited1[j] == 0)
            {
                visited1[j] = 1;
                queue[rear++] = j;
            }
        }
        v = queue[front++];
        cout << v << " ";
        visited1[v] = 1;
        k++;
    }
}
int main()
{

    adj_matrix();
    cout<<"dfs : ";
     DFS();
    cout<<"bfs  :";
     BFS();
    
    return 0;
}