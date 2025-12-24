#include "ch01/dynamic_array_my_answer.h"
#include <algorithm>
#include <iostream>
#include <sstream>

int main()
{
    dynamic_array<int> numbers(5);
    int data[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < std::size(data); ++i)
    {
        numbers[i] = data[i];
    }

    for (const auto i : numbers)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
