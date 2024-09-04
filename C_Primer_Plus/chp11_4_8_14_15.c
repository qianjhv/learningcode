#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define TEST "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"


char *my_strchr(const char *, int);
char *reverse_str(char *);
int my_atoi(const char *);

int main(int argc, char *argv[]) {

    // char ch;
//     char *tmp;
//     char r_string[] = "12314534";
// 
//     printf("%d, %d, %d\n", atoi("0x10"), atoi("-10"), atoi("+10"));
//     printf("%d, %d, %d", my_atoi("0x10"), my_atoi("-10"), my_atoi("+10"));
// 
//     while((ch = getchar()) != '0') {
//         if (ch == '\n') {
//             continue;
//         }
//         tmp = my_strchr(TEST, ch);
//         if(tmp == NULL) {
//             tmp = "cant find, type 0 to exit!";
//             puts(tmp);
//         } else {
//             puts(tmp);
//             puts(reverse_str(r_string));
//         }
//     }

    void print_usage(const char *prog_name) {
        printf("Usage: %s [-p | -u | -l] < input_file\n", prog_name);
        printf("Options:\n");
        printf("  -p    Print the file as is.\n");
        printf("  -u    Convert the file content to uppercase.\n");
        printf("  -l    Convert the file content to lowercase.\n");
    }

    int (*convert_case)(int) = NULL;  // Function pointer for case conversion

     // 如果没有传递参数，或者传递的参数无效，默认使用 -p 功能
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "-p") != 0 && strcmp(argv[1], "-u") != 0 && strcmp(argv[1], "-l") != 0)) {
        argc = 2;
        argv[1] = "-p";
    }

    if (argc != 2) {
        print_usage(argv[0]);
        return 1;
    }

    // Determine which option was selected
    if (strcmp(argv[1], "-p") == 0) {
        convert_case = NULL;  // No case conversion
    } else if (strcmp(argv[1], "-u") == 0) {
        convert_case = toupper;  // Convert to uppercase
    } else if (strcmp(argv[1], "-l") == 0) {
        convert_case = tolower;  // Convert to lowercase
    } else {
        print_usage(argv[0]);
        return 1;
    }

    // Read and process the input until the end of the file
    int ch;
    while ((ch = getchar()) != EOF) {
        if (convert_case) {
            ch = convert_case(ch);
        }
        putchar(ch);
    }

    return 0;
}   

char *my_strchr(const char *str, int c) {
    while(*str != '\0') {
        if(*str == (char)c) {
            return (char *)str;
        }
        str++;
    }

    if(c == '\0') {
        return (char *)str;
    }
    
    return NULL;
}

char *reverse_str(char *str) {
   int l = 0, r = strlen(str) - 1;
   char tmp;

   while(l < r) {
       tmp = str[l];
       str[l] = str[r];
       str[r] = tmp;

       l++;
       r--;
   }

   return str;
}

int my_atoi(const char *str) {
    int result = 0;  // 保存最终结果
    int sign = 1;    // 符号位，默认为正数

    // 跳过前导空白字符
    while (isspace(*str)) {
        str++;
    }

    // 处理正负号
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // 逐字符处理数字部分
    while (isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }

    // 返回最终结果，乘以符号位
    return result * sign;
}



