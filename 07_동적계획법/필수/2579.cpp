#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int stair[301];
int dp[301];

int upStair(int n) {
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    //연속된 세개 밟으면x 
    //3번까지 가는 길은 두가지이며 둘 중 값이 큰거로 저장
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

    for(int i = 4; i <= n; i++) {
        //두가지 방법 중 값이 큰 것으로 저장
        dp[i] = max(dp[i-2] + stair[i], dp[i-3] + stair[i-1] + stair[i]);
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> stair[i];
    }    

    cout << upStair(n);

    return 0;
}