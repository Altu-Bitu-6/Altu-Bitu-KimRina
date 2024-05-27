#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define endl '\n';
const int MAX = 100001;

int maxLength(vector<int> list, int n, int k) {
    int result = 1;
    int left = 0; int right = 1;
    //각 숫자 개수
    vector<int> count(MAX, 0);

    count[list[left]] ++;
    //right가 수열 가장 끝으로 가면 종료
    while(right < n) {
        if(count[list[right]] >= k) { //k개 이상일 경우, 아닐때까지 left 한칸씩 이동
            count[list[left]] --;
            left++;
            continue;
        }

        else { //k개 이상 아닐 경우
            count[list[right]]++;
            right++;

            result = max(result, right-left);
        }
    }
    
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    //수열
    vector<int> list(n);
    for(int i=0; i<n; i++) {
        cin >> list[i];
    }

    cout << maxLength(list, n, k);

    return 0;
}