## easyprint
C++11 header to print STL containers. All containers that contain a ```const_iterator``` are supported, as well as ```std::tuple```. Simply include the header file, and use the implemented print function to print your containers:

CMake is required to compile the supplied test code.

#### Linux Compilation:
```bash
mkdir bin && cd bin && cmake .. && make && ./easyprint_test
```

#### Windows Compilation
Use CMake-GUI to compile on windows using your compiler of choice.

### Usage:

Simply include the header file ```easyprint``` and use the implemented print function to print your containers. All containers that contain a ```const_iterator``` are supported. ```std::tuple``` is also supported. The content of the container can be printed to any ```std::ostream```.

Arbitrary nested containers are also supported, with the exception of tuples of non-trivial types.

#### Example:

```C++
#include <iostream>
#include <vector>

#include "easyprint"

using namespace std;

int main(int argc, char const *argv[]) {
    vector <int> int_vec = {1,3,5};
    cout << "int_vec =";
    print(cout, int_vec); cout << endl;
    return 0;
}
```

Output:

```
int_vec = [1, 3, 5]
```

### Print syntax:

|Type   | Delimiters|
|--------|-----------|
| Default | ```[1, 2, 3]```|
|```std::map```, ```std::unordered_map```| ```{(1, 2), (3, 4)}``` |
|```std::pair``` | ```(1, 2)```|
|```std::tuple```| ```(1, 2, 3, 4)```|
|```std::set```| ```{1, 3, 4}```|
