#include "play_page.h"
#include "ui_play_page.h"

#include "hexa.h"
#include "QLabel"
#include "agent.h"
#include "QString"
#include "inrangesystem.h"
#include <queue>
#include "levelmanager.h"

#include "floating.h"
#include "flying.h"
#include "waterwaking.h"
#include "grounded.h"

using std::queue;


void play_page::change_turn(){
    turn = (turn == '1') ? '2' : '1';

    if(turn == '1'){
        ui->player_1_turn_label->show();
        ui->player_2_turn_label->hide();
    }

    else if(turn == '2'){
        ui->player_1_turn_label->hide();
        ui->player_2_turn_label->show();
    }

    qDebug() << "turn : " << turn;
}

char play_page::turn = '2';

void play_page::parse(const QString &filepath) {

    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    QStringList lines = in.readAll().split('\n');

    QString lines_QStringArray[11];

    for(int i = 0; i < 11; i++){
        lines_QStringArray[i] = lines[i];
    }


    for(int i = 0; i <= 8; i ++){
        for(int j = i % 2; j <= 8; j+= 2){

            extracted_datas_from_txtFile[i][j] = lines_QStringArray[i + 1][3 * j + 1];
            if(extracted_datas_from_txtFile[i][j].toLatin1() == ' '){
                extracted_datas_from_txtFile[i][j] = QChar('p');
            }
        }
    }

    //text(3, 1) = hexa(2, 0)
    //text(5, 1) = hexa(4, 0)
    //text(5, 7) = hexa(4, 2)

    //text(i+1 , 3j+1) = hexa(i, j)
}

play_page::play_page(QString player_1_name, QString player_2_name, vector <cart *> player_1_selectedCarts, vector <cart *> player_2_selectedCarts, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::play_page)
{    
    ui->setupUi(this);

    in_range_system = new InRangeSystem(this);

    ui->player1_groupBox->setTitle(player_1_name);
    ui->player2_groupBox->setTitle(player_2_name);

    change_turn();

    QString adress = ":/new/prefix1/grid" + QString::number((rand() % 8) + 1) + ".txt";
    parse(adress);


    for(int i = 0; i <= 8; i ++){
        for(int j = i % 2; j <= 8; j += 2){

            hexa_array[i][j] = new Hexa(i, j, this, this);
            hexa_array[i][j]->Set_type(extracted_datas_from_txtFile[i][j].toLatin1()); 
        }
    }

    for(int i = 0; i <= 8; i ++){
        for(int j = i % 2; j <= 8; j += 2){
            hexa_array[i][j]->setNeighbors();
        }
    }

    player_1_agents.resize(3);
    player_2_agents.resize(3);
    string t, n;

    for(int i = 0; i < 3; i++){

        n = player_1_selectedCarts[i]->get_subAgentName();
        t = player_1_selectedCarts[i]->get_subAgentType();

        if(t == "Floating"){
            player_1_agents[i] = new Floating('1', this, this, n);
        }
        else if(t == "Flying"){
            player_1_agents[i] = new Flying('1', this, this, n);
        }
        else if(t == "Water Walking"){
            player_1_agents[i] = new WaterWalking('1', this, this, n);
        }
        else if(t == "Grounded"){
            player_1_agents[i] = new Grounded('1', this, this, n);
        }
        player_1_agents[i]->setGeometry(50, 70 * (i + 1), 50, 50);
    }

    for(int i = 0; i < 3; i++){
        n = player_2_selectedCarts[i]->get_subAgentName();
        t = player_2_selectedCarts[i]->get_subAgentType();

        if(t == "Floating"){
            player_2_agents[i] = new Floating('2', this, this, n);
        }
        else if(t == "Flying"){
            player_2_agents[i] = new Flying('2', this, this, n);
        }
        else if(t == "Water Walking"){
            player_2_agents[i] = new WaterWalking('2', this, this, n);
        }
        else if(t == "Grounded"){
            player_2_agents[i] = new Grounded('2', this, this, n);
        }
        player_2_agents[i]->setGeometry(1260, 70 * (i + 1), 50, 50);
    }


    setWindowTitle("play_page");

    setMaximumSize(1400, 840);
    setMinimumSize(1400, 840);

    // queue <Hexa *> q = in_range_system->Find_in_range(hexa_array[5][5], 3);
    // while(!q.empty()){
    //     qDebug() << q.front()->get_i() << ", " << q.front()->get_j();
    //     q.front()->Set_type('g');
    //     q.pop();
    // }
    // hexa_array[5][5]->Set_type('d');

    level_maganer = new LevelManager(this);
}

play_page::~play_page()
{
    delete ui;
}

void play_page::write_on_RullLabel(string str){
    ui->Rull_label->setText(QString::fromStdString(str));
}
