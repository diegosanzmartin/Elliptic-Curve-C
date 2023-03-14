#include <stdio.h>

void reverse_string(char *str, int start, int end) {
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char *itoa(int number, char *str, int base) {
    int i = 0, is_negative = 0;

    if (number == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (number < 0 && base == 10) {
        number = -number;
        is_negative = 1;
    }

    while (number != 0) {
        int remainder = number % base;
        str[i++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
        number /= base;
    }

    if (is_negative) {
        str[i++] = '-';
    }

    reverse_string(str, 0, i - 1);
    str[i] = '\0';

    return str;
}
