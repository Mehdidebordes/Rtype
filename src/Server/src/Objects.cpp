/*
** EPITECH PROJECT, 2022
** ECS
** File description:
** Objects
*/

#include "../include/Objects.hpp"
#include "../include/Components.hpp"

rtype::Entity createPlayer(rtype::Manager *manager) {
    rtype::Entity e = manager->createEntity();

    std::vector<const char*> p_sprites = {"assets/Game/player_one.png", "assets/Game/player_two.png", "assets/Game/player_thr.png", "assets/Game/player_fou.png"};
    std::vector<int> p_type = {TYPE_PLAYER_ONE, TYPE_PLAYER_TWO, TYPE_PLAYER_THR, TYPE_PLAYER_FOU};
    sf::Vector2f pos = {200, static_cast<float>(rand() % HEIGHT - 100)};
    sf::IntRect Rect = {0, 0, 33, 17};

    manager->addComponent(e, new Position(pos));
    manager->addComponent(e, new Velocity({10, 10}));
    manager->addComponent(e, new Sprite(p_sprites[manager->getPlayers().size()], pos, Rect, {4, 4}));
    manager->addComponent(e, new Hitbox({ 33. * 4., 17. * 4.}));
    manager->addComponent(e, new Type(p_type[manager->getPlayers().size()]));
    manager->addComponent(e, new Stats(5, 5, 0, 1));
    manager->addComponent(e, new Clock(0.f, 0.f, 0.f, 0.f));

    manager->subscribeEntityToSystems(e);
    return e;
}

void createMenu(rtype::Manager *manager) {
	float W = WIDTH/2 - 618/2;
	float H = HEIGHT/2 - 65;

    sf::IntRect Rect = {0, 0, 618, 65};
    sf::IntRect RectParallax = {0, 0, WIDTH * 2, HEIGHT};
    sf::Vector2f v_play = {W, H - 32 - 65 - 20 - 65 - 20};
    // sf::Vector2f v_save = {W, H - 32 - 65 - 20};
    sf::Vector2f v_settings = {W, H - 32};
    // sf::Vector2f v_credit = {W, H - 32 + 65 + 20};
    sf::Vector2f v_quit = {W, H - 32 + 65 + 20 + 65 + 20};
    sf::Vector2f VectParallax = { 0, 0 };

	rtype::Entity one = manager->createEntity();
	rtype::Entity two = manager->createEntity();
	rtype::Entity three = manager->createEntity();
	rtype::Entity four = manager->createEntity();
	rtype::Entity five = manager->createEntity();
	rtype::Entity six = manager->createEntity();

	// rtype::Entity start = manager->createEntity();
	// rtype::Entity settings = manager->createEntity();
	// rtype::Entity quit = manager->createEntity();

	manager->addComponent(one, new Sprite("assets/menu/one.png", VectParallax, RectParallax, {1., 1.}));
	manager->addComponent(two, new Sprite("assets/menu/two.png", VectParallax, RectParallax, {1., 1.}));
	manager->addComponent(three, new Sprite("assets/menu/three.png", VectParallax, RectParallax, {1., 1.}));
	manager->addComponent(four, new Sprite("assets/menu/four.png", VectParallax, RectParallax, {1., 1.}));
	manager->addComponent(five, new Sprite("assets/menu/five.png", VectParallax, RectParallax, {1., 1.}));
	manager->addComponent(six, new Sprite("assets/menu/six.png", VectParallax, RectParallax, {1., 1.}));
    manager->addComponent(one, new Velocity({-1, 0}));
    manager->addComponent(two, new Velocity({-2, 0}));
    manager->addComponent(three, new Velocity({-3, 0}));
    manager->addComponent(four, new Velocity({-4, 0}));
    manager->addComponent(five, new Velocity({-5, 0}));
    manager->addComponent(six, new Velocity({-6, 0}));
    manager->addComponent(one, new Position(VectParallax));
    manager->addComponent(two, new Position(VectParallax));
    manager->addComponent(three, new Position(VectParallax));
    manager->addComponent(four, new Position(VectParallax));
    manager->addComponent(five, new Position(VectParallax));
    manager->addComponent(six, new Position(VectParallax));
    manager->addComponent(one, new Type(TYPE_PARALLAX_ONE));
    manager->addComponent(two, new Type(TYPE_PARALLAX_TWO));
    manager->addComponent(three, new Type(TYPE_PARALLAX_THR));
    manager->addComponent(four, new Type(TYPE_PARALLAX_FOU));
    manager->addComponent(five, new Type(TYPE_PARALLAX_FIV));
    manager->addComponent(six, new Type(TYPE_PARALLAX_SIX));

    manager->addComponent(one, new Clock(0.f, 0.f, 0.01, 0.f));
    manager->addComponent(two, new Clock(0.f, 0.f, 0.01, 0.f));
    manager->addComponent(three, new Clock(0.f, 0.f, 0.01, 0.f));
    manager->addComponent(four, new Clock(0.f, 0.f, 0.01, 0.f));
    manager->addComponent(five, new Clock(0.f, 0.f, 0.01, 0.f));
    manager->addComponent(six, new Clock(0.f, 0.f, 0.01, 0.f));
    // manager->addComponent(start, new Sprite("assets/menu/start.png", v_play, Rect, {1., 1.}, 20));
	// manager->addComponent(settings, new Sprite("assets/menu/settings.png", v_settings, Rect, {1., 1.}, 20));
	// manager->addComponent(quit, new Sprite("assets/menu/quit.png", v_quit, Rect, {1., 1.}, 20));

	manager->subscribeEntityToSystems(one);
	manager->subscribeEntityToSystems(two);
	manager->subscribeEntityToSystems(three);
	manager->subscribeEntityToSystems(four);
	manager->subscribeEntityToSystems(five);
	manager->subscribeEntityToSystems(six);
    
	// manager->subscribeEntityToSystems(start);
	// manager->subscribeEntityToSystems(settings);
	// manager->subscribeEntityToSystems(quit);
	return;
}

void createEnemy(rtype::Manager *manager)
{
    rtype::Entity e = manager->createEntity();
    sf::Vector2f pos = {WIDTH - 100, static_cast<float>(rand() % (HEIGHT - 100) + 100)};

    sf::IntRect Rect = {0, 0, 33, 36};

    manager->addComponent(e, new Position(pos));
    manager->addComponent(e, new Velocity({-.3, -1}));
    manager->addComponent(e, new Sprite("assets/Game/enemy_one.png", pos, Rect, {3, 3}));
    manager->addComponent(e, new Hitbox({ 33 * 3., 36 * 3.}));
    manager->addComponent(e, new Type(TYPE_ENEMY_ONE));
    manager->addComponent(e, new Stats(50, 10, 0, 1));
    manager->addComponent(e, new Clock(0.1f, 3.f, 0.1f, 0.f));

    manager->subscribeEntityToSystems(e);

    return;
}

void createEnemyShoot(rtype::Manager *manager, sf::Vector2f pos)
{
    rtype::Entity e = manager->createEntity();
    sf::IntRect Rect = {0, 0, 9, 5};

    manager->addComponent(e, new Position(pos));
    manager->addComponent(e, new Velocity({-7, 0}));
    manager->addComponent(e, new Sprite("assets/Game/enemy_shoot_one.png", pos, Rect, {3, 3}));
    manager->addComponent(e, new Hitbox({ 9 * 3., 5 * 3.}));
    manager->addComponent(e, new Type(TYPE_ENEMY_SHOOT));
    manager->addComponent(e, new Stats(10, 10, 0, 1));
    manager->addComponent(e, new Clock(0.f, 0.f, 0.1f, 0.f));

    manager->subscribeEntityToSystems(e);

    return;
}

void createPlayerShoot(rtype::Manager *manager, rtype::Entity c_entity)
{
    Hitbox *hitbox = manager->getComponent<Hitbox>(c_entity);
    Position *pos = manager->getComponent<Position>(c_entity);
    Stats *stats = manager->getComponent<Stats>(c_entity);
    rtype::Entity e = manager->createEntity();
    sf::IntRect Rect = {0, 0, 14, 9};

    manager->addComponent(e, new Position({ pos->pos.x + hitbox->x, pos->pos.y + (hitbox->y / 2) }));
    manager->addComponent(e, new Velocity({6, 0}));
    manager->addComponent(e, new Sprite("assets/Game/player_shoot_one.png", pos->pos, Rect, {2, 2}));
    manager->addComponent(e, new Hitbox({9 * 2, 5 * 2}));
    manager->addComponent(e, new Type(TYPE_SHOOT));
    manager->addComponent(e, new Stats(20, stats->attack, 0, 1));
    manager->addComponent(e, new Clock(0.f, 0.f, 0.001f, 0.f));

    manager->subscribeEntityToSystems(e);

    return;
}

void createBossSpecial(rtype::Manager *manager)
{
    rtype::Entity e = manager->createEntity();
    sf::IntRect Rect = {0, 0, 256, 64};

    manager->addComponent(e, new Position({0, HEIGHT/2 - (64 * 6 )/ 2}));
    manager->addComponent(e, new Velocity({0, 0}));
    manager->addComponent(e, new Sprite("assets/Game/boss_special.png", {WIDTH/2, HEIGHT/2}, Rect, {6, 6}));
    manager->addComponent(e, new Hitbox({ 256 * 6., 64 * 6.}));
    manager->addComponent(e, new Type(TYPE_BOSS_SPECIAL));
    manager->addComponent(e, new Stats(10, 10, 0, 1));
    manager->addComponent(e, new Clock(0.3f, 0.3f, 0.1f, 2.f));

    manager->subscribeEntityToSystems(e);

    return;
}

void createBossShoot(rtype::Manager *manager, rtype::Entity c_entity)
{
    Position *pos = manager->getComponent<Position>(c_entity);
    Hitbox *hitbox = manager->getComponent<Hitbox>(c_entity);
    rtype::Entity one = manager->createEntity();
    rtype::Entity two = manager->createEntity();
    sf::IntRect Rect = {0, 0, 9, 5};

    manager->addComponent(one, new Position({pos->pos.x + 10, pos->pos.y + 170}));
    manager->addComponent(one, new Velocity({-2, -2}));
    manager->addComponent(one, new Sprite("assets/Game/enemy_shoot_one.png", {pos->pos.x + 10, pos->pos.y + 30}, Rect, {3, 3}));
    manager->addComponent(one, new Hitbox({ 9 * 3., 5 * 3.}));
    manager->addComponent(one, new Type(TYPE_BOSS_SHOOT));
    manager->addComponent(one, new Stats(10, 10, 0, 1));
    manager->addComponent(one, new Clock(0.3f, 0.3f, 0.1f, 2.f));

    manager->addComponent(two, new Position({pos->pos.x + 10, pos->pos.y + hitbox->y - 170}));
    manager->addComponent(two, new Velocity({-2, 2}));
    manager->addComponent(two, new Sprite("assets/Game/enemy_shoot_one.png", {pos->pos.x + 10, pos->pos.y + 30}, Rect, {3, 3}));
    manager->addComponent(two, new Hitbox({ 9 * 3., 5 * 3.}));
    manager->addComponent(two, new Type(TYPE_BOSS_SHOOT));
    manager->addComponent(two, new Stats(10, 10, 0, 1));
    manager->addComponent(two, new Clock(0.3f, 0.3f, 0.1f, 2.f));

    manager->subscribeEntityToSystems(one);
    manager->subscribeEntityToSystems(two);

    return;
}

void createBoss(rtype::Manager *manager)
{
    rtype::Entity e = manager->createEntity();
    sf::Vector2f pos = {WIDTH, HEIGHT/2 - (260 * 3.)/2};

    sf::IntRect Rect = {0, 0, 143, 260};

    manager->addComponent(e, new Position(pos));
    manager->addComponent(e, new Velocity({-2, 0}));
    manager->addComponent(e, new Sprite("assets/Game/boss_one.png", pos, Rect, {3, 3}));
    manager->addComponent(e, new Hitbox({ 143 * 3., 260 * 3.}));
    manager->addComponent(e, new Type(TYPE_BOSS_ONE));
    manager->addComponent(e, new Stats(2000, 10, 0, 1));
    manager->addComponent(e, new Clock(0.3f, 0.3f, 0.01f, 10.f));
	/* TO DO: Add component clock for enemy to manage shoot */

    manager->subscribeEntityToSystems(e);

    return;
}
