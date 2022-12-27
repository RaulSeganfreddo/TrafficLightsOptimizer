#include "barchartview.h"

BarChartView::BarChartView(BarChartModel* m, QWidget *parent) : QWidget(parent)
{
    chart = new QChart();
    // series = new QBarSeries();
    scrollBar = new QScrollBar(Qt::Horizontal);

    QVBoxLayout *layout = new QVBoxLayout();

    QLabel *title = new QLabel("Bar Chart");
    title->setFont(QFont("Arial", 20, QFont::Bold));
    backArrow = new QPushButton();
    QPixmap pixHome = QPixmap(QCoreApplication::applicationDirPath() + "/images/backArrowIcon.png");
    QWidget* topBar = new TopBar(backArrow, title, pixHome);

    chart->setTitle("Numero Auto al giorno per le due strade");
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(1000);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    createSets(m->getStrada1(), m->getStrada2());
    applyAxis(m->getDays());

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(chartView);
    mainLayout->addWidget(scrollBar);
    layout->addWidget(topBar);
    layout->addLayout(mainLayout);
    setLayout(layout);
    setMinimumSize(800, 600);
    resize(800, 600);
    
    connect(backArrow, &QPushButton::clicked, this, &BarChartView::showOptimizerView);
}

BarChartView::~BarChartView()
{
    delete chart;
    chart = nullptr;
    delete scrollBar;
    scrollBar = nullptr;
}

void BarChartView::createSets(std::vector<unsigned int> strada1, std::vector<unsigned int> strada2)
{
    QBarSet *set1 = new QBarSet("Strada 1");
    QBarSet *set2 = new QBarSet("Strada 2");

    for (auto it = strada1.begin(); it != strada1.end(); ++it)
    {
        *set1 << *it;
    }

    for (auto it = strada2.begin(); it != strada2.end(); ++it)
    {
        *set2 << *it;
    }

    setList.push_back(set1);
    setList.push_back(set2);
}

void BarChartView::applyAxis(QStringList days)
{
    chart->removeAllSeries();
    QBarSeries *series = new QBarSeries();

    for (auto it = setList.begin(); it != setList.end(); ++it)
    {
        series->append(*it);
    }
    chart->addSeries(series);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(days);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 20000);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}

void BarChartView::showOptimizerView()
{
    emit toOptimizerView();
}