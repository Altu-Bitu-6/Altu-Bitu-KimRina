#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


//dp[i] = arr의 i번째를 마지막 값으로 가지는 가장 긴 부분 수열의 길이
int arr[1001];
int dp[1001];

int subSequence(int n) {
    //dp 첫번째, answer는 1로 초기화
    dp[0] = 1; 
    int answer = dp[0];

    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            // 현재 원소가 이전 원소보다 클 때
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // 현재 원소까지 고려했을 때 최대 길이
        answer = max(answer, dp[i]);
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << subSequence(n);

    return 0;
}