#include "play_page.h"
#include "ui_play_page.h"

#include "hexa.h"
#include "QLabel"

play_page::play_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::play_page)
{
    ui->setupUi(this);

    Hexa * hexa_array[9][5];

    // Create an instance of your custom label

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 9; j++){
            hexa_array[i][j] = new Hexa(i, j, this);
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

    // Set the label as central widget or position it as needed
    //setCentralWidget(myCustomLabel);

    // Or if you want to position it:
    // myCustomLabel->setGeometry(50, 50, 200, 50);

    setWindowTitle("play_page");

    setMaximumSize(800, 600);
    setMinimumSize(800, 600);
}

play_page::~play_page()
{
    delete ui;
}
