/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#include "MorseCodeGenerator.h"

MorseCodeGenerator::MorseCodeGenerator(const std::shared_ptr<MorseCodeGeneratorConfiguration>& cfg)
    : configuration(cfg)
{
    // N/A
}

void MorseCodeGenerator::Send(std::string& value)
{
    auto result = Serialise(value);

    for (auto s : result)
    {
        switch (s)
        {
            case Dit:
                configuration->Transmit(configuration->DitLengthMs);
                configuration->NoTransmit(DitSpacing * configuration->DitLengthMs);
                break;
            case Dah:
                configuration->Transmit(DahDitRatio * configuration->DitLengthMs);
                configuration->NoTransmit(DitSpacing * configuration->DitLengthMs);
                break;
            case Char:
                configuration->NoTransmit(CharacterSpacing * configuration->DitLengthMs);
                break;
            case Word:
                configuration->NoTransmit(WordSpacing * configuration->DitLengthMs);
                break;
            default:
                throw;
        }
    }
}

std::vector<MorseCodeSignal> MorseCodeGenerator::Serialise(std::string& value)
{
    std::vector<MorseCodeSignal> result;

    // Trim leading/trailing ' ' characters (hard to believe we have to write this ourselves).
    std::size_t start = value.find_first_not_of(SPACE);
    std::size_t end = value.find_last_not_of(SPACE);
    auto trimmedValue = start == end ? std::string() : value.substr(start, end - start + 1);

    // Convert to lower case (even harder to believe it is not part of std::string).
    transform(trimmedValue.begin(), trimmedValue.end(), trimmedValue.begin(), 
        [](unsigned char c){ return std::tolower(c); });
    
    // Approximate the final vector size.
    result.reserve(trimmedValue.length() * (3 + CharacterSpacing) + WordSpacing);
    
    for(const auto c : trimmedValue)
    {
        if(map.find(c) == map.end()) continue;

        auto signal = map.at(c);

        for(const auto s : signal)
        {
            result.push_back(s);
        }

        result.push_back(Char);
    }

    result.push_back(Word);

    return result;
}
