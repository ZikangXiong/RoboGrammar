#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <robot_design/robot.h>

namespace py = pybind11;
namespace rd = robot_design;

void initRobot(py::module &m) {
  py::enum_<rd::LinkShape>(m, "LinkShape")
      .value("NONE", rd::LinkShape::NONE)
      .value("CAPSULE", rd::LinkShape::CAPSULE)
      .value("CYLINDER", rd::LinkShape::CYLINDER);

  py::enum_<rd::JointType>(m, "JointType")
      .value("FREE", rd::JointType::FREE)
      .value("HINGE", rd::JointType::HINGE)
      .value("FIXED", rd::JointType::FIXED);

  py::class_<rd::Link>(m, "Link")
      .def(py::init<>())
      .def_readwrite("parent", &rd::Link::parent_)
      .def_readwrite("joint_type", &rd::Link::joint_type_)
      .def_readwrite("joint_pos", &rd::Link::joint_pos_)
      .def_readwrite("joint_rot", &rd::Link::joint_rot_)
      .def_readwrite("joint_axis", &rd::Link::joint_axis_)
      .def_readwrite("shape", &rd::Link::shape_)
      .def_readwrite("length", &rd::Link::length_)
      .def_readwrite("color", &rd::Link::color_)
      .def_readwrite("joint_color", &rd::Link::joint_color_)
      .def_readwrite("label", &rd::Link::label_)
      .def_readwrite("joint_label", &rd::Link::joint_label_);

  py::class_<rd::Robot>(m, "Robot")
      .def(py::init<>())
      .def_readwrite("link_density", &rd::Robot::link_density_)
      .def_readwrite("link_radius", &rd::Robot::link_radius_)
      .def_readwrite("friction", &rd::Robot::friction_)
      .def_readwrite("motor_kp", &rd::Robot::motor_kp_)
      .def_readwrite("motor_kd", &rd::Robot::motor_kd_)
      .def_readwrite("links", &rd::Robot::links_);
}
