#include <string>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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