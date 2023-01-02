#include <iostream>
using namespace std;
class complex
{
private:
    int real, img;

public:
    complex(int x = 0, int y = 0)
    {
        real = x;
        img = y;
    }
    friend ostream &operator<<(ostream &out, complex const &obj);
    friend istream &operator>>(istream &in, complex &obj);

    complex operator+(complex const &obj)
    {
        complex res;
        res.real = real + obj.real;
        res.img = img + obj.img;
        return res;
    }
    complex operator*(complex const &obj)
    {
        complex res;
        res.real = ((real) * (obj.real)) - ((img) * (obj.img));
        res.img = ((real) * (obj.img)) + ((obj.real) * (img));
        return res;
    }
};
ostream &operator<<(ostream &out, complex const &obj)
{
    out << obj.real;
    out <<'+' <<obj.img << "i";
    return out;
}
istream &operator>>(istream &in, complex &obj)
{
    cout << "ENTER THE REAL PART : " << endl;
    in >> obj.real;
    cout << "ENTER THE IMAGINARY PART : " << endl;
    in >> obj.img;
    return in;
}
int main()
{
    complex c1, c2, c3, c4;
    int no;
    cout << "enter first number : " << endl;
    cin >> c1;
    cout << "enter second number : " << endl;
    cin >> c2;

    cout << "1.addition \n2.multiplication";
    cin >> no;
    switch (no)
    {
    case 1:
        c3 = c1 + c2;
        cout << "the addition is"
             << " " << c3;
        break;

    case 2:
        c4 = c1 * c2;
        cout << "the multiplication is"<< " " << c4;
        break;

    default:
        cout << "please choose correctly";
        break;
    }
    return 0;
}
