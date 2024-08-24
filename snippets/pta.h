#include <stdbool.h>

// 判断一个数是否为素数
bool prime(int N) {
    if (N <= 3) {
        return N > 1;
    }

    // 不在 6 的倍数两侧的一定不是素数，如 4、6、8、9、10
    if (N % 6 != 1 && N % 6 != 5) {
        return false;
    }

    // 在 6 的两侧的也不一定是素数，如 25、49
    for (int i=5; i*i<=N; i+=6) {
        if (N % i == 0 || N % (i+2) == 0) {
            return false;
        }
    }

    return true;
}

// 两个整数取余
int mod(int a, int b) {
    return a - (a / b) * b;
}

// 最大公约数
int gcd(int a, int b) {

    // int t;
    // while (a % b != 0) {
    //     t = a % b;
    //     a = b;
    //     b = t;
    // }

    // return b;

    return a % b == 0 ? b : gcd(b, a % b);
}

// 返回斐波那契数列的第 N 项
int fibonacci(int N) {

    int a = 1, b = 0, fib;
    for (int i=0; i<N; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }

    return fib;
}