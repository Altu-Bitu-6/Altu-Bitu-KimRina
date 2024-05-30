#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define endl '\n';

vector<int> list(30000);
vector<int> sushi(3001);

int maxSushi(int n, int d, int k, int c) {
    int result = 0;
    int cnt = 0;

    int left = 0;
    int right = k-1;

    for(int i=0; i<k; i++){
        sushi[list[i]]++;
        if(sushi[list[i]] == 1) {
            cnt++;
        }
    }

    // 쿠폰으로 제공된 초밥
    sushi[c]++;
    if(sushi[c] == 1) {
        cnt++;
    }

    //최대 초밥 개수 계산하기
    while(left < n) {
        result = max(result, cnt);
        if(--sushi[list[left++]] == 0) {
            cnt--;
        }

        right = (right+1) % n;
        if(++sushi[list[right]] == 1) {
            cnt++;
        }

    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    for(int i=0;i<n;i++) {
        cin>>list[i];
    }
    
    cout << maxSushi(n, d, k, c);
    return 0;
}