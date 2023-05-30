 
#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Nhap so nguyen a: ";
    cin >> a;

    // Dem so bit co gia tri 1
    int count = 0;
    int temp = a;
    while (temp > 0) {
        if (temp & 1) {
            count++;
        }
        temp >>= 1;
    }
    cout << "So bit co gia tri 1: " << count << endl;

    // Thay doi bit thu 4 tu phai qua thanh 0
    a &= ~(1 << 3);
    cout << "Gia tri cua a sau khi thay doi bit thu 4 tu phai qua thanh 0: " << a << endl;

    // Thay doi bit thu 5 tu phai qua thanh 1
    a |= (1 << 4);
    cout << "Gia tri cua a sau khi thay doi bit thu 5 tu phai qua thanh 1: " << a << endl;

    // Dao gia tri bit thu 3 tu phai qua thanh 0
    a ^= (1 << 2);
    cout << "Gia tri cua a sau khi dao gia tri bit thu 3 tu phai qua thanh 0: " << a << endl;

    // Thay doi gia tri 0x1234 thanh 0x3412 va 0x4321
    int b = 0x1234;
    int c = ((b & 0xFF) << 8) | ((b >> 8) & 0xFF);
    int d = ((c & 0xF0F) << 4) | ((c >> 4) & 0xF0F);
    int e = ((d & 0xCCCC) << 2) | ((d >> 2) & 0xCCCC);
    int f = ((e & 0xAAAA) << 1) | ((e >> 1) & 0xAAAA);
    cout << "Gia tri cua 0x1234 sau khi thay doi thanh 0x3412: " << c << endl;
    cout << "Gia tri cua 0x1234 sau khi thay doi thanh 0x4321: " << f << endl;

    return 0;
}
