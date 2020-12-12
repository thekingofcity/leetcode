// time: O(n+m) space: O(n+m)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end()), n2(nums2.begin(), nums2.end());
        vector<int> res;
        for(auto it1=n1.begin();it1!=n1.end();++it1){
            auto it2=n2.find(*it1);
            if(it2!=n2.end())
                res.push_back(*it2);
        }
        return res;
    }
};

// time: O(nlogn+mlogm) space: O(1)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0,j=0;
        vector<int> res;
        while(i<nums1.size()&&j<nums2.size()){
            int l=nums1[i], r=nums2[j];
            if(l==r){
                res.push_back(l);
                while(i<nums1.size()&&nums1[i]==l) ++i;
                while(j<nums2.size()&&nums2[j]==r) ++j;
            }
            else if(l<r) 
                while(i<nums1.size()&&nums1[i]==l)
                    ++i;
            else if(l>r)
                while(j<nums2.size()&&nums2[j]==r)
                    ++j;
        }
        return res;
    }
};
