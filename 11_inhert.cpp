#include <iostream>

using namespace std;

// 父类
class People {
private:
    string m_name;
    int m_age;
public:
    People(string name, int age);

    void set_name(string name);

    void set_age(int age);

    string get_name();

    int get_age();
};

People::People(string name, int age) : m_name(name), m_age(age) {}

void People::set_name(string name) {
    this->m_name = name;
}

void People::set_age(int age) {
    this->m_age = age;
}

string People::get_name() {
    return this->m_name;
}

int People::get_age() {
    return this->m_age;
}

// 子类
class Student : public People {
private:
    float m_score;
public:
    Student(string name, int age, float score);

    void set_score(float score);

    float get_score();
};

// 构造函数中， 调用父类构造函数， 因为 name 和 age 字段对于子类不可见
// 相当于 python 中的 super()
Student::Student(string name, int age, float score) : People(name, age), m_score(score) {}

void Student::set_score(float score) {
    this->m_score = score;
}

float Student::get_score() {
    return this->m_score;
}

int main() {
    People p = People("dawson", 15);
    cout << p.get_name() << ": " << p.get_age() << endl;

    Student stu = Student("jerry", 5, 98);
    cout << stu.get_name() << "\nage: " << stu.get_age() << "\nscore: " << stu.get_score() << endl;
}

/*
 *  
 */