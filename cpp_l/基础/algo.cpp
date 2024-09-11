#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int a,int b){
    return a>b;
}
int main(){
    int x=1,y=2;
    int z=min(x,y);
    z=max(x,y);

    swap(x,y); // 交换x和y的值

    int a[]={1,2,3,4,5,6,7,8};
    reverse(a+1,a+4);  // 将两迭代器之间的元素进行反转

    // 给出一个序列在全排列中的下一个序列
    do{
        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    }while(next_permutation(a,a+3));

    fill(a,a+5,66);

    sort(a,a+7);
    sort(a,a+7,cmp); // 可以自定义比较函数

    // 寻找第一个大于或小于val的值的位置，返回指针或迭代器
    auto it=upper_bound(a,a+7,6);
    auto it2=lower_bound(a,a+7,6);

}