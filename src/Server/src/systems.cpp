/*
** EPITECH PROJECT, 2022
** RTYPE
** File description:
** systems
*/

#include "../include/systems.hpp"
#include "../include/Objects.hpp"

bool isPlayers(int type) {
  return (type == TYPE_PLAYER_ONE || type == TYPE_PLAYER_TWO || type == TYPE_PLAYER_THR || type == TYPE_PLAYER_FOU);
}

void Input::preUpdate(float delta)
{
  sf::Event event;

  while (m_window->pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        m_window->close();
        break;

      case sf::Event::KeyPressed:
        switch (event.key.code) {
          case sf::Keyboard::Escape:
            m_window->close();
            break;

          default:
            break;
        }
        break;
      default:
        break;
    }
  }
}

void Shooting::updateEntity(float delta, rtype::Entity e)
{
  Clock *clock = getManager()->getComponent<Clock>(e);
  Type *type = getManager()->getComponent<Type>(e);
  Position *pos = getManager()->getComponent<Position>(e);
  Hitbox *hitbox = getManager()->getComponent<Hitbox>(e);

  if (type->object == TYPE_ENEMY_ONE) {
    sf::Time elapsed1 = clock->c_shoot.getElapsedTime();
    if (elapsed1.asSeconds() > clock->t_shoot) {
      createEnemyShoot(getManager(), {pos->pos.x, pos->pos.y + (hitbox->y / 2)});
      clock->c_shoot.restart();
    }
  }

  if (type->object == TYPE_BOSS_ONE) {
    sf::Time elapsed1 = clock->c_special.getElapsedTime();
    sf::Time elapsed2 = clock->c_shoot.getElapsedTime();
    if (elapsed1.asSeconds() > clock->t_special) {
      createBossSpecial(getManager());
      clock->c_special.restart();
    }
    if (elapsed2.asSeconds() > clock->t_shoot) {
      createBossShoot(getManager(), e);
      clock->c_shoot.restart();
    }
  }
}

void Movement::updateBoss(float delta, rtype::Entity e)
{
  Position *pos = getManager()->getComponent<Position>(e);
  Hitbox *hitbox = getManager()->getComponent<Hitbox>(e);
  Velocity *velocity = getManager()->getComponent<Velocity>(e);
  Clock *clock = getManager()->getComponent<Clock>(e);
  sf::Time elapsed = clock->c_move.getElapsedTime();

  if (elapsed.asSeconds() > clock->t_move) {
    if (pos->pos.x <= WIDTH - hitbox->x) return;
    pos->pos.x += velocity->velocity.x; 
    pos->pos.y += velocity->velocity.y;
    clock->c_move.restart();
  }
}

void Movement::updateEnemyShoot(float delta, rtype::Entity e)
{
  Position *pos = getManager()->getComponent<Position>(e);
  Velocity *velocity = getManager()->getComponent<Velocity>(e);
  Clock *clock = getManager()->getComponent<Clock>(e);

  sf::Time elapsed = clock->c_sprite.getElapsedTime();

  if (elapsed.asMilliseconds() > clock->t_move) {
    pos->pos.x += velocity->velocity.x; 
    pos->pos.y += velocity->velocity.y;
    if (pos->pos.x < -WIDTH)
      pos->pos.x = 0; 
    clock->c_sprite.restart();
  }
}

void Movement::updateEnemy(float delta, rtype::Entity e)
{
  Position *pos = getManager()->getComponent<Position>(e);
  Hitbox *hitbox = getManager()->getComponent<Hitbox>(e);
  Velocity *velocity = getManager()->getComponent<Velocity>(e);
  Clock *clock = getManager()->getComponent<Clock>(e);

  sf::Time elapsed = clock->c_move.getElapsedTime();

  if (elapsed.asMicroseconds() > clock->t_move) {
    pos->pos.x += velocity->velocity.x; 
    pos->pos.y += velocity->velocity.y;
    if (pos->pos.y <= 0)
      velocity->velocity.y *= -1;
    if (pos->pos.y > HEIGHT - hitbox->y - 10)
      velocity->velocity.y *= -1;

    if (pos->pos.x < 0 - hitbox->x) {
      getManager()->removeEntity(e);
    }
    if (pos->pos.x > WIDTH) {
      getManager()->removeEntity(e);
    }
    clock->c_move.restart();
  } 
}

void Movement::updateParallax(float delta, rtype::Entity e)
{
  Position *pos = getManager()->getComponent<Position>(e);
  Velocity *velocity = getManager()->getComponent<Velocity>(e);
  Type *type = getManager()->getComponent<Type>(e);
  Clock *clock = getManager()->getComponent<Clock>(e);

  if (type->object < 7 && type->object > 0) {
      sf::Time elapsed = clock->c_sprite.getElapsedTime();
      if (elapsed.asMilliseconds() > clock->t_move) {
        pos->pos.x += velocity->velocity.x; 
        pos->pos.y += velocity->velocity.y;
        if (pos->pos.x < -WIDTH)
          pos->pos.x = 0;
        clock->c_sprite.restart();
      }
  }
}

void Movement::updateEntity(float delta, rtype::Entity e)
{
  Type *type = getManager()->getComponent<Type>(e);

  if (type->object == isPlayers(static_cast<int>(type->object))) return;

  switch (type->object) {
    case TYPE_ENEMY_ONE:
      updateEnemy(delta, e);
      break;
    case TYPE_BOSS_ONE:
      updateBoss(delta, e);
      break;
    case TYPE_SHOOT:
      updateEnemy(delta, e);
      break;
    case TYPE_BOSS_SHOOT:
      updateEnemy(delta, e);
      break;
    case TYPE_ENEMY_SHOOT:
      updateEnemyShoot(delta, e);
      break;
    default:
      updateParallax(delta, e);
      break;
  }
}

void Collision::updatePlayer(float delta, rtype::Entity e)
{
  Position *pos = getManager()->getComponent<Position>(e);
  Hitbox *hitbox = getManager()->getComponent<Hitbox>(e);
  Stats *stats = getManager()->getComponent<Stats>(e);

  for (rtype::Entity tmp: getEntities()) {
    Type *e_type = getManager()->getComponent<Type>(tmp);
    if (e_type->object == TYPE_ENEMY_ONE || e_type->object == TYPE_BOSS_SHOOT || e_type->object == TYPE_BOSS_SPECIAL || e_type->object == TYPE_ENEMY_SHOOT) {
      Position *e_pos = getManager()->getComponent<Position>(tmp);
      Hitbox *e_hitbox = getManager()->getComponent<Hitbox>(tmp);
      Stats *e_stats = getManager()->getComponent<Stats>(tmp);
      if (pos->pos.x < e_pos->pos.x + e_hitbox->x && pos->pos.x + hitbox->x > e_pos->pos.x) {
        if (pos->pos.y < e_pos->pos.y + e_hitbox->y && pos->pos.y + hitbox->y > e_pos->pos.y) {
          stats->health -= e_stats->attack;
          if (stats->health <= 0) {
            stats->alive = false;
            getManager()->removeEntity(e);
          }
          getManager()->removeEntity(tmp);
        }
      }
    };
  }
}

void Collision::updateEnemy(float delta, rtype::Entity e)
{
  Position *pos = getManager()->getComponent<Position>(e);
  Hitbox *hitbox = getManager()->getComponent<Hitbox>(e);
  Stats *stats = getManager()->getComponent<Stats>(e);

  for (rtype::Entity tmp: getEntities()) {
    Type *e_type = getManager()->getComponent<Type>(tmp);
    if (e_type->object != TYPE_SHOOT) continue;
    Position *e_pos = getManager()->getComponent<Position>(tmp);
    Hitbox *e_hitbox = getManager()->getComponent<Hitbox>(tmp);
    Stats *e_stats = getManager()->getComponent<Stats>(tmp);
    if (pos->pos.x < e_pos->pos.x + e_hitbox->x && pos->pos.x + hitbox->x > e_pos->pos.x) {
      if (pos->pos.y < e_pos->pos.y + e_hitbox->y && pos->pos.y + hitbox->y > e_pos->pos.y) {
        stats->health -= e_stats->attack;
        if (stats->health <= 0) {
          getManager()->removeEntity(e);
        }
        getManager()->removeEntity(tmp);
      }
    }
  }
}

void Collision::updateBoss(float delta, rtype::Entity e)
{
  Position *pos = getManager()->getComponent<Position>(e);
  Hitbox *hitbox = getManager()->getComponent<Hitbox>(e);
  Stats *stats = getManager()->getComponent<Stats>(e);

  for (rtype::Entity tmp: getEntities()) {
    Type *e_type = getManager()->getComponent<Type>(tmp);
    if (e_type->object != TYPE_SHOOT) continue;
    Position *e_pos = getManager()->getComponent<Position>(tmp);
    Hitbox *e_hitbox = getManager()->getComponent<Hitbox>(tmp);
    Stats *e_stats = getManager()->getComponent<Stats>(tmp);
    if (pos->pos.x < e_pos->pos.x + e_hitbox->x && pos->pos.x + hitbox->x > e_pos->pos.x) {
      if (pos->pos.y < e_pos->pos.y + e_hitbox->y && pos->pos.y + hitbox->y > e_pos->pos.y) {
        stats->health -= e_stats->attack;
        if (stats->health <= 0) {
          getManager()->removeEntity(e);
        }
        getManager()->removeEntity(tmp);
      }
    }
  }
}

void Collision::updateEntity(float delta, rtype::Entity e)
{
  Type *type = getManager()->getComponent<Type>(e);

  switch (type->object) {
    case TYPE_PLAYER_ONE:
      updatePlayer(delta, e);
      break;
    case TYPE_PLAYER_TWO:
      updatePlayer(delta, e);
      break;
    case TYPE_PLAYER_THR:
      updatePlayer(delta, e);
      break;
    case TYPE_PLAYER_FOU:
      updatePlayer(delta, e);
      break;
    case TYPE_ENEMY_ONE:
      updateEnemy(delta, e);
      break;
    case TYPE_BOSS_ONE:
      updateBoss(delta, e);
      break;
  }
}

void Render::preUpdate(float delta) {
  m_window->clear(sf::Color::Blue);
}

void Render::updateBoss(float delta, rtype::Entity e)
{
  Sprite *sprite = getManager()->getComponent<Sprite>(e);
  Clock *clock = getManager()->getComponent<Clock>(e);
  
  sf::Time elapsed1 = clock->c_sprite.getElapsedTime();
  if (elapsed1.asSeconds() > clock->t_sprite) {
    int top = sprite->sprite.getTextureRect().top + 260;
    if (top >= 1820) {
      top = 0;
    }
    sprite->sprite.setTextureRect({0, top, 143, 260});
    clock->c_sprite.restart();
  }
}

void Render::updateEnemy(float delta, rtype::Entity e)
{
  Sprite *sprite = getManager()->getComponent<Sprite>(e);
  Clock *clock = getManager()->getComponent<Clock>(e);
  
  sf::Time elapsed1 = clock->c_sprite.getElapsedTime();
  if (elapsed1.asSeconds() > clock->t_sprite) {
    int left = sprite->sprite.getTextureRect().left + 33;
    if (left >= 267 - 32) {
      left = 0;
    }
    sprite->sprite.setTextureRect({left, 0, 33, 36});
    clock->c_sprite.restart();
  }
}

void Render::updateBossSpecial(float delta, rtype::Entity e)
{
  Sprite *sprite = getManager()->getComponent<Sprite>(e);
  Clock *clock = getManager()->getComponent<Clock>(e);
  
  sf::Time elapsed1 = clock->c_sprite.getElapsedTime();
  sf::Time elapsed2 = clock->c_special.getElapsedTime();
  if (elapsed1.asSeconds() > clock->t_sprite) {
    int top = sprite->sprite.getTextureRect().top + 64;
    if (top >= 448 - 64) {
      top = 0;
    }
    sprite->sprite.setTextureRect({0, top, 256, 64});
    clock->c_sprite.restart();
  }
  if (elapsed2.asSeconds() > clock->t_special) {
    getManager()->removeEntity(e);
  }
}

void Render::updateEntity(float delta, rtype::Entity e)
{
  Sprite *sprite = getManager()->getComponent<Sprite>(e);
  Position *pos = getManager()->getComponent<Position>(e);
  Type *type = getManager()->getComponent<Type>(e);
  
  switch (type->object) {
    case TYPE_ENEMY_ONE:
      updateEnemy(delta, e);
      break;
    case TYPE_BOSS_ONE:
      updateBoss(delta, e);
      break;
    case TYPE_BOSS_SPECIAL:
      updateBossSpecial(delta, e);
    default:
      break;
  }
  sprite->sprite.setPosition(pos->pos);
  m_window->draw(sprite->sprite);
}

void Render::postUpdate(float delta) {
  m_window->display();
}
