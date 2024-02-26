#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool usingStack(const string& str) {
    stack<char> s;

    for(char b : str) {
        if (b == '[' || b == '(') {
            s.push(b);
        }
        else if(b == ']' || b == ')') {
            //비어있는데 닫힘 괄호 나올 경우
            if(s.empty())
                return false;
            //짝이 안맞는 경우
            if((b == ')' && s.top() != '(') || (b == ']' && s.top() != '['))
                return false;
            //짝이 맞으면 제거
            s.pop();
        }
    }

    //비어있으면 true, 아니면 false
    return s.empty();
}

int main() {
    
    string line;

    while (true) {
        getline(cin, line);
        //. 나오면 끝내기
        if(line == ".") {
            break;
        }

        if(usingStack(line)) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

}