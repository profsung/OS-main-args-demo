#include <stdio.h>

void* f1(void*);
void* f2(void*);
void* f3(void*);

struct person {
    int age;
    double gpa;
};

// int main(int argc, char *argv[]) { => **argv == *argv[]
int main(int argc, char **argv) {

    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] => %s\n", i, argv[i]);
    }

    const char* message = "hello world!";
    f1((void *) message);

    int value = 299;
    f2((void *) &value);

    person john;
    john.age = 21;
    john.gpa = 3.95;

    f3((void *) &john);

}

void* f1(void* param) {
    const char* m = (const char *) param;
    printf("f1: %s\n", m);
}

void* f2(void* param) {
    int* n = (int *) param;
    printf("f2: %d\n", *n);
}

void* f3(void* param) {
    person* p = (person*) param;
    printf("f3: age=%d gpa=%f\n", p->age, p->gpa);
}