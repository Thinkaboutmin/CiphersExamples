cmake_minimum_required(VERSION 3.0.0)

project(ciphers VERSION 0.1.0)

include(FindPkgConfig)
if (!PKG_CONFIG_FOUND)
    message(FATAL_ERROR "Could not find Pkg Config")
endif()

pkg_check_modules(GTKMM gtkmm-3.0)

if(!GTKMM_FOUND)
    message(FATAL_ERROR "Could not find gtk mm")
endif()

add_executable(ciphers main.cpp src/caesar/caesar.cpp src/ui/cipher_window.cpp src/ui/ciphers_menu_window.cpp src/ui/caesar_window.cpp)
target_include_directories(ciphers PUBLIC ${GTKMM_INCLUDE_DIRS})
target_link_libraries(ciphers ${GTKMM_LIBRARIES})
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
