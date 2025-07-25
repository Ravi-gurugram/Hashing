class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
           m[nums[i]]++ ;
    
    vector<int>ans ;
    for(auto it=m.begin();it!=m.end();it++)
       if(it->second==2)
          ans.push_back(it->first) ;
return ans ;
    }
};