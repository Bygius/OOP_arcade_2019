/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Display_lib_managment
*/

#include "Display.hpp"
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <memory>
#include <dlfcn.h>
#include <cstddef>
#include <algorithm>

void Display::PrintAllLib(void) const
{
    for(auto &it : this->lib_list) {
        std::cout << it.c_str() << std::endl;
    }
}

bool Display::RefreshLibList(void)
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

bool Display::Load(const std::string name)
{
    void *handle;

    this->RefreshLibList();
    if (this->lib_list.size() == 0) {
        if (this->actual_lib.get() == nullptr)
            exit(84);
        return EXIT_FAILURE;
    }
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
    this->current_lib_name = name;

    return EXIT_SUCCESS;
}

bool Display::LoadPreviousLib(void)
{
    this->RefreshLibList();
    auto pos = std::find(this->lib_list.begin(), this->lib_list.end(), this->current_lib_name);

    if (pos == this->lib_list.end()) {
        if (this->lib_list.size() > 0) {
            this->Load(this->lib_list.front());
            return EXIT_SUCCESS;
        } else
            return EXIT_FAILURE;
    }
    if (pos == this->lib_list.begin()) {
        this->Load(this->lib_list.back());
    } else {
        pos--;
        this->Load(pos->c_str());
    }
    return EXIT_SUCCESS;
}

bool Display::LoadNextLib(void)
{
    this->RefreshLibList();

    auto pos = std::find(this->lib_list.begin(), this->lib_list.end(), this->current_lib_name);

    if (pos == this->lib_list.end()) {
        if (this->lib_list.size() > 0) {
            this->Load(this->lib_list.front());
            return EXIT_SUCCESS;
        } else
            return EXIT_FAILURE;
    }
    if (pos == this->lib_list.end()-1) {
        this->Load(this->lib_list.front());
    } else {
        pos++;
        this->Load(pos->c_str());
    }
    return EXIT_SUCCESS;
}