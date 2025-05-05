a, b = map(int, input().split())

# Step 1: Check for power of 2 in range
x = 1
while x <= b:
    if a <= x <= b:
        print(x)
        exit()
    x <<= 1  # Multiply by 2

# Step 2: Otherwise, check for minimal popcount (bit count)
answer = a
min_ones = bin(a).count('1')

for num in range(a, b + 1):
    ones = bin(num).count('1')
    if ones < min_ones:
        min_ones = ones
        answer = num
    elif ones == min_ones and num < answer:
        answer = num

print(answer)