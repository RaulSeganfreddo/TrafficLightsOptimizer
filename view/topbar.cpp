#include "topbar.h"

TopBar::TopBar(QPushButton *left, QLabel* center, QPixmap btnIcon)
{
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(left);
    layout->addWidget(center);
    
    left->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    left->setStyleSheet("border:2px solid #ededed;");
    left->setIconSize(QSize(50,50));
    left->resize(QSize(50,50));
    left->setIcon(QIcon(btnIcon));
    left->setCursor(Qt::PointingHandCursor);

    QColor color(0,0,0,0);
    QPalette palette(left->palette());
    palette.setColor(QPalette::Button, color);

    layout->setAlignment(left, Qt::AlignLeft);
    layout->setAlignment(center, Qt::AlignLeft);

    this->setLayout(layout);
}