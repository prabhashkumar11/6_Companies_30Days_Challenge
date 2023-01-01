class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        int i=0,j=0;
        int end=n-1;
        int ans=0;
        while(j<n)
        {
            mp[s[j]]++;
            while(mp['a'] && mp['b'] && mp['c']) // till window is good
            {
               ans+=1+(end-j);

               mp[s[i]]--;
               i++;// shrinking window;
               
            }
            j++;
        }

        return ans;


        
        
    }

    // T.C=O(N);
    // S.C=O(1) constant space as always it will contain 3 characters
};