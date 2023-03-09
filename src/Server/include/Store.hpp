/*
** EPITECH PROJECT, 2022
** ECS
** File description:
** Store
*/

#ifndef STORE_HPP_
#define STORE_HPP_
#include "./ECS.hpp"
#include "./Entity.hpp"
#include "./Component.hpp"

namespace rtype {

  class Store {
    public:
      bool has(Entity e);
      Component *get(Entity e);
      bool add(Entity e, Component *c);
      bool remove(Entity e);
      std::set<Entity> getEntities() const;

    protected:
    private:
        std::map<Entity, Component *> m_store;
  };

}

#endif /* !STORE_HPP_ */
