#include <QDebug>
#include <QFile>
#include <QtCore/qmath.h> 

#include "utc.h"

Question::Question() 
{
// qDebug() << "Question construction"; 
	quest = 0;
	for (int i=0; i < 4; i++) 
	{
		ans_correct[i] = 0;
		ans_student[i] = 0;
		ans_student_correct[i] = 0;
	}	
}
Question::~Question()
{
// qDebug() << "Question destruction";	
}

Test::Test() {
// qDebug() << "Test construction";
	points = 0;
	for (int i=0; i < 20; i ++) q[i] = Question();
//qDebug() << "end Test construction";		
	} 
Test::~Test() 
{ 
// qDebug() << "Test destruction";
}

BaseQuestion::BaseQuestion(QString s, QVector<BaseAns> a)
{
	text = s;
	ans = a;
}
 
Utc::Utc(QWidget *parent) : QDialog(parent)
{
qDebug() << "start Utc";
ui.setupUi(this);
	filename = "data.tex";
	connect(ui.a0, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.a1, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.a2, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.b0, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.b1, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.b2, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.c0, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.c1, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.c2, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.d0, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.d1, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.d2, SIGNAL(clicked()), this, SLOT(abcd()));
	connect(ui.test_no, SIGNAL(valueChanged(int)), this, SLOT(new_test(int)));
	connect(ui.quest_no, SIGNAL(valueChanged(int)), this, SLOT(new_quest(int)));
	connect(ui.save, SIGNAL(clicked()), this, SLOT(save()));
	connect(ui.load, SIGNAL(clicked()), this, SLOT(load/*read_students_tests*/()));
	connect(ui.calc, SIGNAL(clicked()), this, SLOT(calc()));

	read_data_tests();	
//	print();
//	read_data();
	go();
qDebug() << "stop Utc";
}

void Utc::abcd()
{
qDebug() << "abcd begin" << current_quest;	
	Question* qq = &current_test.value().q[current_quest - 1];
	qq->ans_student[0] = 0;
	if (ui.a1->isChecked())	qq->ans_student[0] = 1;
	if (ui.a2->isChecked()) qq->ans_student[0] = 2;	
	qq->ans_student[1] = 0;
	if (ui.b1->isChecked())	qq->ans_student[1] = 1;
	if (ui.b2->isChecked()) qq->ans_student[1] = 2;	
	qq->ans_student[2] = 0;
	if (ui.c1->isChecked())	qq->ans_student[2] = 1;
	if (ui.c2->isChecked()) qq->ans_student[2] = 2;
	qq->ans_student[3] = 0;
	if (ui.d1->isChecked())	qq->ans_student[3] = 1;
	if (ui.d2->isChecked()) qq->ans_student[3] = 2;

	calc_points();

	const QString pmm = "0+-";
	ui.aplus->setText(pmm[qq->ans_student_correct[0]]);
	ui.bplus->setText(pmm[qq->ans_student_correct[1]]);
	ui.cplus->setText(pmm[qq->ans_student_correct[2]]);
	ui.dplus->setText(pmm[qq->ans_student_correct[3]]);

	ui.quest->setNum(current_test.value().q[current_quest - 1].quest);

	total = current_test.value().points;
	ui.total->setNum(total);

	double ep = total*(ui.exam_max->value())/num_questions/4.0;
	if (ep < 0) ep = 0;
	ui.exam->setNum(qCeil(ep));

qDebug() << "abcd end" << current_quest << ": " 
	<< qq->ans_student[0] << qq->ans_student[1] << qq->ans_student[2]  << qq->ans_student[3] << " : " 
	<< qq->ans_student_correct[0] << " " << qq->ans_student_correct[1] << " " 
	<< qq->ans_student_correct[2] << " " << qq->ans_student_correct[3];
}

void Utc::go()
{
qDebug() << "begin go";	
	current_test = all_tests.begin();
	ui.test_no->setValue(current_test.key());
	current_quest = 1;
	ui.quest->setNum(0);
	ui.exam_max->setValue(10);
	total = 0;
	new_test(ui.test_no->value());
qDebug() << "end go";	
}

void Utc::new_test(int i)
{
qDebug() << "new_test " << i; 
	QMap<int, Test>::iterator it = all_tests.find(i); 
	if (it != all_tests.end()) 
	{
		current_test = it;
	}
	else ui.test_no->setValue(current_test.key());
	ui.quest_no->setValue(1);
	total = 0;
	ui.total->setNum(0);
	new_quest(1);
}

void Utc::new_quest(int i)
{
qDebug() << "new_quest " << i;	
	current_quest = i;
	Question* qq = &current_test.value().q[current_quest - 1];
qDebug() << i << ": " << qq->ans_student[0] << qq->ans_student[1] << qq->ans_student[2]  << qq->ans_student[3];	
	if (qq->ans_correct[0] == 1) ui.label_a->setText("A)");
	else ui.label_a->setText("a)");
	ui.a0->setChecked(true);
	if (qq->ans_student[0] == 1) ui.a1->setChecked(true);
	else if (qq->ans_student[0] == 2) ui.a2->setChecked(true);

	if (qq->ans_correct[1] == 1) ui.label_b->setText("B)");
	else ui.label_b->setText("b)");
	ui.b0->setChecked(true);
	if (qq->ans_student[1] == 1) ui.b1->setChecked(true);
	else if (qq->ans_student[1] == 2) ui.b2->setChecked(true);

	if (qq->ans_correct[2] == 1) ui.label_c->setText("C)");
	else ui.label_c->setText("c)");
	ui.c0->setChecked(true);
	if (qq->ans_student[2] == 1) ui.c1->setChecked(true);
	else if (qq->ans_student[2] == 2) ui.c2->setChecked(true);

	if (qq->ans_correct[3] == 1) ui.label_d->setText("D)");
	else ui.label_d->setText("d)");
	ui.d0->setChecked(true);
	if (qq->ans_student[3] == 1) ui.d1->setChecked(true);
	else if (qq->ans_student[3] == 2) ui.d2->setChecked(true);

	abcd();
}

void Utc::print()
{
 	QMapIterator<int, Test> it(all_tests);
 	while (it.hasNext()) 
	{
     		it.next();
		for (int j=0; j < num_questions; j++)
			for (int k=0; k < 4; k++)
qDebug() << it.key() << "-" << j << "-" << k << ":" << it.value().q[j].ans_correct[k];
	}
}
/*
bool Utc::read_students_tests() // load
{
qDebug() << "begin read_students_tests ";
	QFile inp("save.txt");
	if (!inp.open(QFile::ReadOnly))
	{
qDebug() << "ERROR!";
		return false;		
	}
	int num_test, q;
	QTextStream text(&inp);
	QString line;
	while (!text.atEnd())
	{
		line = inp.readLine();
qDebug() << line;
if (!line.isEmpty ())
{
		Question* qq;
		if (line.left(8) == "Test No.")
		{
			num_test = line.mid(8).toInt();
qDebug() << num_test;			
			current_test = all_tests.insert(num_test, Test());
			q = 0;
		}
		else if (line.left(1) == "q")
		{
			current_quest = q;
			q++;
			qq = &(current_test.value().q[current_quest]);
		}
		else if (line.size() > 1 && line.left(1) == "a") 
		{
			qq->ans_correct[0] = 2;
			if (line.mid(2,1) == "n") 
			{
				qq->ans_student[0] = 2;
				qq->ans_student_correct[0] = 1;
			}
			else if (line.mid(2,1) == "y")
			{
				qq->ans_student[0] = 1;
				qq->ans_student_correct[0] = 2;
			}	
		}
}		
	
	}
	inp.close();
	return true;
}
*/
bool Utc::read_data_tests()
{
qDebug() << "begin read_data_tests " << filename;
	QFile inp("out.tex");
	if (!inp.open(QFile::ReadOnly))
	{
qDebug() << "ERROR!";
		return false;		
	}
	int num_test = 0;
	int j = -1, k = -1;
	QTextStream text(&inp);
	while (!text.atEnd())
	{
		QString line = inp.readLine();
		int no = line.indexOf("No.");
		if (no > 0) 
		{
			num_test = line.mid(no + 4, 4).toInt();
			all_tests.insert(num_test, Test());
			j = -1;	
		}
		else if (line.left(5) == "%%%% ")
		{
		
//			all_tests[num_test].q[j].num = j; //line.mid(5,2).toInt();
qDebug() << num_test << k << j;
			 k = -1; j++;
		}	
		else if (line.left(4) == "%%% ")
		{
			k++;
			if (line.mid(4,2).toInt() > 0) all_tests[num_test].q[j].ans_correct[k] = 1;
			else all_tests[num_test].q[j].ans_correct[k] = 2;
qDebug() << num_test << "-" << j << "-" << k << ":" << all_tests[num_test].q[j].ans_correct[k];
		
		}
	}
	num_questions = j + 1;
	ui.quest_no->setRange(1, num_questions);
qDebug() << "num_questions = " << num_questions;
	return true;
}


void Utc::calc_points()
{
	int sum = 0;
	for (int i=0; i < num_questions; i++)
	{
		int q_sum = 0;
		Question* qq = &(current_test.value().q[i]);
		for (int j=0; j < 4; j++)
		{
			qq->ans_student_correct[j] = 0; // no answer
qDebug() << 0;			
			if (qq->ans_correct[j] == qq->ans_student[j]) 
			{ 
				sum++; q_sum++; 
				qq->ans_student_correct[j] = 1; // correct
qDebug() << 1;				
			}
			if (qq->ans_correct[j] + qq->ans_student[j] == 3) 
			{ 
				sum--; q_sum--; 
				qq->ans_student_correct[j] = 2; // incorrect
qDebug() << 2;				
			}
		}
		qq->quest = q_sum;
	}
	current_test.value().points = sum;
}

void Utc::save()
{
qDebug() << "begin save"; 
	QFile outfile("save.txt");
	outfile.open(QIODevice::WriteOnly);
	QTextStream out(&outfile);
	out.setCodec("UTF-8");

	QString abcd = "abcd", ABCD = "ABCD";

//	QMapIterator<int, Test> it(all_tests);
	QMap<int, Test>::iterator it;
// 	while (it.hasNext()) 
	for (it = all_tests.begin(); it != all_tests.end(); ++it)
	{
//     		it.next();
		out << "Test No. " << it.key() << endl;
		for (int j=0; j < num_questions; j++)
		{
			out << "q" << j + 1 << " " << endl;
			const Question* qq = &(it.value().q[j]);
			for (int k=0; k < 4; k++)
			{
				if (qq->ans_correct[k] == 1) out << ABCD[k];
				else out << abcd[k]; 
				if (qq->ans_student[k] == 1) out << " yes ";
				else if  (qq->ans_student[k] == 2) out << " no ";
				if (qq->ans_student[k] == qq->ans_correct[k]) out << "+";
				if (qq->ans_student[k] + qq->ans_correct[k] == 3) out << "-";
				out << endl;
			}
			current_test = it; calc_points();
			out << qq->quest << endl;
		}

		double ep =  it.value().points*(ui.exam_max->value())/num_questions/4.0;
		if (ep < 0) ep = 0;
		out << "Total " << it.value().points << " ( " << qCeil(ep) << " pt )" << endl;
	}
	outfile.close();
qDebug() << "end save";	
}

bool Utc::load()
{
qDebug() << "begin load"; 
	QFile inp("save.txt");
	if (!inp.open(QFile::ReadOnly))
	{
qDebug() << "ERROR!";
		return false;		
	}
	QTextStream text(&inp);
	int id, num;
	QString abcd = "abcd";
	Test *t;
	while (!text.atEnd())
	{
		QString line = text.readLine();
		QStringList qsl = line.split(' ');
		if (qsl[0] == "Test") 
		{
			id = qsl[2].toInt();
			t = new Test;
			num = 0;
		}
		else if (qsl[0] == "Total") 
		{
			t->points = qsl[1].toInt();
			all_tests.insert(id, *t);
		}
		else if (qsl[0][0] == 'q')
		{
			for (int ind = 0; ind < 4; ind++)
			{
				line = text.readLine();
				qsl = line.split(' ');
				if (abcd.indexOf(qsl[0]) >= 0) t->q[num].ans_correct[ind] = 2;
				else t->q[num].ans_correct[ind] = 1;
				if (qsl.size() > 1)
				{
					if(qsl[1] == "no") t->q[num].ans_student[ind] = 2;
					else t->q[num].ans_student[ind] = 1;
					if (qsl[2] == "-") t->q[num].ans_student_correct[ind] = 2;
					else t->q[num].ans_student_correct[ind] = 1;
				}
			}
			line = text.readLine();
			t->q[num].quest = line.toInt();
			num++;	
		}
		else 
qDebug() << "ERROR " << line;			
	}

	inp.close();
qDebug() << "end load"; 
	return true;
}

bool Utc::read_data()
{
qDebug() << "begin read_data()";	
	QFile inp("data.tex");
	if (!inp.open(QFile::ReadOnly))
	{
qDebug() << "ERROR 1!";
		return false;		
	}
	QTextStream text(&inp);

	QFile outfile("data_result.txt");
//	outfile.open(QIODevice::WriteOnly);
	if (!outfile.open(QFile::WriteOnly))
	{
qDebug() << "ERROR 2!";
		return false;		
	}
	QTextStream out(&outfile);
	out.setCodec("UTF-8");

	QVector<BaseAns> ans;
	while (!text.atEnd())
	{
		QString line = text.readLine();
		if (line.isEmpty() || line[0] != '%') out << line << endl;
qDebug() << "--------- new line";
qDebug() << line;
		if ("%%%%% " == line.left(6))
		{
			ans.clear();
		}
		else if ("%%% " == line.left(4))
		{
			BaseAns a;
//%%% 2 2172-1-0; 2179-2-3;  %%%			
			QStringList qst0 = line.split(" ");
			int i = qst0[1].toInt();
			for (int j = 0; j < i; j++)
			{
//2172-1-0;	
				QStringList qst1 = qst0[2 + j].split('-');
				qst1[2] = qst1[2].remove(qst1[2].size() - 1);
				int testID = qst1[0].toInt();
				if (all_tests[testID].points > 0)
				{
					int k = 
				all_tests[testID].q[qst1[1].toInt()].ans_student[qst1[2].toInt()];
					a.total++;
					if (k == 1) a.correct++;
					else if (k == 2) a.incorrect++;
qDebug() << " all : " << a.total << a.correct << a.incorrect;  	
// ep = total*(ui.exam_max->value())/num_questions/4.0;
					if (all_tests[testID].points*(ui.exam_max->
								value())/num_questions/4.0 >= 5) //????????????????
					{
						a.total1++;
						if (k == 1) a.correct1++;
						else if (k == 2) a.incorrect1++;
qDebug() << " >=5 : " << a.total1 << a.correct1 << a.incorrect1;  				
					}
				}
			}
			a.text = text.readLine();
			out << a.text << " % " << a.total << ":" << a.correct << ":" << a.incorrect 
				<< "  " << a.total1 << ":" << a.correct1 << ":" << a.incorrect1 << endl;
qDebug() << a.text;
			ans.push_back(a);
		}		
	}
	inp.close();
	outfile.close();
qDebug() << "end read_data()";	
	return true;
}

void Utc::write_result()
{
qDebug() << "begin write_result()";

qDebug() << "end write_result()";	
}


void Utc::calc()
{
	if (read_data()) write_result();
}


