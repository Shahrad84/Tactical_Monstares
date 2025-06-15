#include "levelmanager.h"
#include "agent.h"
#include "hexa.h"

LevelManager::LevelManager(play_page * parent) {
    playPage = parent;
    level = "Placing";
    playPage->write_on_RullLabel("players must place their agents");
    agentLockCount = 0;

    player_1_remained_agents = playPage->player_1_agents.size();
    player_2_remained_agents = playPage->player_2_agents.size();
}

void LevelManager::Update(){
    if(level == "Placing"){
        for(int i = 0; i < 3; i++){
            if(playPage->player_1_agents[i]->located_hexa != nullptr && !playPage->player_1_agents[i]->get_isLock()){
                playPage->player_1_agents[i]->LockAgent(true);
                agentLockCount ++;
            }

            if(playPage->player_2_agents[i]->located_hexa != nullptr && !playPage->player_2_agents[i]->get_isLock()){
                playPage->player_2_agents[i]->LockAgent(true);
                agentLockCount ++;
            }
        }

        if(agentLockCount == 6){
            Go_to_level_Fight();
        }
    }

    // if(level == "Fight"){

    //     int temp = 0;
    //     for(int i = 0; i < 3; i++){
    //         temp = (playPage->player_1_agents[i]) ? temp + 1 : temp;
    //     }
    //     player_1_remained_agents = temp;


    //     temp = 0;
    //     for(int i = 0; i < 3; i++){
    //         temp = (playPage->player_2_agents[i]) ? temp + 1 : temp;
    //     }
    //     player_2_remained_agetns = temp;

    //     if(player_1_remained_agents == 0){
    //         qDebug() << "Player 2 won the game";
    //         playPage->write_on_RullLabel("Player 2 won the game");
    //     }
    //     else if(player_2_remained_agetns == 0){
    //         qDebug() << "Player 1 won the game";
    //         playPage->write_on_RullLabel("Player 2 won the game");
    //     }
    // }
}

void LevelManager::Go_to_level_Fight(){
    level = "Fight";

    for(int i = 0; i < 3; i++){
        playPage->player_1_agents[i]->LockAgent(false);
        playPage->player_2_agents[i]->LockAgent(false);

        playPage->player_1_agents[i]->Unlock_allCompatibleHexas();
        playPage->player_2_agents[i]->Unlock_allCompatibleHexas();
    }

    playPage->write_on_RullLabel("Fight");

    for(int i = 0; i <= 8; i++){
        for(int j = i % 2; j <= 8; j += 2){
            if(playPage->hexa_array[i][j]->get_type() == '1' || playPage->hexa_array[i][j]->get_type() == '2'){
                playPage->hexa_array[i][j]->Set_type('p');
            }

            //qDebug() << "hexa[" << i << j << "] : " << playPage->hexa_array[i][j]->get_type();
        }
    }
}

string LevelManager::get_level(){
    return level;
}

void LevelManager::agentDied(char agentOwnership){
    if(agentOwnership == '1'){
        player_1_remained_agents --;
        qDebug() << player_1_remained_agents;

        if(player_1_remained_agents == 0){
            qDebug() << "Player 2 won the game";
            playPage->write_on_RullLabel("Player 2 won the game");
        }
    }
    else if(agentOwnership == '2'){
        player_2_remained_agents --;
        qDebug() << player_2_remained_agents;


        if(player_2_remained_agents == 0){
            qDebug() << "Player 1 won the game";

            playPage->write_on_RullLabel("Player 1 won the game");
        }
    }
}
