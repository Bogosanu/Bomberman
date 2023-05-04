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
        int i, x, y, hp, n;
        fin>>n;
        for(i = 0; i < n; ++i){
            fin >> x >> y;
            this->getMbr().getWallmatrix()[x].getRow()[y].setdetails(x,y,2);
            m[x][y] = this->getMbr().getWallmatrix()[x].getRow()[y].gethp();
        }
        while(fin >> x >> y >> hp){
            this->getMbr().getWallmatrix()[x].getRow()[y].setdetails(x,y,hp);
            m[x][y] = this->getMbr().getWallmatrix()[x].getRow()[y].gethp();
        }
        if(player.can_be_placed(1,1,m))
            player.setpos(1,1);



        this->drawlevel();
    }
    void Game::drawlevel() {
       int i, j, br;
        sf::RenderWindow window(sf::VideoMode(950, 650), "BOMBERMAN", sf::Style::Close | sf::Style::Titlebar);
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


        window.setFramerateLimit(15);
        while (window.isOpen()) {
            sf::Event evnt;
            for (i = 0; i <= 12 * 50; i += 50) {
                for (j = 0; j <= 18 * 50; j += 50) {
                    br = m[i/50][j/50];
                    if (br == 9){
                        curr_brick.setTexture(hardbrick);
                        curr_brick.setScale(0.5f, 0.5f);
                        curr_brick.setPosition(float(j), float(i));
                    }
                    else if (br == 1) {
                        curr_brick.setTexture(softbrick);
                        curr_brick.setScale(0.5f, 0.5f);
                        curr_brick.setPosition(float(j), float(i));
                    }
                    else if (br == 2){
                        curr_brick.setTexture(objective);
                        curr_brick.setScale(0.5f, 0.5f);
                        curr_brick.setPosition(float(j), float(i));
                    }
                    else if (br == 0 && j == player.getX() && i == player.getY()){
                        curr_brick.setTexture(objective);
                        curr_brick.setScale(0.5f, 0.5f);
                        curr_brick.setPosition(float(j), float(i));
                    }
                    window.draw(curr_brick);

                }
            }



            while (window.pollEvent(evnt)) {
                switch (evnt.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    default:
                        continue;
                }

            }
            window.display();

        }



    }


