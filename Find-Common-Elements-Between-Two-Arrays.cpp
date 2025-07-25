class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans ;
        int count=0 ;
     unordered_set<int>s2(nums2.begin(),nums2.end()) ;
     for(int i=0;i<nums1.size();i++){
        if(s2.count(nums1[i]))
            count++ ;
     }
ans.push_back(count) ;
  unordered_set<int>s1(nums1.begin(),nums1.end()) ;
  count=0;
  for(int i=0;i<nums2.size();i++){
    if(s1.count(nums2[i]))
        count++ ;
  }
ans.push_back(count) ;
return ans ;

    }
};