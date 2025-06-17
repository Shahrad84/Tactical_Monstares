#include "agent.h"
#include <QLabel>
#include "hexa.h"
#include <QMouseEvent>
#include <play_page.h>
#include <QDebug>
#include "queue"
using std::queue;

play_page * Agent::playPage = nullptr;

Agent * Agent::clicked_agent = nullptr;

InRangeSystem * Agent::in_range_system = nullptr;

void Agent::mousePressEvent(QMouseEvent* event)
{

    qDebug() << "ii";
    if (event->button() == Qt::LeftButton && playPage->turn == ownership)
    {
        //Agent * priviousClicked = clicked_agent;


        if(clicked_agent == this){
            size = 50;
            resize(size, size);
            playPage->in_range_system->clear_queue_and_vector();
            clicked_agent = nullptr;
        }
        else{
            clicked_agent = this;
            size = 60;
            resize(size, size);
            if(located_hexa != nullptr){
                playPage->in_range_system->Find_in_range(this, mobility);
            }
        }


        // if(located_hexa != nullptr){
        //     playPage->in_range_system->Find_in_range(this, mobility);
        // }

        // clicked_agent = (clicked_agent == nullptr) ? this : nullptr;
        // size = (clicked_agent == this) ? 60 : 50;
        // resize(size, size);

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
        setGeometry(located_hexa->get_x_position() + 5, located_hexa->get_y_position() + 5, size, size);

        located_hexa->located_agent = this;
    }
}

Agent::Agent(char input_ownership, QWidget * parent, play_page * page, string input_name) : QLabel(parent){

    if(playPage == nullptr){
        playPage = page;
    }

    size = 50;

    ownership = input_ownership;
    compatible_types_to_LOCATE.push_back(ownership);

    name = input_name;

    Render_Agent();

    located_hexa = nullptr;
    Move(nullptr);

    setMouseTracking(true);
}

void Agent::Render_Agent(){
    // if(ownership == '1'){
    //     setStyleSheet("image: url(:/new/prefix1/heros/hero1.png);");
    // }
    // else if(ownership == '2'){
    //     setStyleSheet("image: url(:/new/prefix1/heros/hero2.png);");
    // }

    setStyleSheet("image: url(:/new/prefix1/heros/" + QString::fromStdString(name) + ".png);");
}

void Agent::LockAgent(bool lockMode){
    setEnabled(!lockMode);
    isLock = lockMode;
}

bool Agent::get_isLock(){
    return isLock;
}

bool Agent::is_hexa_compatible(Hexa * target_hexa, vector <char> v){

    for(int i = 0; i < v.size(); i++){
        if(v[i] == target_hexa->get_type()){
            return true;
        }
    }

    return false;
}

void Agent::Attack(Agent * target_agent){
    target_agent->reduce_HP(damage);
    if(target_agent->get_HP() > 0){
        reduce_HP(target_agent->get_damage() / 2);
    }
}

int Agent::get_HP(){return HP;}
int Agent::get_damage(){return damage;}

void Agent::reduce_HP(int decrement){
    HP -= decrement;
    if(HP <= 0){
        this->deleteLater();
    }
}

Agent::~Agent(){
    Hexa * privious_hexa = located_hexa;
    located_hexa = nullptr;
    privious_hexa->located_agent = nullptr;
    playPage->level_maganer->agentDied(ownership);
}
