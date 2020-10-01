#include <string>
#include <gtkmm.h>

#include "../cipher/cipher.h"

#ifndef CIPHER_WINDOW_H
#define CIPHER_WINDOW_H

namespace ciphers {
    class CipherWindow : public Gtk::ApplicationWindow {
    public:
        virtual void decrypt();

        virtual void encrypt();

        virtual ~CipherWindow();

    protected:
        Cipher * cipher = nullptr;
        Glib::RefPtr<Gtk::TextBuffer> input_buffer;

        Glib::RefPtr<Gtk::TextBuffer> output_buffer;

        const Glib::RefPtr<Gtk::Builder> builder;

        CipherWindow(BaseObjectType * c_object, const Glib::RefPtr<Gtk::Builder> builder);
    };
};

#endif