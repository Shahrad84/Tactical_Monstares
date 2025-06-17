#include "waterwaking.h"
#include "QString"

WaterWalking::WaterWalking(char player_type, QWidget* parent, play_page * page, string input_name)
    : Agent(player_type, parent, page, input_name)
{
    Render_Agent();
    setWariourProperties();
}

void WaterWalking::setWariourProperties(){
    if(name == "Billy"){
        HP = 320;mobility = 3;damage = 90;attackRange = 1;
    }
    else if(name == "Reketon"){
        HP = 320;mobility = 2;damage = 80;attackRange = 2;
    }
    else if(name == "Angus"){
        HP = 400;mobility = 2;damage = 100;attackRange = 1;
    }
    else if(name == "Duraham"){
        HP = 320;mobility = 2;damage = 100;attackRange = 2;
    }
    else if(name == "Colonel Baba"){
        HP = 400;mobility = 2;damage = 100;attackRange = 1;
    }
    else if(name == "Medusa"){
        HP = 320;mobility = 2;damage = 100;attackRange = 1;
    }
    else if(name == "Bunka"){
        HP = 320;mobility = 3;damage = 100;attackRange = 1;
    }
    else if(name == "Sanka"){
        HP = 320;mobility = 3;damage = 100;attackRange = 1;
    }
}


void WaterWalking::Unlock_allCompatibleHexas(){
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
