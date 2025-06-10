//hexa.cpp
#include "hexa.h"
#include <QFont>
#include "agent.h"
#include "QDebug"
#include "QMessageBox"
#include "play_page.h"
#include "random"

class Agent;

play_page * Hexa::playPage = nullptr;

void Hexa::mousePressEvent(QMouseEvent* event){
    if(event->button() == Qt::LeftButton){

        if(Agent::clicked_agent != nullptr && located_agent == nullptr){

            if(((playPage->in_range_system->find_in_queue(this, playPage->in_range_system->get_movebale_hexas())) || !Agent::clicked_agent->located_hexa)
                && Agent::clicked_agent->is_hexa_compatible(this, Agent::clicked_agent->compatible_types_to_LOCATE)){
                emit clicked();

                Hexa * privious_hexa = Agent::clicked_agent->located_hexa;

                Agent::clicked_agent->located_hexa = this;

                located_agent = Agent::clicked_agent;

                Agent::clicked_agent->Move(this);
                Agent::clicked_agent = nullptr;

                if(privious_hexa != nullptr){
                    privious_hexa->located_agent = nullptr;
                }

                playPage->change_turn();
                playPage->level_maganer->Update();

                playPage->in_range_system->clear_queue_and_vector();
            }
        }

        else if(Agent::clicked_agent != nullptr && located_agent->ownership != Agent::clicked_agent->ownership){
            if(playPage->in_range_system->find_in_queue(this, playPage->in_range_system->get_attackable_hexas())){


                Agent::clicked_agent->Attack(located_agent);

                playPage->in_range_system->clear_queue_and_vector();
                playPage->in_range_system->Find_in_range(located_agent, 1);

                Hexa * privious_hexa = Agent::clicked_agent->located_hexa;

                int r = rand() % playPage->in_range_system->get_movebale_hexas().size();
                Agent::clicked_agent->Move(playPage->in_range_system->movebale_hexas_with_index(r));
                playPage->in_range_system->clear_queue_and_vector();

                //Agent::clicked_agent->located_hexa = nullptr;
                Agent::clicked_agent = nullptr;
                //located_agent = nullptr;

                privious_hexa->located_agent = nullptr;
                playPage->change_turn();
                playPage->level_maganer->Update();
            }
        }
    }

    QLabel::mousePressEvent(event);
}

void Hexa::Set_type(char input_type){
    type = input_type;
    Render(type);
}

void Hexa::Render(char ch){

    switch (ch) {
    case 'p':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_p.png);");
        break;

    case '1':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_1.png);");
        break;

    case '2':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_2.png);");
        break;

    case 'y':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_y.png);");
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

    case 'r':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_r.png);");
        break;
    }

}


Hexa::Hexa(int row, int col, QWidget *parent, play_page * page) : QLabel(parent){

    if(playPage == nullptr){
        playPage = page;
    }

    setFont(QFont("Arial", 12, QFont::Bold));
    setAlignment(Qt::AlignCenter);

    x_pos = 390 + 70 * col;
    y_pos = 200 + 40 * row;
    setGeometry(x_pos, y_pos, size, size);

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


void Hexa::printStatus(){
    qDebug() << get_i() << get_j();
}
