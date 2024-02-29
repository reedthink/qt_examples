#include "calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent), sumInMemory(0.0), sumSoFar(0.0), factorSoFar(0.0), waitingForOperand(true)
{
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    for(int i=0; i < NumDigitButtons; ++i)
    {
        digitButtons[i] = createButton(QString::number(i), &Calculator::digitClicked);

    }

    Button *pointButton = createButton(tr("."), &Calculator::pointClicked);
    Button *changeSignButton = createButton(tr("\302\261"), &Calculator::changeSignClicked);

    Button *backspaceButton = createButton(tr("Backspace"), &Calculator::backspaceClicked);
    Button *clearButton = createButton(tr("Clear"), &Calculator::clear);
    Button *clearAllButton = createButton(tr("Clear All"), &Calculator::clearAll);

    Button *clearMemoryButton = createButton(tr("MC"), &Calculator::clearMemory);
    Button *readMemoryButton = createButton(tr("MR"), &Calculator::readMemory);
    Button *setMemoryButton = createButton(tr("MS"), &Calculator::setMemory);
    Button *addToMemoryButton = createButton(tr("M+"), &Calculator::addToMemory);

    Button *divisionButton = createButton(tr("\303\267"), &Calculator::multilicativeOperatorClicked);
    Button *timesButton = createButton(tr("\303\227"), &Calculator::multilicativeOperatorClicked);
    Button *minusButton = createButton(tr("-"), &Calculator::additiveOperatorClicked);
    Button *plusButton = createButton(tr("+"), &Calculator::additiveOperatorClicked);

    Button *squareRootButton = createButton(tr("Sqrt"), &Calculator::unaryOperatorClicked);
    Button *powerButton = createButton(tr("x\302\262"), &Calculator::unaryOperatorClicked);
    Button *reciprocalButton = createButton(tr("1\x"), &Calculator::unaryOperatorClicked);
    Button *equalButton = createButton(tr("="), &Calculator::equalClicked);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(display, 0, 0, 1, 6);
    mainLayout->addWidget(backspaceButton, 1, 0, 1, 2);
    mainLayout->addWidget(clearButton, 1, 2, 1, 2);
    mainLayout->addWidget(clearAllButton, 1, 4, 1, 2);

    mainLayout->addWidget(clearMemoryButton, 2, 0);
    mainLayout->addWidget(readMemoryButton, 3, 0);
    mainLayout->addWidget(setMemoryButton,4, 0);
    mainLayout->addWidget(addToMemoryButton, 5, 0);

    for (int i=1; i< NumDigitButtons; i++)
    {
        int row = ((9-i)/3)+2;
        int column = ((i-1)%3)+1;
        mainLayout->addWidget(digitButtons[i], row, column);
    }

    mainLayout->addWidget(digitButtons[0], 5, 1);
    mainLayout->addWidget(pointButton, 5, 2);
    mainLayout->addWidget(changeSignButton, 5, 3);

    mainLayout->addWidget(divisionButton, 2, 4);
    mainLayout->addWidget(timesButton, 3, 4);
    mainLayout->addWidget(minusButton, 4, 4);
    mainLayout->addWidget(plusButton, 5, 4);

    mainLayout->addWidget(squareRootButton, 2, 5);
    mainLayout->addWidget(powerButton, 3, 5);
    mainLayout->addWidget(reciprocalButton, 3, 5);
    mainLayout->addWidget(equalButton, 5, 5);
    setLayout(mainLayout);

    setWindowTitle(tr("Calculator"));


}
Calculator::~Calculator()
{
}

void Calculator::digitClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    int digitValue = clickedButton->text().toInt();
    if (display->text() == "0" && digitValue == 0.0)
        return;
    if (waittingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text()+QString::number(digitValue));
}

void Calculator::unaryOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    if (clickedOperator == tr("Sqrt"))
    {
        if (operand < 0.0)
        {
            abortOperation();
            return;
        }
        result = std::sqrt(operand);

    }
    else if (clickedOperator == tr("x\302\262"))
    {
        result = std::pow(operand, 2.0);
    }
    else if (clickedOperator == tr("1/x"))
    {
        if (operand == 0.0)
        {
            abortOperation();
            return;
        }
        result = 1.0 / operand;
    }
    display->setText(QString::number(result));
    waitingForOperand = true;

}

void Calculator::additiveOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    if (!clickedButton)
        return;
   QString clickedOperator = clickedButton->text();
   double operand = display->text().toDouble();

   if(!pendingMultiplicativeOperator.isEmpty())
   {
       if (!calculate(operand, pendingMultiplicativeOperator))
       {
           abortOperation();
           return;
       }
       display->setText(QString::number(factorSoFar));
       operand = factorSoFar;
       factorSoFar = 0.0;
       pendingMultiplicativeOperator;
   }
   if(!pendingAdditiveOperator.isEmpty())
   {
       if (!calculate(operand, pendingAdditiveOperator))
       {
           abortOperation();
           return;
       }
       display->setText(QString::number(sumSoFar));

   }
   else{
       sumSoFar = operand;
   }
   pendingAdditiveOperator = clickedOperator;
   waitingForOperand = true;
}

