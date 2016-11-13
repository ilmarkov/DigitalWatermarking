//
// Created by ilya on 13.11.16.
//

#ifndef WATERMARKENGINE_PLUGINEXCEPTION_H
#define WATERMARKENGINE_PLUGINEXCEPTION_H

#include <exception>
#include <cstring>

struct ProjectException : public std::exception {

    char *_message;
    ProjectException() { ProjectException("undefined exception"); }
    ProjectException(const char* msg){
        const size_t size = std::strlen(msg);
        _message = new char[size + 1];
        std::strncpy(_message,msg,size);
        _message[size] = 0;
    }
    ProjectException(std::string msg){
        ProjectException(msg.c_str());
    }
    ProjectException(const ProjectException& e):std::exception(e) {
      const size_t size = std::strlen(e._message);
      _message = new char[size + 1];
      std::strncpy(_message,e._message,size);
      _message[size] = 0;
    }
    ~ProjectException() throw() { delete[] _message; }
    ProjectException& operator=(const ProjectException& e) {
      const size_t size = std::strlen(e._message);
      _message = new char[size + 1];
      std::strncpy(_message,e._message,size);
      _message[size] = 0;
      return *this;
    }
    //! Return a C-string containing the error message associated to the thrown exception.
    const char *what() const throw() { return _message; }

  };


#endif //WATERMARKENGINE_PLUGINEXCEPTION_H
