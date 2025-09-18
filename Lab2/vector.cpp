#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/** @brief prints elements and their memory locations */
void printMemVec(const vector<int>& v) {
    if (!v.empty())
        printf("Vector — Each int is worth %zu bytes\n", sizeof(v[0]));
    else
        printf("Vector is empty\n");

    for (size_t i = 0; i < v.size(); ++i) {
        printf("Value: %d at Memory Location: %p\n", v[i], (const void*)(&v[i]));
    }
}

/** @brief increments all elements in v by 10 */
void incVecBy10(vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) v[i] += 10;
}

int main() {
    const int SIZE = 5;

    vector<int> vec;
    vec.reserve(SIZE);
    for (int i = 0; i < SIZE; ++i) vec.push_back(100 + i);

    printf("Before Increment-----------\n");
    printMemVec(vec);

    incVecBy10(vec);
    printf("After Increment------------\n");
    printMemVec(vec);

    vec.pop_back();
    printf("After Pop------------------\n");
    printMemVec(vec);

    vec.push_back(101);
    vec.push_back(102);
    printf("After Push-----------------\n");
    printMemVec(vec);

    return 0;
}