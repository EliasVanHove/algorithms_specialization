import numpy as np

def split_number(g1, split):
    """
    This function will split the number g1 with n digits into two parts:
    g1 = a*10**(n//2)+b with b 'split' digits and a the first n-split digits

    return: a, b, n
    """
    g1_string = str(g1)
    n = len(g1_string)
    a_string = g1_string[:n-split]
    b_string = g1_string[n-split:]
    return int(a_string), int(b_string)

def Karatsuba(g1, g2):
    n1 = len(str(g1))
    n2 = len(str(g2))

    if (n1==1) or (n2==1):
        return g1*g2


    else:
        split = min(n1//2, n2//2)
        a,b = split_number(g1, split)
        c,d = split_number(g2, split)

        ac = Karatsuba(a,c)
        a_bc_d = Karatsuba(a+b,c+d)
        bd = Karatsuba(b,d)
        return ac * 10**(split + split) + (a_bc_d - ac - bd) * 10**(split) + bd


if __name__ == "__main__":
    numbers = []
    with open(R'module 1\week 1\numbers.txt') as infile:
        for line in infile:
            words = line.split(' ')
            numbers.append(int(words[-1]))
    print(Karatsuba(numbers[0], numbers[1])-numbers[0]*numbers[1])
    print('ok')