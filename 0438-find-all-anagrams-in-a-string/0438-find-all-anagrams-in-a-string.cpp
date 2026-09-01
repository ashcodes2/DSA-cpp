class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<p.size();i++){
            mp1[p[i]]++;
        }
         int left=0;
        for(int right=0;right<s.size();right++){
            mp2[s[right]]++;

            if(right-left+1>p.size()){
                mp2[s[left]]--;
                

                if(mp2[s[left]]==0){
                    mp2.erase(s[left]);
                }
                left++;


            }
            if(mp1==mp2){
                ans.push_back(left);
            }
        }
        return ans;
    }
};