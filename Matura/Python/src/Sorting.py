

def Merge(Array, LowerBound, midPoint, UpperBound):
    sizeLeft = midPoint + 1 - LowerBound
    sizeRight = UpperBound - midPoint

    leftArray = [0] * (sizeLeft)
    rightArray = [0] * (sizeRight)

    for i in range(sizeLeft):
        leftArray[i] = Array[LowerBound + i]

    for i in range(sizeRight):
        rightArray[i] = Array[midPoint + 1 + i]

    iLeft = 0
    iRight = 0
    iMain = LowerBound

    while iLeft < sizeLeft and iRight < sizeRight:
        if leftArray[iLeft] <= rightArray[iRight]:
            Array[iMain] = leftArray[iLeft]
            iLeft += 1
            iMain += 1
        else:
            Array[iMain] = rightArray[iRight]
            iRight += 1
            iMain += 1

    while iLeft < sizeLeft:
        Array[iMain] = leftArray[iLeft]
        iLeft += 1
        iMain += 1
    
    while iRight < sizeRight:
        Array[iMain] = rightArray[iRight]
        iRight += 1
        iMain += 1

def MergeSort(Array, LowerBound, UpperBound):
    if LowerBound < UpperBound:
        midPoint = (LowerBound + UpperBound) // 2
        MergeSort(Array, LowerBound, midPoint)
        MergeSort(Array, midPoint + 1, UpperBound)
        Merge(Array, LowerBound, midPoint, UpperBound)

def Partition(Array, LowerBound, UpperBound):
    index = LowerBound
    pivot = Array[UpperBound]

    for i in range(LowerBound, UpperBound):
        if (Array[i] <= pivot):
            temp = Array[i]
            Array[i] = Array[index]
            Array[index] = Array[i]
            index += 1
    
    temp = Array[UpperBound]
    Array[UpperBound] = Array[index]
    Array[index] = temp

    return index

def QuickSort(Array, LowerBound, UpperBound):
    if LowerBound < UpperBound:
        i = Partition(Array, LowerBound, UpperBound)
        QuickSort(Array, LowerBound, i - 1)
        QuickSort(Array, i + 1, UpperBound)

def BubbleSort(Array, LowerBound, UpperBound):
    isSwapped = False

    while True:

        isSwapped = False

        for i in range(LowerBound, UpperBound - 1):
            if Array[i] >= Array[i + 1]:
                temp = Array[i]
                Array[i] = Array[i + 1]
                Array[i + 1] = temp
                isSwapped = True

        if not isSwapped:
            break

def InsertionSort(Array, LowerBound, UpperBound):
    for i in range(LowerBound + 1, UpperBound):
        j = i
        while j > 0 and Array[j - 1] > Array[j]:
            temp = Array[j - 1]
            Array[j - 1] = Array[j]
            Array[j] = temp
            j -= 1

def SelectionSort(Array, LowerBound, UpperBound):
    for i in reversed(range(LowerBound, UpperBound)):
        iMax = i
        for j in range(LowerBound, i):
            if Array[iMax] <= Array[j]:
                iMax = j
        temp = Array[i]
        Array[i] = Array[iMax]
        Array[iMax] = temp

