def to_decimal(binary_str):
    decimal = 0
    length = len(binary_str)

    for i in range(length):
        bit = int(binary_str[i])
        if bit not in (0, 1):
            raise ValueError("Invalid binary digit")
        decimal += bit * (2 ** (length - i - 1))

    return decimal

# Test cases
print(to_decimal("101"))              #5
print(to_decimal("1010"))             #10
print(to_decimal("10010"))            #18
print(to_decimal("1010101"))          #85


