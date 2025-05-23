#include "play_page.h"
#include "ui_play_page.h"

#include "hexa.h"
#include "QLabel"
#include "agent.h"
#include "QString"
#include "inrangesystem.h"
#include <queue>
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

        }
    }

    //text(3, 1) = hexa(2, 0)
    //text(5, 1) = hexa(4, 0)
    //text(5, 7) = hexa(4, 2)

    //text(i+1 , 3j+1) = hexa(i, j)
}

play_page::play_page(QString player_1_name, QString player_2_name, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::play_page)
{
    ui->setupUi(this);

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

    for(int i = 0; i < 3; i++){
        Agent * a = new Agent('1', this, this);
        a->setGeometry(50, 70 * (i + 1), 50, 50);
    }

    for(int i = 0; i < 3; i++){
        Agent * a = new Agent('2', this, this);
        a->setGeometry(680, 70 * (i + 1), 50, 50);
    }

    setWindowTitle("play_page");

    setMaximumSize(800, 600);
    setMinimumSize(800, 600);

    in_range_system = new InRangeSystem(this);
    // queue <Hexa *> q = in_range_system->Find_in_range(hexa_array[5][5], 3);
    // while(!q.empty()){
    //     qDebug() << q.front()->get_i() << ", " << q.front()->get_j();
    //     q.front()->Set_type('g');
    //     q.pop();
    // }
    // hexa_array[5][5]->Set_type('d');
}

play_page::~play_page()
{
    delete ui;
}
