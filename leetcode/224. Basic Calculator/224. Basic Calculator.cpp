// ³Ë³ý²»¿ÉÒÔÇ¶Ì×£¬À¨ºÅ¿ÉÒÔÇ¶Ì×
 
class Solution {
public:
	bool isdigit(char c){
		return c>='0' && c<='9';
	}
	
    int calculate(string s) {
        int len = s.length();
        int sign = 1;
        
        stack<long long> st;
        long long ans = 0;
		for(int i = 0; i < len; i++){
        	if(isdigit(s[i])){
        		long long tmp = s[i] - '0';
        		while(i + 1 < len && isdigit(s[i+1])){
        			tmp = tmp * 10 + s[i+1] - '0';
        			i++;
				}
				
				ans += tmp * sign;
			} else if(s[i] == '+'){
				sign = 1;
			} else if(s[i] == '-'){
				sign = -1;
			} else if(s[i] == '('){
				st.push(ans);
				ans = 0;
				st.push(sign);
				sign = 1;
			} else if(s[i] == ')'){
				ans = st.top() * ans;
				st.pop();
				ans += st.top();
				st.pop();
			}
		}
		return ans;
    }
};
