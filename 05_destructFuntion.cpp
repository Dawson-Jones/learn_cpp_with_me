#include <iostream>

using namespace std;

class VLA {
private:
    const int m_len;
    int *m_arr;

public:
    VLA(int len);
    ~VLA();

    void input();
    void show();

private:
    int *at(int i);
};

VLA::VLA(int len) : m_len(len) {
    if (len > 0)
        m_arr = new int[len];
    else
        m_arr = NULL;
}

VLA::~VLA() {
    delete[] m_arr; //释放内存
}

void VLA::input() {
    for (int i = 0; at(i); i++)
        cin >> *at(i);
}

void VLA::show() {
    for (int i = 0; at(i); i++) {
        if (i == m_len - 1)
            cout << *at(i) << endl;
        else
            cout << *at(i) << ", ";
    }
}

int *VLA::at(int i) {
    if (!m_arr || i < 0 || i >= m_len) {
        return NULL;
    } else {
        return m_arr + i;
    }
}

int main() {
    int n;
    cout << "Input array length: ";
    cin >> n;

    VLA *parr = new VLA(n);
    cout << "Input " << n << " numbers: ";
    parr->input();

    cout << "Elements: ";
    parr->show();
    //删除数组（对象）
    delete parr;

    return 0;
}