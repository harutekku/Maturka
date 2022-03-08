#include <algorithm>
#include <iterator>
#include <type_traits>
#include <vector>
#include <stdexcept>
#include <string>
#include <array>
#include <string_view>

#ifndef MATURA_LIB
#define MATURA_LIB

// Algorytmy pomocnicze - Pierwiastek kwadratowy oraz wartosc bezwgledna
namespace Utilities {
    template<typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>>>
    [[nodiscard]] constexpr auto Sqrt(T Number) -> long double {
        if (Number == 0)
            return 0;
        else if (Number < 0)
            return -1;
        else {
            long double result = Number / 2;
            for (size_t i = 0; i != 10; ++i)
                result -= (result * result - Number) / (2 * result);
            return result;
        }
    }

    template<typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>>>
    [[nodiscard]] constexpr auto Abs(T Number) noexcept -> T {
        return (Number >= 0)? Number : -Number;
    }
}

// Szyfr cezara
namespace Cipher {
    auto CaesarCipher(std::string& CipherText, int Offset) -> void;
}

// Algorytmy sortowania
namespace Sort {

    template<typename Iter>
    constexpr auto Merge(Iter First, Iter MidPoint, Iter Last) -> void {
        using Type = std::remove_reference_t<decltype(*First)>;
        
        const std::size_t size = std::distance(First, Last);

        Type* array = new Type[size];

        Iter i = First;
        Iter j = MidPoint;
        Type* first = array; 

        while (i != MidPoint && j != Last)
            if (*i <= *j)
                *first++ = std::move(*i++);
            else
                *first++ = std::move(*j++);

        std::move(i, MidPoint, first);
        std::move(j, Last, first);

        std::move(array, &array[size], First);

        delete[] array;
    }

    template<typename Iter>
    constexpr auto MergeSort(Iter First, Iter Last) -> void {
        if (std::size_t dist = std::distance(First, Last); dist > 1) {
            Iter midPoint = std::next(First, dist / 2);
            MergeSort(First, midPoint);
            MergeSort(midPoint, Last);
            Merge(First, midPoint, Last);
        }
    }

    template<typename Iter>
    [[nodiscard]] constexpr auto Partition(Iter First, Iter Last) -> Iter {
        Iter index = First;
        Iter pivot = Last - 1;

        for (Iter i = First; i != pivot; ++i)
            if (*i <= *pivot) {
                std::swap(*index, *i);
                ++index;
            }

        std::swap(*index, *pivot);

        return index;
    }

    template<typename Iter>
    constexpr auto QuickSort(Iter First, Iter Last) -> void {

        if (First < Last) {
            Iter i = Partition(First, Last);

            QuickSort(First, i);
            QuickSort(i + 1, Last);
        }
    }

    template<typename Iter>
    constexpr auto BubbleSort(Iter First, Iter Last) -> void {

        bool isSwapped = false;

        do {
            isSwapped = false;

            for (auto i = First; i != Last - 1; ++i)
                if (*i > *(i + 1)) {
                    std::swap(*i, *(i + 1));
                    isSwapped = true;
                }

        } while (isSwapped);
    }

    template<typename Iter>
    constexpr auto SelectionSort(Iter First, Iter Last) -> void {
        for (Iter i = First; i != Last; ++i)
            std::swap(*i, *std::min_element(i, Last));
    }

    template<typename Iter>
    constexpr auto InsertionSort(Iter First, Iter Last) -> void {
        for (Iter i = First + 1; i != Last; ++i)
            for (Iter j = i; j > First and *j < *(j - 1); --j)
                std::swap(*j, *(j - 1));
    }
}

// Algorytmy numeryczne
namespace Numeric {

    [[nodiscard]] auto ESieve(size_t Range) -> std::vector<size_t>;

    [[nodiscard]] auto Factorise(size_t Number) -> std::vector<size_t>;

    [[nodiscard]] constexpr auto RecursiveFibonacci(size_t Range) -> size_t {
        if (Range <= 1)
            return Range;
        else
            return RecursiveFibonacci(Range - 1) + RecursiveFibonacci(Range - 2);
    }

    [[nodiscard]] constexpr auto IterativeFibonacci(size_t Range) -> size_t {
        size_t oldValue = 0;
        size_t currentValue = 1;

        for (; Range != 1; --Range)
            oldValue = std::exchange(currentValue, currentValue + oldValue);

        return currentValue;
    }

    [[nodiscard]] constexpr auto IsPrime(size_t Number) -> bool {

        if (Number > 2 and !(Number % 2))
            return false;
        else if (Number > 3 and !(Number % 3))
            return false;

        size_t i = 5;

        while (i * i <= Number)
            if (!(Number % i))
                return false;
            else if (!(Number % (i + 2)))
                return false;
            else
                i += 6;

        return true;
    }
    
    [[nodiscard]] constexpr auto IsPerfect(size_t Number) -> bool {
        const size_t range = Utilities::Sqrt(Number);
        size_t sum = 1;
        size_t i = 2;

        while (i <= range) {
            if (!(Number % i))
                sum += Number / i + i;
            ++i;
        }

        if (range * range == Number)
            sum -= range;

        if (sum == Number)
            return true;
        else
            return false;
    }

    template<typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>>>
    [[nodiscard]] constexpr auto Power(T Base, size_t Exponent) -> T {
        if (Exponent == 0)
            return 1;
        else if (Exponent % 2)
            return Base * Power(Base, Exponent - 1);
        else {
            const auto retVal = Power(Base, Exponent / 2);
            return retVal * retVal;
        }    
    }

    template<typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
    [[nodiscard]] constexpr auto RecursiveEuclidGCD(T First, T Second) -> T {
        if (First % Second == 0)
            return Second;
        else
            return RecursiveEuclidGCD(Second, First % Second);
    }

    template<typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
    [[nodiscard]] constexpr auto IterativeEuclidGCD(T First, T Second) -> T {
        auto ray = First;

        while (Second != 0) {
            ray = First % Second;
            First = Second;
            Second = ray;
        }
        return First;
    }
    
    [[nodiscard]] constexpr auto FindRoot(long double LowerBracket, long double UpperBracket, long double (*Function)(long double RealArg)) -> long double {
        constexpr long double Epsilon = 0.000000000000001l;

        if (Function(LowerBracket) * Function(UpperBracket) > 0)
            throw std::logic_error{ "Bad bracket" };

        long double midPoint = 0.0l;
        while (Utilities::Abs(UpperBracket - LowerBracket) > Epsilon) {
            midPoint = (LowerBracket + UpperBracket) / 2;

            const auto midPointValue = Function(midPoint);
            
            if (Utilities::Abs(midPointValue) < Epsilon)
                return midPoint;
            else if (midPointValue * Function(LowerBracket) < 0)
                UpperBracket = midPoint;
            else
                LowerBracket = midPoint;
        }
        return midPoint;
    }

    [[nodiscard]] auto GiveReturn(long double Value) -> std::vector<long double>;
}

// Algorytmy na tekstach
namespace Text {
    template<typename Iter>
    [[nodiscard]] constexpr auto IsPalindrome(Iter First, Iter Last) -> bool {
        while (First < Last)
            if (*First++ != *--Last)
                return false;
        return true;
    }

    template<typename Iter>
    [[nodiscard]] constexpr auto MatchPattern(Iter First, Iter Last, Iter PatternFirst, Iter PatternLast) -> Iter {
        const size_t patternLength = std::distance(PatternFirst, PatternLast);
        const size_t dataLength = std::distance(First, Last);

        if (patternLength > dataLength)
            throw std::range_error{ "Pattern impossible to match => PatternSize < DataSize" };

        for (Iter i = First; i != Last - patternLength; ++i)
            if (*i == *PatternFirst) {
                const Iter occurence = i;
                Iter tempI = i;
                Iter j = PatternFirst;
                for (; j != PatternLast and *tempI == *j; ++tempI, ++j);

                if (j == PatternLast)
                    return occurence;
            }
        return Last;
    }
}

// Algorytmy szukania w zbiorach [wymog: polozenie konsekwetne w pamieci]
namespace Search {
    template<typename Iter, typename T>
    [[nodiscard]] constexpr auto BinarySearch(Iter First, Iter Last, T What) -> Iter {
        while (First < Last) {
        size_t midPoint = std::distance(First, Last) / 2;

        if (*(First + midPoint) < What)
            First += midPoint + 1;
        else
            Last = (First + midPoint);
        }
        return Last;
    }

    template<typename Iter, typename T>
    [[nodiscard]] constexpr auto LinearSearch(Iter First, Iter Last, T What) -> Iter {
        while (First != Last && *First++ != What) ++First;
        return First;
    }
}

#endif
