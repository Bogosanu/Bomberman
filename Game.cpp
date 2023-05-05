#include "Game.h"

    [[nodiscard]] const std::array<std::array<int, 19>, 13> &Game::getM() const {
        return m;
    }

    Game::Game() = default;


    Wall &Game::getMbr()  {
        return mbr;
    }

const Player &Game::getPlayer() const {
    return player;
}





void Game::generatelevel(){
        std::ifstream fin("level.txt");
        int i, x, y, hp, n, vsize = 0;
        fin >> x >> y;
        if(player.can_be_placed(x,y,m))
            player.setpos(x,y);
        fin >> n;
        for(i = 0; i < n; ++i){
            fin >> x >> y;
            this->getMbr().getWallmatrix()[x].getRow()[y].setdetails(x,y,2);
            m[x][y] = this->getMbr().getWallmatrix()[x].getRow()[y].gethp();
            obj.emplace_back(std::make_shared<Objective>());
            obj[vsize]->setX(x);
            obj[vsize]->setY(y);
            vsize++;
        }
        while(fin >> x >> y >> hp){
            this->getMbr().getWallmatrix()[x].getRow()[y].setdetails(x,y,hp);
            m[x][y] = this->getMbr().getWallmatrix()[x].getRow()[y].gethp();
        }



        this->drawlevel();
    }
    void Game::drawlevel() {
       int i, j, br;
        sf::RenderWindow window(sf::VideoMode(950, 650), "BOMBERMAN", sf::Style::Close | sf::Style::Titlebar);
        std::vector<sf::Sprite> sp_board;
        sf::Sprite player1;
        sf::Sprite curr_brick;
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
        player1.setTexture(player_text);
        player1.setScale(0.5f, 0.5f);
        player1.setPosition(player.getY()*50, player.getX()*50);


        window.setFramerateLimit(7);
        while (window.isOpen()) {
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
                    br = this->getM()[i/50][j/50];
                    if (br == 9){
                        curr_brick.setTexture(hardbrick);
                        curr_brick.setScale(0.5f, 0.5f);
                        curr_brick.setPosition(float(j), float(i));
                        sp_board.push_back(curr_brick);
                    }
                    else if (br == 1) {
                        curr_brick.setTexture(softbrick);
                        curr_brick.setScale(0.5f, 0.5f);
                        curr_brick.setPosition(float(j), float(i));
                        sp_board.push_back(curr_brick);
                    }
                    else if (br == 2){
                        curr_brick.setTexture(objective);
                        curr_brick.setScale(0.5f, 0.5f);
                        curr_brick.setPosition(float(j), float(i));
                        sp_board.push_back(curr_brick);
                    }

                }

            }

            ///MOVEMENT
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
                sf::Vector2f pos = player1.getPosition();
                try {
                    if (m[pos.y / 50 + 1][pos.x / 50] == 0) {
                        pos.y += 50;
                        player.setpos(pos.y / 50, pos.x / 50);
                        player1.setPosition(pos);
                    }
                    else throw Unreachable();
                }
                catch (const Exception& e) {
                    std::cout<<"Error: "<<e.what();
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
                sf::Vector2f pos = player1.getPosition();
                try {
                    if (m[pos.y / 50 - 1][pos.x / 50] == 0) {
                        pos.y -= 50;
                        player.setpos(pos.y / 50, pos.x / 50);
                        player1.setPosition(pos);
                    }
                    else throw Unreachable();
                }
                catch (const Exception& e) {
                    std::cout<<"Error: "<<e.what();
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
                sf::Vector2f pos = player1.getPosition();
                try {
                    if (m[pos.y / 50][pos.x / 50 - 1] == 0) {
                        pos.x -= 50;
                        player.setpos(pos.y / 50, pos.x / 50);
                        player1.setPosition(pos);
                    }
                    else throw Unreachable();
                }
                catch (const Exception& e) {
                    std::cout<<"Error: "<<e.what();
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
                sf::Vector2f pos = player1.getPosition();
                try {
                    if (m[pos.y / 50][pos.x / 50 + 1] == 0) {
                        pos.x += 50;
                        player.setpos(pos.y / 50, pos.x / 50);
                        player1.setPosition(pos);
                    }
                    else throw Unreachable();
                }
                catch (const Exception& e) {
                    std::cout<<"Error: "<<e.what();
                }
            }
            //////////


            window.draw(player1);
            int n = sp_board.size();
            for(i = 0; i < n; i++)
                window.draw(sp_board[i]);
            window.display();



        }



    }

