#include "cipher_window.h"

namespace ciphers {
    void CipherWindow::decrypt() {
        this->cipher->text = this->input_buffer->get_text();

        this->cipher->decrypt();

        this->output_buffer->set_text(this->cipher->text);
    }

    void CipherWindow::encrypt() {
        this->cipher->text = this->input_buffer->get_text();
        
        this->cipher->encrypt();

        this->output_buffer->set_text(this->cipher->text);
    }

    CipherWindow::CipherWindow(BaseObjectType * c_object, const Glib::RefPtr<Gtk::Builder> builder) 
        : builder(builder), Gtk::ApplicationWindow(c_object) {}

    CipherWindow::~CipherWindow() {
        if (this->cipher != nullptr) {
            delete this->cipher;
        }
    }
};