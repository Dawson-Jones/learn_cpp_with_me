#include <iostream>
using namespace std;

/*
 * 多态是面向对象编程的主要特征之一
 * C++中虚函数的唯一用处就是构成多态。
 * 
 * 注意事项
 * 1. 只需要在虚函数的声明处加上 virtual 关键字，函数定义处可以加也可以不加。
 * 2. 为了方便，可以只将基类中的函数声明为虚函数，这样所有派生类中具有遮蔽关系的同名函数都将自动成为虚函数。
 * 3. 只有派生类的虚函数覆盖基类的虚函数（函数原型相同）才能构成多态（通过基类指针访问派生类函数）。
 *    例如: 
 *    基类虚函数的原型为virtual void func();
 *    派生类虚函数的原型为virtual void func(int);
 *    那么当基类指针 p 指向派生类对象时，语句 p->func(100) 将会出错，
 *    而语句 p->func() 将调用基类的函数。
 *  4. 构造函数不能是虚函数。
 *  5. 析构函数可以声明为虚函数，而且用来做基类的类的析构函数一般都是虚函数。原因见 14
 */
class People{
public:
    People(char *name, int age);
    virtual void display();  // 声明为虚函数
protected:
    char *m_name;
    int m_age;
};
People::People(char *name, int age): m_name(name), m_age(age){}
void People::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
}

// 派生类Teacher
class Teacher: public People{
public:
    Teacher(char *name, int age, int salary);
    virtual void display();  // 声明为虚函数
private:
    int m_salary;
};
Teacher::Teacher(char *name, int age, int salary): People(name, age), m_salary(salary){}
void Teacher::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
}

int main(){
    People *p = new People("王志刚", 23);
    p -> display();

    p = new Teacher("赵宏佳", 45, 8200);
    p -> display();

    return 0;
}