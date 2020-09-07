#include <iostream>

using namespace std;

class Student{
public:
    // 成员变量
    char *name;
    int age;
    float score;

    // 成员函数  
    // 这样定义会使得函数自动变为内联函数, 从而大量占用内存
    // 使用类内声明, 类外定义会更好
    void display(){
        cout<<name<<"\tage: "<<age<<"\tscore: "<<score<<endl;
    }
};

int main(){
    // 栈上使用 class
    Student dawson{
        "dawson",
        23,
        98
    };
    dawson.display();

    // 堆上申请class 空间
    auto *dawsonPtr = new Student;
    dawsonPtr->name = "dawson";
    dawsonPtr->age  = 18;
    dawsonPtr->score= 100;
    dawsonPtr->display();
    delete dawsonPtr;

    return 0;
}