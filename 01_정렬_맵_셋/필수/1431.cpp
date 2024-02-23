#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int compare(string& s1, string& s2) {
    int sumA = 0, sumB = 0;

    // A와 B의 길이가 다를 경우
    if(s1.size() != s2.size()) {
        return s1.size() < s2.size();
    }
    // A와 B의 길이가 같을 경우
    else {
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] >= '0' && s1[i] <= '9'){
                sumA += s1[i] - '0';
            }

            if(s2[i] >= '0' && s2[i] <= '9'){
                sumB += s2[i] - '0';
            }
        }

        // sumA != sumB
        if (sumA != sumB) return sumA < sumB;
        // sumA = sumB
        else return s1 < s2;
    }
}


int main() {
    int n;
    cin >> n;
    
    string str[100];
    for (int i=0; i < n; i++) {
        cin >> str[i];
    }
    
    sort(str, str + n, compare);

    for(int i=0; i < n; i++) {
        cout << str[i] << '\n';
    }
    return 0;
}

