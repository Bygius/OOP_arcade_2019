/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <string>
#include <memory>

template <typename T>
class DLLoader {
    public :
        DLLoader(const std::string &lib_name);
        ~DLLoader();
        std::unique_ptr <T>getInstance();
        void loadLibrary();
        void loadLibrary(const std::string &lib_name);
        void closeLibrary();
        std::string _lib_name;

    private:
        bool isLoaded(void);

        void * _handle;
};

#endif /* !DLLOADER_HPP_ */
