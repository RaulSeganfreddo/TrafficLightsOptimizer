#ifndef VIEW_H
#define VIEW_H

#include "model.h"
#include "ctrl.h"
#include "view/homeview.h"
#include "view/howitworksview.h"
#include "view/optimizerview.h"
#include "view/barchartview.h"
#include "view/linechartview.h"
#include "view/piechartview.h"
#include "view/editDBview.h"
#include "view/inputdialog.h"
#include "model/database.h"
#include "model/record.h"
#include "model/barchartmodel.h"
#include "model/linechartmodel.h"
#include "model/piechartmodel.h"
#include "ctrl.h"

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QDialog>
#include <QInputDialog>
#include <QDir>

class Ctrl;
class Model;
class HomeView;
class DBIO;
class HowItWorksView;
class OptimizerView;
class BarChartView;
class LineChartView;
class PieChartView;
class editDBView;
class InputDialog;

class View : public QWidget
{
    Q_OBJECT
private:
    Ctrl *ctrl;
    
    HomeView *homeView = nullptr;
    OptimizerView *optimizerView = nullptr;
    HowItWorksView *howItWorksView = nullptr;
    EditDBView *editDBView = nullptr;
    BarChartView *barChartView = nullptr;
    LineChartView *lineChartView = nullptr;
    PieChartView *pieChartView = nullptr;

    PieChartModel *pieChartModel = nullptr;

public:
    /*
     * @brief Costruttore della classe View
     * @param ctrl Controller
     * @param parent Oggetto padre
     */
    explicit View(Ctrl *ctrl);

    /*
     * @brief Metodo che permette di nascondere la view corrente
     */
    void hideCurrentView();

    /*
     * @brief Metodo che permette di impostare la size della view
     */
    void windowSize(QWidget *widget);
    

public slots:
    /*
     * @brief Slot che permette di mostrare la howItWorksView
     */
    void viewShowHowItWorksView();

    /*
     * @brief Slot che permette di mostrare la homeView
     */
    void viewShowHomeView();

    /*
     * @brief Slot che permette di mostrare la optimizerView
     */
    void viewShowOptimizerView();

    /*
     * @brief Slot che permette di mostrare la barChartView
     */
    void viewShowBarChartView();

    /*
     * @brief Slot che permette di mostrare la lineChartView
     */
    void viewShowLineChartView();

    /*
     * @brief Slot che permette di mostrare la pieChartView
     */
    void viewShowPieChartView();

    /*
     * @brief Slot che permette di mostrare la editDBView
     */
    void viewShowEditDBView();
};

#endif // VIEW_H