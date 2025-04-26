#include "play_page.h"
#include "ui_play_page.h"

#include "hexa.h"
#include "QLabel"
#include "agent.h"
#include "QString"

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

    int row = 0;

    for(int i = 1; i < lines.size(); i += 2){

        if(i + 1 >= lines.size()){
            break;
        }

        QString evenLine = lines[i];
        QString oddLine = lines[i + 1];

        // 1, 7, 13, ...
        for(int col = 0, j = 1; j < evenLine.length(); col += 2, j += 6){
            extracted_datas_from_txtFile[row][col] = evenLine[j].toLatin1();
        }

        // 4, 6, 10, ...
        for(int col = 1, j = 4; j < oddLine.length(); col += 2, j += 6){
            extracted_datas_from_txtFile[row][col] = oddLine[j].toLatin1();
        }

        row ++;
    }
}

play_page::play_page(QString player_1_name, QString player_2_name, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::play_page)
{
    ui->setupUi(this);

    ui->player1_groupBox->setTitle(player_1_name);
    ui->player2_groupBox->setTitle(player_2_name);

    change_turn();

    Hexa * hexa_array[9][5];

    QString adress = ":/new/prefix1/grid" + QString::number((rand() % 8) + 1) + ".txt";
    parse(adress);


    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 9; j++){
            hexa_array[i][j] = new Hexa(i, j, this, this);
            hexa_array[i][j]->Set_type(extracted_datas_from_txtFile[i][j].toLatin1());
        }
    }

    for(int j = 0; j < 9; j++){
        if(j % 2 != 0){
            hexa_array[4][j] = NULL;
        }
        else{
            hexa_array[4][j] = new Hexa(4, j, this, this);
            hexa_array[4][j]->Set_type(extracted_datas_from_txtFile[4][j].toLatin1());
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
}



play_page::~play_page()
{
    delete ui;
}
