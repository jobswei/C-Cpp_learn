#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
 using namespace std;

class Solution {
public:
    vector<int> res;
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<pair<int,int>> delta;
        for(int i=0;i<reward1.size();i++){
            delta.push_back(pair<int,int>(reward1[i]-reward2[i],i));
        }
        sort(delta.begin(),delta.end(),cmp);
        
        int res=0;
        for(int j=0;j<k;j++){
            auto p=delta[j];
            res+=reward1[p.second];
        }
        for(int j=k;j<reward1.size()){
            auto p=delta[j];
            res+=reward2[p.second];
        }
        return res;
    }
    bool cmp(pair<int,int> p1,pair<int,int> p2){
        return p1.first>p2.second;
    }
};