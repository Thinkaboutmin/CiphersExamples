#include <gtkmm.h>
#include <unordered_map>
#include <string>

#include "ciphers_enum.h"
#include "../cipher/cipher.h"
#include "cipher_window.h"

#ifndef CIPHERS_MENU_WINDOW_H
#define CIPHERS_MENU_WINDOW_H

namespace ciphers {
    class CiphersMenuWindow {
    /*
     * Variables
     */
    public:
        Glib::RefPtr<Gtk::Builder> builder;

    private:
        CipherType cipher_in_use = CipherType::NONE;

        std::unordered_map<std::string, CipherWindow *> ciphers_windows;

        Glib::RefPtr<Gtk::Application> app;

    /*
     * Functions
     */
    public:
        CiphersMenuWindow(int, char **);

        void openCipherWindow();

        void start();
    };
};

#endif