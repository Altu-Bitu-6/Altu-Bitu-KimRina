#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n';

//m=조카수, n=과자수
bool check(int len, int m, int n, vector<int> &snack) {
    int cnt = 0;

    //과자 수가 조카 수보다 많으면
    if (m < n) {
        for(int i = n-1; i >= n-m-1; i--) {
            cnt += snack[i] / len;
        }
    }
    //조카 수가 과자 수보다 많으면
    else {
        for(int i = 0; i < n; i++) {
            cnt += snack[i] / len;
        }
    }
    //조카 모두에게 줄수있는지 확인
    if(cnt >= m) return true;
    else return false;
}

int binarySearch(int m, int n, vector<int> &snack) {
    
    int max = 0;
    int left = 1; //과자 최소길이
    int right = snack[n-1]; //과자 최대길이
    int mid;

    while(left <= right) {
        int mid = (left + right) / 2;
        if(check(mid, m, n, snack)) {
            max = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return max;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //m = 조카 수, n = 과자 수
    int m, n;
    cin >> m >> n;

    vector<int> snack(n);
    for(int i=0; i<n; i++) {
        cin >> snack[i];
    }
    sort(snack.begin(), snack.end());

    cout << binarySearch(m, n, snack);

    return 0;
}