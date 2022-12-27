#include "editDBview.h"

EditDBView::EditDBView(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();

    QLabel *title = new QLabel("DataBase Editor");
    title->setAlignment(Qt::AlignLeft);
    title->setFont(QFont("Arial", 20, QFont::Bold));
    home = new QPushButton();
    QPixmap pixHome = QPixmap(QCoreApplication::applicationDirPath() + "/images/homeIcon.png");
    QWidget* topBar = new TopBar(home, title, pixHome);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setSpacing(20);
    QVBoxLayout *leftLayout = new QVBoxLayout;
    QVBoxLayout *rightLayout = new QVBoxLayout;

    QCalendarWidget *calendar = new QCalendarWidget;
    calendar->setMaximumHeight(200);
    leftLayout->setAlignment(Qt::AlignTop);
    leftLayout->addWidget(calendar);

    model = new EditDBModel(calendar->selectedDate());

    tableView = new QTableView;
    tableView->setModel(model);
    tableView->setMinimumSize(400, 400);
    rightLayout->addWidget(tableView);

    QHBoxLayout *toolbarLayout = new QHBoxLayout;
    QPushButton *save = new QPushButton("Save");
    save->setMaximumWidth(50);
    toolbarLayout->addWidget(save);
    toolbarLayout->setDirection(QBoxLayout::RightToLeft);
    toolbarLayout->setAlignment(Qt::AlignLeft);

    rightLayout->addLayout(toolbarLayout);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    layout->addWidget(topBar);
    layout->addLayout(mainLayout);

    setLayout(layout);

    connect(home, &QPushButton::clicked, this, &EditDBView::showHomeView);
    connect(calendar, &QCalendarWidget::selectionChanged, this, [=](){
        model->setNewData(calendar->selectedDate());
        tableView->setModel(model);
    });
    connect(save, &QPushButton::clicked, this, [=](){
        model->saveData(calendar->selectedDate());
    });
}

EditDBView::~EditDBView()
{
}

void EditDBView::showHomeView()
{
    emit toHomeView();
}