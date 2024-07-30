class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str)
 {

        
        map<string,vector<string>>mp;

        for(int i=0;i<str.size();i++)
        {
            string s = str[i];
            sort(s.begin(),s.end());

            mp[s].push_back(str[i]);
        }
  

    
        vector<vector<string>> ans(mp.size());
        int index =0;
        for(auto x:mp)
        {
            
            auto temp = x.second;

            for(auto x:temp)
            {
                ans[index].push_back(x);
            }

            index++;

        }

        return ans;

    }
};