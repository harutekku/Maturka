"use strict";

function BinarySearch(Array, LowerBound, UpperBound, What) {

    while (LowerBound != UpperBound) {
        const midPoint = Math.floor((LowerBound + UpperBound) / 2);
        if (Array[midPoint] < What)
            LowerBound = midPoint;
        else if (Array[midPoint] > What)
            UpperBound = midPoint - 1;
        else
            return midPoint;
    }
    return null;
}