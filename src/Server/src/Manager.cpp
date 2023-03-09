#include <cassert>
#include <algorithm>
// #include "../Store/Store.hpp"
#include "../include/Manager.hpp"

std::vector<int> parseReceive(std::string s)
{
  std::vector<int> vec;
  std::string token;
  size_t pos = 0;

  while ((pos = s.find(";")) != std::string::npos) {
    token = s.substr(0, pos);
    vec.push_back(std::stoi(token));
    s.erase(0, pos + 1);
  }

  vec.push_back(std::stoi(s));
  return vec;
}

namespace rtype {

  Manager::~Manager() {
    for (auto store : _stores) {
      delete store.second;
    }
  }

  Store *Manager::getStore(ComponentType ct) {
    auto it = _stores.find(ct);
    return it == _stores.end() ? nullptr : it->second;
  }

  bool Manager::addComponent(Entity e, ComponentType ct, Component *c)
  {
    if (e == 0 || ct == 0) {
      return false;
    }

    Store *store = getStore(ct);

    if (store == nullptr) {
      return false;
    }

    auto it = m_entities.find(e);

    if (it == m_entities.end()) {
      return false;
    }

    it->second.insert(ct);
    return store->add(e, c);
  }

  Component *Manager::getComponent(Entity e, ComponentType ct)
  {
    if (e == 0 || ct == 0) {
      return nullptr;
    }

    Store *store = getStore(ct);

    if (store == nullptr) {
      return nullptr;
    }

    return store->get(e);
  }

  int Manager::subscribeEntityToSystems(Entity e, std::set<ComponentType> components)
  {
    if (e == 0) {
      return 0;
    }

    int n = 0;
    for (auto& sys : _systems) {
      const std::set<ComponentType> needed = sys->getNeededComponents();
      if (std::includes(components.begin(), components.end(), needed.begin(), needed.end())) {
        sys->addEntity(e);
        n++;
      } else {
        sys->removeEntity(e);
      }
    }

    return n;
  }

  int Manager::subscribeEntityToSystems(Entity e) {
    auto it = m_entities.find(e);

    if (it == m_entities.end()) {
      return 0;
    }

    return subscribeEntityToSystems(e, it->second);
  }
  bool Manager::addSystems(System *sys) {
    if (sys) {
      _systems.push_back(sys);
      return true;
    }
    return false;
  }

  void Manager::updateSystems(float delta)
  {
    for (auto& sys : _systems) {
      sys->preUpdate(delta);
    }

    for (auto& sys : _systems) {
      sys->update(delta);
    }

    for (auto& sys : _systems) {
      sys->postUpdate(delta);
    }
  }

  Entity Manager::createEntity(void) {
    Entity e = _id++;
    _entities.push_back(e);
    auto ret = m_entities.insert(std::make_pair(e, std::set<ComponentType>()));
    return e;
  }

  void Manager::removeEntity(Entity e) {
    for (auto& sys : _systems) {
      sys->removeEntity(e);
    }
    m_entities.erase(e);
    _entities.erase(std::remove(_entities.begin(), _entities.end(), e), _entities.end());
  }

  void Manager::getInput(std::string *buff)
  {
    if (buff->empty()) return;

    std::vector<int> tmp(parseReceive(*buff));
    int port = tmp[0];
    auto it = _players.find(port);

    if (it == _players.end()) {
      Entity e = createPlayer(this);
      _players.insert(std::make_pair(port, e));
      std::cout << "New connection from port n°" << port << "." << std::endl;
    } else {
      if (tmp[2] != 99) {
        getInput(port, it->second, tmp);
      }
    }
    buff->clear();
  }

  void Manager::getInput(int port, Entity e, std::vector<int> input)
  {
    Position *pos = getComponent<Position>(e);
    Velocity *vel = getComponent<Velocity>(e);
    Clock *clock = getComponent<Clock>(e);
    Stats *stats = getComponent<Stats>(e);
    if (!stats->alive) return;

    sf::Time elapsed = clock->c_shoot.getElapsedTime();
    switch (input[1]) {
      case UP:
        pos->pos.y -= vel->velocity.y;
        break;
      case LEFT:
        pos->pos.x -= vel->velocity.x;
        break;
      case DOWN:
        pos->pos.y += vel->velocity.y;
        break;
      case RIGHT:
        pos->pos.x += vel->velocity.x;
        break;
      case SPACE:
        if (elapsed.asSeconds() > 0.3) {
          createPlayerShoot(this, e);
          clock->c_shoot.restart();
        }
        break;

      default:
        break;
    }
  }

  void Manager::postUpdate(void)
  {
    _buff.clear();

    // "SPRITE_ID:POSITION_X:POSITION_Y:RECT_LEFT:RECT_WIDTH:RECT_TOP:RECT_HEIGHT/"
    for (Entity e: _entities) {
      Sprite *sprite = getComponent<Sprite>(e);
      sf::IntRect rect = sprite->sprite.getTextureRect();
      Position *pos = getComponent<Position>(e);
      Type *type = getComponent<Type>(e);
      _buff += std::to_string(static_cast<int>(type->object)) + ":" + std::to_string(static_cast<int>(pos->pos.x)) + ":" + std::to_string(static_cast<int>(pos->pos.y)) + ":";
      _buff += std::to_string(rect.left) + ":" + std::to_string(rect.top) + ":" + std::to_string(rect.width) + ":" + std::to_string(rect.height) + "/";
    }
  }

  void Manager::spawnEnemy(void)
  {
    sf::Time e_game = c_game.getElapsedTime(); 
    sf::Time e_spawn = c_spawn.getElapsedTime(); 
    sf::Time e_boss = c_boss.getElapsedTime(); 
    if (e_game.asSeconds() < 10000) {
      if (e_spawn.asSeconds() > 5) {
        createEnemy(this);
        c_spawn.restart();
      }
    }
    if (e_boss.asSeconds() > 120) {
      createBoss(this);
      c_boss.restart();
    }
  }
}
