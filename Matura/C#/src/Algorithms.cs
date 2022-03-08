using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using Algorithms;



namespace Algorithms {

    class Cipher {
        public static string CaesarCipher(string Cryptograme, int Offset, bool IsEncoding) {

            if (Offset == 0)
                return Cryptograme;
            else if (Offset > 0)
                Offset %= 26;
            else if (Offset < 0)
                Offset %= -26;

            var decodingString = new StringBuilder(Cryptograme.ToLower());

            for (var i = 0; i < decodingString.Length; ++i)
            {
                var decodedChar = Convert.ToInt32(decodingString[i]);

                decodedChar = 97 + (IsEncoding? ((decodedChar - 97) + Offset) : ((decodedChar - 97) - Offset)) % 26;
                
                decodingString[i] = Convert.ToChar(decodedChar);
            }

            return decodingString.ToString();
        }
    }

    class Utilities {
        public static void Swap<T>(ref T First, ref T Second) {
            T temporary = First;
            First = Second;
            Second = temporary;
        }

        public static T Exchange<T>(ref T First, T NewValue) {
            var oldValue = First;
            First = NewValue;
            return oldValue;
        }
    }

    class Sort {
        internal static uint Partition<T>(ref T[] Array, uint LowerBound, uint UpperBound) where T : IComparable<T> {
            var index = LowerBound;
            var pivot = Array[UpperBound];

            for (var i = LowerBound; i < UpperBound; ++i) {
                if (Array[i].CompareTo(pivot) < 0) {
                    Utilities.Swap(ref Array[i], ref Array[index]);
                    ++index;
                }
            }

            Utilities.Swap(ref Array[UpperBound], ref Array[index]);
            return index;
        }

        public static void QuickSort<T>(ref T[] Array, uint LowerBound, uint UpperBound) where T : IComparable<T> {
            if (LowerBound < UpperBound) {
                uint partitionIndex = Partition(ref Array, LowerBound, UpperBound);
                QuickSort(ref Array, LowerBound, partitionIndex - 1);
                QuickSort(ref Array, partitionIndex + 1, UpperBound);
            }
        }
    
        public static void BubbleSort<T>(ref T[] Array, uint LowerBound, uint UpperBound) where T : IComparable<T> {
            bool isSwapped;

            do {
                isSwapped = false;

                for (var i = LowerBound; i < UpperBound - 1; ++i)
                    if (Array[i].CompareTo(Array[i + 1]) > 0) {
                        Utilities.Swap(ref Array[i], ref Array[i + 1]);
                        isSwapped = true;
                    }
            } while (isSwapped);
        }

        public static void InsertionSort<T>(ref T[] Array, uint LowerBound, uint UpperBound) where T : IComparable<T> {
            for (var i = LowerBound + 1; i < UpperBound; ++i)
                for (var j = i; j > 0 && Array[j - 1].CompareTo(Array[j]) > 0; --j)
                    Utilities.Swap(ref Array[j - 1], ref Array[j]);
        }

        public static void SelectionSort<T>(ref T[] Array, uint LowerBound, uint UpperBound) where T : IComparable<T> {
            for (var i = UpperBound - 1; i != LowerBound; --i)
                Utilities.Swap(ref Array[i], ref Array[Search.FindMax(in Array, LowerBound, i)]);
        }

        
        internal static void Merge<T>(ref T[] Array, uint LowerBound, uint MidPoint, uint UpperBound) where T : IComparable<T> {
            uint leftArraySize = MidPoint + 1 - LowerBound;
            uint rightArraySize = UpperBound - MidPoint;

            T[] leftArray = new T[leftArraySize];
            T[] rightArray = new T[rightArraySize];

            for (var i = 0u; i < leftArraySize; ++i)
                leftArray[i] = Array[LowerBound + i];
            for (var i = 0u; i < rightArraySize; ++i)
                rightArray[i] = Array[MidPoint + 1 + i];

            var rightArrayIndex = 0u;
            var leftArrayIndex = 0u;
            var mainArrayIndex = LowerBound;

            while (leftArrayIndex < leftArraySize && rightArrayIndex < rightArraySize)
                if (leftArray[leftArrayIndex].CompareTo(rightArray[rightArrayIndex]) <= 0)
                    Array[mainArrayIndex++] = leftArray[leftArrayIndex++];
                else 
                    Array[mainArrayIndex++] = rightArray[rightArrayIndex++];
            

            while (leftArrayIndex < leftArraySize)
                Array[mainArrayIndex++] = leftArray[leftArrayIndex++];


            while (rightArrayIndex < rightArraySize)
                Array[mainArrayIndex++] = rightArray[rightArrayIndex++];
        }

        public static void MergeSort<T>(ref T[] Array, uint LowerBound, uint UpperBound) where T : IComparable<T> {
            if (LowerBound < UpperBound) {
                var midPoint = (LowerBound + UpperBound) / 2;

                MergeSort(ref Array, LowerBound, midPoint);
                MergeSort(ref Array, midPoint + 1, UpperBound);
                Merge(ref Array, LowerBound, midPoint, UpperBound);
            }
        }


    }

    class Numeric {
        public static List<uint> ESieve(uint Number) {

            var indexes = new bool[Number];

            var numberRoot = Math.Sqrt(d: Number);

            for (var i = 0u; i < Number; ++i)
                indexes[i] = true;    
            
            for (var i = 2u; i < numberRoot; ++i)
                if (indexes[i] == true)
                    for (var j = 2 * i; j < Number; j += i)
                        indexes[j] = false;

            var result = new List<uint>();

            for (var i = 0u; i < Number; ++i)
                if (indexes[i] == true)
                    result.Add(i);

            return result;
        }

        public static List<int> Factorise(int Number) {

            var result = new List<int>();

            int i = 2;
            
            while (i * i <= Number)
                if (Number % i == 0) {
                    result.Add(i);
                    Number /= i;
                } else
                    ++i;
                

            result.Add(Number);

            return result;
        }

        public static uint RecursiveFibonacci(uint Range) {
            if (Range <= 1)
                return Range;
            else
                return RecursiveFibonacci(Range - 1) + RecursiveFibonacci(Range - 2);
        }

        public static uint IterativeFibonacci(uint Range) {
            
            var oldValue = 0u;

            var result = 1u;

            for (var i = 1u; i != Range; ++i) {
                oldValue = Utilities.Exchange(ref result, oldValue + result);
            }

            return result;
        }

        public static bool IsPrime(uint Number) {
            if (Number > 2 && Number % 2 == 0)
                return false;
            else if (Number > 3 && Number % 3 == 0)
                return false;


            uint i = 5;

            while (i * i <= Number)
                if (Number % i == 0)
                    return false;
                else if (Number % (i + 2) == 0)
                    return false;
                else
                    i += 6;
            return true;
        }

        public static bool IsPerfect(uint Number) {
            var range = (uint)Math.Sqrt(Number);
            
            var i = 2u;

            var sum = 1u;

            while (i <= range)
                if (Number % i == 0)
                    sum += (Number / i) + i++;
                else
                    ++i;

            if (range * range == Number)
                sum -= range;

            if (sum == Number)
                return true;
            else
                return false;
        }

        public static ulong Power(uint Base, uint Exponent) {
            if (Exponent == 0u)
                return 1u;
            else if (Exponent % 2 == 1u)
                return Base * Power(Base, Exponent - 1);
            else {
                var result = Power(Base, Exponent / 2);

                return result * result;
            }
        }

        public static int RecursiveEuclidGCD(int First, int Second) {
            if (First % Second == 0)
                return Second;
            else
                return RecursiveEuclidGCD(Second, First % Second);
        }

        public static int IterativeEuclidGCD(int First, int Second) {

            var ray = 0;

            while (Second != 0) {
                ray = First % Second;
                First = Second;
                Second = ray;
            }

            return First;
        }

        public static decimal FindRoot(decimal LowerBound, decimal UpperBound, Func<decimal, decimal> Function) {

            var epsilon = 0.0000000000000001M;


            if (Function(LowerBound) * Function(UpperBound) > 0)
                throw new Exception("Funkcja nie spełnia założeń");
            
            var midPoint = 0.0M;

            while (Math.Abs(UpperBound - LowerBound) > epsilon) {

                midPoint = (LowerBound + UpperBound) / 2;

                var midPointValue = Function(midPoint);

                if (Math.Abs(midPointValue) < epsilon)
                    return midPoint;
                else if (midPointValue * Function(LowerBound) < 0)
                    UpperBound = midPoint;
                else
                    LowerBound = midPoint;
            }
            return midPoint;
        }

        public static List<decimal> GiveReturn(decimal Value) {

            decimal[] nominals = { 0.01M, 0.02M, 0.05M, 0.1M, 0.2M, 0.5M, 1.0M, 2.0M, 5.0M, 10.0M, 20.0M, 50.0M, 100.0M, 200.0M };

            List<decimal> result = new List<decimal>();

            while (Value > 0.0M) {

                decimal nominal = 0.0M;

                foreach (var i in nominals)
                    if (i <= Value && i > nominal)
                        nominal = i;
                
                Value -= nominal;
                result.Add(nominal);
            } 
            return result;
        }
    }

    class Text {
        public static bool IsWordPalindrome(string Candidad) {
            
            int i = 0;
            int j = Candidad.Length - 1;

            while (i < j) {
                if (Candidad[i] != Candidad[j])
                    return false;
                
                ++i;
                --j;
            }
            return true;
        }

        public static List<uint> MatchPattern(string Data, string Pattern) {
            
            var result = new List<uint>();

            var j = 0u;
            
            var occurence = 0u;

            for (var i = 0u; i < Data.Length; ++i) {

                if (Data[(int)i] == Pattern[0]) {
                    occurence = i;
                    for (j = 0u; j < Pattern.Length && Data[(int)i] == Pattern[(int)j]; ++i, ++j);
                }
                if (j == Pattern.Length)
                    result.Add(occurence);
                occurence = 0u;    
                j = 0u;
            }

            return result;  
        }
    }
        
    class Search {
        public static uint BinarySearch<T>(in T[] Array, uint Size, in T What) where T : IComparable<T>, IComparable {
            uint low = 0u;
            uint high = Size - 1;
            uint mid = 0u;

            while (low != high) {
                mid = (low + high) / 2;

                if (Array[mid].CompareTo(What) > 0)
                    high = mid - 1;
                else if (Array[mid].CompareTo(What) < 0)
                    low = mid;
                else
                    return mid;
            }
            return Size;
        }
        public static uint LinearSearch<T>(in T[] Array, uint Size, T What) where T : IComparable<T> {
            for (var i = 0u; i < Size; ++i)
                if (Array[i].CompareTo(What) == 0)
                    return i;

            return Size;
        }

        public static uint FindMax<T>(in T[] Array, uint LowerBound, uint UpperBound) where T : IComparable<T> {
            
            var maxIndex = 0u;
            
            for (var i = LowerBound; i < UpperBound; ++i)
                if (Array[i].CompareTo(Array[maxIndex]) >= 0)
                    maxIndex = i;
            return maxIndex;
        }
    }
}
