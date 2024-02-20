#include<iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    int ans = 0 ;
    string input;

    set<string> set_s;

    cin >> n;
    cin >> m;

    for(int i=0; i<n; i++) {
        cin >> input;
        set_s.insert(input);
    }

    for(int i=0; i<m; i++) {
        cin >> input;
        if(set_s.find(input) != set_s.end()) {
            ans++;
        }
    }

    cout << ans;

}