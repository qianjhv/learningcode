#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int main(void) {
    int a;
    ofstream out("/dev/null");

    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        out << i << "\n";
    }
    clock_t end = clock();
    cout << start << endl;
    cout << end << endl;
    cout << double(end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
