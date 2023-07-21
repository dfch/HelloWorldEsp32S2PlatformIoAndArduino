/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#ifndef MorseCodeGenerator_h
#define MorseCodeGenerator_h

    #include <map>
    #include <vector>
    #include <memory>

    #include "MorseCode/MorseCodeSignal.h"
    #include "MorseCode/MorseCodeGeneratorConfiguration.h"

    class MorseCodeGenerator
    {
        private:
            const unsigned short DahDitRatio = 3;

            // Spacing between Dits/Dahs is 1 unit.
            const unsigned short DitSpacing = 1;

            // A character spacing is 3 units, but as we already inserted a single unit after the 
            // last character, we only need 2 more units.
            const unsigned short CharacterSpacing = 3 - DitSpacing;

            // A word spacing is 7 units, but as we already inserted a character spacing with 
            // 3 units after the last character, we only need 4 more units.
            const unsigned short WordSpacing = 7 - CharacterSpacing - DitSpacing;

            const char SPACE = ' ';

            const std::map<char, std::vector<MorseCodeSignal>> map = 
            {
                { 'a', { Dit, Dah } },
                { 'b', { Dah, Dit, Dit, Dit } },
                { 'c', { Dah, Dit, Dah, Dit } },
                { 'd', { Dah, Dit, Dit } },
                { 'e', { Dit } },
                { 'f', { Dit, Dit, Dah, Dit } },
                { 'g', { Dah, Dah, Dit } },
                { 'h', { Dit, Dit, Dit, Dit } },
                { 'i', { Dit, Dit } },
                { 'j', { Dit, Dah } },
                { 'k', { Dit, Dah, Dah, Dah } },
                { 'l', { Dit, Dah, Dit, Dit } },
                { 'm', { Dah, Dah } },
                { 'n', { Dah, Dit } },
                { 'o', { Dah, Dah, Dah } },
                { 'p', { Dit, Dah, Dah, Dit } },
                { 'q', { Dah, Dah, Dit, Dah } },
                { 'r', { Dit, Dah, Dit } },
                { 's', { Dit, Dit, Dit } },
                { 't', { Dah } },
                { 'u', { Dit, Dit, Dah } },
                { 'v', { Dit, Dit, Dit, Dah } },
                { 'w', { Dit, Dah, Dah } },
                { 'x', { Dah, Dit, Dit, Dah } },
                { 'y', { Dah, Dit, Dah, Dah } },
                { 'z', { Dah, Dah, Dit, Dit } },

                { '1', { Dit, Dah, Dah, Dah, Dah } },
                { '2', { Dit, Dit, Dah, Dah, Dah } },
                { '3', { Dit, Dit, Dit, Dah, Dah } },
                { '4', { Dit, Dit, Dit, Dit, Dah } },
                { '5', { Dit, Dit, Dit, Dit, Dit } },
                { '6', { Dah, Dit, Dit, Dit, Dit } },
                { '7', { Dah, Dah, Dit, Dit, Dit } },
                { '8', { Dah, Dah, Dah, Dit, Dit } },
                { '9', { Dah, Dah, Dah, Dah, Dit } },
                { '0', { Dah, Dah, Dah, Dah, Dah } },

                { SPACE, { Word } },
            };

            // Algorithm implementation -*- C++ -*-
            // Copyright (C) 2001-2018 Free Software Foundation, Inc.
            template<typename _InputIterator, typename _OutputIterator,
                typename _UnaryOperation>
            _OutputIterator
            transform(_InputIterator __first, _InputIterator __last,
                    _OutputIterator __result, _UnaryOperation __unary_op)
            {
                // concept requirements
                __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
                __glibcxx_function_requires(_OutputIteratorConcept<_OutputIterator,
                // "the type returned by a _UnaryOperation"
                __typeof__(__unary_op(*__first))>)
                __glibcxx_requires_valid_range(__first, __last);

                for (; __first != __last; ++__first, (void)++__result)
                    *__result = __unary_op(*__first);
                return __result;
            }
            
            const std::shared_ptr<MorseCodeGeneratorConfiguration> configuration;
            
        public:

            MorseCodeGenerator(const std::shared_ptr<MorseCodeGeneratorConfiguration>& cfg);

            std::vector<MorseCodeSignal> Serialise(std::string& value);

            void Send(std::string& value);
    };

#endif
