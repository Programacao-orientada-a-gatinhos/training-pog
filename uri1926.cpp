#include <stdio.h>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

const int MAX = 50001;
vector<int> adj[MAX];
int a, b, sequence[MAX], answer, n, depth, card;

int bfs (int s) {
    queue<int> q;
    int visited[MAX];
    fill(visited, visited + MAX, 0);
    q.push(s); // primeiro nessa merda de fila
    visited[s]=1;

    while (!q.empty()) {
        int curr = q.front(); // pega o primeiro
        q.pop(); // tira o primeiro
        for (int neighbor : adj[curr]) { // itera em todos os vizinhos da carta em questão
            printf("gen> %d ", visited[curr]);
            printf("neighbor> %d ", neighbor);
            printf("visited? %d\n", visited[neighbor]);
            if (!visited[neighbor]) {
                if (sequence[neighbor] == card) {
                    return visited[curr];
                } else {
                    visited[neighbor] = visited[curr] + 1;
                    printf("gen atributted> %d\n", visited[neighbor]);
                    printf("rodou\n"); 
                    q.push(neighbor);
                }
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &sequence[i]);
    }
    while (scanf(" %d %d", &a, &b) != EOF){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    unordered_set<int> seen_cards;
    for (int j=1; j<=n; j++) {
        if (seen_cards.count(sequence[j]) == 0) {
            seen_cards.insert(sequence[j]);
            card = sequence[j];
            int result = bfs(j);
            // printf("%d", result);
            answer += result;
        }
    }
    printf("%d\n", answer);
}
