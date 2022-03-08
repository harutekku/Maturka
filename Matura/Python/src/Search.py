def BinarySearch(Array, LowerBound, UpperBound, What):

    while LowerBound != UpperBound:
        mid = (LowerBound + UpperBound) // 2
        if Array[mid] < What:
            LowerBound = mid
        elif Array[mid] > What:
            UpperBound = mid - 1
        else:
            return mid
    
    return None

