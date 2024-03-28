#include <iostream>
#include <vector>

using namespace std;

long speed(vector<int> v, int n) {
    long result;

    //마지막 속도
    result = v[n-1];

    for (int i = n - 2; i >= 0; --i) {
        //앞에 속도가 더 크면 result 변경
        if (v[i] > result) {
            result = v[i];
        }
        //아닐 경우
        else {
            if (result % v[i]) { //result가 v[i]의 배수가 아닌 경우
                //result보다 큰 v[i]의 배수 중 가장 작은 값 찾기
                result /= v[i];
                result = (result + 1) * v[i];
            }
        }
    }
    return result;
}

int main() {
    int n;
    long result;

    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    result = speed(v, n);
    cout << result;

    return 0;
}
