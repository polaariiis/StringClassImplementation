# Custom String Implementation (C++)

A minimal implementation of a string class in C++ built for learning core concepts of memory management, copy/move semantics, and operator overloading.

## Features

- Dynamic character buffer
- Deep copy constructor
- Move constructor and move assignment
- Copy assignment operator
- String concatenation (`operator+`)
- Substring extraction (`substr`)
- Reverse string
- Character search (`find`)
- Array-style indexing (`operator[]`)
- Stream output (`operator<<`)
- Null-terminated internal representation

## Design Goals

This project was created to understand:

- Manual memory management with `new` and `delete[]`
- Rule of 5 (copy/move semantics)
- RAII principles
- Basic string manipulation internals
- How `std::string`-like behavior can be implemented

## Limitations

- No small string optimization (SSO)
- No allocator support
- Not thread-safe
- Basic exception safety only
- No iterator support

## Example Usage

```cpp
#include "String.h"
#include <iostream>

int main()
{
    String a = "Hello";
    String b = "World";

    String c = a + " " + b;

    std::cout << c << std::endl;

    std::cout << c.find('o') << std::endl;
    std::cout << c.substr(0, 5) << std::endl;
}
