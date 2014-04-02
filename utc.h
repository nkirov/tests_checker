#ifndef MENU_H
#define MENU_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QDebug>

#include "ui_utc.h"

class Question
{
public:
	int ans_correct[4]; // 1 - yes; 2 - no
	int ans_student[4]; // 0 - nothing 1 - yes, 2 - no
	int ans_student_correct[4]; // 0 - no answer; 1 - correst; 2 - incorrect
	int quest; // points for this question
	Question();
	~Question();
};

class Test
{
public:
	Test();
	int points;
	~Test();
	Question q[20];
};

class BaseAns {
public:
	BaseAns() {
	total = total1 = correct = correct1 = incorrect = incorrect1 = 0;
	}
// private:
	QString text;
	int total, total1; // total number ot tests; only for >= 5pt
	int correct, correct1;
	int incorrect, incorrect1;
};

class BaseQuestion {
public:
	BaseQuestion(QString, QVector<BaseAns>);
private:
	QString text;
	QVector<BaseAns> ans;
};		
	
class Utc : public QDialog
{
	Q_OBJECT
	public:
		Utc(QWidget *parent = 0);
	private:
		Ui::utc ui;
	
		QString filename;
		bool read_data_tests();
		QMap<int, Test> all_tests;
		void print();
		void go();
		int total;
		int exam;
		int num_questions;
		int current_quest;
		QMap<int, Test>::iterator current_test;
		void calc_points(QMap<int, Test>::iterator);

		bool read_data();
		QVector<BaseQuestion> base;
		void write_result();
	public slots:
		void abcd();
		void new_test(int);
		void new_quest(int);
		void save();
		bool load();
	//	bool read_students_tests();
		void calc();
};
#endif
