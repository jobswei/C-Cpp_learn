
### 1. initialize vector
```C++
#include<vector>;

vector<int> a(10);  // 10个整形元素的向量
vector<int> a(10,1) //10 int elements, with value 1
vector<int> a(b) // define a using b, copy b to a completely
vector<int> a(b.begin(), b.begin()+3)
int b[7]={1,2,3,4,5,6,7};
vector<int> a(b,b+7); // get initial value from array
```

### 2. operation of object vector
```C++
a.assign(b.begin(),b.begin()+3) //copy from b
a.assign(4,2)   // 4个元素2
a.back()    // return the last element of a 
a.front();  // return the first element of a
a[i];
a.empty();  // judge whether a is empty: True or False
a.clear();// clear all element
a.pop_back()//delete the last
a.erase(a.begin()+1,a.begin()+3); // delete from ,, to ,,
a.push_back(5); // add 5 to last
a.insert (a.begin()+1,5)    // insert to NO.i (from 0)
a.insert(a.begin()+1,3,5); //在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5
a.insert(a.begin()+1,b+3,b+6); //b为数组，在a的第1个元素（从第0个算起）的位置插入b的第3个元素到第5个元素（不包括b+6），如b为1,2,3,4,5,9,8         ，插入元素后为1,4,5,9,2,3,4,5,9,8
a.size()    //
a.capacity()    //返回a在内存中总共可以容纳的元素个数
a.resize(10); //将a的现有元素个数调至10个，多则删，少则补，其值随机
a.resize(10,2); //将a的现有元素个数调至10个，多则删，少则补，其值为2
a.reserve(100); //将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.这种操作只有在需要给a添加大量数据的时候才         显得有意义，因为这将避免内存多次容量扩充操作（当a的容量不足时电脑会自动扩容，当然这必然降低性能
a.swap(b)   //b为向量，将a中的元素和b中的元素进行整体性交换
a==b; //b为向量，向量的比较操作还有!=,>=,<=,>,<
```
```C++
int a[6]={1,2,3,4,5,6};
vector<int> b;
vector<int> c(a,a+4);
for(vector<int>::iterator it=c.begin();it<c.end();it++){
    b.push(*it);
}
```

### 3. some algorithm
```C++
#include<algorithm>

sort(a.begin(),a.end());//对a中的从a.begin()（包括它）到a.end()（不包括它）的元素进行从小到大排列
reverse(a.begin(),a.end()); //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，但不排列，如a中元素为1,3,2,4,倒置后为4,2,3,1
copy(a.begin(),a.end(),b.begin()+1); //把a中的从a.begin()（包括它）到a.end()（不包括它）的元素复制到b中，从b.begin()+1的位置（包括它）开        始复制，覆盖掉原有元素
find(a.begin(),a.end(),10); //在a中的从a.begin()（包括它）到a.end()（不包括它）的元素中查找10，若存在返回其在向量中的位置

```