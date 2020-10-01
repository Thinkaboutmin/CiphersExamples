#include <functional>

#include "ciphers_menu_window.h"
#include "../caesar/caesar.h"
#include "caesar_window.h"

namespace ciphers {
    CiphersMenuWindow::CiphersMenuWindow(int argc, char ** argv) {
        this->app = Gtk::Application::create(argc, argv, "org.ciphers");
        this->builder = Gtk::Builder::create_from_file("../glade_ui/ui.glade");

        CipherWindow * caesar_window = nullptr;
        this->builder->get_widget_derived("caesarCipherWindow", caesar_window);
        this->ciphers_windows["caesar"] = caesar_window;

        // Ciphers menu
        Gtk::Button * caesar_button;
        this->builder->get_widget("caesarCipherButton", caesar_button);

        caesar_button->signal_clicked().connect(
            std::function<void()>([&](){this->openCipherWindow();})
        );
    }

    void CiphersMenuWindow::start() {
        Gtk::Window * cipher_menu = nullptr;
        this->builder->get_widget("ciphersWindow", cipher_menu);
        this->app->run(*cipher_menu);
    }    

    void CiphersMenuWindow::openCipherWindow() {
        switch(this->cipher_in_use) {
            case CipherType::NONE:
                break;

            case CipherType::CAESAR: {
                this->ciphers_windows["caesar"]->show();
                break;
            }
        }
    }
};