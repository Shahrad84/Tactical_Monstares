#include "levelmanager.h"
#include "agent.h"
#include "hexa.h"

LevelManager::LevelManager(play_page * parent) {
    playPage = parent;
    level = "Placing";
    playPage->write_on_RullLabel("players must place their agents");
    agentLockCount = 0;
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
