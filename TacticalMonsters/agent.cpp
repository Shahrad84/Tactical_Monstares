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
    if (event->button() == Qt::LeftButton && playPage->turn == ownership)
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

Agent::Agent(char input_ownership, QWidget * parent, play_page * page, string input_name) : QLabel(parent){

    if(playPage == nullptr){
        playPage = page;
    }

    size = 50;

    ownership = input_ownership;
    compatible_hexa_types.push_back(ownership);

    name = input_name;

    //Render_Agent();

    located_hexa = nullptr;
    Move(nullptr);

    setMouseTracking(true);
}

void Agent::Render_Agent(){
    if(ownership == '1'){
        setStyleSheet("image: url(:/new/prefix1/heros/hero1.png);");
    }
    else if(ownership == '2'){
        setStyleSheet("image: url(:/new/prefix1/heros/hero2.png);");
    }
}

void Agent::LockAgent(bool lockMode){
    setEnabled(!lockMode);
    isLock = lockMode;
}

bool Agent::get_isLock(){
    return isLock;
}

bool Agent::is_hexa_compatible_with_agent(Hexa * target_hexa){

    for(int i = 0; i < compatible_hexa_types.size(); i++){
        if(compatible_hexa_types[i] == target_hexa->get_type()){
            return true;
        }
    }

    return false;
}
