#include "ch01/build_array.h"
#include <algorithm>
#include <iostream>
#include <sstream>

int main()
{
    auto data = build_array(1, 0u, 'a', 3.2f, false);

    for (auto i : data)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
