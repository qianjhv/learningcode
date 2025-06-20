#include <stdio.h>

int binary_string_to_int(const char *bin_str);
int bstr_to_dec(const char *str);
int bit_at_index(int n, int index);

int main(void) {

    char str[100];

    while((scanf("%s", str) == 1)) {
        printf("%d\n", binary_string_to_int(str)); 
        
    }
    
    return 0;
}

int binary_string_to_int(const char *bin_str) {
    int result = 0;

    while (*bin_str) {
        if (*bin_str == '0') {
            result = result << 1;
        } else if (*bin_str == '1') {
            result = (result << 1) | 1;
        } else {
            printf("Invalid character: %c\n", *bin_str);
            return -1;
        }
        bin_str++;
    }

    return result;
}

int bstr_to_dec(const char *str) {
    int value = 0;

    while (*str != '\0') {
        value = 2 * value + (*str - '0');
        str++;
    }

    return value;
}

int bit_at_index(int n, int index) {
    static const int size = CHAR_BIT * sizeof(int) + 1;
    index -= 1;

    if (index > size || index < 0) {
        printf("Error index\n");
        return -1;
    }

    if (1 & (n >> pos)) {
        return 1;
    } else {
        return 0;
    }
}


