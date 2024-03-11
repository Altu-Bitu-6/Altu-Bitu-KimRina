#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int S = 0;
    int M;
    cin >> M;

    for(int i=0; i<M; i++) {
        int num;
        string a;
        cin >> a;

        if(a == "add") {
            cin >> num;
            S |= (1 << num); //1로 바꾸기
        }
        else if(a == "remove") {
            cin >> num;
            S &= ~(1 << num); //0으로 바꾸기
        }
        else if(a == "check") {
            cin >> num;
            if (S & (1 << num)) { //숫자가 존재하면 1출력
                cout << "1\n";
            }
            else { //0이면 0출력
                cout << "0\n";
            }
        }
        else if(a == "toggle") {
            cin >> num;
            if(S & (1 << num)) { //x가 있으면 제거
                S &= ~(1 << num);
            }
            else { //없으면 x 추가
                S |= (1 << num);
            }
        }
        else if (a == "all") {
            S = (1 << 21) - 1; //111 ... 111 넣기
        }
        else if (a == "empty") {
            S = 0;
        }
    }

    return 0;
}