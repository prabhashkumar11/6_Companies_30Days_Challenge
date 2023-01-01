class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> PrevGreater(n,0);
        vector<int> NextSmaller(n,0);

        stack<int> st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&st.top()<=nums[i])
            {
                st.pop();
            }
            if(st.empty()) PrevGreater[i]=nums[i];
            else{
                PrevGreater[i]=st.top();
            }
            st.push(nums[i]);
        }

        while(!st.empty())
        {
            st.pop();
        }

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()>=nums[i])
            {
                st.pop();
            }
            if(st.empty()) NextSmaller[i]=nums[i];
            else{
                NextSmaller[i]=st.top();
            }
            st.push(nums[i]);
        }
        int left=-1; 
        for(int i=0;i<NextSmaller.size();i++)
        {
            if(NextSmaller[i]!=PrevGreater[i])
            {
                left=i;
                break;
            }
        }

        int j=n-1;
        while(j>left)
        {
            if(NextSmaller[j]!=PrevGreater[j])
            {
                break;
            }
            j--;
        }

        // //for(int i=0)
        if(left==-1) return 0;

        return j-left+1;
    }
};
