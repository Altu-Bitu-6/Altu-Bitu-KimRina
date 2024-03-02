#include<iostream>
#include<queue>

using namespace std;


void pick(int n, int k) {
    queue<int> q;

    for(int i=1; i<=n; i++) {
        q.push(i);
    }
    cout << "<";


    for(int i=0; i<n; i++) {
        //j=1,2, k-1 이면 dequeue, enqueue 하기
        for(int j=0; j<k-1; j++){
            q.push(q.front());
            q.pop();
        }
        //i=k 이면 cout << 숫자
        cout << q.front();
        q.pop();

        //위 방법 N번 반복
        if(i != n-1) {
            cout << ", ";
        }
    }

    cout << ">";

}

int main() {
    int n, k;
    cin >> n >> k;

    pick(n, k);
    return 0;
}

