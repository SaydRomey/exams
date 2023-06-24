
/*
Printf exam version

Write a function named ft_printf 
that will mimic the real printf 
but it will manage only the following conversions:

s (string)
d (decimal) 
x (lowercase hexademical)
*/

#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdarg.h> 
 
void        put_string(char *string, int *length) 
{ 
        if (!string) 
                string = "(null)"; 
        while (*string) 
                *length += write(1, string++, 1); 
} 
  
void        put_digit(long long int number, int base, int *length) 
{ 
        char        *hexadecimal = "0123456789abcdef"; 
 
        if (number < 0) 
        { 
                number *= -1; 
                *length += write(1, "-", 1); 
        } 
        if (number >= base) 
                put_digit((number / base), base, length); 
        *length += write(1, &hexadecimal[number % base], 1); 
} 
 
int        ft_printf(const char *format, ...) 
{ 
        int length = 0; 
         
        va_list        pointer; 
        va_start(pointer, format); 
         
        while (*format) 
        { 
                if ((*format == '%') && *(format + 1)) 
                { 
                        format++; 
                        if (*format == 's') 
                                put_string(va_arg(pointer, char *), &length); 
                        else if (*format == 'd') 
                                put_digit((long long int)va_arg(pointer, int), 10, &length); 
                        else if (*format == 'x') 
                                put_digit((long long int)va_arg(pointer, unsigned int), 16, &length); 
                } 
                else 
                        length += write(1, format, 1); 
                format++; 
        } 
        return (va_end(pointer), length); 
}

// Or shorter

#include <unistd.h> 
#include <stdarg.h> 
 
size_t        ft_putstr(char *string, int length) 
{ 
        while (string && string[length] && ++length); 
        return (string ? write(1, string, length) : write(1, "(null)", 6)); 
} 
 
void        ft_putnbr(long number, unsigned length, char *sign, int *size) 
{ 
        if (number >= length) 
                ft_putnbr(number / length, length, sign, size); 
        *size += (int) write(1, &sign[number % length], 1); 
} 
 
void        ft_puthex(long number, int length, char *sign, int *size) 
{ 
        (number < 0) ? (*size += (int) write(1, "-", 1), \ 
                ft_putnbr(-number, length, sign, size)) : (ft_putnbr(number, length, sign, size)); 
} 
 
int        ft_printf(char *format, ...) 
{ 
        int                size = 0; 
        va_list        ap; 
 
        va_start(ap, format); 
        while (*format) 
        { 
                if (*format == '%' && *(format + 1) == 's' && (format += 2)) 
                        size += (int) ft_putstr(va_arg(ap, char *), 0); 
                else if (*format == '%' && *(format + 1) == 'x' && (format += 2)) 
                        ft_putnbr(va_arg(ap, int), 16, "0123456789abcdef", &size); 
                else if (*format == '%' && *(format + 1) == 'd' && (format += 2)) 
                        ft_puthex(va_arg(ap, int), 10, "0123456789", &size); 
                else 
                        size += (int) write(1, format++, 1); 
        } 
        return (va_end(ap), size); 
}
