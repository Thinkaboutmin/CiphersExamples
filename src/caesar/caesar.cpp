#include "caesar.h"

namespace ciphers {
    #define FIRST_CHAR_UPPER 65
    #define LAST_CHAR_UPPER 90
    #define FIRST_CHAR_LOWER 97
    #define LAST_CHAR_LOWER 122

    Caesar::Caesar(unsigned short & jumps) {
        this->setJumps(jumps);
    }

    Caesar::Caesar(unsigned short && jumps) {
        this->setJumps(jumps);
    }

    Caesar & Caesar::setJumps(unsigned short jumps) {
        jumps %= 26;
        this->_jumps = jumps;

        return *this;
    }

    std::string & Caesar::encrypt() {
        return this->linearEncryptString();
    }

    std::string & Caesar::linearEncryptString() {
        for (std::string::size_type i = 0; i < this->text.size(); ++i) {
            short char_val = static_cast<short>(this->text[i]);
            bool upper = char_val >= FIRST_CHAR_UPPER && char_val <= LAST_CHAR_UPPER;
            bool lower = char_val >= FIRST_CHAR_LOWER && char_val <= LAST_CHAR_LOWER;
            if (!upper && !lower) {
                continue;
            }

            short result = char_val + this->_jumps;
            if (upper) {
                short go_back = result - LAST_CHAR_UPPER;
                if (go_back > 0) {
                    this->text[i] = static_cast<char>(go_back + FIRST_CHAR_UPPER - 1);
                } else {
                    this->text[i] = static_cast<char>(result);
                }
            } else {
                short go_back = result - LAST_CHAR_LOWER;
                if (go_back > 0) {
                    this->text[i] = static_cast<char>(go_back + FIRST_CHAR_LOWER - 1);
                } else {
                    this->text[i] = static_cast<char>(result);
                }
            }
        }

        return this->text;
    }

    std::string & Caesar::multiLinearEncryptString() {
        return this->text;
    }


    std::string & Caesar::decrypt() {
        return this->linearDecryptString();
    }

    std::string & Caesar::linearDecryptString()  {
        for (std::string::size_type i = 0; i < this->text.size(); ++i) {
            short char_val = static_cast<short>(this->text[i]);
            bool upper = char_val >= FIRST_CHAR_UPPER && char_val <= LAST_CHAR_UPPER;
            bool lower = char_val >= FIRST_CHAR_LOWER && char_val <= LAST_CHAR_LOWER;
            if (!upper && !lower) {
                continue;
            }
            short result = char_val - this->_jumps;
            if (upper) {
                short go_back = FIRST_CHAR_UPPER - result;
                if (go_back > 0) {
                    this->text[i] = static_cast<char>(LAST_CHAR_UPPER + 1 - go_back);
                } else {
                    this->text[i] = static_cast<char>(result);
                }
            } else {
                short go_back = FIRST_CHAR_LOWER - result;
                if (go_back > 0) {
                    this->text[i] = static_cast<char>(LAST_CHAR_LOWER + 1 - go_back);
                } else {
                    this->text[i] = static_cast<char>(result);
                }
            }
        }

        return this->text;
    }

    std::string & Caesar::multiLinearDecryptString() {
        return this->text;
    }
};