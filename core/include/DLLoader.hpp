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
        DLLoader(const std::string &path, const std::string &name);
        ~DLLoader();
        std::unique_ptr <T>getInstance();
        void loadLibrary();
        void loadLibrary(const std::string &lib_name);
        void closeLibrary();
        std::string getLibPath();
        std::string getLibName();

    private:


        bool isLoaded(void);
        void * _handle;
        const std::string _lib_path;
        std::string _lib_name;
};

#endif /* !DLLOADER_HPP_ */
