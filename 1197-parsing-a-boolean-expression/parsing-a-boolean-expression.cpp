class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        int n = exp.size();
        int i = 0;
        while(i<n){
            char temp = exp[i];
            if(temp == 't' ||temp == 'f' ||temp == '(' ||temp == '!' ||temp == '&' ||temp == '|'){
                st.push(temp);
                i++;
            }

            else if(temp == ',')i++;
            else if(temp == ')'){i++;
                vector<char> ch;
                while(st.top()!='('){
                    ch.push_back(st.top());
                    st.pop();
                }
                st.pop();
                int t = st.top();
                st.pop();
                if(t == '!'){
                    if(ch[0] == 'f')st.push('t');
                    else st.push('f');
                }
                else if(t == '&'){  
                    char res = true;
                    for(auto c:ch){
                        if(c == 'f') res = false;
                    }
                    if(res)st.push('t');
                    else st.push('f');
                }
                else if(t == '|'){  
                    char res = false;
                    for(auto c:ch){
                        if(c == 't') res = true;
                    }
                    if(res)st.push('t');
                    else st.push('f');
                }
            }
        }
        return st.top() == 't';
    }
};