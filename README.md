## easyprint
[![Build Status](https://travis-ci.org/hebaishi/easy-cpp-print.svg?branch=master)](https://travis-ci.org/hebaishi/easy-cpp-print)

C++11 header to print STL containers. All containers that contain a ```const_iterator``` are supported, as well as ```std::tuple```. Simply include the header file, and use the `stringify` function to stringify your containers. A `print` function has also been provided for convenience, which prints to standard output.

CMake is required to compile the supplied test code.

#### Linux Compilation:
```bash
mkdir bin && cd bin && cmake .. && make && ./easyprint_demo
```

#### Windows Compilation
Use CMake-GUI to compile on windows using your compiler of choice.

### Usage:

Simply include the header file ```easyprint.hpp``` and use the implemented print function to print your containers. All containers that contain a ```const_iterator``` are supported. ```std::tuple``` is also supported.

Arbitrary nested containers are also supported, with the exception of tuples of non-trivial types. Nested tuples are allowed, however.

Function signatures:
```cpp
namespace easyprint {

// Stringify any container
template <typename T> void stringify(const T &container);

// Print container to stdout
std::string print(const T &container);

}  // namespace easyprint
```

#### Example:

```cpp
#include <iostream>
#include <vector>

#include <easyprint.hpp>

using easyprint::stringify;

int main(int argc, char const *argv[]) {
    std::vector <int> int_vec = {1,3,5};
    std::cout << "My int vector is = " << stringify(int_vec) << std::endl;
    return 0;
}
```

Output:

```
My int vector is = {1, 3, 5}
```
