class Solution {
public:
    
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int c = 0; // count
        priority_queue<int,vector<int>,greater<int>> pq; /// min heap
        int op = numsDivide[0];
        int n = numsDivide.size();
        for(int i = 1;i < n;i++){
            op = __gcd(op,numsDivide[i]); // as it will be the maximum number that will divide all the numbers 
        }
        for(auto&i : nums){
            pq.push(i); // pushing all elements in the heap
        } 
        while(!pq.empty())
        {
            int n=pq.top();
            pq.pop();
            if(op%n==0)
            {
                return c;
            } 

            if(n>op) return -1;

            c++;
        }
         
        //if(pq.empty()) return -1; 
        return -1;

        
    }
};
