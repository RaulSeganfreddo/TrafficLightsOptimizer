#ifndef HOWITWORKSVIEW_H
#define HOWITWORKSVIEW_H

#include "view.h"
#include "view/topbar.h"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QFont>
#include <QCoreApplication>


/*
 * @brief La classe HowItWorksView mostra la schermata che spiega come funziona l'applicazione
 */
class HowItWorksView : public QWidget
{
    Q_OBJECT

public:

    /*
     * @brief Costruttore della classe HowItWorksView
     * @param parent Puntatore al QWidget padre
     */
    explicit HowItWorksView(QWidget *parent = nullptr);

    /*
     * @brief Distruttore della classe HowItWorksView
     */
    ~HowItWorksView();

    /*
     * @brief Metodo che aggiunge i layout alla view
     */
    void addLayouts();

    /*
     * @brief Metodo che si occupa di creare il layout della descrizione
     * @return Puntatore al layout creato
     */
    QLayout* createDescriptionLayout(const QString &title, const QString &description);

    /*
     * @brief Metodo che si occupa di creare il layout dell'immagine
     * @return Puntatore al layout creato
     */
    QLayout* createImageLayout(const QString &imagePath);

private:
    QVBoxLayout *mainLayout;
    QPushButton *home;

signals:
    /*
     * @brief Segnale per tornare alla view HomeView
     */
    void toHomeView();

public slots:
    /*
     * @brief Slot per mostrare la view HomeView
     */
    void showHomeView();
};

#endif // HOWITWORKSVIEW_H
