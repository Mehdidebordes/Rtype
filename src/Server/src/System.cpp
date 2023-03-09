/*
** EPITECH PROJECT, 2022
** RTYPE
** File description:
** System
*/

#include "../include/System.hpp"

namespace rtype {

  bool System::addEntity(Entity e) {
    auto ret = m_entities.insert(e);
    return ret.second;
  }

  bool System::removeEntity(Entity e) {
    auto ret = m_entities.erase(e);
    return ret > 0;
  }

  void System::update(float delta) {
    auto copy = getEntities();

    for (rtype::Entity e : copy) {
      updateEntity(delta, e);
    }
  }

  void System::updateEntity(float delta, Entity entity) {
    // nothing by default
  }

}
