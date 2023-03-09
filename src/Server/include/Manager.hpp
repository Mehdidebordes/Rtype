/*
** EPITECH PROJECT, 2022
** ECS
** File description:
** Manager
*/

#ifndef MANAGER_HPP_
#define MANAGER_HPP_
#include "./ECS.hpp"
#include "./Entity.hpp"
#include "./Store.hpp"
#include "./System.hpp"
#include "./Components.hpp"

void createMenu(rtype::Manager *manager);
rtype::Entity createPlayer(rtype::Manager *manager);
void createPlayerShoot(rtype::Manager *manager, rtype::Entity c_entity);
void createEnemy(rtype::Manager *manager);
void createEnemyShoot(rtype::Manager *manager, sf::Vector2f pos);
void createBoss(rtype::Manager *manager);
void createBossShoot(rtype::Manager *manager, rtype::Entity c_entity);
void createBossSpecial(rtype::Manager *manager);

namespace rtype {

  class Manager {
    public:
      Manager(): _id(1), _state(0) {
        _window.create(sf::VideoMode(WIDTH, HEIGHT), "R-TYPE", sf::Style::Titlebar | sf::Style::Close);
        _window.setPosition({0, 0});
        /* init clock */
      };

      ~Manager();

      sf::RenderWindow *getWindow() { return &_window; };

      bool createStoreFor(ComponentType ct) {
        auto ret = _stores.insert(std::make_pair(ct, new Store));
        return ret.second;
      }

      Store *getStore(ComponentType ct);

      bool addComponent(Entity e, ComponentType ct, Component *c);
      template<typename C>
      bool addComponent(Entity e, C *c) {
        return addComponent(e, C::type, c);
      }

      Component *getComponent(Entity e, ComponentType ct);
      template<typename C>
      C *getComponent(Entity e) {
        return static_cast<C*>(getComponent(e, C::type));
      }

      int subscribeEntityToSystems(Entity e, std::set<ComponentType> components);
      int subscribeEntityToSystems(Entity e);

      bool addSystems(System *sys);
      void updateSystems(float delta);

      Entity createEntity(void);
      void removeEntity(Entity e);
      std::vector<Entity> getEntities(void) { return _entities; };

      void getInput(std::string *buff);
      void getInput(int port, Entity e, std::vector<int> input);
      std::map<int, Entity> getPlayers() { return _players; };

      void postUpdate(void);
      std::string getPostUpdate() const { return _buff; };
      void spawnEnemy(void);
    private:
      std::vector<Entity> _entities;
      Entity _id;

      std::map<int, Entity> _players;
      std::map<ComponentType, Store *> _stores;
      std::map<Entity, std::set<ComponentType>> m_entities;
      std::vector<ISystem *> _systems;

      sf::RenderWindow _window;
      std::string _buff;
      sf::Clock c_game;
      sf::Clock c_spawn;
      sf::Clock c_boss;
      int _state;
  };

}

#endif /* !MANAGER_HPP_ */
