#pragma once
#include <iostream>
#include <cstddef>

class String
{
private:
    unsigned int m_Size;
    char* m_Buffer;

private:
    String(unsigned int size);

public:
    static const size_t npos;

public:
    String();
    String(const char* string);
    String(const String& otherString);
    String(String&& other) noexcept;

    ~String();

    size_t size() const;

    String substr(unsigned int start, unsigned int length) const;
    String reverse() const;
    size_t find(char a) const;

    String operator+(const String& other) const;

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;

    char& operator[](unsigned int index);
    const char& operator[](unsigned int index) const;

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};