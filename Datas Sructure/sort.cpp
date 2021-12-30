#include <iostream>

using namespace std;

class shape {
public:
    virtual int area() = 0;
    virtual int perimeter() = 0;
};

class triangle:public shape{
private:
    int h, x;
public:
    triangle(int a, int b) {
        h = a;
        x = b;
    }
    int getH() {
        return h;
    }
    int getx() {
        return x;
    }    
    void setH(int a){
        h = a;
    }
    void setX(int a) {
        x = a;
    }
    int area(){
        return (x * h) / 2;
    }
    int perimeter(){
        return 3 * x;
    }
};

class rectangle:public shape{
private:
    int x, y;
public:
    rectangle(int a, int b) {
        x = a;
        y = b;
    }
    int getY() {
        return y;
    }
    int getx() {
        return x;
    }    
    void sety(int a){
        y = a;
    }
    void setX(int a) {
        x = a;
    }
    int area(){
        return (x * y) ;
    }
    int perimeter(){
        return 2 * (x + y);
    }
};
int main()
{
    shape *a = new triangle(4, 2);
    cout << a->area() << " " << a->perimeter() << endl;

    shape *b = new rectangle(4, 2);
    cout << b->area() << " " << b->perimeter() << endl;
}

