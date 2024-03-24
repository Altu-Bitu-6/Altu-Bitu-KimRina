#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    // 최소힙으로 설정
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, num;
	cin >> n;

    //처음 n개 넣기
    for (int i=0; i<n; i++){
        cin >> num;
        pq.push(num);
    }

    //n개 넣고 n개 제거 -> n-1번 반복2075.cpp
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.push(num);
		}
		for(int j=0; j<n; j++){
            pq.pop();
        }
	}

    //남은 수 n개 중 제일 작은 수 출력
	cout << pq.top();
}
