#include <iostream>
#include <string>
#include <vector>
#include <array>

int main(void) {

    using namespace std;
    string str = "hello";
    cout << str << endl << &str << endl;

    vector<int> vi(5);
    vi[0] = 1; 
    cout << vi[0] << endl;

    array<int, 4> arr;
    arr[0] = 12;
    cout << arr[0] << endl;

    return 0;
}
