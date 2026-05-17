#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 99999999

void selectionSort()
{
    int n;
    cout << "\n ------------Selection sort -------------------\n";
    cout << "enter no. of elements : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }

    cout << "\nSorted array : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// JOB SCHEDULING+++++++++++++++++++++++++++++++

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void JobScheduling()
{
    int n;
    cout << "\n---------- Job Scheduling Algorithm ---------------\n";
    cout << "Enter no. of jobs: ";
    cin >> n;
    vector<Job> jobs(n);
    cout << "Enter job id, deadline and profit:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), compare);

    vector<int> slot(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                cout << jobs[i].id << " ";
                break;
            }
        }
    }
    cout << endl;
}

void dijkstras()
{
    int n;
    cout << "\n-------- Dijkstras -------------\n";
    cout << "Enter no. of vertices: ";
    cin >> n;
    int graph[n][n];
    cout << "Enter adjacency matrix : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    int source;
    cout << "Enter source vertex:";
    cin >> source;

    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    dist[source] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        int min = INF, u;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dist[v] <= min)
            {
                min = dist[v];
                u = v;
            }
        }
        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex \t Distance from source \n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main()
{
    int choice;
    cout << "\n-----------------Greedy Algo------------------------\n";
    do
    {

        cout << "1 - selection sort\n";
        cout << "2 - job scheduling\n";
        cout << "3 - dijkstras algo\n";
        cout << "4 - exit";

        cout << "\nEnter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            selectionSort();
            break;
        case 2:
            JobScheduling();
            break;
        case 3:
            dijkstras();
            break;
        case 4:
            cout << "Program ended";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}