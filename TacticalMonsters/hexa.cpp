//hexa.cpp
#include "hexa.h"
#include <QFont>
#include "agent.h"
#include "QDebug"
#include "QMessageBox"
#include "play_page.h"

class Agent;

play_page * Hexa::playPage = nullptr;

void Hexa::mousePressEvent(QMouseEvent* event){
    if(event->button() == Qt::LeftButton){
        if(Agent::clicked_agent != nullptr && located_agent == nullptr && Agent::clicked_agent->is_hexa_compatible_with_agent(this)){

            emit clicked();

            Hexa * last_hexa = Agent::clicked_agent->located_hexa;

            Agent::clicked_agent->located_hexa = this;

            this->located_agent = Agent::clicked_agent;

            Agent::clicked_agent->Move(this);
            Agent::clicked_agent = nullptr;

            if(last_hexa != nullptr){
                last_hexa->located_agent = nullptr;
            }

            playPage->change_turn();
            playPage->level_maganer->Update();

        }
    }

    QLabel::mousePressEvent(event);
}

void Hexa::Set_type(char input_type){

    type = input_type;

    switch (type) {
    case 'p':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_p.png);");
        break;

    case '1':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_1.png);");
        break;

    case '2':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_2.png);");
        break;

    case '~':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_~.png);");
        break;

    case '#':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_m.png);");
        break;

    case 'g':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_g.png);");
        break;

    case 'd':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_d.png);");
        break;
    }

}


Hexa::Hexa(int row, int col, QWidget *parent, play_page * page) : QLabel(parent){

    if(playPage == nullptr){
        playPage = page;
    }

    setFont(QFont("Arial", 12, QFont::Bold));
    setAlignment(Qt::AlignCenter);

    x_pos = 220 + 38 * col;
    y_pos = 170 + 23 * row;
    setGeometry(x_pos, y_pos, 50, 50);

    setAlignment(Qt::AlignCenter);

    i = row;
    j = col;
    //setNeighbors();
}

Hexa::~Hexa()
{

}

int Hexa::get_x_position(){
    return x_pos;
}

int Hexa::get_y_position(){
    return y_pos;
}

char Hexa::get_type(){
    return type;
}

void Hexa::setNeighbors(){
    up = (i - 2 >= 0) ? playPage->hexa_array[i - 2][j] : NULL;
    down = (i + 2 <= 8) ? playPage->hexa_array[i + 2][j] : NULL;
    right_up = (i - 1 >= 0 && j + 1 <= 8) ? playPage->hexa_array[i - 1][j + 1] : NULL;
    right_down = (i + 1 <= 8 && j + 1 <= 8) ? playPage->hexa_array[i + 1][j + 1] : NULL;
    left_up = (i - 1 >= 0 && j - 1 >= 0) ? playPage->hexa_array[i - 1][j - 1] : NULL;
    left_down = (i + 1 <= 8 && j - 1 >= 0) ? playPage->hexa_array[i + 1][j - 1] : NULL;

    neighbors.push_back(up);
    neighbors.push_back(down);
    neighbors.push_back(right_up);
    neighbors.push_back(right_down);
    neighbors.push_back(left_up);
    neighbors.push_back(left_down);
}

Hexa * Hexa::get_up(){return up;}
Hexa * Hexa::get_down(){return down;}
Hexa * Hexa::get_right_up(){return right_up;}
Hexa * Hexa::get_right_down(){return right_down;}
Hexa * Hexa::get_left_up(){return left_up;}
Hexa * Hexa::get_left_down(){return left_down;}
int Hexa::get_i(){return i;}
int Hexa::get_j(){return j;}
Hexa * Hexa::get_member_of_neighbors(int index){
    if(index < 0 || index > 5){
        return nullptr;
    }
    return neighbors[index];
}

