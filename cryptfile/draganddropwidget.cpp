#include "draganddropwidget.h"

DragAndDropWidget::DragAndDropWidget() :
    QFrame()
{
    initStyle();
    initHintText();
}

/**
 * @brief this event is called when the drop operation is initiated at the widget
 */
void DragAndDropWidget::dropEvent(QDropEvent* event)
{
    const QMimeData* mimeData = event->mimeData();
    if (mimeData->hasUrls()){
        QStringList pathList;
        QList<QUrl>urlList = mimeData->urls();

        for(int i=0; i<urlList.size(); ++i){
            pathList.append(urlList.at(i).toLocalFile());
        }
        emit returnPathList(pathList);
    }
}

/**
 * @brief this event is called when the mouse enters the widgets area during a drag/drop operation
 */
void DragAndDropWidget::dragEnterEvent(QDragEnterEvent *event)
{
    // if some actions should not be usable, like move, this code must be adopted
    event->acceptProposedAction();
}


/**
 * @brief this event is called when the mouse moves inside the widgets area during a drag/drop operation
 */
void DragAndDropWidget::dragMoveEvent(QDragMoveEvent *event)
{
    // if some actions should not be usable, like move, this code must be adopted
    event->acceptProposedAction();
}

/**
 * @brief this event is called when the mouse leaves the widgets area during a drag/drop operation
 */
void DragAndDropWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

/**
 * @brief Initialize default style for drag and drop widget
 */
void DragAndDropWidget::initStyle()
{
    this->setStyleSheet("border: 3px solid gray; border-radius: 40px; background: white;");
    this->setMinimumSize(100,100);
    this->setAcceptDrops(true);
    mainLayout = new QHBoxLayout(this);
}


/**
 * @brief Initialize default style for hint
 */
void DragAndDropWidget::initHintText()
{
    hintText = new QLabel(this);
    mainLayout->addWidget(hintText);
    mainLayout->setAlignment(hintText,Qt::AlignCenter);
    hintText->setStyleSheet("border: 0px; font: 20pt");
}

/**
 * @brief Public method for change hint text
 * @param text
 */

void DragAndDropWidget::setHintText(QString text)
{
    hintText->setText(text);
}
