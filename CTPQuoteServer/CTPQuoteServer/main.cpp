#include "ctpquoteserver.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CTPQuoteServer w;
	w.show();
	return a.exec();
}
