// hexa.cpp
#include "hexa.h"
#include <QFont>
#include "agent.h"
#include "QDebug"
#include "QMessageBox"
#include "play_page.h"

class Agent;

void Hexa::mousePressEvent(QMouseEvent* event){
    if(event->button() == Qt::LeftButton){
        if(located_agent->clicked_agent != nullptr && located_agent == nullptr && located_agent->clicked_agent->player_1_or_2 == this->type){

            emit clicked();

            Hexa * last_hexa = located_agent->clicked_agent->located_hexa;

            //located_agent->clicked_agent->located_hexa->located_agent = nullptr;

            located_agent->clicked_agent->located_hexa = this;

            this->located_agent = located_agent->clicked_agent;
            //located_agent->clicked_agent = located_agent->clicked_agent;
            located_agent->clicked_agent->Move(this);
            located_agent->clicked_agent = nullptr;

            if(last_hexa != nullptr){
                last_hexa->located_agent = nullptr;
            }

            located_agent->change_turn();

        }
    }

    QLabel::mousePressEvent(event);
}

void Hexa::Set_type(char input_type = 'p'){

    type = input_type;
    //setStyleSheet("image: url(:/new/prefix1/hex_ver_1.png);");

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
        setStyleSheet("image: url(:/new/prefix1/hex_ver_w.png);");
        break;

    case '#':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_r.png);");
        break;
    }
}


Hexa::Hexa(int row, int col, QWidget *parent) : QLabel(parent){

    Set_type();
    setFont(QFont("Arial", 12, QFont::Bold));
    setAlignment(Qt::AlignCenter);

    x_pos = 220 + 40 * col;
    y_pos = (col % 2 == 0) ? 140 + 60 * row : 170 + 60 * row;
    setGeometry(x_pos, y_pos, 50, 50);

    setAlignment(Qt::AlignCenter);
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
