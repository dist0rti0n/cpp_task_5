#include <iostream>
#include "MyString.h"

MyString::MyString(const char *str) {
    this->mSize = strlen(str);
    this->mStr = new char[this->mSize + 1];
    strcpy(this->mStr, str);
}

MyString::MyString(size_t sizeOfFilling, char filler) {
    this->mSize = sizeOfFilling;
    this->mStr = new char[sizeOfFilling + 1];
    for (size_t i = 0; i < sizeOfFilling; ++i) {
        this->mStr[i] = filler;
    }
    this->mStr[this->mSize] = '\0';
}

MyString::MyString(const MyString &strForCopy) {
    this->mSize = strForCopy.mSize;
    this->mStr = new char[this->mSize + 1];
    strcpy(this->mStr, strForCopy.mStr);
}

MyString::~MyString() {
    delete[] mStr;
}

MyString& MyString::operator=(const MyString &stringForCopy) {
    this->mSize = stringForCopy.mSize;
    delete[] this->mStr;
    this->mStr = new char[this->mSize + 1];
    strcpy(this->mStr, stringForCopy.mStr);
    return *this;
}


void MyString::append(const char *appendedStr) {
    auto *formerStr = new char[this->mSize + 1];
    strcpy(formerStr, this->mStr);
    delete[] this->mStr;
    size_t newSize = strlen(appendedStr) + this->mSize;
    this->mStr = new char[newSize + 1];
    
    for (size_t i = 0; i < this->mSize; ++i) {
        this->mStr[i] = formerStr[i];
    }
    for (size_t i = mSize; i < newSize; ++i) {
        this->mStr[i] = appendedStr[i - this->mSize];
    }
    
    this->mSize = newSize;
    this->mStr[this->mSize] = '\0';
    delete[] formerStr;
}

void MyString::append(const MyString &appendedStr) {
    this->append(appendedStr.mStr);
}

void MyString::print() {
    std::cout << this->mStr << std::endl;
}


int main() {
    MyString myString("123");
    MyString myString1(3, 'f');
    myString.append(" test ");
    myString.append(myString1);
    myString.print();
    
    myString.append(" ");
    myString.append(myString);
    myString.print();
    
    MyString copyTestString("CT ONE LOVE ");
    MyString copyTestString1(copyTestString);
    copyTestString.print();
    
    copyTestString.append(copyTestString);
    copyTestString1 = copyTestString;
    copyTestString1.print();
    
}