#include <iostream>
#include <map>
#include <stack>

bool isValid(std::string s) {
    std::stack<char> st;
    std::map<char, char> mapping = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != mapping[c]) {
                
                return false;
                
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    std::string s = "{()}";
    
    if (isValid(s)) {
        std::cout << "Строка допустима." << std::endl;
    } else {
     std::cout << "Строка недопустима." << std::endl;
    }
    return 0;
}
