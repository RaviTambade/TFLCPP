#ifndef MARKSHEET_H
#define MARKSHEET_H


//Header file
class Marksheet
{
	private :
			 char  student[10];
			 int  english, marathi, hindi;
	public:
		Marksheet();
		Marksheet(int e, int m, int h, char nm[]);
		void showResult();
		~Marksheet();
	protected:
};

#endif
