#include <iostream>
#include "RefactoredVector.h"

int main()
{
    RefactoredVector<int> v;
    v.push_back(1, "one");
    v.push_back(2, "two");

    RefactoredVector<int> v2(v);

    v2.push_back(3, "three");

    std::cout << v["one"];
    std::cout << v["two"];
    std::cout << v2["one"];
    std::cout << v2["two"];
    std::cout << v2["three"];
}