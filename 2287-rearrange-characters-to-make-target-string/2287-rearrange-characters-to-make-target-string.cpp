class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        vector<int> a(26,0),b(26,0);
        for(auto c : s){
            a[c-'a']++;
        }
        for(auto c : t){
            b[c-'a']++;
        }
        int ans=INT_MAX;
        for(auto c: t){
            ans=min(a[c-'a']/b[c-'a'],ans);
        }
        return ans;
        
    }
};