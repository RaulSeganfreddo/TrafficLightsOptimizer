#include "linechartview.h"

LineChartView::LineChartView(LineChartModel* m, QWidget *parent) : QWidget(parent)
{   
    chart = new QChart();
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QLabel *title = new QLabel("Line Chart");
    title->setFont(QFont("Arial", 20, QFont::Bold));
    backArrow = new QPushButton();
    QPixmap pixHome = QPixmap(QCoreApplication::applicationDirPath() + "/images/backArrowIcon.png");
    QWidget* topBar = new TopBar(backArrow, title, pixHome);

    QHBoxLayout *layout = new QHBoxLayout;
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTitle("Secondi di semaforo verde per le due strade in base all'ottimizzazione");
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(1000);

    applySeries(m->getOttimizzazione1(), m->getOttimizzazione2(), m->getOre());

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(chartView);
    mainLayout->addWidget(topBar);
    mainLayout->addLayout(layout);
    setLayout(mainLayout);
    setMinimumSize(800, 600);
    resize(800, 600);

    connect(backArrow, &QPushButton::clicked, this, &LineChartView::showOptimizerView);
}

LineChartView::~LineChartView()
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

void LineChartView::applySeries(std::vector<unsigned int> ottimizzazione1, std::vector<unsigned int> ottimizzazione2, std::vector<unsigned int> ore)
{
    chart->removeAllSeries();
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();

    series1->setName("Strada 1");
    series2->setName("Strada 2");

    for (int i = 0; i < 24; i++)
    {
        series1->append(ore[i], ottimizzazione1[i]);
        series2->append(ore[i], ottimizzazione2[i]);
    }

    chart->addSeries(series1);
    chart->addSeries(series2);
    chart->createDefaultAxes();
    if(chart->axisX() && chart->axisY())
    {
        chart->axisX()->setRange(0, 24);
        chart->axisY()->setRange(0, 300);
    }
}

void LineChartView::showOptimizerView()
{
    emit toOptimizerView();
}