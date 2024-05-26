#include <iostream>
#include <algorithm>
#include <vector>

const int MAX = 101;

using namespace std;

vector<vector<int>> list; //현재 노트와 연결된 다른 노드들의 리스트
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;

    // 현재 노드랑 연결된 모든 노드들
    for(int i=0; i<list[node].size(); i++) {
        int next = list[node][i];
        if(!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int com, net;
    cin >> com >> net;

    list.resize(com+1);
    visited.resize(com+1, false);

    for(int i=0; i<net; i++) {
        int start, end;
        cin >> start >> end;

        // 양방향으로 추가
        list[start].push_back(end);
        list[end].push_back(start);
    }
    //1번 컴퓨터 시작으로 dfs 실행
    dfs(1);

    int virus = count(visited.begin(), visited.end(), true) -1;

    cout << virus;

    return 0;
}
