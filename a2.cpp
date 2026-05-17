#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int x, y;
    int g, h, f;
    Node *parent;

    Node(int x, int y, int g, int h, Node *parent)
        : x(x), y(y), g(g), h(h), f(g + h), parent(parent)
    {
    }
};

// heuristic manhattan distance
int heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isValid(int x, int y, vector<vector<int>> &graph)
{
    return x >= 0 && y >= 0 && x < graph.size() && y < graph[0].size() && graph[x][y] == 0;
}

void astar(vector<vector<int>> &graph, pair<int, int> start, pair<int, int> goal)
{
    // min heap based on f value
    // i.e. the node with the lowest f value will be at the top of the priority queue
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> open;
    vector<vector<bool>> closed(graph.size(), vector<bool>(graph[0].size(), false));

    Node *startNode = new Node(start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second), nullptr);
    open.push({startNode->f, startNode});

    while (!open.empty())
    {
        Node *curr = open.top().second;
        open.pop();

        int x = curr->x;
        int y = curr->y;

        closed[x][y] = true;

        if (x == goal.first && y == goal.second)
        {
            cout << "Path found \n";
            while (curr)
            {
                cout << "(" << curr->x << "," << curr->y << ") ";
                curr = curr->parent;
            }
            return;
        }

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, graph) && !closed[nx][ny])
            {
                int gnew = curr->g + 1;
                int hNew = heuristic(nx, ny, goal.first, goal.second);

                Node *nbr = new Node(nx, ny, gnew, hNew, curr);
                open.push({nbr->f, nbr});
            }
        }
    }
    cout << "NO PATH FOUND !!!!! " << endl;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 0}};

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {3, 3};

    astar(graph, start, goal);

    return 0;
}