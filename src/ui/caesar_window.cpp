#include "caesar_window.h"

#include <gtkmm.h>

#include "../caesar/caesar.h"

namespace ciphers {
    CaesarWindow::~CaesarWindow() {
        // TODO: What do I even destroy here?
    }
    CaesarWindow::CaesarWindow(BaseObjectType * c_object, const Glib::RefPtr<Gtk::Builder> builder) : 
           CipherWindow(c_object, builder)  {
        // Cipher
        this->cipher = new Caesar();

        // Set buffers
        Gtk::TextView * text_IO = nullptr;
        this->builder->get_widget("caesarInputText", text_IO);
        this->input_buffer = text_IO->get_buffer();
        
        this->builder->get_widget("caesarOutputText", text_IO);
        this->output_buffer = text_IO->get_buffer();
        

        // Caesar Widget
        Gtk::Button * caesar_decrypt_button;
        this->builder->get_widget("caesarDecryptButton", caesar_decrypt_button);
        caesar_decrypt_button->signal_clicked().connect(std::function<void()>([&]{this->decrypt();}));

        Gtk::Button * caesar_encrypt_button;
        this->builder->get_widget("caesarEncryptButton", caesar_encrypt_button);
        caesar_encrypt_button->signal_clicked().connect(std::function<void()>([&]{this->encrypt();}));

        Gtk::Button * caesar_plus_button;
        this->builder->get_widget("caesarPlusJumpsButton", caesar_plus_button);
        caesar_plus_button->signal_clicked().connect(std::function<void()>([&]{this->changeCaesarJump(1);}));

        Gtk::Button * caesar_minus_button;
        this->builder->get_widget("caesarMinusJumpsButton", caesar_minus_button);
        caesar_minus_button->signal_clicked().connect(std::function<void()>([&]{this->changeCaesarJump(-1);}));

        Gtk::TextView * caesar_text_jumps;
        this->builder->get_widget("caesarJumpsNumberField", caesar_text_jumps);
        auto buffer = caesar_text_jumps->get_buffer();
        buffer->set_text("0");
    }

    void CaesarWindow::changeCaesarJump(const short & number_of_jumps) {
        Gtk::TextView * jumps_viewer;
        this->builder->get_widget("caesarJumpsNumberField", jumps_viewer);
        auto buffer = jumps_viewer->get_buffer();
        auto text = buffer->get_text(buffer->begin(), buffer->end());
        auto value = std::stoi(text);

        value += number_of_jumps;
        if (value > 26) {
            value = 1;
        } else if (value < 0) {
            value = 26;
        }
        static_cast<Caesar *>(this->cipher)->setJumps(value);
        

        text = std::to_string(value);
        buffer->set_text(text);
    }
};
