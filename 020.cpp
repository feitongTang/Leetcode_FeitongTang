/*
    link: https://leetcode.com/problems/valid-parentheses/
*/

/*
    comment:
    need to consider different situations
    a stack problem
*/

/*
    status:
    Runtime: 19.33%
    Memory Usage: 50.86%
*/

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> container;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' or s[i] == '[' or s[i] == '{') {
                container.push(s[i]);
            } else {
                if (container.empty()) {
                    return false;
                }
                char temp = container.top();
                if ((temp == '(' && s[i] == ')') || (temp == '[' && s[i] == ']') || (temp == '{' && s[i] == '}')) {
                    container.pop();
                } else {
                    return false;
                }
            }
        }
        if (container.empty()) {
            return true;
        } else {
            return false;
        }
    }
};