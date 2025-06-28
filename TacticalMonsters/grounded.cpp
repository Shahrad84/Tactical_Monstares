#include "grounded.h"
#include "QString"

Grounded::Grounded(char player_type, QWidget* parent, play_page * page, string input_name)
    : Agent(player_type, parent, page, input_name)
{
    Render_Agent();
    setWariourProperties();
}

void Grounded::setWariourProperties(){
    if(name == "Sir Lamorak"){
        HP = 320;mobility = 3;damage = 110;attackRange = 1;
    }
    if(name == "Kabu"){
        HP = 400;mobility = 2;damage = 120;attackRange = 1;
    }
    if(name == "Rajakal"){
        HP = 320;mobility = 2;damage = 130;attackRange = 1;
    }
    if(name == "Salih"){
        HP = 400;mobility = 2;damage = 80;attackRange = 1;
    }
    if(name == "Khan"){
        HP = 320;mobility = 2;damage = 90;attackRange = 1;
    }
    if(name == "Boi"){
        HP = 400;mobility = 2;damage = 100;attackRange = 1;
    }
    if(name == "Eloi"){
        HP = 240;mobility = 2;damage = 100;attackRange = 2;
    }
    if(name == "Kanar"){
        HP = 160;mobility = 2;damage = 100;attackRange = 2;
    }
    if(name == "Elsa"){
        HP = 320;mobility = 2;damage = 140;attackRange = 2;
    }
    if(name == "Karissa"){
        HP = 280;mobility = 2;damage = 80;attackRange = 2;
    }
    if(name == "Sir Philip"){
        HP = 400;mobility = 2;damage = 100;attackRange = 1;
    }
    if(name == "Frost"){
        HP = 260;mobility = 2;damage = 80;attackRange = 2;
    }
    if(name == "Tusk"){
        HP = 400;mobility = 2;damage = 100;attackRange = 1;
    }


}


void Grounded::Unlock_allCompatibleHexas(){
    compatible_types_to_PASS.push_back('p');

    compatible_types_to_LOCATE.push_back('p');
}

// void Floating::Render_Agent(){
//     setStyleSheet("image: url(:/new/prefix1/heros/" + QString::fromStdString(name) + ".png);");
// }
