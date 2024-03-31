#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string pelindrom(string name){
    vector<int> freq(26, 0); // freq 벡터를 0으로 초기화
    for (int i = 0; i < name.length(); i++) {
        freq[name[i] - 'A']++; // 알파벳의 빈도수 카운트
    }

    int cnt=0, location=-1;
    for(int i=0; i<freq.size(); i++) {
        if(freq[i] % 2 == 1){ // 홀수인 경우
            cnt++;
            location = i;
            freq[i]--;
        }
    }

    string result;
    string temp;
    //홀수개가 1개 이하로 있으면 만들수있음
    if(cnt <= 1){
        for(int i=0; i<freq.size(); i++) {
            for(int j=0; j<freq[i]/2; j++) {
                result += i + 'A';
            }
        }
        temp = result;

        if(location != -1) { 
            result += location + 'A';
        }

        //temp 뒤집어서 result 뒤에 붙이기
        reverse(temp.begin(), temp.end());
        result += temp;

        return result;
    }
    // 펠린드롬을 만들 수 없는 경우
    else { 
        return "I'm Sorry Hansoo";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string name;
    cin >> name;

    cout << pelindrom(name) << '\n'; // 결과 출력
}
