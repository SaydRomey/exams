
#include <unistd.h>

/*
ascii conversions
	nbr + '0' : decimal to ascii char (putnbr, itoa, etc)
	nbr - '0' : ascii char to decimal (atoi)

	c + ' ' : tolower
	c - ' ' : toupper
*/


/* lvl 2 exam notes

print_bits

bit = 128
while (bit > 0)
if (octet >= bit)
write 1; octet %= bit; bit /= 2;
else
write 0; bit /= 2;


reverse_bits

result = 0; i = 8;
while (i > 0)
reversed *= 2; //left shift
reversed += octet % 2; //add least significant bit of octet to reversed
octet /= 2; //right shift
i--;
return (reversed);


swap bits

high = octet / 16; //moves high 4 bits to low 4 bits position
low = octet % 16; //gets the low 4 bits
return (low * 16) + high; //move the low bits to high pos, then add original high bits
*/

void	ft_puthex(int nbr)
{
	char	*digits = "0123456789abcdef";

	if (nbr > 15)
		ft_puthex(nbr / 16);
	ft_putchar(digits[nbr % 16]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	ft_putchar(base[nbr % base_len]);
}



int        ft_atoi_base(const char *str, int str_base)
{
        int        idx;
        int        sign;
        int        result;
        int        value;

        idx = 0;
        sign = 1;
        result = 0;
        if (str[0] == '-')
        {
                sign = -1;
                idx++;
        }
        while (str[idx])
        {
                char c = str[idx];
                if (c >= '0' && c <= '9')
                        value = c - '0';
                else if (c >= 'A' && c <= 'F')
                        value = c - 'A' + 10;
                else if (c >= 'a' && c <= 'f')
                        value = c - 'a' + 10;
                else
                        value = 0; // If the character is not recognized, it defaults to 0.
                if (value >= str_base)
                        break; // Stop if character is outside the base's range

                result = result * str_base + value;
                idx++;
        }
        return (result * sign);
}

..  .. ..





...

...

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 2) // Check that exactly one number is provided for factorization
    {
        int i = 2; // Start from the smallest prime number
        int number = atoi(argv[1]); // Convert the argument to an integer

        if (number == 1) // The prime factorization of 1 is just 1
            printf("1");

        // Factorize the number
        while (i <= number) // Loop until we've tested all possible factors
        {
            if (number % i == 0) // If 'i' is a factor of 'number'
            {
                printf("%d", i); // Print the factor
                number /= i; // Divide 'number' by its factor

                // If the remaining 'number' is 1, we're done
                if (number == 1)
                    break;

                printf("*"); // Print an asterisk to separate the factors
                // No need to reset 'i' here because we need to check if 'i' is a factor again
            }
            else
            {
                i++; // Increment 'i' if it's not a factor
            }
        }
    }
    printf("\n"); // Print a newline at the end
    return 0; // Exit the program
}

...

...

#include "ft_list.h"

...

#include <stdlib.h>

static int  is_delimiter(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

static int  count_words(char *str)
{
    int count = 0;
    while (*str)
    {
        while (*str && is_delimiter(*str))
            str++;
        if (*str && !is_delimiter(*str))
        {
            count++;
            while (*str && !is_delimiter(*str))
                str++;
        }
    }
    return count;
}

static char *malloc_word(char *str)
{
    char *word;
    int i = 0;

    while (str[i] && !is_delimiter(str[i]))
        i++;
    word = (char *)malloc(sizeof(char) * (i + 1));
    if (!word)
        return NULL;
    for (int j = 0; j < i; j++)
        word[j] = str[j];
    word[i] = '\0';
    return word;
}

char    **ft_split(char *str)
{
    int words = count_words(str);
    char **result = (char **)malloc(sizeof(char *) * (words + 1));
    if (!result)
        return NULL;

    int i = 0;
    while (*str)
    {
        while (*str && is_delimiter(*str))
            str++;
        if (*str && !is_delimiter(*str))
        {
            result[i] = malloc_word(str);
            if (!result[i])
            {
                while (i > 0)
                    free(result[--i]);
                free(result);
                return NULL;
            }
            i++;
            while (*str && !is_delimiter(*str))
                str++;
        }
    }
    result[i] = NULL; // NULL-terminate the array
    return result;
}


..

#include <stdio.h>


int ft_to_digit(char c, int base) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'Z')
        return 10 + c - 'A';
    else if (c >= 'a' && c <= 'z')
        return 10 + c - 'a';
    return -1; // Error case, not a valid digit
}

int ft_atoi_base(const char *str, int base) {
    int result = 0;
    int sign = 1;
    int digit;

    // Skip white spaces
    while (ft_is_space(*str)) str++;

    // Check for sign
    if (*str == '+' || *str == '-') {
        if (*str == '-')
            sign = -1;
        str++;
    }

    // Convert characters to integer value
    while ((digit = ft_to_digit(*str++, base)) >= 0 && digit < base) {
        result = result * base + digit;
    }

    return sign * result;
}

int main() {
    const char *hex_str = "1A3F";
    int num = ft_atoi_base(hex_str, 16); // Convert from base 16
    printf("The number is: %d\n", num);
    return 0;
}

...

int ft_to_digit(char c) {
    const int offset_for_digits = '0'; // Numerical value of '0'
    const int offset_for_uppercase = 'A' - 10; // Numerical value of 'A' should be 10
    const int offset_for_lowercase = 'a' - 10; // Numerical value of 'a' should be 10

    // If c is a digit (0-9)
    if (c >= '0' && c <= '9')
        return c - offset_for_digits; // Convert to integer value (0-9)

    // If c is an uppercase letter (A-F)
    if (c >= 'A' && c <= 'F')
        return c - offset_for_uppercase; // Convert to integer value (10-15)

    // If c is a lowercase letter (a-f)
    if (c >= 'a' && c <= 'f')
        return c - offset_for_lowercase; // Convert to integer value (10-15)

    return -1; // Error case, not a valid digit
}

...

void ft_iterate_digits(int number, int base) {
    char digit_char;
    int digit;
    int divisor = 1;

    // Find the highest power of the base that is less than or equal to the number
    while (number / divisor >= base)
        divisor *= base;

    // Iterate through the digits of the number
    while (divisor > 0) {
        digit = (number / divisor) % base; // Extract the digit
        digit_char = ft_digit_to_char(digit, base); // Convert digit to character
        putchar(digit_char); // Print the character
        divisor /= base; // Move to the next digit
    }
}

...

char ft_digit_to_char(int digit) {
    if (digit >= 0 && digit <= 9)
        return '0' + digit;
    else if (digit >= 10 && digit < 36)
        return 'A' + digit - 10;
    
    return '?'; // Error case, not a valid digit
}

void ft_print_digits(int number, int base) {
    char stack[32]; // A stack to hold characters (digits)
    int top = 0;    // Stack pointer

    // Handle 0 explicitly
    if (number == 0) {
        putchar('0');
        return;
    }

    // Handle negative numbers
    if (number < 0 && base == 10) {
        putchar('-');
        number = -number; // Make the number positive
    }

    // Fill the stack with digits of the number
    while (number > 0) {
        int digit = number % base;
        stack[top++] = ft_digit_to_char(digit); // Convert and push to stack
        number /= base;
    }

    // Pop from stack and print
    while (top > 0) {
        putchar(stack[--top]);
    }
}

...

void ft_print_digits(int number, int base) {
    char buffer[33]; // Buffer to hold characters (digits) + null terminator
    int index = 32;  // Start from the end of the buffer

    buffer[index] = '\0'; // Null-terminate the string

    // Handle 0 explicitly
    if (number == 0) {
        buffer[--index] = '0'; // Only need to place '0' in the buffer
    } else {
        // Handle negative numbers for base 10
        int is_negative = (number < 0 && base == 10);
        if (is_negative) {
            number = -number; // Make the number positive
        }

        // Fill the buffer with digits of the number, in reverse order
        while (number > 0) {
            int digit = number % base;
            buffer[--index] = ft_digit_to_char(digit); // Convert and place in buffer
            number /= base;
        }

        // If the number was negative, add the minus sign
        if (is_negative) {
            buffer[--index] = '-';
        }
    }

    // Print the buffer starting from the first non-null character
    printf("%s", &buffer[index]);
}






