#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "userReporter.hpp"

namespace py = pybind11;

PYBIND11_MODULE(userReporter, m)
{
    m.doc() = "Python binding for the C++ UserReport class.";

    // Bind the UserReport class
    py::class_<UserReport>(m, "UserReport")
        .def(py::init<>()) // Constructor
        .def("reportUser", &UserReport::reportUser, "Add user to the report",
             py::arg("username"))
        .def("unreportUser", &UserReport::unreportUser, "Remove user to the report",
             py::arg("username"))
        .def("getRandom", &UserReport::getRandom, "Remove and return the value for a given key")
        .def("printRatio", &UserReport::printRatio, "Add user to the report",
             py::arg("loops"));
}