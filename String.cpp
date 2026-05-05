#include "String.h"
#include <cstring>
#include <stdexcept>

// static member definition
const size_t String::npos = static_cast<size_t>(-1);

// private constructor
String::String(unsigned int size)
{
    m_Size = size;
    m_Buffer = new char[size + 1];
}

// default constructor
String::String()
    : m_Size(0), m_Buffer(new char[1])
{
    m_Buffer[0] = '\0';
}

// C-string constructor
String::String(const char* string)
{
    m_Size = (unsigned int)strlen(string);
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, string, m_Size);
    m_Buffer[m_Size] = '\0';
}

// copy constructor
String::String(const String& otherString)
    : m_Size(otherString.m_Size)
{
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, otherString.m_Buffer, m_Size + 1);
}

// move constructor
String::String(String&& other) noexcept
{
    m_Size = other.m_Size;
    m_Buffer = other.m_Buffer;

    other.m_Buffer = nullptr;
    other.m_Size = 0;
}

// destructor
String::~String()
{
    delete[] m_Buffer;
}

// size
size_t String::size() const
{
    return (size_t)m_Size;
}

// substr
String String::substr(unsigned int start, unsigned int length) const
{
    if (start >= m_Size)
        throw std::out_of_range("Start out of range");

    if (start + length > m_Size)
        length = m_Size - start;

    String result(length);
    memcpy(result.m_Buffer, m_Buffer + start, length);
    result.m_Buffer[length] = '\0';

    return result;
}

// reverse
String String::reverse() const
{
    String result(m_Size);

    for (unsigned int i = 0; i < m_Size; i++)
        result.m_Buffer[i] = m_Buffer[m_Size - 1 - i];

    result.m_Buffer[m_Size] = '\0';

    return result;
}

// find
size_t String::find(char a) const
{
    for (size_t i = 0; i < m_Size; i++)
        if (m_Buffer[i] == a)
            return i;

    return npos;
}

// operator+
String String::operator+(const String& other) const
{
    String result(m_Size + other.m_Size);

    memcpy(result.m_Buffer, m_Buffer, m_Size);
    memcpy(result.m_Buffer + m_Size, other.m_Buffer, other.m_Size);

    result.m_Buffer[result.m_Size] = '\0';

    return result;
}

// copy assignment
String& String::operator=(const String& other)
{
    if (this == &other)
        return *this;

    delete[] m_Buffer;

    m_Size = other.m_Size;
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, other.m_Buffer, m_Size + 1);

    return *this;
}

// move assignment
String& String::operator=(String&& other) noexcept
{
    if (this == &other)
        return *this;

    delete[] m_Buffer;

    m_Buffer = other.m_Buffer;
    m_Size = other.m_Size;

    other.m_Buffer = nullptr;
    other.m_Size = 0;

    return *this;
}

// operator[]
char& String::operator[](unsigned int index)
{
    if (index >= m_Size)
        throw std::out_of_range("index");

    return m_Buffer[index];
}

const char& String::operator[](unsigned int index) const
{
    if (index >= m_Size)
        throw std::out_of_range("index");

    return m_Buffer[index];
}

// ostream operator
std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}