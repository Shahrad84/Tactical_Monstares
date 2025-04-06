// hexa.h
#ifndef HEXA_H
#define HEXA_H

#include <QLabel>


class Hexa : public QLabel
{
    Q_OBJECT

public:
    explicit Hexa(int row, int col, QWidget *parent = nullptr);
    ~Hexa();

    void Set_type(char input_type);

    //void Determine_x_and_y(int row, int col);

    // You can add custom methods and signals/slots here


private:
    int x_pos;
    int y_pos;
    char type;
};

#endif // HEXA_H
