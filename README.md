# MyMath Library

The `MyMath` library provides a simple implementation of a vector class in C++. It includes basic vector operations and supports integration with Google Test for unit testing.

## Features

- Vector creation and initialization
- Element access
- Vector addition
- Norm calculation
- Dot product calculation
- Equality comparison

## Directory Structure

## Getting Started

### Prerequisites

- CMake 3.10 or higher
- A C++ compiler (e.g., MinGW, GCC, Clang)
- Google Test installed in your MinGW directory

### Building the Library and Tests

1. **Clone the repository**:
    ```sh
    git clone <repository-url>
    cd <repository-directory>
    ```

2. **Configure the project**:
    ```sh
    mkdir build
    cmake -G "MinGW Makefiles" -S . -B build
    ```

3. **Build and install the project**:
    ```sh
    cd build
    cmake --build .
    cmake --build install .
    ```

4. **Run the tests**:
    ```sh
    cd build
    ctest
    ```

### Usage

Include the [Vector.h](http://_vscodecontentref_/4) header in your project to use the `MyMath::Vector` class.

```cpp
#include "Vector.h"

int main() {
    MyMath::Vector<int> v0({1, 2, 3});
    MyMath::Vector<int> v1({4, 5, 6});
    auto v2 = v0 + v1;

    for (size_t i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] << " ";
    }

    return 0;
}