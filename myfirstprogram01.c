#include <stdio.h>
#include <math.h>

int main() {
    // === DATA TYPES ===
    int a = 10;                 // Integer
    float b = 5.5;               // Floating point number
    double c = 15.6789;         // Double precision floating point
    char ch = 'A';              // Character
    char str[] = "Hello c!";    // String (array of chars)

    printf("==== DATA TYPES ===\n");
    printf("Integer a = %d\n", a);
    printf("Float b = %.2f\n", b);
    printf("Double c = %.4lf\n", c);
    printf("Character ch = %c\n", ch);
    printf("String str = %s\n\n", str);

    // === ARITHMETIC OPERATORS ===
    int x = 8, y = 3;
    printf("=== ARITHMETIC OPERATORS ===\n");
    printf("%d + %d = %d\n", x, y, x + y);
    printf("%d - %d = %d\n", x, y, x - y);
    printf("%d * %d = %d\n", x, y, x * y);
    printf("%d / %d = %d (integer division) \n", x, y, x / y);
    printf("%d %% %d = %d (modulus) \n\n", x, y, x % y);

    // === RELATIONAL OPERATORS ===
    printf("=== RELATIONAL OPERATORS ===\n");
    printf("%d > %d = %d\n", x, y, x > y);
    printf("%d < %d = %d\n", x, y, x < y);
    printf("%d == %d = %d\n", x, y, x == y);
    printf("%d != %d = %d\n", x, y, x != y);
    printf("%d >= %d = %d\n", x, y, x >= y);
    printf("%d <= %d = %d\n\n", x, y, x <= y);

    // === LOGICAL OPERATORS ===
    int p = 1, q = 0;
    printf("===  LOGICAL OPERATORS ===\n");
    printf("p && q = %d (AND)\n", p && q);
    printf("p || q = %d (OR)\n", p || q);
    printf("!p = %d (NOT)\n\n", !p);

    // === ASSIGNMENT OPERATORS ===
    printf("=== ASSIGNMENT OPERATORS ===\n");
    int num = 10;
    printf("Initial num = %d\n", num);
    num += 5; printf("num += 5 -> %d\n", num);
    num -= 3; printf("num -= 3 -> %d\n", num);
    num *= 2; printf("num *= 2 -> %d\n", num);
    num /= 4; printf("num /= 4 -> %d\n", num);
    num %= 3; printf("num %%= 3 -> %d\n\n", num);

    // === BITWISE OPERATORS ===
    unsigned int m = 6;    // 0110 in binary
    unsigned int n = 3;    // 0011 in binary
    printf("=== BITWISE OPERATORS ===\n");
    printf("m & n = %d (AND)\n", m & n);
    printf("m | n = %d (OR)\n", m | n);
    printf("m ^ n = %d (XOR)\n", m ^ n);
    printf("~m = %d (NOT)\n", ~m);
    printf("m << 1 = %d (Left Shift)\n", m << 1);
    printf("m >> 1 = %d (Right Shift)\n\n", m >> 1);

    // === INCREMENT & DECREMENT OPERATORS ===
    printf("=== INCREMENT & DECREMENT ===\n");
    int count = 5;
    printf("count = %d\n", count);
    printf("++count = %d (pre-increment)\n",  ++count);
    printf("count++ = %d (post-increment)\n", count++);
    printf("After count++ -> %d\n", count);
    printf("-- count = %d (pre-decrement)\n", --count);
    printf("count-- = %d (post-decrement)\n", count--);
    printf("After count-- -> %d\n\n", count);

    // === TYPE CONVERSION (Casting) ===
    printf("=== TYPE CONVERSION ===\n");
    int i = 5;
    int j = 2;
    float div1 = i / j;             // Integer division
    float div2 = (float)i / j;      // Type casting
    printf("i / j (int division) = %.2f\n", div1);
    printf("(float)i / j = %.2f\n\n", div2);

    // === COMPLEX EXPRESSIONS ===
    printf("=== COMLEX EXPRESSIONS ===\n");
    int exp = (x + y) * (a - 5) / 2;
    printf("Expression (x + y) * (a - 5) / 2 = %d\n", exp);

    double z = (a + b) / c + pow(b, 2);
    printf("Expression (a + b) / c + b^2 = %.4lf\n", z);

    printf("\n=== END OF PROGRAM ===\n");

    return 0;
}


