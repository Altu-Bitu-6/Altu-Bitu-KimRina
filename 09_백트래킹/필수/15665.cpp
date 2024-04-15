#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10];
int check[10];

void back(int n, int m, int idx){
    if(idx == m) {
        for(int i=0; i<m; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; ++i) {
        if(check[i] == 0) {
            check[i] = 1;
            arr[idx] = i;
            back(n, m, idx+1);
            check[i] = 0;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    back(n, m, 0);
    return 0;
}
