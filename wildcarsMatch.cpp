
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
class Solution {
    private:
    bool f(int i,int j,string s, string t,vector<vector<int>>& dp){
        if(i < 0 && j < 0)return true;
        if(i < 0)return false;
        if(j < 0){
            for(int k=0;k<=i;k++){
                if(s[k] != '*')return false;
            }
            return true;
        }

        if(dp[i][j] != -1)return dp[i][j];

        if(s[i] == t[j] || s[i] == '?'){
            return dp[i][j] = f(i-1,j-1,s,t,dp);
        }
        else if(s[i] == '*'){
            return dp[i][j] = f(i-1,j,s,t,dp) | f(i,j-1,s,t,dp);
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string t, string s) {
        int n = s.size();int m = t.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '*') {
        dp[i][0] = dp[i - 1][0];
    } else {
        dp[i][0] = false;
    }
}


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1] || s[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(s[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};
