#include "cart.h"

cart::cart(QLabel *inputQLabel, char inputOwnership, QWidget *parent)
    : QLabel(parent), ownership(inputOwnership)
{
    qlabel = inputQLabel;

    qlabel->setMouseTracking(true);
    qlabel->installEventFilter(this);
    qlabel->setMouseTracking(true);

    isSelected = false;
}

bool cart::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == qlabel && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {

            if(isSelected){
                qlabel->resize(50, 60);
                isSelected = false;
            }
            else{
                qlabel->resize(60, 70);
                isSelected = true;
            }

            emit clicked();
            return true; // Event handled
        }
    }
    return QWidget::eventFilter(watched, event);
}

bool cart::get_isSelected(){
    return isSelected;
}
