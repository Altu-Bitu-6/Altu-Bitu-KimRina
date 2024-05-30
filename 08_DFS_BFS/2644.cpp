#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, p1, p2, m;
vector<int> v[101];
int depth[101];  //각 사람의 촌수 저장

void dfs(int start, int d) {
	for (int i = 0; i < v[start].size(); i++) { //현재 노드의 인접 노드 탐색
		int nxt = v[start][i];

		if (depth[nxt] == 0) {
			depth[nxt] = d + 1;
			dfs(nxt, depth[nxt]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);

	cin >> n >> p1 >> p2 >> m;
    
    int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;	// x가 y의 부모
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(p1, 0);
    // 촌수 없으면 -1 출력
	if (depth[p2] == 0) {
        cout << -1;
    }
	else {
        cout << depth[p2];
    }

	return 0;
}