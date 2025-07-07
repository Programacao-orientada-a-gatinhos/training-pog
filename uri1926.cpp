#include <stdio.h>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

const int MAX = 50001;
vector<int> adj[MAX];
int a, b, sequence[MAX][2], answer, n, depth, card, visited[MAX], curr_gen=0;

int bfs (int s) {
    queue<int> q;
    q.push(s);
    sequence[s][1]=0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int neighbor : adj[curr]) {
            if (visited[neighbor]==curr_gen) {
                visited[neighbor]=curr_gen;
                sequence[neighbor][1] = sequence[curr][1]+1;
                if (sequence[neighbor][0] == card) {
                    return sequence[neighbor][1];
                } else {
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
        scanf("%d", &sequence[i][0]);
    }
    while (scanf(" %d %d", &a, &b) != EOF){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    unordered_set<int> seen_cards;
    for (int j=1; j<=n; j++) {
        if (seen_cards.count(sequence[j][0]) == 0) {
            seen_cards.insert(sequence[j][0]);
            sequence[j][1] = 0;
            card = sequence[j][0];
            curr_gen++;
            int result = bfs(j);
            answer += result;
        }
    }
    printf("%d\n", answer);
}
