class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int i=0;
        int j=0;
        int count=0;

        unordered_map<char,int> mp;

        while(j<n){
            mp[s[j]]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                count+=n-j;
                mp[s[i]]--;
                i++;
            }
           j++;
        }
        return count;
    }
};