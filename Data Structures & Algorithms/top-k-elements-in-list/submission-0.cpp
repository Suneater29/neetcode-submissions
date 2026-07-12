class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto i:nums){
            mpp[i]++;
        }
        vector<pair<int,int>>temparr;
        for(auto &it:mpp){
            temparr.push_back({it.second,it.first});
        }
        sort(temparr.rbegin(),temparr.rend());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(temparr[i].second);
        }
        return ans;
    }
};
