#ifndef MYSTRING_H
#define MYSTRING_H

#include <QObject>
#include <iostream>
#include <cctype>
class MyString : public QObject
{
    Q_OBJECT
private:
    char* mystr; //c style string which holds mystring
public:
    explicit MyString(QObject *parent = nullptr); // no arg constructor
    MyString(const char* normalstr); // overloaded constructor
    MyString(MyString &copystring); // copy constructor
    MyString(MyString &&movestring); //move constructor
    ~MyString();

    void display(std::ostream& outstream) const; // display string
    int getlength() const; // display string length
    const char* getmystring() const; // get string

    MyString& operator=(const MyString &rhs); // assignment operator overloading
    MyString& operator=(MyString &&rhs); //move operator overloading
    MyString operator-() const; //unary operators takes no argument while bunary requires one
    MyString operator+(const MyString &rhs) const; //addition operator overloading for concatanation
    bool operator==(const MyString &rhs) const; //comparison operator overloading for string comparison

signals:

};

#endif // MYSTRING_H
