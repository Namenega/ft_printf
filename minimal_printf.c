#include <stdarg.h>
#include <unistd.h>

/* Custom implementation of strlen */
int ft_strlen(const char *s) {
    int len = 0;
    while (s[len])
        len++;
    return len;
}

/* Custom implementation of putchar */
int ft_putchar(char c) {
    return write(1, &c, 1);
}

/* Custom implementation of puts */
int ft_putstr(const char *s) {
    int len = 0;
    if (!s)
        s = "(null)";
    while (*s)
        len += ft_putchar(*s++);
    return len;
}

/* Custom implementation of putnbr */
int ft_putnbr(int n) {
    int len = 0;
    if (n == -2147483648)
        return ft_putstr("-2147483648");
    if (n < 0) {
        len += ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        len += ft_putnbr(n / 10);
    len += ft_putchar((n % 10) + '0');
    return len;
}

/* Custom implementation of putnbr_unsigned */
int ft_putnbr_unsigned(unsigned int n) {
    int len = 0;
    if (n >= 10)
        len += ft_putnbr_unsigned(n / 10);
    len += ft_putchar((n % 10) + '0');
    return len;
}

/* Custom implementation of putnbr_hex */
int ft_putnbr_hex(unsigned int n, int uppercase) {
    int len = 0;
    char *base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    if (n >= 16)
        len += ft_putnbr_hex(n / 16, uppercase);
    len += ft_putchar(base[n % 16]);
    return len;
}

/* Custom implementation of putptr */
int ft_putptr(unsigned long n) {
    int len = 0;
    char *base = "0123456789abcdef";
    if (n >= 16)
        len += ft_putptr(n / 16);
    len += ft_putchar(base[n % 16]);
    return len;
}

/* Custom implementation of ft_printf */
int ft_printf(const char *format, ...) {
    va_list args;
    int i = 0, len = 0;

    va_start(args, format);
    while (format[i]) {
        if (format[i] == '%' && format[i + 1]) {
            i++;
            if (format[i] == 'c')
                len += ft_putchar(va_arg(args, int));
            else if (format[i] == 's')
                len += ft_putstr(va_arg(args, char *));
            else if (format[i] == 'd' || format[i] == 'i')
                len += ft_putnbr(va_arg(args, int));
            else if (format[i] == 'u')
                len += ft_putnbr_unsigned(va_arg(args, unsigned int));
            else if (format[i] == 'x')
                len += ft_putnbr_hex(va_arg(args, unsigned int), 0);
            else if (format[i] == 'X')
                len += ft_putnbr_hex(va_arg(args, unsigned int), 1);
            else if (format[i] == 'p') {
                len += ft_putstr("0x");
                len += ft_putptr((unsigned long)va_arg(args, void *));
            }
            else if (format[i] == '%')
                len += ft_putchar('%');
            else
                len += ft_putchar(format[i]);
        } else
            len += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return len;
}

