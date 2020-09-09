#include <iostream>

using namespace std;

// friend
// 可以使得 `其他类中的成员函数` 以及 `全局范围内的函数` 访问当前类的 private 成员。

class Stu{
private:
    char *m_name;
    int m_age;
public:
    Stu(char *name, int age);
    friend void show(Stu *stu_p);
};

Stu::Stu(char *name, int age) : m_name(name), m_age(age) {}

void show(Stu *stu_p) {
    // 访问了私有属性
    cout << stu_p->m_name << "'s age: " << stu_p->m_age << endl;
}

int main() {
    Stu stu("dawson", 15);
    show(&stu);

    Stu *stu_p = new Stu("tt", 14);
    show(stu_p);

    return 0;
}