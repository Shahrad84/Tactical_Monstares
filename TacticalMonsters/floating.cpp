#include "floating.h"
#include "QString"

Floating::Floating(char player_type, QWidget* parent, play_page * page, string input_name)
    : Agent(player_type, parent, page, input_name)
{
    Render_Agent();
    setWariourProperties();

}

void Floating::setWariourProperties(){
    if(name == "Sabrina"){
        HP = 320;mobility = 3;damage = 100;attackRange = 1;
    }
    else if(name == "Death"){
        HP = 240;mobility = 3;damage = 120;attackRange = 2;
    }
}


void Floating::Unlock_allCompatibleHexas(){
    compatible_types_to_PASS.push_back('p');
    compatible_types_to_PASS.push_back('~');
    compatible_types_to_PASS.push_back('#');

    compatible_types_to_LOCATE.push_back('p');
    compatible_types_to_LOCATE.push_back('~');
    compatible_types_to_LOCATE.push_back('#');
}

// void Floating::Render_Agent(){
//     setStyleSheet("image: url(:/new/prefix1/heros/" + QString::fromStdString(name) + ".png);");
// }
