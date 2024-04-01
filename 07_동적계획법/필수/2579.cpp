#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int stair[301];
int dp[301];

int upStair(int n) {
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

    for(int i = 4; i <= n; i++) {
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