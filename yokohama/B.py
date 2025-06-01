a, b = input().split(" ")
a = bin(int(a))[2:]
b = bin(int(b))[2:]
    
a = "0" * (len(b) - len(a)) + a
differ_index = -1 # index of first 0 in small number and 1 in larger number
for i in range(len(b)):
    if a[i] != b[i]:
        differ_index = i
        break
    
if differ_index == -1:
    print(int(a, base=2))
else:
    count = 0
    last_zero = -1
    for i in range(differ_index + 1, len(b)):
        if a[i] == "1":
            if last_zero == -1:
                last_zero = i
            count += 1
    if count >= 2:
        pre_zeros = last_zero - differ_index - 1
        post_zeros = len(b) - differ_index - 1 - pre_zeros
        print(int(a[:differ_index] + "0" * pre_zeros + "1" + "0" * post_zeros, base=2))
    else:
        print(int(a, base=2))
