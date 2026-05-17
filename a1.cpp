#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

void bfsTraversal(string root, unordered_map<string, vector<string>> &webGraph)
{
    unordered_set<string> vis;
    queue<string> q;

    vis.insert(root);
    q.push(root);

    while (!q.empty())
    {
        string node = q.front();
        q.pop();
        cout << node << " ";

        for (string nbr : webGraph[node])
        {
            if (!vis.count(nbr)) // or if (vis.find(nbr) == vis.end())
            {
                vis.insert(nbr);
                q.push(nbr);
            }
        }
    }
    cout << endl;
    return;
}

// DFS
bool isValid(int x, int y, vector<vector<char>> &building, int rows, int cols)
{
    if (x < rows && x >= 0 && y >= 0 && y < cols && building[x][y] != '1' && building[x][y] != 'V')
    {
        return true;
    }
    return false;
}

void dfs(int stx, int sty, vector<vector<char>> &building, int rows, int cols, bool &found)
{
    if (building[stx][sty] == 'E')
    {
        found = true;
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    building[stx][sty] = 'V';

    for (int i = 0; i < 4; i++)
    {
        int nx = stx + dx[i];
        int ny = sty + dy[i];

        if (isValid(nx, ny, building, rows, cols))
        {
            dfs(nx, ny, building, rows, cols, found);
        }
    }
}

// -------------------------------------------------------------------------------

int main()
{
    cout << "Enter 1 for bfs and 2 for dfs : ";
    int option;
    cin >> option;

    if (option == 1)
    {
        unordered_map<string, vector<string>> webGraph;
        int n;
        cout << "Enter no. of webpages : ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string page;
            int links;

            cout << "Enter root page name : ";
            cin >> page;
            cout << "\nEnter no. of subpages or links to this root page : ";
            cin >> links;

            for (int j = 0; j < links; j++)
            {
                string link;
                cout << "\nEnter subpage node : ";
                cin >> link;
                webGraph[page].push_back(link);
            }
        }

        string root;
        cout << "Enter the root element of the web page : ";
        cin >> root;

        cout << "Calling BFS : ";
        bfsTraversal(root, webGraph);
    }
    else if (option == 2)
    {
        int rows, cols;
        cout << "enter no. of rows and columns : ";
        cin >> rows >> cols;

        vector<vector<char>> building(rows, vector<char>(cols));

        cout << "Enter building (S - start; E - end; 0 - can move freely; 1 - wall ) : ";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> building[i][j];
            }
        }

        int stx = -1, sty = -1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (building[i][j] == 'S')
                {
                    stx = i;
                    sty = j;
                }
            }
        }

        if (stx == -1 || sty == -1)
        {
            cout << "Enter valid starting position !!!!!";
            return 0;
        }

        bool found = false;
        dfs(stx, sty, building, rows, cols, found);
        if (found)
        {
            cout << "Exit path found using DFS\n";
        }
        else
        {
            cout << "No exit path found \n";
        }
    }
    else
    {
        cout << "Enter valid value from 1 and 2 only!! ";
    }
    return 0;
}
