/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

class Error: public std::exception
{
    public:
        Error(const std::string &msg);
        virtual ~Error() throw(){}
        virtual const char *what() const throw();
    protected:
        std::string error_msg;
};

class LibError: public Error
{
    public:
        LibError(const std::string &msg);
        virtual ~LibError() throw(){}
        virtual const char *what() const throw();
    protected:
        std::string error_msg;
};

class CoreError: public Error
{
    public:
        CoreError(const std::string &msg);
        virtual ~CoreError() throw(){}
        virtual const char *what() const throw();
    protected:
        std::string error_msg;
};

#endif /* !ERROR_HPP_ */
