class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.size()==0) return "";
        stack<int> st;

        for(int i=0; i<s.size(); i++)
            if(s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
                if (!st.empty() && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);

        string result = "";
        for(int i=s.size()-1; i>=0; i--)
            if(!st.empty() && st.top() == i)
                st.pop();
            else
                result += s[i];

        reverse(result.begin(), result.end());
        return result;
    }
};