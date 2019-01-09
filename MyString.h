#pragma once

class MyString {
public:
    MyString(const char*);
    MyString(size_t sizeOfFilling, char filler);
    MyString(const MyString&);
    
    ~MyString();
    
    void append(const char*);
    void append(const MyString&);
    
    void print();
    
    MyString& operator=(const MyString&);

private:
    char* mStr;
    size_t mSize;
};
