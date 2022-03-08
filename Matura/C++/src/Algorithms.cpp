#include "../include/Algorithms.hpp"

[[nodiscard]] auto Numeric::ESieve(size_t Range) -> std::vector<size_t> {

    const size_t rangeSqrt = Utilities::Sqrt(Range);

    std::vector<bool> primesPoll(Range, true);

    std::vector<size_t> retVal;

    for (size_t i = 2u; i < rangeSqrt; ++i)
        if (primesPoll[i])
            for (size_t j = i * 2; j < Range; j += i)
                primesPoll[j] = false;

    for (size_t i = 2u; i != primesPoll.size(); ++i)
        if (primesPoll[i])
            retVal.push_back(i);

    return retVal;
}

[[nodiscard]] auto Numeric::Factorise(size_t Number) -> std::vector<size_t> {
    const size_t range = Utilities::Sqrt(Number);

    std::vector<size_t> retVal;

    size_t i = 2u;

    while (i <= range)
        if (!(Number % i)) {
            retVal.push_back(i);
            Number /= i;
        } else
            ++i;

    retVal.push_back(Number);

    return retVal;
}

[[nodiscard]] auto Numeric::GiveReturn(long double Value) -> std::vector<long double> {
    
    static constexpr std::array nominals{ 1u, 2u, 5u, 10u, 20u, 50u, 100u, 200u, 500u, 1000u, 2000u, 5000u, 10000u, 20000u, 50000u };
    size_t actualValue = Value * 100;

    std::vector<long double> retVal{  };

    while (actualValue != 0) {
        unsigned int nominal = 0u;

        for (unsigned i : nominals)
            if (i <= actualValue and i > nominal)
                nominal = i;

        actualValue -= nominal;

        switch (nominal) {
            case 1u:
                retVal.push_back(.01l);
                break;
            case 2u:
                retVal.push_back(.02l);
                break;
            case 5u:
                retVal.push_back(.05l);
                break;
            case 10u:
                retVal.push_back(.1l);
                break;
            case 20u:
                retVal.push_back(.2l);
                break;
            case 50u:
                retVal.push_back(.5l);
                break;
            case 100u:
                retVal.push_back(1.0l);
                break;
            case 200u:
                retVal.push_back(2.0l);
                break;
            case 500u:
                retVal.push_back(5.0l);
                break;
            case 1000u:
                retVal.push_back(10.0l);
                break;
            case 2000u:
                retVal.push_back(20.0l);
                break;
            case 5000u:
                retVal.push_back(50.0l);
                break;
            case 10000u:
                retVal.push_back(100.0l);
                break;
            case 20000u:
                retVal.push_back(200.0l);
                break;
            case 50000u:
                retVal.push_back(500.0l);
                break;
        }
    }
    
    return retVal;
}

auto Cipher::CaesarCipher(std::string& CipherText, int Offset) -> void {
    for (auto& ch : CipherText) {
        if (ch >= 'A' && ch <= 'Z')
            ch = (ch + Offset - 'A') % 26 + 'A';
        else if (ch >= 'a' && ch <= 'z')
            ch = (ch + Offset - 'a') % 26 + 'a';
        else
            continue;
    }
}
