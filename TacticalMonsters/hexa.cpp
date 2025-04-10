// hexa.cpp
#include "hexa.h"
#include <QFont>

void Hexa::Set_type(char input_type = 'p'){

    type = input_type;
    //setStyleSheet("image: url(:/new/prefix1/hex_ver_1.png);");

    switch (type) {
    case 'p':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_p.png);");
        break;

    case '1':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_1.png);");
        break;

    case '2':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_2.png);");
        break;

    case 'w':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_w.png);");
        break;

    case 'r':
        setStyleSheet("image: url(:/new/prefix1/hex_ver_r.png);");
        break;
    }
}


Hexa::Hexa(int row, int col, QWidget *parent) : QLabel(parent)
{
    // Custom initialization
    //setText("This is my custom label!");
    //setStyleSheet("color: blue; background-color: lightyellow;");

    Set_type();
    setFont(QFont("Arial", 12, QFont::Bold));
    setAlignment(Qt::AlignCenter);

    x_pos = 220 + 40 * col;
    y_pos = (col % 2 == 0) ? 140 + 60 * row : 170 + 60 * row;
    setGeometry(x_pos, y_pos, 50, 50);

    setAlignment(Qt::AlignCenter);
}

Hexa::~Hexa()
{
    // Cleanup if needed
}
