#include "homeview.h"

HomeView::HomeView(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    inizialize();

    connect(HowItWorks, &QPushButton::clicked, this, &HomeView::showHowItWorksView);
    connect(Optimizer, &QPushButton::clicked, this, &HomeView::showOptimizerView);
    connect(EditDB, &QPushButton::clicked, this, &HomeView::showEditDBView);
}

HomeView::~HomeView()
{
    delete HowItWorks;
    HowItWorks = nullptr;
    delete Optimizer;
    Optimizer = nullptr;
    delete EditDB;
    EditDB = nullptr;
    delete mainLayout;
    mainLayout = nullptr;
}

void HomeView::inizialize()
{
    QLabel *Title = new QLabel("Benevunuto nel Traffic Lights Optimizer!", this);
    Title->setAlignment(Qt::AlignCenter);
    Title->setFont(QFont("Arial", 20, QFont::Bold));

    QLabel *Subtitle = new QLabel("Scegli un'opzione:", this);
    Subtitle->setAlignment(Qt::AlignCenter);
    Subtitle->setFont(QFont("Arial", 15, QFont::Bold));

    // Layout delle opzioni selezionabili
    optionsLayout = new QHBoxLayout();
    optionsLayout->setAlignment(Qt::AlignCenter);

    // Buttons delle opzioni selezionabili
    HowItWorks = new QPushButton();
    Optimizer = new QPushButton();
    EditDB = new QPushButton();

    // Labels dei bottoni
    QHBoxLayout *labelsLayout = new QHBoxLayout();

    QLabel *HowItWorksLabel = new QLabel("How it works");
    HowItWorksLabel->setAlignment(Qt::AlignCenter);
    HowItWorksLabel->setFont(QFont("Arial", 12, QFont::Bold));

    QLabel *OptimizerLabel = new QLabel("Optimizer");
    OptimizerLabel->setAlignment(Qt::AlignCenter);
    OptimizerLabel->setFont(QFont("Arial", 12, QFont::Bold));

    QLabel *EditDBLabel = new QLabel("Edit DB");
    EditDBLabel->setAlignment(Qt::AlignCenter);
    EditDBLabel->setFont(QFont("Arial", 12, QFont::Bold));

    // Aggiunta delle icone ai bottoni
    QPixmap pixHowItWorks = QPixmap(QCoreApplication::applicationDirPath() + "/images/howItWorksIcon.png");
    setIcons(pixHowItWorks, HowItWorks);

    QPixmap pixOptimizer = QPixmap(QCoreApplication::applicationDirPath() + "/images/optimizerIcon.png");
    setIcons(pixOptimizer, Optimizer);

    QPixmap pixEditDB = QPixmap(QCoreApplication::applicationDirPath() + "/images/editDBIcon.png");
    setIcons(pixEditDB, EditDB);

    // aggiunta dei bottoni
    optionsLayout->addWidget(HowItWorks);
    optionsLayout->addWidget(Optimizer);
    optionsLayout->addWidget(EditDB);

    // aggiunta delle label ai bottoni
    labelsLayout->addWidget(HowItWorksLabel);
    labelsLayout->addWidget(OptimizerLabel);
    labelsLayout->addWidget(EditDBLabel);

    // aggiunta dei layout al layout principale
    mainLayout->addWidget(Title);
    mainLayout->addWidget(Subtitle);
    mainLayout->addLayout(optionsLayout);
    mainLayout->addLayout(labelsLayout);
}

void HomeView::setIcons(const QPixmap &pix, QPushButton *btn)
{
    btn->setIcon(pix);
    btn->setIconSize(QSize(150, 150));
    btn->resize(QSize(150, 150));
    btn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    btn->setStyleSheet("border: 3px solid #e0e0e0;");
    QPalette palette = btn->palette();
    palette.setColor(QPalette::Button, QColor(Qt::white));
    btn->setAutoFillBackground(true);
    btn->setPalette(palette);
    btn->update();
    btn->setCursor(Qt::PointingHandCursor);
}

void HomeView::showHowItWorksView()
{
    emit toHowItWorksView();
}

void HomeView::showOptimizerView()
{
    emit toOptimizerView();
}

void HomeView::showEditDBView()
{
    emit toEditDBView();
}

#if 0

void HomeView::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Traffic Lights Optimizer",
                                                                tr("Are you sure you want to exit?"

                                                                ),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,   QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}

#endif 