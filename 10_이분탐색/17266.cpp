#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define endl '\n';

//굴다리 모두 비추는지 확인
//n = 굴다리 길이, m = 가로등 개수
bool check(int height, int n, int m, vector<int> location) {
    //첫번째 가로등 위치 확인
    if(location[0] > height) {
        return false;
    }
    //중간 가로등 위치 확인
    //이전 가로등에서 hegith*2보다 멀리있으면 false
    for(int i=1; i<m; i++) {
        if(location[i] > location[i-1] + 2*height) {
            return false;
        }
    }
    //마지막 가로등 위치 확인
    if(n - location[m-1] > height) {
        return false;
    }

    return true;
}

int binarySearch(int n, int m, vector<int> location) {
    int left = 0;
    int right = n;

    int height, mid;

    while(left <= right) {
        mid = (left + right) / 2;

        //가로등 길이 조건 부합할 경우 줄여서 탐색
        if(check(mid, n, m, location)) {
            height = mid;
            right = mid - 1;
        }
        //조건 부합 아닐 경우 늘려서 탐색
        else {
            left = mid + 1;
        }
    }

    return height;
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    //n=굴다리 길이, m=가로등 개수
    int n, m;
    cin >> n >> m;
    vector<int> location(m);

    for(int i=0; i<m; i++) {
        cin >> location[i];
    }
    
    cout << binarySearch(n, m, location);

    return 0;
}