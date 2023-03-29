#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - this function will print according format
 * @format: this is the pointer function
 *
 * Return: count
 */ 
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}
