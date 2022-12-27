#include "optimizerview.h"

OptimizerView::OptimizerView(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    addLayouts();
    connect(home, &QPushButton::clicked, this, &OptimizerView::showHomeView);
    connect(barChartButton, &QPushButton::clicked, this, &OptimizerView::showBarChartView);
    connect(lineChartButton, &QPushButton::clicked, this, &OptimizerView::showLineChartView);
    connect(pieChartButton, &QPushButton::clicked, this, &OptimizerView::showPieChartView);
}

OptimizerView::~OptimizerView()
{
    delete mainLayout;
    mainLayout = nullptr;
    if (home) {
        delete home;
        home = nullptr;
    }
    if (barChartButton) {
        delete barChartButton;
        barChartButton = nullptr;
    }
    if (lineChartButton) {
        delete lineChartButton;
        lineChartButton = nullptr;
    }
    if (pieChartButton) {
        delete pieChartButton;
        pieChartButton = nullptr;
    }
}

void OptimizerView::addLayouts()
{
    QLabel *title = new QLabel("Optimizer");
    title->setFont(QFont("Arial", 20, QFont::Bold));
    home = new QPushButton();
    QPixmap pixHome = QPixmap(QCoreApplication::applicationDirPath() + "/images/homeIcon.png");
    QWidget* topBar = new TopBar(home, title, pixHome);
    
    // i 3 pulsanti per scegliere il tipo di grafico
    QHBoxLayout *optionsLayout = new QHBoxLayout;
    optionsLayout->setAlignment(Qt::AlignCenter);
    barChartButton = new QPushButton();
    lineChartButton = new QPushButton();
    pieChartButton = new QPushButton();

    // labels dei pulsanti
    QHBoxLayout *labelsLayout = new QHBoxLayout;
    QLabel *barChartLabel = new QLabel("Bar Chart");
    barChartLabel->setAlignment(Qt::AlignCenter);
    barChartLabel->setFont(QFont("Arial", 12, QFont::Bold));

    QLabel *lineChartLabel = new QLabel("Line Chart");
    lineChartLabel->setAlignment(Qt::AlignCenter);
    lineChartLabel->setFont(QFont("Arial", 12, QFont::Bold));

    QLabel *pieChartLabel = new QLabel("Pie Chart");
    pieChartLabel->setAlignment(Qt::AlignCenter);
    pieChartLabel->setFont(QFont("Arial", 12, QFont::Bold));

    // aggiunta delle icone ai pulsanti
    QPixmap pixBarChart = QPixmap(QCoreApplication::applicationDirPath() + "/images/barChartIcon.png");
    HomeView::setIcons(pixBarChart, barChartButton);

    QPixmap pixLineChart = QPixmap(QCoreApplication::applicationDirPath() + "/images/lineChartIcon.png");
    HomeView::setIcons(pixLineChart, lineChartButton);

    QPixmap pixPieChart = QPixmap(QCoreApplication::applicationDirPath() + "/images/pieChartIcon.png");
    HomeView::setIcons(pixPieChart, pieChartButton);

    // aggiunta dei pulsanti e delle label ai layout
    optionsLayout->addWidget(barChartButton);
    optionsLayout->addWidget(lineChartButton);
    optionsLayout->addWidget(pieChartButton);

    labelsLayout->addWidget(barChartLabel);
    labelsLayout->addWidget(lineChartLabel);
    labelsLayout->addWidget(pieChartLabel);

    mainLayout->addWidget(topBar);
    mainLayout->addLayout(optionsLayout);
    mainLayout->addLayout(labelsLayout);
}

void OptimizerView::showHomeView()
{
    emit toHomeView();
}

void OptimizerView::showBarChartView()
{
    emit toBarChartView();
}

void OptimizerView::showLineChartView()
{
    emit toLineChartView();
}

void OptimizerView::showPieChartView()
{
    emit toPieChartView();
}