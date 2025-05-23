#include "inrangesystem.h"

play_page * InRangeSystem::playPage = nullptr;

InRangeSystem::InRangeSystem(play_page * input_playPage) {
    if(playPage == nullptr){
        playPage = input_playPage;
    }
}

queue <Hexa *> InRangeSystem::Find_in_range(Hexa * origin, int range){
    int depth = 0;
    clear_queue_and_vector();

    inProcess.push(origin);
    visited.push_back(origin);
    result.push(origin);

    while(!inProcess.empty() && depth < range){
        int levelSize = inProcess.size();

        for(int i = 0; i < levelSize; i++){
            Hexa  * current = inProcess.front();
            inProcess.pop();

            for(int j = 0; j < 4; j++){
                Hexa * neighbor = current->get_member_of_neighbors(j);

                if(neighbor && !isVisited(visited, neighbor) && neighbor->get_type() != '#'){
                    if(!find_in_queue(neighbor, inProcess)){
                        //qDebug() << neighbor->get_i() << ", " << neighbor->get_j();
                        visited.push_back(neighbor);
                        inProcess.push(neighbor);
                        result.push(neighbor);
                    }
                }
            }
        }
        depth ++;
    }

    return result;
}

void InRangeSystem::clear_queue_and_vector(){
    vector <Hexa *>().swap(visited);
    queue <Hexa *>().swap(inProcess);
    queue <Hexa *>().swap(result);
}

bool InRangeSystem::isVisited(const vector <Hexa*> visited, Hexa * node){
    //Debug() << node->get_i() << ", " << node->get_j();
    return std::find(visited.begin(), visited.end(), node) != visited.end();

    // int s = visited.size();
    // for(int i = 0; i < s; i++){
    //     if(visited[i] == node){
    //         return true;
    //     }
    // }

    // return false;
}

bool InRangeSystem::find_in_queue(Hexa * data, queue<Hexa *> input_q){
    //queue<Hexa *> q = input_q;

    while (!input_q.empty()) {
        if (data == input_q.front()) {
            return true;
        }
        input_q.pop();
    }
    return false;
}
