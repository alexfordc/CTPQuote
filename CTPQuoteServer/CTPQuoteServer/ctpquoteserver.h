#ifndef CTPQuoteServer_H
#define CTPQuoteServer_H

#include <QtWidgets/QMainWindow>
#include "ui_CTPQuoteServer.h"
#include "ThostFtdcMdApi.h"
#include "MdSpi.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QtSql>
#include <string>
#include <iostream>
#include <windows.h>
#include <atlstr.h>
#include "tinystr.h"
#include "tinyxml.h"

using namespace std;

class CTPQuoteServer : public QMainWindow
{
	Q_OBJECT

public:
	CTPQuoteServer(QWidget *parent = 0);
	~CTPQuoteServer();

private slots:
	void MDLogin();
	void ReceiveHqToDB(QString);
	void ReceiveHqToDB2(CThostFtdcDepthMarketDataField*);
	CString getAppPath();
	bool getDbConfig(string &dbconfig);

private:
	Ui::CTPQuoteServerClass ui;
	MdSpi* md;
	QSqlDatabase db;
	//QSqlQuery query;
};

#endif // CTPQuoteServer_H
