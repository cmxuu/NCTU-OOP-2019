//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2020/07/14
//
#include "mySystem_StudentRecordManager.h"
#include <iostream>

using namespace std;

STUDENT_RECORD_MANAGER::STUDENT_RECORD_MANAGER( )
{
	mNumStudents = 0;
}

void STUDENT_RECORD_MANAGER::askForInput( )
{
	//Show the system title
	//Ask to input the number of students
	//Ask to input the score of each student
	//Show the average
	//Show the standard deviation
	//Show the scores in an ascending order
	//
	cout << "STUDENT_RECORD_MANAGER" << endl;

	while (true) {
		cout << "Input the number of students [2, 100]:" << endl;
		cin >> mNumStudents;
		if (mNumStudents >= 2 && mNumStudents <= 100) break;
	}

	mScore.clear();
	mSortedScore.clear();

	int _score;
	cout << "Input the scores [1,100]:" << endl;
	for (int i = 0; i < mNumStudents; i++)
	{
		while (true) {
			cout << "Student: " << i << ")\t";
			cin >> _score;
			if (_score >= 0 && _score <= 100) {
				mScore.push_back(_score);
				mSortedScore.push_back(_score);
				break;
			}	
		}
	}
	computeAverage( );
	computeStandardDeviation( );
	cout << "Average:" << mAverageScore << endl;
	cout << "Standard Deviation:" << mStandardDeviation << endl;
	sortScores( );
	showSortedScores( );
}

double STUDENT_RECORD_MANAGER::computeAverage( )
{
	//Compute the average
	double totalScore = 0.0;
	for (int i = 0; i < mNumStudents; i++)
		totalScore += mScore[i];
	mAverageScore = (double)totalScore/mNumStudents;
	return mAverageScore;
}

double STUDENT_RECORD_MANAGER::computeStandardDeviation( )
{
	//Compute the standard deviation
    mStandardDeviation = 0.0;
    if ( mNumStudents < 2 ) return 0.0;
	double sum = 0.0;
	for (int i = 0; i < mNumStudents; i++)
		sum += ((mScore[i] - mAverageScore)*(mScore[i] - mAverageScore));
	mStandardDeviation = sqrt( (double)sum / (mNumStudents -1) );
	return mStandardDeviation;
}

void STUDENT_RECORD_MANAGER::sortScores( )
{
	//Sorting in an ascending order
	for (int i = 0; i < mNumStudents; i++)
	{
		int key = mSortedScore[i];
		int j = i - 1;
		while (mSortedScore[j] > key&&j>=0) {
			mSortedScore[j + 1] = mSortedScore[j];
			j--;
		}
		mSortedScore[j + 1] = key;
	}
	
}

void STUDENT_RECORD_MANAGER::showSortedScores( ) const
{
	//Show the scores in an ascending order

	cout << "Sorted scores:" << endl;
	for ( int i = 0; i < mNumStudents; ++i ) {
		cout << mSortedScore[i] << endl;
	}
}

int STUDENT_RECORD_MANAGER::getNumOfStudentsInScoreInterval(int s0, int s1) const
{
	//
	//Return the number of students whose score is inside the interval [s0, s1]. 
	//s0 and s1 are included.
	// 
	int num = 0;
	for ( int i = 0; i < mNumStudents; ++i ) {
		if (mSortedScore[i] >= s0 && mSortedScore[i] <= s1)
			num++;
	}
	return num;
}
// CODE: 2020/07/14. Do not delete this line.