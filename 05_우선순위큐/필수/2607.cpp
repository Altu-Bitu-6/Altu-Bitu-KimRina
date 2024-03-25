// 2607: 비슷한 단어 (실버3/구현, 문자열)
#include <iostream>
#include <vector>

using namespace std;
const int NUM_CHARS = 26;

// 각 알파벳의 개수 세기(구성 세는 함수)
void countFreq(string word, vector<int> &freq) {
    //단어 구성하는 문자들의 배열
    for (int i = 0; i < word.length(); i++) {
        freq[word[i] - 'A']++; //각 알파벳 아스키코드(0~25)에 해당하는 배열 위치에 +1 하기
    }
}

// 구성 비교하는 함수 (단어 차이 몇개 나는지 세는 함수)
// (비교할 단어, 원본 단어의 구성 저장한 배열)
int countDiff(string word, vector<int> original_freq) { 
    vector<int> freq(NUM_CHARS, 0); //비교할 단어 구성 저장할 벡터
    int diff = 0; // 원본 단어와의 차이

    countFreq(word, freq); // 비교 대상 알파벳의 개수(구성) 세기
    
    // 원본 단어와 다른 알파벳 개수 구하기
    for (int i = 0; i < NUM_CHARS; i++) {
        diff += abs(original_freq[i] - freq[i]);
    }
    return diff;
}

int main() {
    int N, ans=0; 
    string original;
    // 입력
    cin >> N;
    cin >> original; //첫 단어(비교대상) 입력받기
    vector<int> original_freq(NUM_CHARS, 0); //알파벳 개수만큼 배열 만들기

    // 연산(비교대상 단어 구성 연산)
    countFreq(original, original_freq);

    // 첫번째 단어 제외, 나머지 단어 입력받고 비교하기 -> n-1번 반복
    for (int i = 1; i < N; i++) {
        string word;
        cin >> word;

        int diff = countDiff(word, original_freq);
        // 비슷한 단어 세기
        // 차이 0개인 경우(구성 동일)
        // 차이가 1개인 경우(1개 추가 or 제거) 
        // 차이가 2개이면서 길이 같을 경우(1개 변경)
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length()) {
            ans++;
        }
    }
    // 출력
    cout << ans;
    return 0;
}