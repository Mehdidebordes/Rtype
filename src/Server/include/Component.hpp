/*
** EPITECH PROJECT, 2022
** ECS
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_
#include "./ECS.hpp"

namespace rtype {

  typedef uint64_t ComponentType;

  struct Component {
    static const ComponentType type = 0;
  };
}

#endif /* !COMPONENT_HPP_ */
