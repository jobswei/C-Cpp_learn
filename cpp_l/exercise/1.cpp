#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
            mp[*it]=(int)(it-nums.begin());
        }
        vector<int> res(2,-1);
        for(int i=0;i<nums.size();i++){
            if(mp.count(target-nums[i])!=0 && mp[target-nums[i]]!=i ){
                res[0]=i; // 这里利用了一个map里键唯一的特点
                res[1]=mp[target-nums[i]];
                break;
            }
        }

        return res;
    }
    vector<int> twoSum1(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>::iterator beg=nums.begin(),end=nums.end()-1;
        // cout<<*beg<<*end<<endl;
        while (end-beg>0){
            int tar=*beg+*end;
            // cout<<tar<<endl;

            if (tar==target){
                break;
            }
            if (tar<target){
                beg+=1;
            }else{
                end-=1;
            }

        }
        // cout<<*beg<<*end<<endl;
        // vector<int> res({*beg,*end});
        // int b=beg-nums.begin();
        // int c=end-nums.begin();
        vector<int> res({(int)(beg-nums.begin()),(int)(end-nums.begin())});
        return res;
    }
};

int main(){
    // Solution so;
    // Solution *p=&so;
    Solution *so = new Solution();
    vector<int> nums({2,7,11,15});
    vector<int> res=so->twoSum(nums,9);
    for(auto i:res){
        cout<<i;
    }

}