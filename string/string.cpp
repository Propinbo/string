#include <cstring>
#include <iostream>
#include "string.h"

String::String(const char* str) {
    length = std::strlen(str);
    this->str = new char[length + 1];
    std::strcpy(this->str, str);
}
String::~String() {
    delete[] str;
}
String::String(const String& s) {
    std::cout << "copy\n";
    length = s.length;
    str = new char[length + 1];
    std::strcpy(str, s.str);
}
String& String::operator=(const String& s) {
    if (this == &s) {
        return *this;
    }
    delete[] str;
    length = s.length;
    str = new char[length + 1];
    std::strcpy(str, s.str);
    return *this;
}
String& String::operator=(char* s) {
    delete[] str;
    length = std::strlen(s);
    str = new char[length + 1];
    std::strcpy(str, s);
    return *this;
}
String::String(int len) {
    length = len;
    str = new char[len + 1];
}
String String::operator+(const String& s) const {
    String res(length + s.length);
    std::strcpy(res.str, str);
    std::strcpy(res.str + length, s.str);
    return res;
}
String String::operator+(char* s) const {
    String res(length + std::strlen(s));
    std::strcpy(res.str, str);
    std::strcpy(res.str + length, s);
    return res;
}
String& String::operator+=(const String& s) {
    char* buf = new char[length + s.length + 1];
    std::strcpy(buf, str);
    std::strcpy(buf + length, s.str);
    delete[] str;
    str = buf;
    length = length + s.length;
    return *this;
    // return *this = *this + s;
}
String& String::operator+=(char* s) {
    char* buf = new char[length + std::strlen(s) + 1];
    std::strcpy(buf, str);
    std::strcpy(buf + length, s);
    delete[] str;
    str = buf;
    length = length + std::strlen(s);
    return *this;
}
String operator+(char* s1, const String& s2) {
    String res(s2.length + std::strlen(s1));
    std::strcpy(res.str, s1);
    std::strcpy(res.str + std::strlen(s1), s2.str);
    return res;
}
std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.str << "\n";
    return os;
}
char& String::operator[](int i) {
    if (i < 0 || i > length)
        return str[length];
    return str[i];
}
const char& String::operator[](int i) const {
    if (i < 0 || i > length)
        return str[length];
    return str[i];
}
bool String::operator==(const String& s) const {
    return std::strcmp(str, s.str) == 0;
}
bool String::operator==(char* s) const {
    return std::strcmp(str, s) == 0;
}
bool String::operator!=(const String& s) const {
    return std::strcmp(str, s.str) != 0;
}
bool String::operator!=(char* s) const {
    return std::strcmp(str, s) != 0;
}
bool String::operator<=(const String& s) const {
    return std::strcmp(str, s.str) <= 0;
}
bool String::operator<=(char* s) const {
    return std::strcmp(str, s) <= 0;
}
bool String::operator>=(const String& s) const {
    return std::strcmp(str, s.str) >= 0;
}
bool String::operator>=(char* s) const {
    return std::strcmp(str, s) >= 0;
}
bool String::operator<(const String& s) const {
    return std::strcmp(str, s.str) < 0;
}
bool String::operator<(char* s) const {
    return std::strcmp(str, s) < 0;
}
bool String::operator>(const String& s) const {
    return std::strcmp(str, s.str) > 0;
}
bool String::operator>(char* s) const {
    return std::strcmp(str, s) > 0;
}
bool operator==(char* s1, const String& s2) {
    return std::strcmp(s1, s2.str) == 0;
}
bool operator!=(char* s1, const String& s2) {
    return std::strcmp(s1, s2.str) != 0;
}
bool operator<=(char* s1, const String& s2) {
    return std::strcmp(s1, s2.str) <= 0;
}
bool operator>=(char* s1, const String& s2) {
    return std::strcmp(s1, s2.str) >= 0;
}
bool operator<(char* s1, const String& s2) {
    return std::strcmp(s1, s2.str) < 0;
}
bool operator>(char* s1, const String& s2) {
    return std::strcmp(s1, s2.str) > 0;
}
bool String::is_empty() const {
    return length == 0;
}
int String::len() const {
    return this->length;
}
String String::substring(int begin, int end) const {
    if (begin < 0) {
        begin = 0;
    }
    if (end > length) {
        end = length;
    }
    if (end < begin) {
        return String();
    }
    int l = end - begin + 1;
    String res(l);
    for (int i = 0; i < l; i++) {
        res.str[i] = str[i + begin];
    }
    res.str[l] = '\0';
    return res;
}
String String::left(int count) const {
    return substring(0, count - 1);
}
String String::right(int count) const {
    return substring(length - count, length);
}
bool String::has_substing(const String& s) const {
    return std::strstr(str, s.str) != NULL;
}
bool String::has_substing(char* s) const {
    return std::strstr(str, s) != NULL;
}
bool String::has_symbol(char c) const {
    return std::strchr(str, c) != NULL;
}
String String::remove_substring(int begin, int end) const {
    if (begin <= end)
        return left(begin) + right(end);
    return String();
}
String String::remove_substring(const String& s) const {
    char* start = std::strstr(str, s.str);
    if (start == NULL) {
        return *this;
    }
    //return left(start-str) + right(length - (start-str) - s.length);
    return substring(start - str, (start - str) + s.length);
}
String String::remove_substring(char* s) const {
    char* start = std::strstr(str, s);
    if (start == NULL) {
        return *this;
    }
    //return left(start-str) + right(length - (start-str) - std::strlen(s));
    return substring(start - str, (start - str) + std::strlen(s));
}
String String::get_first_word(const String& sep) const {
    int begin = 0;
    while (sep.has_symbol(str[begin]) && (begin < length))
        begin++;
    int end = begin;
    while (!sep.has_symbol(str[end]) && (end < length))
        end++;
    return substring(begin, end);
}
String String::get_last_word(const String& sep) const {
    int end = length;
    while (sep.has_symbol(str[end]) && (end > 0))
        end--;
    int begin = end;
    while (!sep.has_symbol(str[begin]) && (begin > 0))
        begin--;
    return substring(begin + 1, end);
}