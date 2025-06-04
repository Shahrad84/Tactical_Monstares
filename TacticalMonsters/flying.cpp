#include "flying.h"

Flying::Flying(char player_type, QWidget* parent, play_page * page, string input_name)
    : Agent(player_type, parent, page, input_name)
{
    Render_Agent();
}

void Flying::setWariourProperties(){
    if(name == "Sabrina"){
        HP = 320;
        mobility = 3;
        damage = 100;
        attackRange = 1;
    }
    else if(name == "Death"){
        HP = 240;
        mobility = 3;
        damage = 120;
        attackRange = 2;
    }
}
