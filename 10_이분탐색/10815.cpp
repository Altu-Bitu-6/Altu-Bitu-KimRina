#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int binarySearch(int num, vector<int>& card, int n) {
    int low = 0;
    int high = n-1;

    while (low <= high) {
        int mid = (low + high) / 2;

        //원하는 값 찾았으면 1 반환
        if(num == card[mid]) return 1;
        //원하는 값이 mid보다 작을 경우
        else if(num < card[mid]) {
            high = mid - 1;
        }
        //원하는 값이 mid보다 클 경우
        else {
            low = mid + 1;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> card(n);
    for(int i=0; i<n; i++) {
        cin >> card[i];
    }

    //카드 정렬하기
    sort(card.begin(), card.end());

    int m, num;
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> num;

        cout << binarySearch(num, card, n) << ' ';
    }

    return 0;
}