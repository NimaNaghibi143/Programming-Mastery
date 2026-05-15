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