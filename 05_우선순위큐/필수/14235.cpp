#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int present(priority_queue<int>& pq){
    if(pq.empty()) { //비어있으면 -1
        return -1;
    }
    else { //아니면 가장 큰 숫자 반환, 제거
        int present = pq.top();
        pq.pop();
        return present;
    }
}


int main(){

    int n;
    cin >> n;

    priority_queue<int> pq;

    int a, b;
    for(int i=0; i<n; i++) {
        cin >> a;

        if(a == 0) { //0일 경우
            cout << present(pq) << "\n";
        }
        else { //0이 아닐 경우
            for(int j=0; j<a; j++){
                cin >> b;
                pq.push(b);
            }
        }

    }

}