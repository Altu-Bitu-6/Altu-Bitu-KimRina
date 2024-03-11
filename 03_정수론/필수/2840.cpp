#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

vector<char> lucky_wheel (int n, int k) {
    vector<char> v(n, '?'); //처음 가르킨 곳이 v[0] 알파벳
    int cnt;
    int order = 0;
    char input;

    for(int i=0; i<k; i++) {
        cin >> cnt >> input;
        order += cnt;
        
        order %= n;
        // 해당 위치가 비었거나 같은 알파벳인 경우
        if (v[order] == '?' || v[order] == input) { 
            v[order] = input;
        } 
        // 해당 위치에 다른 알파벳이 있는 경우(행운의 바퀴x)
        else { 
            v[0] = '!';
            return v;
        }
    }
    //같은 애 있나 확인
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(v[i] != '?' && v[i] == v[j]) {
                v[0] = '!';
                return v;
            }
        }
    }

    // 벡터 회전시키기
    reverse(v.begin(), v.end());
    rotate(v.begin(), v.end() - order -1, v.end());
    return v;
}


int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<char> result;
    result = lucky_wheel(n, k);

    if(result[0] == '!'){
        cout << '!';
    } 
    else {
        for(char ch : result) {
            cout << ch;
        }
    }
}
