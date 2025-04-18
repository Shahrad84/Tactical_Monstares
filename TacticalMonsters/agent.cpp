#include "agent.h"
#include <QLabel>
#include "hexa.h"
#include <QMouseEvent>
#include <play_page.h>
#include <QDebug>

play_page * Agent::playPage = nullptr;

Agent * Agent::clicked_agent = nullptr;

void Agent::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && playPage->turn == player_1_or_2)
    {
        clicked_agent = (clicked_agent == nullptr) ? this : nullptr;
        size = (clicked_agent == this) ? 60 : 50;
        resize(size, size);

        emit clicked();

    }

    QLabel::mousePressEvent(event);
}

void Agent::Move(Hexa * new_hexa){
    located_hexa = new_hexa;

    if(located_hexa == nullptr){
        setGeometry(20, 20, 50, 50);
    }
    else{
        size = 50;
        setGeometry(located_hexa->get_x_position(), located_hexa->get_y_position(), size, size);

        located_hexa->located_agent = this;
    }
}

Agent::Agent(char player_type, QWidget * parent, play_page * page) : QLabel(parent){

    if(playPage == nullptr){
        playPage = page;
    }

    size = 50;
    player_1_or_2 = player_type;

    if(player_1_or_2 == '1'){
        setStyleSheet("image: url(:/new/prefix1/heros/hero1.png);");
    }
    else if(player_1_or_2 == '2'){
        setStyleSheet("image: url(:/new/prefix1/heros/hero2.png);");
    }

    located_hexa = nullptr;
    Move(nullptr);

    setMouseTracking(true);
}
