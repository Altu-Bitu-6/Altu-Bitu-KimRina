#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

//반복문 이용하여 최대공약수(gcd) 구하기
int getGcdIter(int a, int b)  {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

vector<int> add(int a1, int a2, int b1, int b2) {
    
    int numerator; //분자
    int denominator; //분모

    numerator = a1*b2 + a2*b1;
    denominator = b1 * b2;

    int gcd = getGcdIter(numerator, denominator);

    denominator /= gcd;
    numerator /= gcd;
    
    vector<int> v = {numerator, denominator};
    return v;
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a1, a2, b1, b2;

    cin >> a1 >> b1;
    cin >> a2 >> b2;

    vector<int> v = add(a1, a2, b1, b2);
    cout << v[0] << " " << v[1];

}