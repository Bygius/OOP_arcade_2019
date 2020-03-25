/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Lib
*/

#include "Lib.hpp"
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <memory>
#include <dlfcn.h>
#include <unistd.h>
#include <algorithm>

#include "../../include/Arcade_interfaces.hpp"

void Lib::PrintAllLib(void) const
{
    for(auto &it : this->lib_list) {
        std::cout << it.c_str() << std::endl;
    }
}

bool Lib::RefreshLibList(void)
{
    struct dirent *entry;
    DIR *dir = opendir(this->lib_path.c_str());

    if (dir == NULL) {
        return EXIT_FAILURE;
    }
    this->lib_list.clear();
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, "lib_arcade_") && strstr(entry->d_name, ".so"))
            // this->lib_list.push_back(this->lib_path + (this->lib_path.at(this->lib_path.size()-1) != '/' ? "/" : "") + std::string(entry->d_name));
            this->lib_list.push_back(std::string(entry->d_name));
    }
    closedir(dir);
    return EXIT_SUCCESS;
}

bool Lib::SetCurrentLib(const std::string name)
{
    void *handle;

    this->RefreshLibList();
    if (this->lib_list.size() == 0)
        exit(42);
    if (std::find(this->lib_list.begin(), this->lib_list.end(), name) == this->lib_list.end()) {
        handle = dlopen((this->lib_path + this->lib_list[0]).c_str(), RTLD_NOW | RTLD_GLOBAL);
    } else {
        handle = dlopen((this->lib_path + name).c_str(), RTLD_NOW | RTLD_GLOBAL);
    }
    if (!handle) {
        std::cout << "Cannot open library: " << dlerror() << '\n';
        return 84;
    }
    std::unique_ptr<IDisplayModule> (*create)();
    create = (std::unique_ptr<IDisplayModule> (*)())dlsym(handle, "createLib");
    this->actual_lib = create();
    return EXIT_SUCCESS;
}

Lib::Lib(const std::string lib_path) : lib_path(lib_path)
{
    RefreshLibList();
}

Lib::~Lib()
{

}
