#include <iostream>

using namespace std;

class Stu {
private:
    // 静态变量， 相当于类属性
    static int m_total;
private:
    char *m_name;
    int m_age;
public:
    Stu(char *name, int age);
    ~Stu();
    void show();
};

// init 静态变量
// 静态成员变量必须初始化，而且只能在类体外进行。
int Stu::m_total = 0;

// 构造函数操作静态变量
Stu::Stu(char *name, int age): m_name(name), m_age(age) {
    m_total++;
}

Stu::~Stu() {
    cout << "now there is " << --m_total << " students here" << endl;
}

void Stu::show() {
    cout << m_name << "\nage: " << m_age << endl;
    cout << "now there is " << m_total << " students here" << endl;
}

int main() {
    (new Stu("dawson", 12))->show();
    Stu *sam = new Stu("sam", 15);
    sam->show();
    delete sam;
    (new Stu("chilly", 14))->show();
}
