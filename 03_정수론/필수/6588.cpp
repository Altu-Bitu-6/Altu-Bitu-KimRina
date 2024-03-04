#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<bool> prime(1000001, true); // 인덱스 0부터 1000000까지 사용

// 에라토스테네스의 체 이용하기
void findPrime() { 
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= 1000000; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    findPrime();

    int input;
    cin >> input;
    while(input != 0) {
        
        bool check = false;
        for(int i=3; i <= input/2; i++) {
            if(prime[i] && prime[input-i]) {
                cout << input << " = " << i << " + " << input-i << '\n';
                check = true;
                break;
            }
        }

        if(!check) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
        
        cin >> input;
    }

}