#include "Game.h"


    [[nodiscard]] const std::array<std::array<int, 19>, 13> &Game::getM() const {
        return m;
    }

    Game::Game() = default;

    Game::Game(const Game &other): mbr{other.mbr}, m{other.m}, player_ghost{other.player_ghost}{
        for(unsigned long i=0; i<other.obj.size(); i++)
        {
            Objective * obj_cl = other.obj[i]->clone();
            obj.emplace_back(obj_cl);
        }

    }


    Wall &Game::getMbr()  {
        return mbr;
    }


Game& Game::operator=(const Game& other) {
    mbr = other.mbr;
    m = other.m;
    player_ghost = other.player_ghost;
    obj = other.obj;
    return *this;
}

void Game::setPlayerGhost(Entity *playerGhost) {
    player_ghost = playerGhost;
}


void Game::generatelevel(){
        std::ifstream fin("level.txt");
        sf::Texture objective_text;
        objective_text.loadFromFile("Textures/objective.png");
        sf::Sprite objective;
        objective.setTexture(objective_text);
        try {
            int x, y, hp, n, vsize = 0;
            fin >> x >> y;
            if (player_ghost->can_be_placed(x, y, m)) {
                player_ghost->setpos(x, y);
            }
            fin >> n;
            for (int i = 0; i < n; ++i) {
                fin >> x >> y;
                this->getMbr().getWallmatrix()[x].getRow()[y].setdetails(x, y, 2);
                m[x][y] = this->getMbr().getWallmatrix()[x].getRow()[y].gethp();
                obj.emplace_back(std::make_shared<Objective>());
                obj[vsize]->setpos(x, y);
                obj[vsize]->setAcquired(false);    //throw in setpos si la player si la objectives
                obj[vsize]->setSprite(objective);
                vsize++;
            }
            while (fin >> x >> y >> hp) {
                this->getMbr().getWallmatrix()[x].getRow()[y].setdetails(x, y, hp);
                m[x][y] = this->getMbr().getWallmatrix()[x].getRow()[y].gethp();
            }
        }
        catch (const Outofbounds& e) {
            std::cout<<"Error: "<<e.what();
        }



        this->drawlevel();
    }
    void Game::drawlevel() {
        int i, j, br, timer = 0;
        int okc = 0, okt = 0, okb = 0, okl = 0, okr = 0;
        Player* playerPtr = dynamic_cast<Player*>(player_ghost);
        sf::RenderWindow window(sf::VideoMode(950, 650), "BOMBERMAN", sf::Style::Close | sf::Style::Titlebar);
        std::vector<sf::Sprite> sp_board;
        sf::Sprite player1;
        sf::Sprite bomb;
        sf::Sprite curr_brick;
        sf::Sprite explosion_center;
        sf::Sprite explosion_top;
        sf::Sprite explosion_bottom;
        sf::Sprite explosion_left;
        sf::Sprite explosion_right;
        sf::Texture spikes_text;
        spikes_text.loadFromFile("Textures/spikes2.png");
        sf::Texture explosion_c;
        explosion_c.loadFromFile("Textures/explosion_center.png");
        sf::Texture explosion_t;
        explosion_t.loadFromFile("Textures/explosion_top.png");
        sf::Texture explosion_b;
        explosion_b.loadFromFile("Textures/explosion_bottom.png");
        sf::Texture explosion_l;
        explosion_l.loadFromFile("Textures/explosion_left.png");
        sf::Texture explosion_r;
        explosion_r.loadFromFile("Textures/explosion_right.png");
        sf::Texture hardbrick;
        hardbrick.loadFromFile("Textures/hardblock2.png");
        sf::Texture softbrick;
        softbrick.loadFromFile("Textures/softblock2.png");
        sf::Texture objective;
        objective.loadFromFile("Textures/objective.png");
        sf::Texture objective_hurt;
        objective_hurt.loadFromFile("Textures/objective_hurt.png");
        sf::Texture player_text;
        player_text.loadFromFile("Textures/player.png");
        sf::Texture bomb_text;
        bomb_text.loadFromFile("Textures/bomb.png");
        player1.setTexture(player_text);
        player1.setScale(0.5f, 0.5f);
        player1.setPosition(player_ghost->getY() * 50, player_ghost->getX() * 50);
        playerPtr->configure_sprite(player1);
        playerPtr->setSprite(player1);
        window.setFramerateLimit(7);
        while (window.isOpen() && playerPtr->isAlive()) {
            sf::Event evnt;
            while (window.pollEvent(evnt)) {
                switch (evnt.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    default:
                        continue;
                }
            }

            sp_board.clear();
            window.clear(sf::Color(74, 93, 35));

            for (i = 0; i <= 12 * 50; i += 50) {
                for (j = 0; j <= 18 * 50; j += 50) {
                    br = this->getM()[i / 50][j / 50];
                    if (br == 9) {
                        curr_brick.setTexture(hardbrick);
                    } else if (br == 1) {
                        curr_brick.setTexture(softbrick);
                    } else if (br == 2) {
                        curr_brick.setTexture(objective);
                    } else if (br == 10) {
                        curr_brick.setTexture(spikes_text);
                    }
                    if (br == 1 || br == 2 || br == 9 || br == 10) {
                        curr_brick.setScale(0.5f, 0.5f);
                        curr_brick.setPosition(float(j), float(i));
                        sp_board.push_back(curr_brick);
                    }


                }

            }

            ///MOVEMENT
            try {
                sf::Vector2f movingpos = player1.getPosition();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                    if (m[movingpos.y / 50 + 1][movingpos.x / 50] == 0) {
                        movingpos.y += 50;
                        playerPtr->setpos(movingpos.y / 50, movingpos.x / 50);
                    } else if (m[movingpos.y / 50 + 1][movingpos.x / 50] == 10) {
                        throw Gameover();
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                    if (m[movingpos.y / 50 - 1][movingpos.x / 50] == 0) {
                        movingpos.y -= 50;
                        playerPtr->setpos(movingpos.y / 50, movingpos.x / 50);
                    } else if (m[movingpos.y / 50 - 1][movingpos.x / 50] == 10) {
                        throw Gameover();
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                    if (m[movingpos.y / 50][movingpos.x / 50 - 1] == 0) {
                        movingpos.x -= 50;
                        playerPtr->setpos(movingpos.y / 50, movingpos.x / 50);
                    } else if (m[movingpos.y / 50][movingpos.x / 50 - 1] == 10) {
                        throw Gameover();
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                    if (m[movingpos.y / 50][movingpos.x / 50 + 1] == 0) {
                        movingpos.x += 50;
                        playerPtr->setpos(movingpos.y / 50, movingpos.x / 50);
                    } else if (m[movingpos.y / 50][movingpos.x / 50 + 1] == 10) {
                        throw Gameover();
                    }
                }
                player1.setPosition(movingpos);
                //////////
                /////////BOMB
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && timer == 0) {
                    sf::Vector2f bombpos = player1.getPosition();
                    bomb.setTexture(bomb_text);
                    bomb.setScale(0.5f, 0.5f);
                    bomb.setPosition(bombpos);
                    timer = 20;
                    m[bombpos.y / 50][bombpos.x /50] = 3; // linia asta e aici ca playerul sa nu poata trece prin bomba (se reseteaza la 0 dupa detonare)

                }
                if (timer > 5) {
                    timer--;
                    window.draw(bomb);
                }
                if (timer == 5) {
                    sf::Vector2f pos = bomb.getPosition();
                    this->getMbr().getWallmatrix()[pos.y / 50].getRow()[pos.x / 50].damagebrick();
                    this->getMbr().getWallmatrix()[pos.y / 50 + 1].getRow()[pos.x / 50].damagebrick();
                    this->getMbr().getWallmatrix()[pos.y / 50 - 1].getRow()[pos.x / 50].damagebrick();
                    this->getMbr().getWallmatrix()[pos.y / 50].getRow()[pos.x / 50 + 1].damagebrick();
                    this->getMbr().getWallmatrix()[pos.y / 50].getRow()[pos.x / 50].damagebrick();
                    if (m[pos.y / 50][pos.x / 50] < 9 && m[pos.y / 50][pos.x / 50] > 0) {
                        m[pos.y / 50][pos.x / 50] = 0;
                    }
                    if (m[pos.y / 50][pos.x / 50] == 0) {
                        okc = 1;
                        explosion_center.setTexture(explosion_c);
                        explosion_center.setScale(3.5f, 3.5f);
                        explosion_center.setPosition(pos);
                    }


                    if (m[pos.y / 50 + 1][pos.x / 50] < 9 && m[pos.y / 50 + 1][pos.x / 50] > 0) {
                        m[pos.y / 50 + 1][pos.x / 50]--;
                    }
                    if (m[pos.y / 50 + 1][pos.x / 50] == 0) {
                        okb = 1;
                        explosion_bottom.setTexture(explosion_b);
                        explosion_bottom.setScale(3.5f, 3.5f);
                        explosion_bottom.setPosition(pos.x, pos.y + 50);
                    }


                    if (m[pos.y / 50 - 1][pos.x / 50] < 9 && m[pos.y / 50 - 1][pos.x / 50] > 0) {
                        m[pos.y / 50 - 1][pos.x / 50]--;
                    }
                    if (m[pos.y / 50 - 1][pos.x / 50] == 0) {
                        okt = 1;
                        explosion_top.setTexture(explosion_t);
                        explosion_top.setScale(3.5f, 3.5f);
                        explosion_top.setPosition(pos.x, pos.y - 50);
                    }


                    if (m[pos.y / 50][pos.x / 50 + 1] < 9 && m[pos.y / 50][pos.x / 50 + 1] > 0) {
                        m[pos.y / 50][pos.x / 50 + 1]--;
                    }
                    if (m[pos.y / 50][pos.x / 50 + 1] == 0) {
                        okr = 1;
                        explosion_right.setTexture(explosion_r);
                        explosion_right.setScale(3.5f, 3.5f);
                        explosion_right.setPosition(pos.x + 50, pos.y);
                    }

                    if (m[pos.y / 50][pos.x / 50 - 1] < 9 && m[pos.y / 50][pos.x / 50 - 1] > 0) {
                        m[pos.y / 50][pos.x / 50 - 1]--;
                    }
                    if (m[pos.y / 50][pos.x / 50 - 1] == 0) {
                        okl = 1;
                        explosion_left.setTexture(explosion_l);
                        explosion_left.setScale(3.5f, 3.5f);
                        explosion_left.setPosition(pos.x - 50, pos.y);
                    }
                    //std::cout<<pos.x<<" "<<pos.y<<"\n";
                    //std::cout<<okl;
                    timer--;

                }
                if (timer < 5 && timer > 0) {
                    if (okc)
                        window.draw(explosion_center);
                    if (okb)
                        window.draw(explosion_bottom);
                    if (okt)
                        window.draw(explosion_top);
                    if (okl)
                        window.draw(explosion_left);
                    if (okr)
                        window.draw(explosion_right);
                    sf::Vector2f playerpos = player1.getPosition();
                    sf::Vector2f bombpos = bomb.getPosition();
                    if ((abs(playerpos.x - bombpos.x) == 50 && abs(playerpos.y - bombpos.y) == 0) ||
                        (abs(playerpos.y - bombpos.y) == 50 && abs(playerpos.x - bombpos.x) == 0) ||
                        playerpos == bombpos) {
                        throw Gameover();
                    }
                    timer--;
                }
            }


            catch (Gameover &e) {
                std::cout << e.what();
                playerPtr->setAlive(false);
                int n = sp_board.size();
                for (i = 0; i < n; i++)
                    window.draw(sp_board[i]); // stilizare game over
                window.display();
                sf::Time sleeptime = sf::seconds(2);
                sf::sleep(sleeptime);
            }
            if (timer == 0) {
                okc = 0;
                okb = 0;
                okt = 0;
                okl = 0;
                okr = 0;
            }
            window.draw(player1);
            int n = sp_board.size();
            for (i = 0; i < n; i++)
                window.draw(sp_board[i]);
            window.display();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }



        }


    }


