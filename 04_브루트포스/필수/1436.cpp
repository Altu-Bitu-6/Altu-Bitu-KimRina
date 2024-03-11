#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int num = 665;
    
    while(n) {
        num++;
        //string으로 바꿔서 666 찾기
        if(to_string(num).find("666") != string::npos) {
            n--;
        }
    }
    cout << num;
    return 0;
}