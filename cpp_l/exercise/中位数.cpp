#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<stack>
 using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]>nums2[j]){
                nums3.push_back(nums1[i++]);
            }else{
                nums3.push_back(nums2[j++]);
            }
        }
        while(i<nums1.size()){
            nums3.push_back(nums1[i++]);
        }
        while(j<nums2.size()){
            nums3.push_back(nums2[j++]);
        }

        int len=nums3.size();
        return (len%2==0) ? (double)(nums3[len/2-1]+nums3[len/2])/2 : (double) nums3[len/2];
    }
};
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=0,n=0;
        int i=0,j=0;
        int all=nums1.size()+nums2.size();
        while (1){
            if(i+j+1>=all/2){
                break;
            }
            if(j>nums2.size()){
                i++;
                m=n;
                n=nums1[i-1];
                continue;
            }
            if(i>nums1.size()){
                j++;
                m=n;
                n=nums2[j-1];
                continue;
            }
            if(nums1[i]<nums2[j]){
                i++;
                m=n;
                n=nums1[i-1];
            }else{
                j++;
                m=n;
                n=nums2[j-1];
            }
        }
        return (all%2==0) ? (double)(m+n)/2 : (double) m;
    }
};

class Solution3 {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int mid=(left+right)/2;

        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            if(left==right) return -1;
            if(nums[left]<=nums[mid]){ // 左边是正常升序的
                if(nums[left]<=target && nums[mid]>=target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{  // 右边是正常升序的
                if(nums[mid]<=target && nums[right]>=target){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return -1;

    }
};

class Solution4 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int mid;
        vector<int> res;
        while(left<=right){
            mid=(left+right)/2;
            // if(nums[left]==target && (left-1<0 || nums[left-1]!=target) && nums[right]==target && (right+1>nums.size()-1 ||nums[right+1]!=target)){
            //     res.clear();
            //     res.push_back(left);
            //     res.push_back(right);
            //     return res;
            // }
            if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                int l=left;
                int r=right;
                int m;
                while(l<=r){
                    m=(l+r)/2;
                    if(nums[m]<target){
                        l=m+1;
                    }else if(nums[m]>target){
                        r=m-1;
                    }else{
                        if(m-1<0||nums[m-1]!=target){
                            res.push_back(m);
                            break;
                        }else{
                            r=m-1;
                        }
                    }
                }
                l=left;r=right;
                while(l<=r){
                    m=(l+r)/2;
                    if(nums[m]<target){
                        l=m+1;
                    }else if(nums[m]>target){
                        r=m-1;
                    }else{
                        if(m+1>nums.size()-1||nums[m+1]!=target){
                            res.push_back(m);
                            break;
                        }else{
                            l=m+1;
                        }
                    }
                }
                break;
            }
        }
        if(res.size()==0){
            res.assign(2,-1);
        }
        else sort(res.begin(),res.end());
        return res;

    }
};
class Solution5 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size()==0){
            res.assign(2,-1);
            return res;
        }
        auto l=lower_bound(nums.begin(),nums.end(),target);
        auto r=upper_bound(nums.begin(),nums.end(),target)-1;
        if(l==nums.end()|| *l != target){
            res.assign(2,-1);
        }else{
            res.push_back((int)(l-nums.begin()));
            res.push_back((int)(r-nums.begin()));
        }
        return res;


    }
};

class Solution6 {
public:
    int mySqrt(int x) {
        int left=0;
        int right=x/2+1;
        long mid;
        while(1){
            mid=(left+right)/2;
            if(mid*mid<=x && (mid+1)*(mid+1)>x){
                return mid;
            }else if(mid*mid>x){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }

    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0;
        int right=matrix.size() * matrix[0].size() - 1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(find(matrix,mid)==target){
                return true;
            }else if(find(matrix,mid)>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return false;

    }

    int find(vector<vector<int>>& matrix,int x){
        int row=matrix.size();
        int column=matrix[0].size();
        return matrix[x/column][x-column*(x/column)];
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            // cout<<left<<" "<<right<<" "<<mid<<endl;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[left]){
                left++;
                continue;
            }
            if(nums[left]<nums[mid]){
                if(nums[mid]>target && nums[left]<=target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if(nums[mid]<target && nums[right]>=target){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            
        }
        return false;
    }
    // bool issame(vector<int>& nums, int left, int right){}
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int minn=100000000;

        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            minn=min(minn,nums[mid]);

            if(nums[left]<nums[right]){
                minn=min(minn,nums[left]);
                break;
            }
            // left=mid 说明左边只有一个值了。考虑右边就行了
            
            if(left==mid || nums[left]<nums[mid]){ // 最小值一定不在正常升序的里面,, 但是到后面被截断后可能全部正常升序了
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return minn;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int mid;
        int minn=100000000;
        while(left<=right){
            mid=(left+right)/2;
            minn=min(minn,nums[mid]);

            if(nums[mid]==nums[right] ){
                right--;
                continue;

            }
            if(nums[mid]>nums[right]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return minn;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int mid;

        while(left<=right){
            mid=(left+right)/2;
            if(((mid-1>=0 && nums[mid-1]<nums[mid]) || (mid-1<0)) && ((mid+1<nums.size() && nums[mid+1]<nums[mid]) || (mid+1>=nums.size()))){
                return mid;
            }
            if(mid-1>=0 && nums[mid-1]>nums[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;
        int mid;

        while(left<=right){
            if(numbers[left]+numbers[right]==target){
                break;
            }
            if(numbers[left]+numbers[right]<target){
                left++;
            }else{
                right--;
            }
        }
        vector<int> res({left,right});
        return res;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> sums;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sums.push_back(sum);
        }
        if(sums[nums.size()-1]<target) return 0;
        int minn=100000000;
        for(int i=0;i<nums.size();i++){
            int delta=target+i;
            auto it=upper_bound(sums.begin()+i,sums.end(),delta);
            minn=min(minn,(int)(it-sums.begin()-i));
        }
        return minn;
    }
};
// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=nums[0];
        int minn=1000000;
        int left=0,right=0;
        while(right<nums.size() && left<=right){
            while(right+1<nums.size() && sum<target){
                sum+=nums[++right];
            }

            if(sum>=target){
                minn=min(minn,right-left+1);
                sum-=nums[left];
                left++;
            }else{
                break;
            }
        }
        if(minn==1000000) return 0;
        return minn;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        TreeNode *node=root;
        int level=0;
        while(node!=NULL){
            level++;
            node=node->left;
        }

        int low=1<<(level-1);
        int high=1<<level-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(exist(root,level,mid)){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low-1;
    }

    bool exist(TreeNode *root, int level, int k){
        TreeNode *node=root;
        int bits=1<<(level-1);
        bits>>=1;
        while(node!=NULL && bits>=0){
            if(bits&k){
                node=node->right;
            }else{
                node=node->left;
            }
        }
        return node!=NULL;
    }
};

// Z字形查找。要想通过移动来查找，就必须找一点使得往一边移动是变大另一边移动是变小，不能两边都变大或变小
// 这样的话，我们选择的就是右上角
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
        int column=matrix[0].size()-1;
        while(row<matrix.size() && column>=0){
            if(matrix[row][column]==target){
                return true;
            }else if(matrix[row][column]>target){
                column--;
            }else{
                row++;
            }
        }
        return false;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;
        int left=0,right=height.size()-1;
        int maxh=0;
        while(left<right){
            if(height[left]>height[right]){
                maxh=max(maxh,height[right]);
                if(height[right-1]<maxh){
                    sum+=maxh-height[right-1];
                }
                right--;
            }else{
                maxh=max(maxh,height[left]);
                if(height[left+1]<maxh){
                    sum+=maxh-height[left+1];
                }
                left++;
            }
        }
        return sum;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        int *fp=new int[n+1]{0};

        for(int i=1;i<n;i++){
            if(s[i]=='(' && s[i-1]==')'){
                fp[i+1]=fp[i];
            }else if(s[i]==')' && s[i-1]=='('){
                fp[i+1]=fp[i]+1;
            }else {
                fp[i+1]=0;
            }
        }
        int maxn=0;
        for(int i=0;i<n+1;i++){
            maxn=max(maxn,fp[i]);
        }
        return maxn;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int len=0;
        int maxlen=0;
        stack<int> stac;
        stac.push(-1);

        for(int i=0;i<s.length();i++){
            if(s[i]==')' ){
                stac.pop();
                if(stac.empty()) stac.push(i);
                else {
                maxlen=max(maxlen,i-stac.top());}
                
            }else{
                stac.push(i);
            }
        }
        return maxlen;

    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        // 动态规划
        int n=s.length();
        int *fp=new int[n+1]{0};

        for(int i=1;i<n;i++){
            if(s[i]=='('){
                continue;
            }else{
                if(s[i-1]=='('){
                    fp[i+1]=fp[i-2+1]+2;
                }else{
                    if(i-1-fp[i-1+1]>=0 && s[i-1-fp[i-1+1]]=='('){
                        fp[i+1]=fp[i-1+1]+fp[i-1-fp[i-1+1]+1-1]+2;
                    }else{
                        fp[i+1]=0;
                    }
                }
            }
        }
        return *max_element(fp,fp+n+1);
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> nowres;
        sort(candidates.begin(),candidates.end());
        
        helper(res,candidates,nowres,target,0);
        return res;
    }

    void helper(vector<vector<int>> &res,vector<int>& candidates,vector<int> nowres, int nowtar, int nowpos){
        if (nowtar==0){
            res.push_back(nowres);
            cout<<"yes"<<endl;
            return ;
        }

        if(nowtar<0) {cout<<"not"<<endl;return ;}

        for(int i=nowpos;i<candidates.size();i++){
            vector<int> newres(nowres);
            int newtar=nowtar-candidates[i];
            newres.push_back(candidates[i]);
            for(auto j:nowres){
                cout<<j<<" ";
            }
            cout<<endl;
            if(newtar>=0) helper(res,candidates,newres,newtar,i);
            else break;
        }
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> newcan;
        for(auto num:candidates){
            if(newcan.empty()||num!=newcan.back()[0]){
                newcan.push_back(vector<int>{num,1});
            }else{
                newcan.back()[1]++;
            }
        }
        vector<vector<int>> res;
        vector<int> nowres;
        helper(res,newcan,nowres,target,0);

        return res;


    }

    void helper(vector<vector<int>> &res,vector<vector<int>>& candidates,vector<int> nowres, int nowtar, int nowpos){
        if (nowtar==0){
            res.push_back(nowres);
            cout<<"yes"<<endl;
            return ;
        }

        if(nowtar<0) {cout<<"not"<<endl;return ;}

        for(int i=nowpos;i<candidates.size();i++){
            int num=candidates[i][0];
            if(nowtar-num<0) break;
            for(int j=1;j<candidates[i][1]+1;j++){
                int newtar=nowtar-num*j;
                cout<<num<<" "<<newtar<<endl;
                if (newtar<0) break;
                vector<int> newres(nowres);
                newres.resize(nowres.size()+j);
                fill(newres.end()-j,newres.end(),num);
                helper(res,candidates,newres,newtar,i+1);
            }
        }
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp;
        dp.assign(nums.size(),1001);
        dp[0]=0;

        int i=0;
        while(i<nums.size()-1){
            for(int j=1;j<nums[i]+1;j++){
                if(i+j>=dp.size()) break;
                dp[i+j]=min(dp[i+j],dp[i]+1);
            }
            i++;
        }
        return *(dp.end()-1);

    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.assign(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            dp[i+1]=max(nums[i],nums[i]+dp[i]);
        }
        return *max_element(dp.begin()+1,dp.end());
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        return C(m+n-2,m-1);
    }

    int C(int n, int m){
        cout<<pro(1,6);
        return pro(n-m+1,n)/pro(1,m);
    }
    long pro(int begin, int end){
        long res=1;
        while(begin<=end){
            res*=begin;
            begin++;
        }
        return res;
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        int total=0;
        helper(total, m,n,0,0);
        return total;
    }

    void helper(int &total, int &m, int &n, int nowx, int nowy){
        if(nowx==m && nowy==n){
            total++;
            return ;
        }

        if(nowx>m || nowy>n){return ;}

        helper(total,m,n,nowx+1,nowy);
        helper(total,m,n,nowx,nowy+1);

    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=0;
                dp[0][0]=1;
                if(i-1>=0){
                    dp[i][j]+=dp[i-1][j];
                }
                if(j-1>=0){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];


    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int dp[m][n];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=0;
                dp[0][0]=1;
                if(obstacleGrid[i][j]==1) continue;
                if(i-1>=0 && obstacleGrid[i-1][j]!=1){
                    dp[i][j]+=dp[i-1][j];
                }
                if(j-1>=0 && obstacleGrid[i][j-1]!=1){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=grid[i][j];
                if(i-1>=0 && j-1>=0){
                    dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
                }
                else if(i-1>=0){
                    dp[i][j]+=dp[i-1][j];
                }
                else if(j-1>=0){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        if(n==1) return 1;
        if(n==2) return 2;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<n+1;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> state(grid.size(),vector<int>(grid[0].size(),0));
        int total=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(state[i][j]==0 && grid[i][j]==0){
                    // cout<<i<<" "<<j<<endl;
                    // cout<<grid[i][j]<<state[i][j]<<endl;
                    bool isok=true;
                    fillall(grid,state,i,j,isok);
                    if(isok) {cout<<i<<" "<<j<<endl;total++;}
                }
            }
        }
        return total;
        
    }

    // bool isok(vector<vector<int>> &grid, vector<vector<int>> &state, int x, int y){

    //     if(grid[x][y]==1) return true;
    //     if(x==0 || y==0 || x==grid.size()-1 || y==grid[0].size()-1){
    //         fillall(grid, state, x, y);
    //         return false;
    //     }
    //     if(grid[x][y]==0 && state[x][y]==0){
    //         // cout<<x<<" "<<y<<endl;
    //         state[x][y]=1;
    //         return (isok(grid,state,x-1,y) && isok(grid,state,x,y-1) && isok(grid,state,x+1,y) && isok(grid,state,x,y+1));
    //     }
    //     return true;
    // }
    void fillall(vector<vector<int>> &grid, vector<vector<int>> &state, int x, int y,bool &isok){
        if(x<0 || y<0 || x>grid.size()-1 || y>grid[0].size()-1){
            return ;
        }
        if(state[x][y]==0 && grid[x][y]==0){
            cout<<"e"<<x<<" "<<y<<endl;
            if(x==0 || y==0 || x==grid.size()-1 || y==grid[0].size()-1){
                isok=false;
            }
            state[x][y]=1;
        }else return;
        fillall(grid, state, x-1, y,isok);
        fillall(grid, state, x+1, y,isok);
        fillall(grid, state, x, y-1,isok);
        fillall(grid, state, x, y+1,isok);
    }
};


class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.length()+1][word2.length()+1];
        dp[0][0]=0;
        for(int i=0;i<word1.length();i++){
            dp[i+1][0]=i+1;
        }
        for(int i=0;i<word2.length();i++){
            dp[0][i+1]=i+1;
        }
        for(int i=0;i<word1.length();i++){
            for(int j=0;j<word2.length();j++){
                if(word1[i]==word2[j]){
                    dp[i+1][j+1]=dp[i][j];
                }else{
                    dp[i+1][j+1]=min(min(dp[i][j+1]+1,dp[i][j]+1),dp[i+1][j]+1);
                }
            }
        }
        return dp[word1.length()+1][word2.length()+1];
    }
};

class Solution {
public:
    int numDecodings(string s) {
int *dp=new int[s.length()+1];
        dp[0]=1;
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                if(i-1<0 || s[i-1]=='0' || s.substr(i-1,i+1)>"26"){
                    dp[i+1]=dp[i];
                }else{
                    dp[i+1]=dp[i]+dp[i-1];
                }
            }else{
                if(i-1<0 || s[i-1]=='0' || s[i-1]>'2') return 0;
                dp[i+1]=dp[i-1];
            }
        }
        return dp[s.length()];
    }
};

class Solution {
public:
    int numTrees(int n) {
        int *dp=new int[n+1]{0};
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
            cout<<dp[i]<<endl;
        }
        return dp[n];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int *dp=new int[prices.size()]{0};
        int *minns=new int[prices.size()]{10000};
        dp[0]=0;
        for(int i=1;i<prices.size();i++){
            int pro=0;
            for(int j=0;j<=i;j++){
                minns[j]=min(minns[j],prices[i]);
                pro=max(pro,dp[j]+prices[i]-minns[j]);
            }
            dp[i]=pro;
        }
        
        return dp[prices.size()-1];
    }

};
