#include <iostream>
#include "circularbuffer.h"

using std::cout;

template<class T>
class CCompare {
    void operator()(T a) {
        std::cout << *a << " ";
    }
};

int main() {
    CCircleBuffer<int> buffer(4);
    CCompare<int> cmpr;
    buffer.push_front(12);
    buffer.push_front(13);
    buffer.push_front(17);
    buffer.push_front(199);
    buffer.push_front(201);
    buffer.push_front(1);
    buffer.resize(5);
    buffer.push_back(1);
    buffer.push_back(4);
    buffer.push_back(5);
    buffer.push_back(6);
    buffer.push_back(10);
    buffer.push_back(11);
    CCircleBuffer<int>::iterator b = CCircleBuffer<int>::iterator(buffer.begin());
    CCircleBuffer<int>::iterator e = CCircleBuffer<int>::iterator(buffer.end());
    cout << *b;
    cout << "\n";
    for (int i = 0; i < buffer.length(); i++) {
        std::cout << buffer[i] << " ";
    }
    cout << "\n";
    CCircleBuffer<int>::iterator result = std::find(b, e, 4);
    cout << *result;
    return 0;
}
