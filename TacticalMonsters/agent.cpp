#include "agent.h"
#include <QLabel>
#include "hexa.h"
#include <QMouseEvent>

Agent * Agent::clicked_agent = nullptr;

void Agent::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {

        clicked_agent = (clicked_agent == nullptr) ? this : nullptr;

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
        setGeometry(located_hexa->get_x_position(), located_hexa->get_y_position(), 50, 50);

        located_hexa->located_agent = this;
    }
}

Agent::Agent(char player_type, QWidget * parent) : QLabel(parent){
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
