#include<bits/stdc++.h>
using namespace std;

stack<int> s1;
stack<char> s2;
string s;

int check(char c) {
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else return -1;
}

int cal() {
    int b = s1.top();
    s1.pop();
    int a = s1.top();
    s1.pop();
    char c = s2.top();
    s2.pop();

    if(c == '+') s1.push(a + b);
    else if(c == '-') s1.push(a - b);
    else if(c == '*') s1.push(a * b);
    else if(c == '/') s1.push(a / b);
}

int main() {
    cin >> s;
    int i = 0;
    while(i < s.size()) {
        if(check(s[i]) > 0) {
            while(!s2.empty() && check(s[i]) <= check(s2.top())) {
                cal();
            }
            s2.push(s[i]);
        } else if(s[i] == '(') s2.push(s[i]);
        else if(s[i] == ')') {
            while(s2.top() != '(') cal();
            s2.pop();
        } else {
            int cc = 0;
            while(s[i] >= '0' && s[i] <= '9' && i < s.size()) {
                cc = cc * 10 + (s[i] - '0');
                i++;
            }
            s1.push(cc);
            continue;
        }
        i++;
    }


    while(!s2.empty()) cal();
    cout << s1.top();
}













