#include <pybind11/pybind11.h>
#include <string>
#include <cstdio>


namespace py = pybind11; 

std::string execute(const std::string& command) {
    std::string result;
    FILE* pipe = nullptr;
    char buffer[128];
    pipe = _popen(command.c_str(), "r");
    if (!pipe) {
        return "";
    }
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    _pclose(pipe);
    return result;
}

PYBIND11_MODULE(cpyprocess, handle) {
    handle.doc() = "Simple Python wrapper for system() in C++";
    handle.def("execute", &execute); 
}
