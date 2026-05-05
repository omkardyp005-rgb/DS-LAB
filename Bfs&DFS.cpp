#include <iostream>
using namespace std;

int graph[10][10], visited[10];
int n;

void dfs(int node) {
    cout << node << " ";
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    int queue[10], front = 0, rear = 0;

    for(int i = 0; i < n; i++) visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear) {
        int node = queue[front++];
        cout << node << " ";

        for(int i = 0; i < n; i++) {
            if(graph[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting node: ";
    cin >> start;

    for(int i = 0; i < n; i++) visited[i] = 0;
    cout << "\nDFS: ";
    dfs(start);
    
    cout << "\nBFS: ";
    bfs(start);

    return 0;
}
