#include <stdio.h>

int main(void) {

    char *p = "hello";
    *p = "halo";
	printf("%s", *p); // 输出响铃字符
    return 0;
}
