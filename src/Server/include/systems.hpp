/*
** EPITECH PROJECT, 2022
** RTYPE
** File description:
** systems
*/

#ifndef SYSTEMS_HPP_
#define SYSTEMS_HPP_

#include "./ECS.hpp"
#include "./System.hpp"
#include "./Manager.hpp"
#include "./Components.hpp"

class Input : public rtype::System {
  public:
    Input(rtype::Manager *manager, sf::RenderWindow *window)
      : System(SYS_INPUT, {  }, manager), m_window(window)
      { }

    virtual void preUpdate(float delta) override;

  private:
    sf::RenderWindow *m_window;
};

class Movement : public rtype::System {
  public:
    Movement(rtype::Manager *manager)
      : System(SYS_MOVEMENT, { Position::type }, manager)
      { }

    virtual void updateEntity(float delta, rtype::Entity e) override;
    void updateEnemy(float delta, rtype::Entity e);
    void updateBoss(float delta, rtype::Entity e);
    void updateEnemyShoot(float delta, rtype::Entity e);
    void updateParallax(float delta, rtype::Entity e);
    // void updateBossShoot(float delta, rtype::Entity e);
};

class Collision : public rtype::System {
  public:
    Collision(rtype::Manager *manager)
     : System(SYS_COLLISION, { Hitbox::type }, manager)
     { }

    virtual void updateEntity(float delta, rtype::Entity e) override;
    void updatePlayer(float delta, rtype::Entity e);
    void updateEnemy(float delta, rtype::Entity e);
    void updateBoss(float delta, rtype::Entity e);
};

class Render : public rtype::System {
  public:
    Render(rtype::Manager *manager, sf::RenderWindow *window)
     : System(SYS_RENDER, { Sprite::type }, manager), m_window(window)
     { }

    virtual void preUpdate(float delta) override;
    virtual void updateEntity(float delta, rtype::Entity e) override;
    void updateEnemy(float delta, rtype::Entity e);
    void updateBoss(float delta, rtype::Entity e);
    void updateBossSpecial(float delta, rtype::Entity e);
    virtual void postUpdate(float delta) override;

  private:
    sf::RenderWindow *m_window;
};

class Shooting : public rtype::System {
  public:
    Shooting(rtype::Manager *manager)
     : System(SYS_SHOOTING, { Clock::type }, manager)
     { }

    virtual void updateEntity(float delta, rtype::Entity e) override;
};


#endif /* !SYSTEMS_HPP_ */
