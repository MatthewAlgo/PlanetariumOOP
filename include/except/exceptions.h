#pragma once
#include <exception>
#include <string>

class PlanetariumException : public std::exception {
public:
    explicit PlanetariumException(const std::string& message);
    const char* what() const noexcept;

protected:
    std::string message_;
};


class GalaxyNotFoundException : public PlanetariumException {
public:
    explicit GalaxyNotFoundException(const std::string& galaxyName);
};

class PlanetNotFoundException : public PlanetariumException {
public:
    explicit PlanetNotFoundException(const std::string& planetName);
};

class StarNotFoundException : public PlanetariumException {
public:
    explicit StarNotFoundException(const std::string& starName);
};

class WindowNotFoundException : public PlanetariumException {
public:
    explicit WindowNotFoundException(const std::string& message);
};

class PlanetarimRuntimeException : public PlanetariumException {
public:
    explicit PlanetarimRuntimeException(const std::string& message);
};