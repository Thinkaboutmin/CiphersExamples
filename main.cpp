#include <iostream>

#include "src/ui/ciphers_menu_window.h"

int main(int argc, char** argv) {
    ciphers::CiphersMenuWindow window(argc, argv);
    window.start();

    return 0;
}
