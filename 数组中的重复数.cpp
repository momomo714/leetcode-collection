class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int>seen;
        vector<int>result;
        for(int x:nums){
            if(seen.count(x)){
                result.push_back(x);
            }else{
                seen.insert(x);
            }
        }return result;
    }
};