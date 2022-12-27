#include "view.h"

View::View(Ctrl *ctrl) : ctrl(ctrl)
{
    homeView = new HomeView(this);
    setMinimumSize(540, 270);
    setMaximumSize(540, 270);
    move(QPoint(600,250));
    homeView->show();
    connect(homeView, &HomeView::toHowItWorksView, this, &View::viewShowHowItWorksView);
    connect(homeView, &HomeView::toOptimizerView, this, &View::viewShowOptimizerView);
    connect(homeView, &HomeView::toEditDBView, this, &View::viewShowEditDBView);
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/images/traffic.png"));
    setWindowTitle("Traffic Lights Optimizer");
}

void View::hideCurrentView()
{
    if (homeView != nullptr && homeView->isVisible())
        homeView->hide();
    if (howItWorksView != nullptr && howItWorksView->isVisible())
        howItWorksView->hide();
    if (optimizerView != nullptr && optimizerView->isVisible())
        optimizerView->hide();
    if (barChartView != nullptr && barChartView->isVisible())
        barChartView->hide();
    if (lineChartView != nullptr && lineChartView->isVisible())
        lineChartView->hide();
    if (pieChartView != nullptr && pieChartView->isVisible())
        pieChartView->hide();
    if (editDBView != nullptr && editDBView->isVisible())
        editDBView->hide();
}

void View::windowSize(QWidget *widget)
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-widget->width()) / 2;
    int y = (screenGeometry.height()-widget->height()) / 2;
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    move(QPoint(x,y));

    if(dynamic_cast<HomeView*>(widget) ||
       dynamic_cast<OptimizerView*>(widget))
    {
        setMaximumSize(540, 270);
        setMinimumSize(540, 270);
    }
    if (dynamic_cast<HowItWorksView*>(widget))
    {
        setMaximumSize(1050, 700);
        setMinimumSize(1050, 700);
    }
    if(dynamic_cast<BarChartView*>(widget))
    {
        setMaximumSize(800,700);
        setMinimumSize(800,700);
    }
    if(dynamic_cast<LineChartView*>(widget))
    {
        setMaximumSize(800,700);
        setMinimumSize(800,700);
    }
    if(dynamic_cast<EditDBView*>(widget))
    {
        setMaximumSize(900,700);
        setMinimumSize(900,700);
    }
    if(dynamic_cast<PieChartView*>(widget))
    {
        setMaximumSize(800,600);
        setMinimumSize(800,600);
    }
    widget->show();
}

void View::viewShowHomeView()
{
    hideCurrentView();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x=(screenGeometry.width()-homeView->width())/2;
    int y=(screenGeometry.height()-homeView->height())/2;
    setMinimumSize(540,270);
    setMaximumSize(540,270);
    move(QPoint(x,y));
    homeView->show();
}

void View::viewShowHowItWorksView()
{
    hideCurrentView();
    delete howItWorksView;
    howItWorksView = new HowItWorksView(this);
    windowSize(howItWorksView);

    connect(howItWorksView, &HowItWorksView::toHomeView, this, &View::viewShowHomeView);
}

void View::viewShowOptimizerView()
{
    hideCurrentView();
    delete optimizerView;
    optimizerView = new OptimizerView(this);
    windowSize(optimizerView);
    optimizerView->show();

    connect(optimizerView, &OptimizerView::toHomeView, this, &View::viewShowHomeView);
    connect(optimizerView, &OptimizerView::toBarChartView, this, &View::viewShowBarChartView);
    connect(optimizerView, &OptimizerView::toLineChartView, this, &View::viewShowLineChartView);
    connect(optimizerView, &OptimizerView::toPieChartView, this, &View::viewShowPieChartView);
}

void View::viewShowBarChartView()
{
    QDate date1;
    QDate date2;
    QStringList list;
    bool ok = false;
    bool check = false;
    
    list = InputDialog::getStrings(this, &ok);
    if (!ok)
        return;

    if(!Model::formatCheck(list[0]) || !Model::formatCheck(list[1]))
    {
        QMessageBox::warning(this, "Bar Chart", "Formato data non valido!");
        return;
    }

    // assegna i due valori della lista a date1 e date2
    date1 = QDate::fromString(list[0], "dd/MM/yyyy");
    date2 = QDate::fromString(list[1], "dd/MM/yyyy");

    if(!Model::dateCheck(date1, date2))
        return;

    hideCurrentView();
    delete barChartView;
    BarChartModel *barChartModel = new BarChartModel(date1, date2);
    barChartView = new BarChartView(barChartModel, this);
    windowSize(barChartView);
    barChartView->show();

    connect(barChartView, &BarChartView::toOptimizerView, this, &View::viewShowOptimizerView);
}

void View::viewShowLineChartView()
{
    bool ok = false;
    QString str = QInputDialog::getText(this, "Line Chart", "Inserisci una data (dd/MM/yyyy):", QLineEdit::Normal, "", &ok);
    if (!ok)
        return;
    
    if(!Model::formatCheck(str))
    {
        QMessageBox::warning(this, "Line Chart", "Formato data non valido!");
        return;
    }

    QDate data = QDate::fromString(str, "dd/MM/yyyy");

    if (!Model::dateCheck(data, data))
        return;

    hideCurrentView();
    delete lineChartView;


    LineChartModel *lineChartModel = new LineChartModel(data);
    lineChartView = new LineChartView(lineChartModel, this);
    windowSize(lineChartView);
    lineChartView->show();

    connect(lineChartView, &LineChartView::toOptimizerView, this, &View::viewShowOptimizerView);
}

void View::viewShowPieChartView()
{
    bool ok;
    bool check = false;
    QStringList list = InputDialog::getStrings(this, &ok);
    if (!ok)
        return;

    if(!Model::formatCheck(list[0]) || !Model::formatCheck(list[1]))
    {
        QMessageBox::warning(this, "Pie Chart", "Formato data non valido!");
        return;
    }
    // assegna i due valori della lista a date1 e date2
    QDate data1 = QDate::fromString(list[0], "dd/MM/yyyy");
    QDate data2 = QDate::fromString(list[1], "dd/MM/yyyy");

    if(!Model::dateCheck(data1, data2))
        return;

    hideCurrentView();

    if (pieChartModel)
    {
        delete pieChartModel;
        pieChartModel = nullptr;
    }
    pieChartModel = new PieChartModel(data1, data2);

    if (pieChartView){
        delete pieChartView;
        pieChartView = nullptr;
    }
    pieChartView = new PieChartView(pieChartModel, this);

    windowSize(pieChartView);
    pieChartView->show();

    connect(pieChartView, &PieChartView::toOptimizerView, this, &View::viewShowOptimizerView);
}

void View::viewShowEditDBView()
{
    hideCurrentView();
    delete editDBView;
    editDBView = new EditDBView(this);
    windowSize(editDBView);
    editDBView->show();

    connect(editDBView, &EditDBView::toHomeView, this, &View::viewShowHomeView);
}