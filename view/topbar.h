#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QPalette>
#include <QPixmap>
#include <QIcon>
#include <QColor>

/*
 * @brief Questa classe rappresenta la topbar della GUI
 */
class TopBar : public QWidget
{
    Q_OBJECT
public:
    /*
     * @brief Costruttore della classe TopBar
     * @param left Puntatore al bottone per tornare indietro
     * @param center Puntatore al titolo della topbar
     * @param btnIcon Puntatore alla pixmap del bottone per tornare alla home
     */
    explicit TopBar(QPushButton *left, QLabel* center, QPixmap btnIcon);
};

#endif // TOPBAR_H