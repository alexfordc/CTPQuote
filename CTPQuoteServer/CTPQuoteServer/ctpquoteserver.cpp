#include "CTPQuoteServer.h"
#include "ThostFtdcMdApi.h"
#include "MdSpi.h"
#include "tinystr.h"
#include "tinyxml.h"
#include <QMessageBox>

using namespace std;

CTPQuoteServer::CTPQuoteServer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	md = new MdSpi(this);
	connect(md, SIGNAL(SendHqToDB(QString)), this, SLOT(ReceiveHqToDB(QString)));
	//connect(md, SIGNAL(SendHqToDB2(CThostFtdcDepthMarketDataField*)), this, SLOT(ReceiveHqToDB2(CThostFtdcDepthMarketDataField*)));

	//**********配置参数 begin**********//
	ui.mdEdit->setText("tcp://180.168.146.187:10031");
	//ui.tdEdit->setText("tcp://180.168.146.187:10000");
	ui.brokerIdEdit->setText("9999");
	ui.loginButton->setEnabled(true);
	ui.loginButton->setText(QString::fromLocal8Bit("启动"));
	//ui.userIdEdit->setText("013604");
	//**********配置参数 end**********//

	db = QSqlDatabase::addDatabase("QODBC");
	db.setDatabaseName(QString("DRIVER={SQL SERVER};"
		"SERVER=%1;"
		"DATABASE=%2;"
		"UID=%3;"
		"PWD=%4;").arg("127.0.0.1")
		.arg("ctp")
		.arg("sa")
		.arg("hundsun@1"));
	if (!db.open())
	{
		QMessageBox::information(this, "", "Connect to Database Failed!");
		//qDebug() << db.lastError();
		//qDebug() << "Connect to Database Failed!";
	}
	else
	{
		///qDebug() << "Connect to Database Success!";
		QMessageBox::information(this, "", "Connect to Database Success!");
	}
	//query = QSqlQuery(db);

	//QString server = "192.168.137.1\\test";
	//QString database = "testdb";s
	//QString server = "127.0.0.1";
	//QString database = "ctp";
	//string filename = "dbconfig.xml";
	//getDbConfig(filename);
}

CTPQuoteServer::~CTPQuoteServer()
{
	db.close();
}

void CTPQuoteServer::MDLogin()
{
	char* chmd;
	char* chbrokerId;
	char* chuserId;

	QByteArray bamd = ui.mdEdit->text().toLatin1();
	QByteArray babrokerId = ui.brokerIdEdit->text().toLatin1();
	QByteArray bauserId = ui.userIdEdit->text().toLatin1();

	chmd = bamd.data();
	chbrokerId = babrokerId.data();
	chuserId = bauserId.data();

	strcpy(md->hq.FRONT_ADDR, chmd);
	strcpy(md->hq.BROCKER_ID, chbrokerId);
	//strcpy(md->hq.INVESTOR_ID, chuserId);

	md->Init();

	ui.loginButton->setText(QString::fromLocal8Bit("已启动"));
	ui.loginButton->setEnabled(false);
	QMessageBox::information(this, "", "MDLogin!");
}

void CTPQuoteServer::ReceiveHqToDB(QString hq_tick)
{
	QStringList tick_list = hq_tick.split(",");

	QString instrument_id = tick_list.at(0);
	QString update_time = tick_list.at(1);
	QString last_price = tick_list.at(2);
	QString bid_price_1 = tick_list.at(3);
	QString bid_volume_1 = tick_list.at(4);
	QString ask_price_1 = tick_list.at(5);
	QString ask_volume_1 = tick_list.at(6);
	QString increase = tick_list.at(7);
	QString volume = tick_list.at(8);
	QString upper_limit_price = tick_list.at(9);
	QString lower_limit_price = tick_list.at(10);
	//////////////////////////////////////
	QString trading_day = tick_list.at(11);
	QString exchange_id = tick_list.at(12);
	QString exchange_inst_id = tick_list.at(13);
	QString pre_settlement_price = tick_list.at(14);
	QString pre_close_price = tick_list.at(15);
	QString pre_open_interest = tick_list.at(16);
	QString open_price = tick_list.at(17);
	QString highest_price = tick_list.at(18);
	QString lowest_price = tick_list.at(19);
	QString turnover = tick_list.at(20);
	QString open_instrest = tick_list.at(21);
	QString close_price = tick_list.at(22);
	QString settlement_price = tick_list.at(23);
	QString pre_delta = tick_list.at(24);
	QString curr_delta = tick_list.at(25);
	QString update_millisec = tick_list.at(26);
	QString bid_price_2 = tick_list.at(27);
	QString bid_volume_2 = tick_list.at(28);
	QString ask_price_2 = tick_list.at(29);
	QString ask_volume_2 = tick_list.at(30);
	QString bid_price_3 = tick_list.at(31);
	QString bid_volume_3 = tick_list.at(32);
	QString ask_price_3 = tick_list.at(33);
	QString ask_volume_3 = tick_list.at(34);
	QString bid_price_4 = tick_list.at(35);
	QString bid_volume_4 = tick_list.at(36);
	QString ask_price_4 = tick_list.at(37);
	QString ask_volume_4 = tick_list.at(38);
	QString bid_price_5 = tick_list.at(39);
	QString bid_volume_5 = tick_list.at(40);
	QString ask_price_5 = tick_list.at(41);
	QString ask_volume_5 = tick_list.at(42);
	QString average_price = tick_list.at(43);
	QString action_day = tick_list.at(44);

	//QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
	//db.setDatabaseName(QString("DRIVER={SQL SERVER};"
	//	"SERVER=%1;"
	//	"DATABASE=%2;"
	//	"UID=%3;"
	//	"PWD=%4;").arg("127.0.0.1")
	//	.arg("ctp")
	//	.arg("sa")
	//	.arg("hundsun@1"));
	//if (!db.open())
	//{
	//	qDebug() << db.lastError();
	//	qDebug() << "Connect to Database Failed!";
	//}
	//else
	//{
	//	//qDebug() << "Connect to Database Success!";
	//}

	QSqlQuery query(db);

	QString check_fq = QString("select COUNT(1) from futurequote where instrument_id = '%1';").arg(instrument_id);
	query.exec(check_fq);
	while (query.next())
	{
		int rowcount = query.value(0).toInt();
		if (rowcount == 0)
		{
			QMessageBox::information(this, "", "INSERT INTO futurequote!");
			query.clear();
			query.prepare("INSERT INTO futurequote (trading_day,instrument_id,exchange_id,exchange_inst_id,last_price,pre_settlement_price,pre_close_price,pre_open_interest,open_price,highest_price,lowest_price,volume,turnover,open_interest,close_price,settlement_price,upper_limit_price,lower_limit_price,pre_delta,curr_delta,update_time,update_millisec,bid_price_1,bid_volume_1,ask_price_1,ask_volume_1,bid_price_2,bid_volume_2,ask_price_2,ask_volume_2,bid_price_3,bid_volume_3,ask_price_3,ask_volume_3,bid_price_4,bid_volume_4,ask_price_4,ask_volume_4,bid_price_5,bid_volume_5,ask_price_5,ask_volume_5,average_price,action_day) VALUES (:trading_day,:instrument_id,:exchange_id,:exchange_inst_id,:last_price,:pre_settlement_price,:pre_close_price,:pre_open_interest,:open_price,:highest_price,:lowest_price,:volume,:turnover,:open_interest,:close_price,:settlement_price,:upper_limit_price,:lower_limit_price,:pre_delta,:curr_delta,:update_time,:update_millisec,:bid_price_1,:bid_volume_1,:ask_price_1,:ask_volume_1,:bid_price_2,:bid_volume_2,:ask_price_2,:ask_volume_2,:bid_price_3,:bid_volume_3,:ask_price_3,:ask_volume_3,:bid_price_4,:bid_volume_4,:ask_price_4,:ask_volume_4,:bid_price_5,:bid_volume_5,:ask_price_5,:ask_volume_5,:average_price,:action_day)");
			query.bindValue(":trading_day", trading_day);
			query.bindValue(":instrument_id", instrument_id);
			query.bindValue(":exchange_id", exchange_id);
			query.bindValue(":exchange_inst_id", exchange_inst_id);
			query.bindValue(":last_price", last_price);
			query.bindValue(":pre_settlement_price", pre_settlement_price);
			query.bindValue(":pre_close_price", pre_close_price);
			query.bindValue(":pre_open_interest", pre_open_interest);
			query.bindValue(":open_price", open_price);
			query.bindValue(":highest_price", highest_price);
			query.bindValue(":lowest_price", lowest_price);
			query.bindValue(":volume", volume);
			query.bindValue(":turnover", turnover);
			query.bindValue(":open_interest", open_instrest);
			query.bindValue(":close_price", close_price);
			query.bindValue(":settlement_price", settlement_price);
			query.bindValue(":upper_limit_price", upper_limit_price);
			query.bindValue(":lower_limit_price", lower_limit_price);
			query.bindValue(":pre_delta", pre_delta);
			query.bindValue(":curr_delta", curr_delta);
			query.bindValue(":update_time", update_time);
			query.bindValue(":update_millisec", update_millisec);
			query.bindValue(":bid_price_1", bid_price_1);
			query.bindValue(":bid_volume_1", bid_volume_1);
			query.bindValue(":ask_price_1", ask_price_1);
			query.bindValue(":ask_volume_1", ask_volume_1);
			query.bindValue(":bid_price_2", bid_price_2);
			query.bindValue(":bid_volume_2", bid_volume_2);
			query.bindValue(":ask_price_2", ask_price_2);
			query.bindValue(":ask_volume_2", ask_volume_2);
			query.bindValue(":bid_price_3", bid_price_3);
			query.bindValue(":bid_volume_3", bid_volume_3);
			query.bindValue(":ask_price_3", ask_price_3);
			query.bindValue(":ask_volume_3", ask_volume_3);
			query.bindValue(":bid_price_4", bid_price_4);
			query.bindValue(":bid_volume_4", bid_volume_4);
			query.bindValue(":ask_price_4", ask_price_4);
			query.bindValue(":ask_volume_4", ask_volume_4);
			query.bindValue(":bid_price_5", bid_price_5);
			query.bindValue(":bid_volume_5", bid_volume_5);
			query.bindValue(":ask_price_5", ask_price_5);
			query.bindValue(":ask_volume_5", ask_volume_5);
			query.bindValue(":average_price", average_price);
			query.bindValue(":action_day", action_day);

			qDebug() << "Connect to Database Success11111!";

			query.exec();
		} 
		else
		{
			QMessageBox::information(this, "", "update INTO futurequote!");
			query.clear();
			query.prepare("update futurequote set trading_day = :trading_day,exchange_id = :exchange_id,exchange_inst_id = :exchange_inst_id,last_price = :last_price,pre_settlement_price = :pre_settlement_price,pre_close_price = :pre_close_price,pre_open_interest = :pre_open_interest,open_price = :open_price,highest_price = :highest_price,lowest_price = :lowest_price,volume = :volume,turnover = :turnover,open_interest = :open_interest,close_price = :close_price,settlement_price = :settlement_price,upper_limit_price = :upper_limit_price,lower_limit_price = :lower_limit_price,pre_delta = :pre_delta,curr_delta = :curr_delta,update_time = :update_time,update_millisec = :update_millisec,bid_price_1 = :bid_price_1,bid_volume_1 = :bid_volume_1,ask_price_1 = :ask_price_1,ask_volume_1 = :ask_volume_1,bid_price_2 = :bid_price_2,bid_volume_2 = :bid_volume_2,ask_price_2 = :ask_price_2,ask_volume_2 = :ask_volume_2,bid_price_3 = :bid_price_3,bid_volume_3 = :bid_volume_3,ask_price_3 = :ask_price_3,ask_volume_3 = :ask_volume_3,bid_price_4 = :bid_price_4,bid_volume_4 = :bid_volume_4,ask_price_4 = :ask_price_4,ask_volume_4 = :ask_volume_4,bid_price_5 = :bid_price_5,bid_volume_5 = :bid_volume_5,ask_price_5 = :ask_price_5,ask_volume_5 = :ask_volume_5,average_price = :average_price,action_day = :action_day where instrument_id = :instrument_id;");
			query.bindValue(":trading_day", trading_day);
			query.bindValue(":instrument_id", instrument_id);
			query.bindValue(":exchange_id", exchange_id);
			query.bindValue(":exchange_inst_id", exchange_inst_id);
			query.bindValue(":last_price", last_price);
			query.bindValue(":pre_settlement_price", pre_settlement_price);
			query.bindValue(":pre_close_price", pre_close_price);
			query.bindValue(":pre_open_interest", pre_open_interest);
			query.bindValue(":open_price", open_price);
			query.bindValue(":highest_price", highest_price);
			query.bindValue(":lowest_price", lowest_price);
			query.bindValue(":volume", volume);
			query.bindValue(":turnover", turnover);
			query.bindValue(":open_interest", open_instrest);
			query.bindValue(":close_price", close_price);
			query.bindValue(":settlement_price", settlement_price);
			query.bindValue(":upper_limit_price", upper_limit_price);
			query.bindValue(":lower_limit_price", lower_limit_price);
			query.bindValue(":pre_delta", pre_delta);
			query.bindValue(":curr_delta", curr_delta);
			query.bindValue(":update_time", update_time);
			query.bindValue(":update_millisec", update_millisec);
			query.bindValue(":bid_price_1", bid_price_1);
			query.bindValue(":bid_volume_1", bid_volume_1);
			query.bindValue(":ask_price_1", ask_price_1);
			query.bindValue(":ask_volume_1", ask_volume_1);
			query.bindValue(":bid_price_2", bid_price_2);
			query.bindValue(":bid_volume_2", bid_volume_2);
			query.bindValue(":ask_price_2", ask_price_2);
			query.bindValue(":ask_volume_2", ask_volume_2);
			query.bindValue(":bid_price_3", bid_price_3);
			query.bindValue(":bid_volume_3", bid_volume_3);
			query.bindValue(":ask_price_3", ask_price_3);
			query.bindValue(":ask_volume_3", ask_volume_3);
			query.bindValue(":bid_price_4", bid_price_4);
			query.bindValue(":bid_volume_4", bid_volume_4);
			query.bindValue(":ask_price_4", ask_price_4);
			query.bindValue(":ask_volume_4", ask_volume_4);
			query.bindValue(":bid_price_5", bid_price_5);
			query.bindValue(":bid_volume_5", bid_volume_5);
			query.bindValue(":ask_price_5", ask_price_5);
			query.bindValue(":ask_volume_5", ask_volume_5);
			query.bindValue(":average_price", average_price);
			query.bindValue(":action_day", action_day);
			qDebug() << "Connect to Database Success1111!";
			query.exec();
		}
	}

	QString check_ftq = QString("select COUNT(1) from futuretickquote where instrument_id = '%1' and trading_day = '%2' and update_time = '%3' and update_millisec = '%4';").arg(instrument_id,trading_day,update_time,update_millisec);
	query.exec(check_ftq);
	while (query.next())
	{
		int rowcount = query.value(0).toInt();
		if (rowcount == 0)
		{
			QMessageBox::information(this, "", "INSERT INTO futuretickquote!");
			query.clear();
			query.prepare("INSERT INTO futuretickquote (trading_day,instrument_id,exchange_id,exchange_inst_id,last_price,pre_settlement_price,pre_close_price,pre_open_interest,open_price,highest_price,lowest_price,volume,turnover,open_interest,close_price,settlement_price,upper_limit_price,lower_limit_price,pre_delta,curr_delta,update_time,update_millisec,bid_price_1,bid_volume_1,ask_price_1,ask_volume_1,bid_price_2,bid_volume_2,ask_price_2,ask_volume_2,bid_price_3,bid_volume_3,ask_price_3,ask_volume_3,bid_price_4,bid_volume_4,ask_price_4,ask_volume_4,bid_price_5,bid_volume_5,ask_price_5,ask_volume_5,average_price,action_day) VALUES (:trading_day,:instrument_id,:exchange_id,:exchange_inst_id,:last_price,:pre_settlement_price,:pre_close_price,:pre_open_interest,:open_price,:highest_price,:lowest_price,:volume,:turnover,:open_interest,:close_price,:settlement_price,:upper_limit_price,:lower_limit_price,:pre_delta,:curr_delta,:update_time,:update_millisec,:bid_price_1,:bid_volume_1,:ask_price_1,:ask_volume_1,:bid_price_2,:bid_volume_2,:ask_price_2,:ask_volume_2,:bid_price_3,:bid_volume_3,:ask_price_3,:ask_volume_3,:bid_price_4,:bid_volume_4,:ask_price_4,:ask_volume_4,:bid_price_5,:bid_volume_5,:ask_price_5,:ask_volume_5,:average_price,:action_day)");
			query.bindValue(":trading_day", trading_day);
			query.bindValue(":instrument_id", instrument_id);
			query.bindValue(":exchange_id", exchange_id);
			query.bindValue(":exchange_inst_id", exchange_inst_id);
			query.bindValue(":last_price", last_price);
			query.bindValue(":pre_settlement_price", pre_settlement_price);
			query.bindValue(":pre_close_price", pre_close_price);
			query.bindValue(":pre_open_interest", pre_open_interest);
			query.bindValue(":open_price", open_price);
			query.bindValue(":highest_price", highest_price);
			query.bindValue(":lowest_price", lowest_price);
			query.bindValue(":volume", volume);
			query.bindValue(":turnover", turnover);
			query.bindValue(":open_interest", open_instrest);
			query.bindValue(":close_price", close_price);
			query.bindValue(":settlement_price", settlement_price);
			query.bindValue(":upper_limit_price", upper_limit_price);
			query.bindValue(":lower_limit_price", lower_limit_price);
			query.bindValue(":pre_delta", pre_delta);
			query.bindValue(":curr_delta", curr_delta);
			query.bindValue(":update_time", update_time);
			query.bindValue(":update_millisec", update_millisec);
			query.bindValue(":bid_price_1", bid_price_1);
			query.bindValue(":bid_volume_1", bid_volume_1);
			query.bindValue(":ask_price_1", ask_price_1);
			query.bindValue(":ask_volume_1", ask_volume_1);
			query.bindValue(":bid_price_2", bid_price_2);
			query.bindValue(":bid_volume_2", bid_volume_2);
			query.bindValue(":ask_price_2", ask_price_2);
			query.bindValue(":ask_volume_2", ask_volume_2);
			query.bindValue(":bid_price_3", bid_price_3);
			query.bindValue(":bid_volume_3", bid_volume_3);
			query.bindValue(":ask_price_3", ask_price_3);
			query.bindValue(":ask_volume_3", ask_volume_3);
			query.bindValue(":bid_price_4", bid_price_4);
			query.bindValue(":bid_volume_4", bid_volume_4);
			query.bindValue(":ask_price_4", ask_price_4);
			query.bindValue(":ask_volume_4", ask_volume_4);
			query.bindValue(":bid_price_5", bid_price_5);
			query.bindValue(":bid_volume_5", bid_volume_5);
			query.bindValue(":ask_price_5", ask_price_5);
			query.bindValue(":ask_volume_5", ask_volume_5);
			query.bindValue(":average_price", average_price);
			query.bindValue(":action_day", action_day);
			query.exec();
		}
		else
		{
			
		}
	}

	//query.prepare("INSERT INTO futuretickquote (trading_day,instrument_id,exchange_id,exchange_inst_id,last_price,pre_settlement_price,pre_close_price,pre_open_interest,open_price,highest_price,lowest_price,volume,turnover,open_interest,close_price,settlement_price,upper_limit_price,lower_limit_price,pre_delta,curr_delta,update_time,update_millisec,bid_price_1,bid_volume_1,ask_price_1,ask_volume_1,bid_price_2,bid_volume_2,ask_price_2,ask_volume_2,bid_price_3,bid_volume_3,ask_price_3,ask_volume_3,bid_price_4,bid_volume_4,ask_price_4,ask_volume_4,bid_price_5,bid_volume_5,ask_price_5,ask_volume_5,average_price,action_day) VALUES (:trading_day,:instrument_id,:exchange_id,:exchange_inst_id,:last_price,:pre_settlement_price,:pre_close_price,:pre_open_interest,:open_price,:highest_price,:lowest_price,:volume,:turnover,:open_interest,:close_price,:settlement_price,:upper_limit_price,:lower_limit_price,:pre_delta,:curr_delta,:update_time,:update_millisec,:bid_price_1,:bid_volume_1,:ask_price_1,:ask_volume_1,:bid_price_2,:bid_volume_2,:ask_price_2,:ask_volume_2,:bid_price_3,:bid_volume_3,:ask_price_3,:ask_volume_3,:bid_price_4,:bid_volume_4,:ask_price_4,:ask_volume_4,:bid_price_5,:bid_volume_5,:ask_price_5,:ask_volume_5,:average_price,:action_day)");
	//query.bindValue(":trading_day", trading_day);
	//query.bindValue(":instrument_id", instrument_id);
	//query.bindValue(":exchange_id", exchange_id);
	//query.bindValue(":exchange_inst_id", exchange_inst_id);
	//query.bindValue(":last_price", last_price);
	//query.bindValue(":pre_settlement_price", pre_settlement_price);
	//query.bindValue(":pre_close_price", pre_close_price);
	//query.bindValue(":pre_open_interest", pre_open_interest);
	//query.bindValue(":open_price", open_price);
	//query.bindValue(":highest_price", highest_price);
	//query.bindValue(":lowest_price", lowest_price);
	//query.bindValue(":volume", volume);
	//query.bindValue(":turnover", turnover);
	//query.bindValue(":open_interest", open_instrest);
	//query.bindValue(":close_price", close_price);
	//query.bindValue(":settlement_price", settlement_price);
	//query.bindValue(":upper_limit_price", upper_limit_price);
	//query.bindValue(":lower_limit_price", lower_limit_price);
	//query.bindValue(":pre_delta", pre_delta);
	//query.bindValue(":curr_delta", curr_delta);
	//query.bindValue(":update_time", update_time);
	//query.bindValue(":update_millisec", update_millisec);
	//query.bindValue(":bid_price_1", bid_price_1);
	//query.bindValue(":bid_volume_1", bid_volume_1);
	//query.bindValue(":ask_price_1", ask_price_1);
	//query.bindValue(":ask_volume_1", ask_volume_1);
	//query.bindValue(":bid_price_2", bid_price_2);
	//query.bindValue(":bid_volume_2", bid_volume_2);
	//query.bindValue(":ask_price_2", ask_price_2);
	//query.bindValue(":ask_volume_2", ask_volume_2);
	//query.bindValue(":bid_price_3", bid_price_3);
	//query.bindValue(":bid_volume_3", bid_volume_3);
	//query.bindValue(":ask_price_3", ask_price_3);
	//query.bindValue(":ask_volume_3", ask_volume_3);
	//query.bindValue(":bid_price_4", bid_price_4);
	//query.bindValue(":bid_volume_4", bid_volume_4);
	//query.bindValue(":ask_price_4", ask_price_4);
	//query.bindValue(":ask_volume_4", ask_volume_4);
	//query.bindValue(":bid_price_5", bid_price_5);
	//query.bindValue(":bid_volume_5", bid_volume_5);
	//query.bindValue(":ask_price_5", ask_price_5);
	//query.bindValue(":ask_volume_5", ask_volume_5);
	//query.bindValue(":average_price", average_price);
	//query.bindValue(":action_day", action_day);
	//query.exec();

	//query.clear();
	//db.close();
}

void CTPQuoteServer::ReceiveHqToDB2(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	//QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
	//db.setDatabaseName(QString("DRIVER={SQL SERVER};"
	//	"SERVER=%1;"
	//	"DATABASE=%2;"
	//	"UID=%3;"
	//	"PWD=%4;").arg("127.0.0.1")
	//	.arg("ctp")
	//	.arg("sa")
	//	.arg("hundsun@1"));
	//if (!db.open())
	//{
	//	qDebug() << db.lastError();
	//	qDebug() << "Connect to Database Failed!";
	//}
	//else
	//{
	//	//qDebug() << "Connect to Database Success!";
	//}

	QSqlQuery query(db);
	QMessageBox::information(this, "", "INSERT INTO Tfuturetickquote!");
	query.prepare("INSERT INTO Tfuturetickquote (trading_day,instrument_id,exchange_id,exchange_inst_id,last_price,pre_settlement_price,pre_close_price,pre_open_interest,open_price,highest_price,lowest_price,volume,turnover,open_interest,close_price,settlement_price,upper_limit_price,lower_limit_price,pre_delta,curr_delta,update_time,update_millisec,bid_price_1,bid_volume_1,ask_price_1,ask_volume_1,bid_price_2,bid_volume_2,ask_price_2,ask_volume_2,bid_price_3,bid_volume_3,ask_price_3,ask_volume_3,bid_price_4,bid_volume_4,ask_price_4,ask_volume_4,bid_price_5,bid_volume_5,ask_price_5,ask_volume_5,average_price,action_day) VALUES (:trading_day,:instrument_id,:exchange_id,:exchange_inst_id,:last_price,:pre_settlement_price,:pre_close_price,:pre_open_interest,:open_price,:highest_price,:lowest_price,:volume,:turnover,:open_interest,:close_price,:settlement_price,:upper_limit_price,:lower_limit_price,:pre_delta,:curr_delta,:update_time,:update_millisec,:bid_price_1,:bid_volume_1,:ask_price_1,:ask_volume_1,:bid_price_2,:bid_volume_2,:ask_price_2,:ask_volume_2,:bid_price_3,:bid_volume_3,:ask_price_3,:ask_volume_3,:bid_price_4,:bid_volume_4,:ask_price_4,:ask_volume_4,:bid_price_5,:bid_volume_5,:ask_price_5,:ask_volume_5,:average_price,:action_day)");
	query.bindValue(":trading_day", QString(pDepthMarketData->TradingDay));
	query.bindValue(":instrument_id", QString(pDepthMarketData->InstrumentID));
	query.bindValue(":exchange_id", QString(pDepthMarketData->ExchangeID));
	query.bindValue(":exchange_inst_id", QString(pDepthMarketData->ExchangeInstID));
	query.bindValue(":last_price", pDepthMarketData->LastPrice);
	query.bindValue(":pre_settlement_price", pDepthMarketData->PreSettlementPrice);
	query.bindValue(":pre_close_price", pDepthMarketData->PreClosePrice);
	query.bindValue(":pre_open_interest", pDepthMarketData->PreOpenInterest);
	query.bindValue(":open_price", pDepthMarketData->OpenPrice);
	query.bindValue(":highest_price", pDepthMarketData->HighestPrice);
	query.bindValue(":lowest_price", pDepthMarketData->LowestPrice);
	query.bindValue(":volume", pDepthMarketData->Volume);
	query.bindValue(":turnover", pDepthMarketData->Turnover);
	query.bindValue(":open_interest", pDepthMarketData->OpenInterest);
	query.bindValue(":close_price", pDepthMarketData->ClosePrice);
	query.bindValue(":settlement_price", pDepthMarketData->SettlementPrice);
	query.bindValue(":upper_limit_price", pDepthMarketData->UpperLimitPrice);
	query.bindValue(":lower_limit_price", pDepthMarketData->LowerLimitPrice);
	query.bindValue(":pre_delta", pDepthMarketData->PreDelta);
	query.bindValue(":curr_delta", pDepthMarketData->CurrDelta);
	query.bindValue(":update_time", QString(pDepthMarketData->UpdateTime));
	query.bindValue(":update_millisec", pDepthMarketData->UpdateMillisec);
	query.bindValue(":bid_price_1", pDepthMarketData->BidPrice1);
	query.bindValue(":bid_volume_1", pDepthMarketData->BidVolume1);
	query.bindValue(":ask_price_1", pDepthMarketData->AskPrice1);
	query.bindValue(":ask_volume_1", pDepthMarketData->AskVolume1);
	query.bindValue(":bid_price_2", pDepthMarketData->BidPrice2);
	query.bindValue(":bid_volume_2", pDepthMarketData->BidVolume2);
	query.bindValue(":ask_price_2", pDepthMarketData->AskPrice2);
	query.bindValue(":ask_volume_2", pDepthMarketData->AskVolume2);
	query.bindValue(":bid_price_3", pDepthMarketData->BidPrice3);
	query.bindValue(":bid_volume_3", pDepthMarketData->BidVolume3);
	query.bindValue(":ask_price_3", pDepthMarketData->AskPrice3);
	query.bindValue(":ask_volume_3", pDepthMarketData->AskVolume3);
	query.bindValue(":bid_price_4", pDepthMarketData->BidPrice4);
	query.bindValue(":bid_volume_4", pDepthMarketData->BidVolume4);
	query.bindValue(":ask_price_4", pDepthMarketData->AskPrice4);
	query.bindValue(":ask_volume_4", pDepthMarketData->AskVolume4);
	query.bindValue(":bid_price_5", pDepthMarketData->BidPrice5);
	query.bindValue(":bid_volume_5", pDepthMarketData->BidVolume5);
	query.bindValue(":ask_price_5", pDepthMarketData->AskPrice5);
	query.bindValue(":ask_volume_5", pDepthMarketData->AskVolume5);
	query.bindValue(":average_price", pDepthMarketData->AveragePrice);
	query.bindValue(":action_day", QString(pDepthMarketData->ActionDay));
	query.exec();
}

CString CTPQuoteServer::getAppPath()
{
	TCHAR modulePath[MAX_PATH];
	GetModuleFileName(NULL,modulePath,MAX_PATH);
	CString strModulePath(modulePath);
	strModulePath = strModulePath.Left(strModulePath.ReverseFind(_T('\\')));
	return strModulePath;
}

bool CTPQuoteServer::getDbConfig(string &dbconfig)
{
	CString appPath = getAppPath();
	string seperator = "\\";
	string fullPath = dbconfig;

	TiXmlDocument *document = new TiXmlDocument(fullPath.c_str());
	document->LoadFile();

	TiXmlElement *rootElement = document->RootElement();
	TiXmlElement *configElement = rootElement->FirstChildElement();
	TiXmlElement *serverElement = configElement->FirstChildElement();
	TiXmlElement *databaseElement = serverElement->NextSiblingElement();
	TiXmlElement *uidElement = databaseElement->NextSiblingElement();
	TiXmlElement *pwdElement = uidElement->NextSiblingElement();

	QString server = serverElement->FirstChild()->Value();
	QString dataBase = databaseElement->FirstChild()->Value();
	QString uid = uidElement->FirstChild()->Value();
	QString pwd = pwdElement->FirstChild()->Value();

	//qDebug() << server;
	//qDebug() << dataBase;
	//qDebug() << uid;
	//qDebug() << pwd;

	return true;
}

