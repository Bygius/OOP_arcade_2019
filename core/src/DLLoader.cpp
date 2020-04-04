/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#include "DLLoader.hpp"
#include <dlfcn.h>
#include "../../include/Arcade_interfaces.hpp"
#include "Error.hpp"

template<typename T>
DLLoader<T>::DLLoader(const std::string &path, const std::string &name) : _lib_path(path), _lib_name(name)
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
    std::unique_ptr<T> (*create)();

    if (isLoaded() == false)
        loadLibrary();
    create = (std::unique_ptr<T>(*)())dlsym(_handle, "createLib");
    if (create == nullptr)
        throw LibError("DLLoader : Cannot get entrypoint in library:" + _lib_name);
    return create();
}

template<typename T>
void DLLoader<T>::loadLibrary(void)
{
    if (isLoaded() == true)
        closeLibrary();
    _handle = dlopen(_lib_name.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    if (!_handle)
        throw LibError(std::string(dlerror()));
}

template<typename T>
void DLLoader<T>::loadLibrary(const std::string &lib_name)
{
    if (isLoaded() == true)
       closeLibrary();
    _handle = dlopen(lib_name.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    if (!_handle)
        throw LibError("DLLoader : " + std::string(dlerror()));
    _lib_name = lib_name;
}

template<typename T>
void DLLoader<T>::closeLibrary()
{
    if (isLoaded() == true)
        dlclose(_handle);
    _handle = NULL;
}

template<typename T>
bool DLLoader<T>::isLoaded(void)
{
    return (_handle == NULL) ? false : true;
}

template<typename T>
std::string DLLoader<T>::getLibName(void)
{
    return _lib_name;
}

template<typename T>
std::string DLLoader<T>::getLibPath(void)
{
    return _lib_path;
}

template class DLLoader<IDisplayModule>;
template class DLLoader<IGameModule>;
