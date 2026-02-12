#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
bool isValid(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else if ((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']'))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    bool ans;
    ans = isValid(s);
    cout << ans << endl;
    return 0;
}