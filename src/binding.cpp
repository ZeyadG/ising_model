#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "ising_model.h"

namespace py = pybind11;

PYBIND11_MODULE(libising, m) {
    py::class_<IsingModel>(m, "IsingModel")
        .def(py::init<int, double, int>())
        .def("thermalize", &IsingModel::thermalize)
        .def("measure", &IsingModel::measure)
        .def("compute_energy", &IsingModel::computeEnergy)
        .def("compute_magnetization", &IsingModel::computeMagnetization);
}