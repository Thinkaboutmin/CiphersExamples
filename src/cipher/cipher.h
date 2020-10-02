#include <string>

#ifndef CIPHER_H
#define CIPHER_H

namespace ciphers {
    class Cipher {
    public:
        std::string text;

        virtual std::string & encrypt() = 0;

        virtual std::string & decrypt() = 0;

        virtual ~Cipher() = default;

    protected:
        Cipher() = default;
    };
};

#endif