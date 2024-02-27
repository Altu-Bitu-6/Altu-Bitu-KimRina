#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> NGE(int n) {
    stack<int> s;
    vector<int> arr(n);
    vector<int> result(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];

    s.push(1e6+1);
    //입력 받은 수 뒤에서 부터 비교
    for(int i=n-1; i>=0; i--) {
        while(s.top() <= arr[i]){
            s.pop();
        }

        if (s.top() == 1e6+1) 
            result[i] = -1;
        else 
            result[i] = s.top();
        
        s.push(arr[i]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> result(n);
    result = NGE(n);

    for(int i=0; i<n; i++) {
        cout << result[i] << " ";
    }
}
