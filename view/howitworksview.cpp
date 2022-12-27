#include "view/howitworksview.h"

HowItWorksView::HowItWorksView(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    addLayouts();
    connect(home, &QPushButton::clicked, this, &HowItWorksView::showHomeView);
}

HowItWorksView::~HowItWorksView()
{
    delete mainLayout;
    mainLayout = nullptr;
    if (home) delete home;
    home = nullptr;
}

void HowItWorksView::addLayouts()
{
    QLabel *title = new QLabel("How it works");
    title->setFont(QFont("Arial", 20, QFont::Bold));
    home = new QPushButton();
    QPixmap pixHome = QPixmap(QCoreApplication::applicationDirPath() + "/images/homeIcon.png");
    QWidget* topBar = new TopBar(home, title, pixHome);
    
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(createImageLayout(QCoreApplication::applicationDirPath() + "/images/junctionIcon.png"));
    layout->addLayout(createDescriptionLayout("How it works",tr("Questa applicazione si propone di acquisire un insieme di dati nel tempo\n"
    "e di proporre l'ottimizzazione dei tempi di un ipotetico impianto semaforico.\n"
    "Tale impianto gestisce l'intersezione o incrocio di 2 strade (quadrivio);\n"
    "tali strade d'ora in avanti verranno identificate con Strada 1 e Strada 2.\n"
    "\n"
    "In base al numero dei passaggi di veicoli lungo la Strada 1 e Strada 2 nel tempo,\n"
    "l'applicazione visualizza, mediante grafici dedicati, sia l'andamento di tali passaggi\n"
    "sia una possibile ottimizzazione dei tempi di attesa (semaforo rosso)\n"
    "e consenso al transito (semaforo verde) per le due direttrici.\n"
    "\n"
    "La base dati è costituita da:\n"
    "- suddivisione per Anno/Mese/Giorno/Ora del numero di passaggi\n"
    "- numero di passaggio su Strada 1 avvenuti in ogni ora della giornata\n"
    "- numero di passaggio su Strada 2 avvenuti in ogni ora della giornata\n"
    "\n"
    "Tale base dati potrebbe ipoteticamente essere alimentata da un sistema di sensori\n"
    "posizionati in prossimità dell'incrocio.\n"
    "Attualmente viene gestita (inserimento/cancellazione/modifica) mediante pagina video dedicata.\n")));

    mainLayout->addWidget(topBar);
    mainLayout->addLayout(layout);
    setLayout(mainLayout);
}

QLayout* HowItWorksView::createDescriptionLayout(const QString &title, const QString &description)
{
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *descrizione = new QLabel(description,this);
    QFont font("Arial", 12);
    descrizione->setFont(font);
    descrizione->setWordWrap(true);
    layout->addWidget(descrizione, 0, Qt::AlignTop);

    QGroupBox *box = new QGroupBox("Descrizione del progetto", this);
    box->setLayout(layout);
    QVBoxLayout *boxLayout = new QVBoxLayout;
    boxLayout->setMargin(10);
    boxLayout->setSpacing(15);
    boxLayout->setContentsMargins(12, 50, 25, 50);
    boxLayout->addWidget(box);
    return boxLayout;
}

QLayout* HowItWorksView::createImageLayout(const QString &imagePath)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(10);
    layout->setSpacing(25);
    layout->setContentsMargins(25, 50, 12, 50);
    layout->setAlignment(Qt::AlignCenter);
    QLabel *image = new QLabel(this);
    QPixmap pix(imagePath);
    pix = pix.scaled(200, 200, Qt::KeepAspectRatio);
    image->setPixmap(pix);
    image->setFixedSize(300, 300);
    layout->addWidget(image, 0, Qt::AlignHCenter);
    return layout;
}

void HowItWorksView::showHomeView()
{
    emit toHomeView();
}