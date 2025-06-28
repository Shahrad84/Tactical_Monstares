#include "flying.h"
#include "QString"

Flying::Flying(char player_type, QWidget* parent, play_page * page, string input_name)
    : Agent(player_type, parent, page, input_name)
{
    Render_Agent();
    setWariourProperties();
}

void Flying::setWariourProperties(){
    if(name == "Rambo"){
        HP = 320;mobility = 3;damage = 120;attackRange = 1;
    }
}


void Flying::Unlock_allCompatibleHexas(){
    compatible_types_to_PASS.push_back('p');
    compatible_types_to_PASS.push_back('~');
    compatible_types_to_PASS.push_back('#');

    compatible_types_to_LOCATE.push_back('p');
}

// void Floating::Render_Agent(){
//     setStyleSheet("image: url(:/new/prefix1/heros/" + QString::fromStdString(name) + ".png);");
// }
