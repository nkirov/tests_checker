#include <QApplication>
#include "utc.h"

int main(int argc, char *argv[])
{
     	QApplication app(argc, argv);
	Utc utc;	
	utc.show();
	return app.exec();
}

