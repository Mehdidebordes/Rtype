/*
** EPITECH PROJECT, 2022
** ECS
** File description:
** ISystem
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_
#include "./ECS.hpp"
#include "./ISystem.hpp"

namespace rtype {

  class System : public ISystem {
  public:
    System(int priority, std::set<ComponentType> needed, Manager *manager)
      : ISystem(priority, needed, manager) { }

    virtual void update(float delta) override;
    virtual bool addEntity(Entity e) override;
    virtual bool removeEntity(Entity e) override;
    virtual void updateEntity(float delta, Entity e);

  protected:
    const std::set<Entity> getEntities() const {
      return m_entities;
    }

  private:
    std::set<Entity> m_entities;
  };

}

#endif /* !SYSTEM_HPP_ */
