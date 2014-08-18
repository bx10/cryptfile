#ifndef ABSTRCLASSWORKWITHDATA_H
#define ABSTRCLASSWORKWITHDATA_H

#include <QByteArray>
#include <QObject>

class AbstrClassWorkWithData : public QObject{

public slots:
	virtual void stop() = 0;

public:
	virtual void setData(const QByteArray &data) = 0;

signals:
	void getData(const QByteArray &data);
	void error(QString msg);


};

#endif // ABSTRCLASSWORKWITHDATA_H
