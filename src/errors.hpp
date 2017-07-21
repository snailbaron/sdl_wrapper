#pragma once

#include <exception>
#include <string>

class SdlError : public std::exception {
public:
    explicit SdlError(const char* (*getErrorFunc)());

    const char* what() const override;

private:
    std::string _message;
};

[[noreturn]] void throwSdl();
[[noreturn]] void throwImage();
[[noreturn]] void throwMixer();
[[noreturn]] void throwNet();
[[noreturn]] void throwTtf();
