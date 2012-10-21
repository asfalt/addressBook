#include <QtGui>
#include "adressbook.h"


//КОНСТРУКТОР
AddressBook::AddressBook(QWidget *parent)
     : QWidget(parent)
 {
     QLabel *nameLabel = new QLabel(tr("Name:"));
     nameLine = new QLineEdit;

     QLabel *addressLabel = new QLabel(tr("Address:"));
     addressText = new QTextEdit;


     QLabel *MyLabel = new QLabel(tr("mymymy"));


     //Добавили 2
     nameLine->setReadOnly(true);
     addressText->setReadOnly(true);

          //создаем экземпляры кнопок: addButton, submitButton и cancelButton
     addButton = new QPushButton(tr("&Add"));
     addButton->show();

     submitButton = new QPushButton(tr("&Submit"));
     submitButton->hide();
     cancelButton = new QPushButton(tr("&Cancel"));
     cancelButton->hide();



     //СОЕДИНЕНИЕ СИГНАЛОВ И СЛОТОВ

     connect(addButton, SIGNAL(clicked()), this, SLOT(addContact()));
     connect(submitButton, SIGNAL(clicked()), this, SLOT(submitContact()));
     connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

     //КОМПОНОВКА
     QGridLayout *mainLayout = new QGridLayout;

         mainLayout->addWidget(nameLabel, 0, 0);
         mainLayout->addWidget(nameLine, 0, 1);
         mainLayout->addWidget(addressLabel, 1, 0, Qt::AlignTop);
         mainLayout->addWidget(addressText, 1, 1);

         mainLayout->addWidget(MyLabel,0,2);


         //Добавили 2
     QVBoxLayout *buttonLayout1  = new QVBoxLayout;
     buttonLayout1->addWidget(addButton, Qt::AlignTop);
     buttonLayout1->addWidget(submitButton);
     buttonLayout1->addWidget(cancelButton);
     buttonLayout1->addStretch();  //своеобразное форматирование тогда всё не равномерно растягивается а нахобится в стороне выравнивания

     mainLayout->addLayout(buttonLayout1,1,2);

         setLayout(mainLayout);
         setWindowTitle(tr("Simple Address Book__!!"));

         //вот так вот
 }


//*-----------------------------------------------------------------------**
//ОПИСАНИЕ ФУНКЦИЙ

void AddressBook::addContact()
{

    QApplication::beep();

    oldName = nameLine->text();
    oldAddress = addressText->toPlainText();

    nameLine->clear();

    nameLine->setReadOnly(false);
    nameLine->setFocus(Qt::OtherFocusReason);
    addressText->setReadOnly(false);

    //выключим пока эту кнопку
    addButton->setEnabled(false);


    //и покажем остальные

    submitButton->show();
    cancelButton->show();
}

//*-----------------------------------------------------------------------**
void AddressBook::submitContact()
{
    //1 сначала сохраним в строковых переменных информацию из полей ввода nameLine  и addressText
    // проверим не пустые ли строки и выведем предупреждение

    QString name = nameLine->text();
    QString address = addressText->toPlainText();

    if (name == "" || address == "")
    {
        QMessageBox::information(this, tr("emty field"), tr("Please enter the name and adress.\nda da da\nda!"));
        return;
    }



}

//*-----------------------------------------------------------------------**
void AddressBook::cancel()
{

}

//*-----------------------------------------------------------------------**
