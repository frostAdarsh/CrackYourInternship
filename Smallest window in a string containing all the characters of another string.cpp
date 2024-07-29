//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
       if (s.size() < p.size()) return "-1";

        vector<int> p_count(256, 0);
        vector<int> window_counts(256, 0);

        for (char c : p) p_count[c]++;

        int required = 0; 
        for (int count : p_count) {
            if (count > 0) required++;
        }

        int l = 0, r = 0, formed = 0;
        int min_len = INT_MAX, start_idx = 0;

        while (r < s.size()) {
            char c = s[r];
            window_counts[c]++;
            
            if (p_count[c] > 0 && window_counts[c] == p_count[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start_idx = l;
                }
                
                char left_char = s[l];
                window_counts[left_char]--;
                if (p_count[left_char] > 0 && window_counts[left_char] < p_count[left_char]) {
                    formed--;
                }
                l++;
            }
            r++;
        }

        return min_len == INT_MAX ? "-1" : s.substr(start_idx, min_len);
    }
            
           
    
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends