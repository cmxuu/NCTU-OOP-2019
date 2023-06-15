//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2020/07/14
//
#include "mySystemApp.h"

using namespace std;

#define STUDENT_INFO "Name: Ming-Hsuan Tsai  ID: 0812203"

void MY_SYSTEM_APP::showMyStudentInfo_2020_Summer( ) const
{
	cout << "*******************************" << endl;
    cout << "Date:2020/07/14" << endl;
	cout << "Student ID:\t0812203" << endl;
	cout << "Student Name:\tMing-Hsuan Tsai" << endl;
	cout << "Student Email:\tminghsuan.am08@nctu.edu.tw" << endl;
	cout << "*******************************" << endl;
}

MY_SYSTEM_APP::MY_SYSTEM_APP( )
{
	mSystemType = SYSTEM_TYPE_MONTE_CARLO;
    string title = STUDENT_INFO;
        glutSetWindowTitle(title.data( ));
}

void MY_SYSTEM_APP::initApp( )
{
	mFlgShow_Grid = true;
}

void MY_SYSTEM_APP::update( )
{

}
// CODE: 2019/02/25. Do not delete this line.



