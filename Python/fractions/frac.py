# Introduction:
#
# Peter needed tp help his daughter Eva do her 5th grade math homework on fractions.
# Remembering a bit of math, knowing that python had tuples, and recalling a bit of 
# code from a dusty blue wizard CS textbook, he wrote the following functions and said 
# "maybe these can help you:"

def add_frac(a, b):
    return (a[0]*b[1] + a[1]*b[0], a[1]*b[1])

def sub_frac(a, b):
    return (a[0]*b[1] - a[1]*b[0], a[1]*b[1])

def mul_frac(a, b):
    return (a[0]*b[0], a[1]*b[1]) 

def div_frac(a, b):
    return (a[0]*b[1], a[1]*b[0])

# In this code, fractions are stored as a tuple containing the numerator and denominator, For example,
# the fraction 2/3 is written as follows:
#
# >>> a = (2, 3)
# >>> 
# 
# To perform various mathematical operations, the above functions are used. Here is a sample of how 
# they work.

a = (2, 3)
b = (3, 4)
assert add_frac(a, b) == (17, 12)
assert mul_frac(a, b) == (6, 12)

