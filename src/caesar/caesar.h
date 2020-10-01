#include <string>
#include <set>

#include "../cipher/cipher.h"

#ifndef CAESAR_H
#define CAESAR_H

namespace ciphers {
    /*
    * Caesar cipher algorithm for strings.
    */
    class Caesar : public Cipher {
    public:
        const unsigned short & jumps = _jumps;

    private:

        unsigned short _jumps = 0;

    public:
        Caesar(unsigned short & jumps);

        Caesar(unsigned short && jumps);

        Caesar() = default;

        Caesar & setJumps(unsigned short jumps);

        Caesar & setReverse(bool is_reverse);

        std::string & encrypt() override;

        std::string & decrypt() override;

    private:
        std::string & linearEncryptString();

        std::string & multiLinearEncryptString();

        std::string & linearDecryptString();

        std::string & multiLinearDecryptString();
    };
};

#endif