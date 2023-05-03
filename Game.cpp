#include <SFML/Graphics.hpp>
#include "Game.h"

    [[nodiscard]] const std::array<std::array<int, 19>, 13> &Game::getM() const {
        return m;
    }

    Game::Game() = default;


    Wall &Game::getMbr()  {
        return mbr;
    }





    void Game::generatelevel(){
        std::ifstream fin("level.txt");
        /*std::cout<<"  _                     _                                     \n"
                   " | |                   | |                                    \n"
                   " | |__   ___  _ __ ___ | |__   ___ _ __ _ __ ___   __ _ _ __  \n"
                   " | '_ \\ / _ \\| '_ ` _ \\| '_ \\ / _ \\ '__| '_ ` _ \\ / _` | '_ \\ \n"
                   " | |_) | (_) | | | | | | |_) |  __/ |  | | | | | | (_| | | | |\n"
                   " |_.__/ \\___/|_| |_| |_|_.__/ \\___|_|  |_| |_| |_|\\__,_|_| |_|\n"
                   "                                                              \n"
                   "                                                              \n";
        std::cout<<"Datele nivelului sunt in fisierul level.txt\n";
        std::cout<<"| caramizi indestructibile \n";
        std::cout<<"% caramizi destructibile \n";
        std::cout<<"* obiective \n";
        std::cout<<"? power up \n";
*/
        int x, y, hp;
        while(fin>> x >> y >> hp){
            this->getMbr().getWallmatrix()[x].getRow()[y].setdetails(x,y,hp);
            m[x][y] = this->getMbr().getWallmatrix()[x].getRow()[y].gethp();
        }
        this->drawlevel();
    }
    void Game::drawlevel() {
       int i, j, br;
      /*  for(i = 0; i <= 12; i++) {
            for (j = 0; j <= 18; j++) {
                br = this->getM()[i][j];
                if (br >= 2)
                    if (j == 0 || j == 18 )
                        std::cout << "|";
                    else if(i == 0 || i == 12)
                        std::cout << "_";
                    else std::cout << "|";
                else if (br == 1)
                    std::cout << "%";
                else std::cout << " ";
            }
            std::cout << "\n";
        }
*/
        sf::RenderWindow window(sf::VideoMode(650, 950), "BOMBERMAN", sf::Style::Close | sf::Style::Titlebar);
        std::vector<sf::Sprite> sp_board;
        std::vector<sf::Texture> tx_board;
        sf::Sprite curr_brick;
        sf::Texture hardbrick;
        hardbrick.loadFromFile("Textures/hardblock2.png");
        sf::Texture softbrick;
        softbrick.loadFromFile("Textures/softblock2.png");
        for (i = 0; i <= 12 * 50; i += 50) {
            for (j = 0; j <= 18 * 50; j += 50) {
                br = this->getM()[i/50][j/50];
                if (br >= 2){
                    curr_brick.setTexture(hardbrick);
                    curr_brick.setScale(0.5f, 0.5f);
                    curr_brick.setPosition(float(i), float(j));
                    sp_board.push_back(curr_brick);
                    tx_board.push_back(hardbrick);
                    //window.draw(curr_brick);
                }
                else if (br == 1){
                    curr_brick.setTexture(softbrick);
                    curr_brick.setScale(0.5f, 0.5f);
                    curr_brick.setPosition(float(i), float(j));
                    sp_board.push_back(curr_brick);
                    tx_board.push_back(softbrick);
                    //window.draw(curr_brick);

                }
            }
        }

            while (window.isOpen()) {
                sf::Event evnt;
                window.clear(sf::Color::Black);
                int n = sp_board.size();
                 for(i = 0; i < n; i++){
                     window.draw(sp_board[i]);
                 }


                while (window.pollEvent(evnt)) {
                    switch (evnt.type) {
                        case sf::Event::Closed:
                            window.close();
                            break;
                    }
                    window.display();
                }
            }



    }

