#include <iostream>
#include "circular_buffer.h"
using namespace std;


int main()
{
    CiruclarBuffer<char> * buffer=new CiruclarBuffer<char>(2);

    buffer->push('a');
    buffer->push('b');
    buffer->show();

    buffer->pop();
    buffer->pop();
    buffer->show();

    delete buffer;

    return 0;
}
