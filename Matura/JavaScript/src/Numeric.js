"use strict";

function ESieve(Range) {
    const indexes = [  ];
    const retVal = [  ];

    for (let i = 0; i != Range; ++i)
        indexes.push(true);

    const rangeSqrt = Math.floor(Math.sqrt(Range));

    for (let i = 2; i != rangeSqrt; ++i)
        if (indexes[i])
            for (let j = 2 * i; j < Range; j += i)
                indexes[j] = false;
    
    for (let i = 2; i != Range; ++i)
        if (indexes[i])
            retVal.push(i);

    return retVal;
}

function IsPrime(Number) {

    Number = Math.abs(Number);

    if (Number > 2 && Number % 2 == 0)
        return false;
    else if (Number > 3 && Number % 3 == 0)
        return false;
    
    let i = 5;

    while (i ** 2 <= Number)
        if (Number % i == 0)
            return false;
        else if (Number % (i + 2) == 0)
            return false;
        else
            i += 6

    return true;
}

function Factorise(Number) {

    let i = 2;

    const retVal = [  ];

    while (i ** 2 <= Number)
        if (Number % i == 0) {
            Number = Math.floor(Number / i);
            retVal.push(i);
        } else
            ++i;
    
    retVal.push(Number);
    
    return retVal;
}

function IsPerfect(Number) {
    let sum = 1;
    let Range = Math.floor(Math.sqrt(Number));
    let i = 2;

    while (i <= Range)
        if (Number % i == 0)
            sum += Number / i + i++;
        else
            ++i;

    if (Range ** 2 == Number)
        sum -= Range;

    if (sum == Number)
        return true;
    else
        return false;
}

function RecursiveEuclid(First, Second) {
    if (First % Second == 0)
        return Second;
    else
        return RecursiveEuclid(Second, First % Second);
}

function IterativeEuclid(First, Second) {
    let ray = 0;

    while (Second != 0) {
        ray = First % Second;
        First = Second;
        Second = First;
    }

    return First;
}

function RecursiveFibonacci(Range) {
    if (Range <= 1)
        return Range;
    else
        return RecursiveFibonacci(Range - 2) + RecursiveFibonacci(Range - 1);
}

function IterativeFibonacci(Range) {
    let second = 0;
    let retVal = 1;

    for (let i = 1; i != Range; ++i) {
        const oldValue = retVal;
        retVal = retVal + second;
        second = oldValue;
    }

    return retVal;
}

function GiveRest(Value) {
    const nominals = [ 0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 1.0, 2.0, 5.0, 10.0, 20.0, 50.0, 100.0, 200.0 ];

    const retVal = [  ];

    while (Value > 0) {
        let currentNominal = 0.0;

        for (const nominal of nominals)
            if (nominal > currentNominal && nominal <= Value)
                currentNominal = nominal;
        Value = Math.round((Value - currentNominal) * 100) / 100;
        retVal.push(currentNominal);
    }
    return retVal;
}

function Power(Base, Exponent) {
    if (Exponent == 0)
        return 1;
    else if (Exponent % 2 == 1)
        return Base * Power(Base, Exponent - 1);
    else {
        const retVal = Power(Base, Exponent / 2);
        return retVal ** 2;
    }
}

function FindRoot(LowerBound, UpperBound, Function) {

    const epsilon = 0.000000000001;

    if (Function(LowerBound) * Function(UpperBound) > 0)
        throw new Exception("Requirements not met");

    let midPoint = null;

    while (Math.abs(UpperBound - LowerBound) > epsilon) {
        midPoint = (LowerBound + UpperBound) / 2;

        const midPointValue = Function(midPoint);

        if (Math.abs(midPointValue) < epsilon)
            return midPoint;
        else if (Function(LowerBound) * midPointValue < 0)
            UpperBound = midPoint;
        else
            LowerBound = midPoint;
    }
    return midPoint;
}
