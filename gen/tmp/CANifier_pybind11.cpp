
#include <pybind11/pybind11.h>
namespace py = pybind11;

#include "CANifier.hpp"

PYBIND11_PLUGIN(CANifier) {

  py::module m("CANifier");

  py::class_<CANifier> canifier(m, "CANifier");
  canifier
    .def(py::init<int>())
    .def("setLEDOutput", &CANifier::setLEDOutput)
    .def("setGeneralOutputs", &CANifier::setGeneralOutputs)
    .def("setGeneralOutput", &CANifier::setGeneralOutput)
    .def("setPWMOutput", &CANifier::setPWMOutput)
    .def("enablePWMOutput", &CANifier::enablePWMOutput)
    .def("getGeneralInputs", &CANifier::getGeneralInputs)
    .def("getGeneralInput", &CANifier::getGeneralInput)
    .def("getPWMInput", &CANifier::getPWMInput)
    .def("getLastError", &CANifier::getLastError)
    .def("getBatteryVoltage", &CANifier::getBatteryVoltage)
    .def("setLastError", &CANifier::setLastError)
  ;
  
  
  return m.ptr();
}