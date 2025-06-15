#include "inrangesystem.h"

play_page * InRangeSystem::playPage = nullptr;

InRangeSystem::InRangeSystem(play_page * input_playPage) {
    if(playPage == nullptr){
        playPage = input_playPage;
    }
}

void InRangeSystem::Find_in_range(Agent * agent, int range){
    Hexa * origin = agent->located_hexa;
    int depth = 0;
    //clear_queue_and_vector();

    //qDebug() << "======";

    inProcess.push(origin);
    visited.push_back(origin);
    moveable_hexas.push(origin);

    while(!inProcess.empty() && depth < range){
        int levelSize = inProcess.size();

        for(int i = 0; i < levelSize; i++){
            Hexa  * current = inProcess.front();
            inProcess.pop();

            for(int j = 0; j < 6; j++){
                Hexa * neighbor = current->get_member_of_neighbors(j);

                if(neighbor && !isVisited(visited, neighbor) && agent->is_hexa_compatible(neighbor, agent->compatible_types_to_PASS) && !find_in_queue(neighbor, inProcess)){
                    if(!neighbor->located_agent){
                        visited.push_back(neighbor);
                        inProcess.push(neighbor);
                        moveable_hexas.push(neighbor);
                    }
                    else if(neighbor->located_agent->ownership != agent->ownership && !find_in_queue(neighbor, attackable_hexas)){
                        attackable_hexas.push(neighbor);
                        //qDebug() << "attackable hexa with index" << neighbor->get_i() << neighbor->get_j();
                    }
                }
            }
        }
        depth ++;
    }

    reDraw_hexa(moveable_hexas, 'y', "draw");
    reDraw_hexa(attackable_hexas, 'r', "draw");
}

void InRangeSystem::clear_queue_and_vector(){
    vector <Hexa *>().swap(visited);
    queue <Hexa *>().swap(inProcess);

    reDraw_hexa(moveable_hexas, 'p', "clear");
    queue <Hexa *>().swap(moveable_hexas);

    reDraw_hexa(attackable_hexas, 'p', "clear");
    queue <Hexa *>().swap(attackable_hexas);
}

void InRangeSystem::reDraw_hexa(queue <Hexa *> q, char type, string mode){
    if(mode == "draw"){
        while(!q.empty()){
            q.front()->Render(type);
            q.pop();
        }
    }
    else if(mode == "clear"){
        while(!q.empty()){
            q.front()->Render(q.front()->get_type());
            q.pop();
        }
    }
}

bool InRangeSystem::isVisited(const vector <Hexa*> visited, Hexa * node){
    return std::find(visited.begin(), visited.end(), node) != visited.end();
}

bool InRangeSystem::find_in_queue(Hexa * data, queue<Hexa *> input_q){

    if(data == nullptr){
        return false;
    }

    while (!input_q.empty()) {
        if (data == input_q.front()) {
            return true;
        }
        input_q.pop();
    }
    return false;
}


queue <Hexa *> InRangeSystem::get_attackable_hexas(){
    return attackable_hexas;
}
queue <Hexa *> InRangeSystem::get_movebale_hexas(){
    return moveable_hexas;
}
Hexa * InRangeSystem::movebale_hexas_with_index(int i){
    for(int i = 0; i < moveable_hexas.size() - 1; i++){
        moveable_hexas.front()->Render('p');
        moveable_hexas.pop();
    }

    return moveable_hexas.front();
}
