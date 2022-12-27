#include "view/piechartview.h"

PieChartView::PieChartView(PieChartModel* m, QWidget *parent) : QWidget(parent)
{

    chart = new QChart();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    QLabel *title = new QLabel("Pie Chart");
    title->setFont(QFont("Arial", 20, QFont::Bold));
    backArrow = new QPushButton();
    QPixmap pixHome = QPixmap(QCoreApplication::applicationDirPath() + "/images/backArrowIcon.png");
    QWidget* topBar = new TopBar(backArrow, title, pixHome);

    QHBoxLayout *layout = new QHBoxLayout();
    chart->setTitle("Ottimizzazione media tra le date selezionate");
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(1000);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    applySeries(m->getOttimizzazione1(), m->getOttimizzazione2());

    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(chartView);

    mainLayout->addWidget(topBar);
    mainLayout->addLayout(layout);
    setLayout(mainLayout);
    setMinimumSize(800, 600);
    resize(800, 600);

    connect(backArrow, &QPushButton::clicked, this, &PieChartView::showOptimizerView);
}

PieChartView::~PieChartView()
{
    if (chart != nullptr){
        delete chart;
        chart = nullptr;
    }
    if (backArrow != nullptr){
        delete backArrow;
        backArrow = nullptr;
    }
}

void PieChartView::applySeries(unsigned int ottimizzazione1, unsigned int ottimizzazione2)
{
    chart->removeAllSeries();
    QPieSeries *series = new QPieSeries();
    series->append("Ottimizzazione Strada 1: " + QString::number(ottimizzazione1), ottimizzazione1);
    series->append("Ottimizzazione Strada 2: " + QString::number(ottimizzazione2), ottimizzazione2);
    QPieSlice *slice1 = series->slices().at(0);
    slice1->setLabelVisible();
    slice1->setExploded();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);
    QPieSlice *slice2 = series->slices().at(1);
    slice2->setLabelVisible();
    slice2->setPen(QPen(Qt::darkRed, 2));
    slice2->setBrush(Qt::red);

    chart->addSeries(series);
}

void PieChartView::showOptimizerView()
{
    emit toOptimizerView();
}