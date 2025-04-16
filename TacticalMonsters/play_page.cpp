#include "play_page.h"
#include "ui_play_page.h"

#include "hexa.h"
#include "QLabel"
#include "agent.h"
#include "QString"

void play_page::chagne_turn(){
    turn = (turn == '1') ? '2' : '1';
}
void play_page::parse(const QString &filepath){

    fgrid.resize(HEX_ROWS);

    for (int row = 0; row < HEX_ROWS; ++row) {
        fgrid[row].resize(HEX_COLS);
        for (int col = 0; col < HEX_COLS; ++col) {
            fgrid[row][col]= ' ';
        }
    }

    QFile file(filepath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //QMessageBox::critical(this , "error" , "connot open file");
        return;
    }

    QTextStream in(&file);
    QStringList lines;

    while(!in.atEnd()) lines << in.readLine();
    unsigned long row = 0;
    unsigned long col = 0;
    unsigned long l = 0;

    int j = 0;
    int i = 1;

    while(i < lines.size()){

        QString line_e = lines[i];
        QString line_o = lines[i + 1];

        col = 0;
        j = 1;
        while(j < line_e.length()){
            QChar c = line_e[j];
            fgrid[row][col] =c.toLatin1();
            col+=2;
            j +=6;
        }
        col = 1;
        j = 4;
        while(j < line_o.length()){
            fgrid[row][col] = line_o[j];
            col+=2;
            j +=6;
        }

        row++;
        i +=2 ;
    }

    //create_board();
}

play_page::play_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::play_page)
{
    ui->setupUi(this);

    Hexa * hexa_array[9][5];

    QString adress = "E:/qtprojects2/Tactical_Monstares-master/grid" + QString::number((rand() % 8) + 1) + ".txt";
    parse(adress);

    // Create an instance of your custom label

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 9; j++){
            hexa_array[i][j] = new Hexa(i, j, this);
            hexa_array[i][j]->Set_type(fgrid[i][j].toLatin1());
        }
    }

    for(int j = 0; j < 9; j++){
        if(j % 2 != 0){
            hexa_array[4][j] = NULL;
        }
        else{
            hexa_array[4][j] = new Hexa(4, j, this);
        }
    }

    for(int i = 0; i < 3; i++){
        Agent * a = new Agent('1', this);
        a->setGeometry(50, 70 * (i + 1), 50, 50);
    }

    for(int i = 0; i < 3; i++){
        Agent * a = new Agent('2', this);
        a->setGeometry(680, 70 * (i + 1), 50, 50);
    }

    // Set the label as central widget or position it as needed
    //setCentralWidget(myCustomLabel);

    // myCustomLabel->setGeometry(50, 50, 200, 50);

    setWindowTitle("play_page");

    setMaximumSize(800, 600);
    setMinimumSize(800, 600);
}



play_page::~play_page()
{
    delete ui;
}
