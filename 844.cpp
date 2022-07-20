/*
    link: https://leetcode.com/problems/backspace-string-compare/
*/

/*
    comment:
    the algorithm is easy, but it uses too much space
*/

/*
    status:
    Runtime: 52.03%
    Memory Usage: 7.26%
*/


#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_stack,t_stack;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '#') {
                s_stack.push(s[i]);
            } else {
                if (!s_stack.empty()) {
                    s_stack.pop();
                }
            }
        }
        for (int j = 0; j < t.length(); ++j) {
            if (t[j] != '#') {
                t_stack.push(t[j]);
            } else {
                if (!t_stack.empty()) {
                    t_stack.pop();
                }
            }
        }
        if (s_stack.empty() && t_stack.empty()) {
            return true;
        } else if (!s_stack.empty() && !t_stack.empty()) {
            char s_temp = s_stack.top(), t_temp = t_stack.top();
            while (s_temp == t_temp) {
                if (s_stack.empty() && t_stack.empty()) {
                    return true;
                } else if (!s_stack.empty() && !t_stack.empty()) {
                    s_temp = s_stack.top();
                    t_temp = t_stack.top();
                    s_stack.pop();
                    t_stack.pop();
                } else {
                    return false;
                }
            }
        }
        return false;
    }
};