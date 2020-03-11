#include <QCoreApplication>
#include "mystring.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyString HelloWorld{"Hello World!!!"};
    std::cout << HelloWorld.getmystring() << std::endl;

    return a.exec();
}
