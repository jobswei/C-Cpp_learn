#include <iostream>
#include<cstring>

using namespace std;

struct Books{
    char title[50];
    char author[50];
    char subject[50];
    int book_id;
};
void printBooks( struct Books book);

typedef long int *print32;
print32 x,y,z; //是指针
int main(){
    Books Book1;
    Books Book2;

    strcpy(Book1.title,"C++教程");
    strcpy(Book1.author,"RUnoob");
    strcpy( Book1.subject, "编程语言");
    Book1.book_id = 12345;

    strcpy( Book2.title, "CSS 教程");
   strcpy( Book2.author, "Runoob");
   strcpy( Book2.subject, "前端技术");
   Book2.book_id = 12346;

   printBooks(Book1);
   printBooks(Book2);

   return 0;
}

void printBooks( struct Books book){
    cout << "书标题 : " << book.title <<endl;
   cout << "书作者 : " << book.author <<endl;
   cout << "书类目 : " << book.subject <<endl;
   cout << "书 ID : " << book.book_id <<endl;
}

void printBooks2(struct Books *book){
    cout<<"书标题"<<book->title<<endl;
    cout<<"ID"<<book->book_id<<endl;
}