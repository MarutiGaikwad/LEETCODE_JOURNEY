class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>  a(26,0);
        for(auto c:chars ){
            a[c-'a']++;
        }
        int n= words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            bool m=true;
            vector<int> b(26,0);
            for(auto c: words[i]){
                b[c-'a']++;
            }
            for(int j=0;j<26;j++){
                if(a[j]<b[j]) m=false;
            }
            if(m) ans+=words[i].size();
            
        }
        return ans;
    }
};