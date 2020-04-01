/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#include "DLLoader.hpp"
#include <dlfcn.h>
#include "../../include/Arcade_interfaces.hpp"


template<typename T>
DLLoader<T>::DLLoader(const std::string &lib_name) : _lib_name(lib_name)
{
    _handle = NULL;
}

template<typename T>
DLLoader<T>::~DLLoader()
{
    closeLibrary();
}

template<typename T>
std::unique_ptr<T> DLLoader<T>::getInstance()
{
    std::unique_ptr<T> ret;
    std::unique_ptr<T> (*create)();

    if (isLoaded() == false)
        loadLibrary();
    create = (std::unique_ptr<T>(*)())dlsym(_handle, "createLib");
    if (create == nullptr) {
         std::cout << this->_lib_name << "\n";
         std::cout << "Cannot open library: " << dlerror() << '\n';
         exit(84);
    }
    ret = create();
        //throw
    return ret;
}

template<typename T>
void DLLoader<T>::loadLibrary(void)
{
    if (isLoaded() == true)
        closeLibrary();
    _handle = dlopen(_lib_name.c_str(), RTLD_LAZY | RTLD_GLOBAL);

    if (!_handle) {
        std::cout << "Cannot open library: " << dlerror() << '\n';
        exit(84);

    }
}

template<typename T>
void DLLoader<T>::closeLibrary()
{
    if (isLoaded() == true)
        dlclose(_handle);
    _handle = NULL;
}


template<typename T>
void DLLoader<T>::loadLibrary(const std::string &lib_name)
{
    if (isLoaded() == true)
    {
       closeLibrary();
    }
    _handle = dlopen(lib_name.c_str(), RTLD_LAZY | RTLD_GLOBAL);

    if (!_handle) {
        //throw
        exit(81);

    }
    this->_lib_name = lib_name;
}

template<typename T>
bool DLLoader<T>::isLoaded(void)
{
    return (_handle == NULL) ? false : true;
}

template class DLLoader<IDisplayModule>;
template class DLLoader<IGameModule>;