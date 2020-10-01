#include <gtkmm.h>

#include "cipher_window.h"

#ifndef CAESAR_WINDOW_H
#define CAESAR_WINDOW_H

namespace ciphers {
    class CaesarWindow : public CipherWindow {
    public:
        CaesarWindow(BaseObjectType * c_object, const Glib::RefPtr<Gtk::Builder> builder);
        ~CaesarWindow();

    private:
        void changeCaesarJump(const short & number_of_jumps);


    };
};

#endif