"use strict";

function Merge(Array, First, MidPoint, Last) {
    const sizeLeft = MidPoint + 1 - First;
    const sizeRight = Last - MidPoint;

    const leftArray = [  ];
    const rightArray = [  ];

    for (let i = 0; i != sizeLeft; ++i)
        leftArray.push(Array[First + i]);

    for (let i = 0; i != sizeRight; ++i)
        rightArray.push(Array[MidPoint + 1 + i]);

    let iLeft = 0;
    let iRight = 0;
    let iMain = First;

    while (iLeft != sizeLeft && iRight != sizeRight)
        if (leftArray[iLeft] <= rightArray[iRight])
            Array[iMain++] = leftArray[iLeft++];
        else
            Array[iMain++] = rightArray[iRight++];

    while (iLeft != sizeLeft)
        Array[iMain++] = leftArray[iLeft++];

    while (iRight != sizeRight)
        Array[iMain++] = rightArray[iRight++];
}

function MergeSort(Array, First, Last) {
    if (First < Last) {
        const mid = Math.floor((First + Last) / 2);

        MergeSort(Array, First, mid);
        MergeSort(Array, mid + 1, Last);
        Merge(Array, First, mid, Last);
    }
}

function Partition(Array, First, Last) {

    let index = First;
    let pivot = Last - 1;

    for (let i = First; i != pivot; ++i)
        if (Array[i] < Array[pivot]) {
            const temp = Array[i];
            Array[i] = Array[index];
            Array[index];
            ++index;
        }
    
    const temp = Array[pivot];
    Array[pivot] = Array[index]
    Array[index] = temp;

    return index;
}

function QuickSort(Array, First, Last) {
    if (First < Last) {
        const pivot = Partition(Array, First, Last);
        QuickSort(Array, First, pivot);
        QuickSort(Array, pivot + 1, Last);
    }
}

// The "Dumb ones"

function BubbleSort(Array, LowerBound, UpperBound) {
    let isSwapped = false;

    do {
        isSwapped = false;
        for (let i = LowerBound; i < UpperBound - 1; ++i)
            if (Array[i] <= Array[i + 1]) {
                const temp = Array[i];
                Array[i] = Array[i + 1];
                Array[i + 1] = temp;
                isSwapped = true;
            }


    } while (isSwapped);
}

function InsertionSort(Array, LowerBound, UpperBound) {
    for (let i = LowerBound + 1; i != UpperBound; ++i)
        for (let j = i; j > 0 && Array[j - 1] > Array[j]; --j) {
            const temp = Array[j - 1];
            Array[j - 1] = Array[j];
            Array[j] = temp;
        }
}

function SelectionSort(Array, LowerBound, UpperBound) {
    for (let i = LowerBound; i != UpperBound; ++i) {
        let minIndex = i;
        for (let j = i; j != UpperBound; ++j)
            if (Array[j] < Array[minIndex])
                minIndex = j;
        const temp = Array[i];
        Array[i] = Array[minIndex];
        Array[minIndex] = temp;
    }
}
