#include <iostream>

class String {
private:
    int length;
    char* str;
    String(int len);
public:
    String(const char* str = "");
    String(const String& s);
    String& operator=(const String& s);
    String& operator=(const char* s);
    ~String();
    String operator+(const String& s) const;
    String operator+(const char* s) const;
    String& operator+=(const String& s);
    String& operator+=(const char* s);
    char& operator[](int i);
    const char& operator[](int i) const;
    friend String operator+(const char* s1, const String& s2);
    friend std::ostream& operator<<(std::ostream& os, const String& s);
    bool operator==(const String& s) const;
    bool operator==(const char* s) const;
    bool operator!=(const String& s) const;
    bool operator!=(const char* s) const;
    bool operator<=(const String& s) const;
    bool operator<=(const char* s) const;
    bool operator>=(const String& s) const;
    bool operator>=(const char* s) const;
    bool operator<(const String& s) const;
    bool operator<(const char* s) const;
    bool operator>(const String& s) const;
    bool operator>(const char* s) const;
    friend bool operator==(const char* s1, const String& s2);
    friend bool operator!=(const char* s1, const String& s2);
    friend bool operator<=(const char* s1, const String& s2);
    friend bool operator>=(const char* s1, const String& s2);
    friend bool operator<(const char* s1, const String& s2);
    friend bool operator>(const char* s1, const String& s2);
    bool is_empty() const;
    int len() const;
    String substring(int begin, int end) const;
    String left(int count) const;
    String right(int count) const;
    bool has_substing(const String& s) const;
    bool has_substing(const char* s) const;
    bool has_symbol(char c) const;
    String remove_substring(int begin, int end) const;
    String remove_substring(const String& s) const;
    String remove_substring(const char* s) const;
    String get_first_word(const String& sep) const;
    String get_last_word(const String& sep) const;
    /*
    remove_left(); remove_right();
    get_first_word(); get_last_word();
    */
};
