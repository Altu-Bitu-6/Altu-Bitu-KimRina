#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

//a가 b에 포함되어 있는지 확인
bool isSubset(const string& a, const string& b) {
    map <char, int> charCount;

    // 문자열 b에 있는 각 문자 카운트
    for (char ch : b) {
        charCount[ch]++;
    }
    // a의 각 문자가 b에 있는지 확인
    for (char ch : a) {
        // 만약 문자가 b에 없거나 카운트 0이면 false
        if (charCount.find(ch) == charCount.end() || charCount[ch] == 0) {
            return false;
        }
        charCount[ch]--;
    }
    return true;
}

bool isSimilar(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    cout << s1 << "\n";
    cout << s2 << "\n";
    
    int dif = 0;
    //문자 길이가 같음 -> 다른 문자 1개 이하
    if(s1.length() == s2.length()) {
        for(int i=0; i< s1.length(); i++) {
            if(s1[i] != s2[i]){
                dif++;
            }
        }
        return dif<=1;
    }
    //길이 차이 = 1
    //기존 문자길이 > 비교 문자길이
    else if(s1.length()-1 == s2.length()) {
        return isSubset(s2, s1);
    }
    //기존 문자길이 < 비교 문자길이
    else if(s1.length()+1 == s2.length()) {
        return isSubset(s1, s2);
    }
    
    return false;
}


int main() {
    int n;
    int cnt = 0 ;
    cin >> n;

    string input, cmp;
    cin >> input;

    for(int i=0; i<n-1; i++) {
        cin >> cmp;
        if(isSimilar(input, cmp)) {
            cnt++;
        }
    }

    cout << cnt;
}