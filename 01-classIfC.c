#include <stdio.h>

struct Student {
    // 成员变量
    char    *name;
    int     age;
    float   score;

    // 成员函数
    void    (*display)(struct Student *);
};

void display(struct Student *self) {
    printf("%s的年龄是 %d，成绩是 %f\n", self->name, self->age, self->score);
}

int main(int argc, char const *argv[]) {
    struct Student dawson = {
            "dawson",
            23,
            98,
            display,
    };
    dawson.display(&dawson);
    return 0;
}

