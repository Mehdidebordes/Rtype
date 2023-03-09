/*
** EPITECH PROJECT, 2022
** ECS
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_
#include "./ECS.hpp"

#include "./Component.hpp"
#include "./Entity.hpp"

namespace rtype {

  class Manager;

  class ISystem {
  public:
    ISystem(int priority, std::set<ComponentType> needed, Manager *manager)
    : m_priority(priority), m_needed(needed), m_manager(manager) { }

    virtual ~ISystem();

    int getPriority() const { return m_priority; }
    std::set<ComponentType> getNeededComponents() const { return m_needed; }
    Manager *getManager() { return m_manager; }

    virtual bool addEntity(Entity e) = 0;
    virtual bool removeEntity(Entity e) = 0;
    virtual void init();
    virtual void preUpdate(float delta);
    virtual void update(float delta);
    virtual void postUpdate(float delta);

  protected:
    Manager *m_manager;
    std::vector<Entity> *_entities;
  private:
    const int m_priority;
    const std::set<ComponentType> m_needed;
  };

}

#endif /* !ISYSTEM_HPP_ */
