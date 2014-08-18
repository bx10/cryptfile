#ifndef DRAGANDDROPWIDGET_H
#define DRAGANDDROPWIDGET_H

#include <QFrame>
#include <QDebug>
#include <QMimeData>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QLabel>
#include <QLayout>

class DragAndDropWidget : public QFrame
{
	Q_OBJECT
public:
    explicit DragAndDropWidget();
    void setHintText(QString text);
	

signals:
    void returnPathList(QStringList);
	
public slots:


private:
    QLabel *hintText;
    QLayout *mainLayout;
    void initStyle();
    void initHintText();

protected:
	void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
	
};

#endif // DRAGANDDROPWIDGET_H
