#include <iostream>

using namespace std;

class Stu {
private:
    // 静态变量
    static int m_total;

    char *m_name;
    int m_age;
public:
    // 静态函数，只能访问静态成员
    static int get_total();
    // 构造函数
    Stu(char *name, int age);

    // 普通的
    void show();
};

int Stu::m_total = 0;

Stu::Stu(char *name, int age): m_name(name), m_age(age) {
    ++m_total;
}

void Stu::show() {
    cout << m_name << "\nage: " << m_age << endl;
}

int Stu::get_total() {
    return m_total;
}

int main() {
    (new Stu("dawson", 15))->show();
    (new Stu("sam", 14))->show();
    (new Stu("tt", 16))->show();

    cout << "there is " << Stu::get_total() << " students here now.";

}
