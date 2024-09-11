#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

/*
template <typename type> ret-type func-name(parameter list)
{
   // 函数的主体
}
*/
// 函数模板
template <typename T>
inline T const& Max(T const& a, T const& b){
    return a<b?b:a;
}

// 类模板
template<class T> 
class Stack{
    private:
        vector<T> elems;
    public:
        void push(T const&);// 入栈
        void pop();
        T top() const;
        bool empty() const{
            return elems.empty();
        }
};
template <class T>
void Stack<T>::push(T const& elem){
    elems.push_back(elem);
}
template<class T>
void Stack<T>::pop(){
    if(elems.empty()){
        throw out_of_range("Stack<>::top(): empty stack.");
    }
    elems.pop_back();
}
template<class T>
T Stack<T>::top() const{
    if(elems.empty()){
        throw out_of_range("Stack<>::top(): empty stack.");
    }
    return elems.back();
}
int main(){
    int i=38,j=49;
    cout<<"Max(i,j): "<<Max(i,j)<<endl;

    string m="hello0",n="hi";
    cout<<"Max(m,n): "<<Max(m,n)<<endl;

    try{
        Stack<int> intStack;
        Stack<string> stringStack;

        intStack.push(7);
        cout<<"int stack top "<<intStack.top()<<endl;

        stringStack.push("Hellow");
        cout<<"string satck: "<<stringStack.top()<<endl;
        stringStack.pop();
        stringStack.pop();
    }catch(exception const& ex){
        cerr<<"Exception: "<<ex.what()<<endl;
        return -1;
    }

    return 0;

}