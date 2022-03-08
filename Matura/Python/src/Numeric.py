import math

def ESieve(Number):

    size = int(math.sqrt(Number))
    
    primes = [True] * (Number)

    for i in range(2, size):
        if primes[i] == True:
            j = i * 2
            while j < Number:
                primes[j] = False
                j += i

    retVal = []

    for i in range(Number):
        if primes[i] == True:
            retVal.append(i)

    return retVal

def IsPrime(Number):
    if Number > 2 and Number % 2 == 0:
        return False
    elif Number > 3 and Number % 3 ==0:
        return False
    
    i = 5

    while i ** 2 <= Number:
        if Number % i == 0:
            return False
        elif Number % (i + 2) == 0:
            return False
        else:
            i += 6
    
    return True

def Factorise(Number):
    i = 2

    retval = []

    while i ** 2 <= Number:
        if Number % i == 0:
            retval.append(i)
            Number //= i
        else:
            i += 1

    retval.append(Number)

    return retval
    
def IsPerfect(Number):
    Range = int(math.sqrt(Number))
    total = 1
    i = 2

    while i <= Range:
        if Number % i == 0:
            total += (Number // i) + i
            i += 1
        else:
            i += 1
    
    if Range ** 2 == Number:
        total -= Range
    
    if total == Number:
        return True
    else:
        return False

def RecursiveEuclid(First, Second):
    if First % Second == 0:
        return Second
    else:
        return RecursiveEuclid(Second, First % Second)

def IterativeEuclid(First, Second):
    rey = 0

    while Second != 0:
        rey = First % Second
        First = Second
        Second = rey
    
    return First

def IterativeFibonacci(Range):
    oldValue = 0
    result = 1

    for i in range(1, Range):
        temp = result
        result = oldValue + result
        oldValue = temp

    return result

def RecursiveFibonacci(Range):
    if Range <= 1:
        return Range
    else:
        return RecursiveFibonacci(Range - 2) + RecursiveFibonacci(Range - 1)

def GiveRest(Value):
    nominals = [ 0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 1.0, 2.0, 5.0, 10.0, 20.0, 50.0, 100.0, 200.0 ]

    result = [  ]

    while Value > 0:

        Value = round(Value, 2)

        nominal = 0
        for i in nominals:
            if i > nominal and i <= Value:
                nominal = i
        Value -= nominal
        result.append(nominal)

    return result

def Power(Base, Exponent):
    if Exponent == 0:
        return 1
    elif Exponent % 2 == 1:
        return Base * Power(Base, Exponent - 1)
    else:
        a = Power(Base, Exponent // 2)
        return a ** 2

def FindRoot(LowerBound, UpperBound, Function):

    if Function(LowerBound) * Function(UpperBound) > 0:
        raise Exception

    while not math.isclose(abs(LowerBound - UpperBound), 0):
        midPoint = (LowerBound + UpperBound) / 2

        midPointValue = Function(midPoint)

        if math.isclose(midPointValue, 0):
            return midPoint
        elif midPointValue * Function(LowerBound) < 0:
            UpperBound = midPoint
        else:
            LowerBound = midPoint

    return midPoint
