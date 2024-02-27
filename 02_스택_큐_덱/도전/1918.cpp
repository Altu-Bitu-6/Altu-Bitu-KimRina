#include<iostream>
#include<string>
#include<stack>

using namespace std;

//연산자 우선순위 설정
int prec(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

string changePostfix(const string& str) {
    stack<char> s;
    string result;

    for (char ch : str) {
        // 연산자
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/') {
            // 스택에 있는 연산자 우선순위가 더 크거나 같으면 출력
            while(!s.empty() && (prec(ch) <= prec(s.top()))) {
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }
        // 왼쪽 괄호
        else if(ch=='(') {
            s.push(ch);
        }
        // 오른쪽 괄호
        else if(ch==')') {
            char top = s.top();
            s.pop();
            while( top != '(') {
                result += top;
                top = s.top();
                s.pop();
            }
        }
        // 피연산자
        else {
            result += ch;
        }
    }
    
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    
    return result;
}


int main() {
    string infix;
    cin >> infix;

    string result = changePostfix(infix);
    cout << result;

    return 0;
}