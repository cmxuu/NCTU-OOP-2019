#include "Matrix.h"

matrix::matrix()
{
	M = { {} };
}

matrix::matrix(int m, int n)
{
	//TO_DO: Use std::cin to initialize a matrix of size m * n

	for (int i = 0; i < m; i++)
	{
		vector<int> num;
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			num.push_back(x);
		}
		M.push_back(num);
	}
}

matrix::matrix(vector<vector<int>>& m)
{
	M = m;
}

void matrix::Add(matrix m1)
{
	if (!IsSameShape(m1))
	{
		cout << "Not the same shpae!" << endl;
	}
	else
	{
		cout << "m1+m2:" << endl;
		for (int i = 0; i < M.size(); i++)
		{
			for (int j = 0; j < M[0].size(); j++)
				cout << M[i][j] + m1.M[i][j] << " ";
			cout << endl;
		}
			
	}
}

void matrix::Sub(matrix m1)
{
	if (!IsSameShape(m1))
	{
		cout << "Not the same shpae!" << endl;
	}
	else
	{
		cout << "m1-m2:" << endl;
		for (int i = 0; i < M.size(); i++)
		{
			for (int j = 0; j < M[0].size(); j++)
				cout << M[i][j] - m1.M[i][j] << " ";
			cout << endl;
		}

	}
}

matrix matrix::Mul(matrix m1)
{
	if (M[0].size() != m1.M.size()) 
	{
		cout << "Cannot do multiplication!";
		return matrix();
	}
	else 
	{
		//TO_DO: Multiply two matrices and print the result.
		cout << "m1*m2:" << endl;
		vector<vector<int> > ans(M.size(), vector<int>(m1.M[0].size()));
		for (int i = 0; i < ans.size(); i++) 
		{
			for (int j = 0; j < ans[0].size(); j++)
			{
				for (int k = 0; k < M[0].size(); k++)
					ans[i][j] += (M[i][k] * m1.M[k][j]);
			}
		}
		return ans;
	}

}

void matrix::Inverse()
{

	//TO_DO: If inverse matrix exist, find and print inverse matrix.
	if (!SquareMatrix()||Det(M)==0)
		cout << "The Inverse Not Exist!" << endl;
	else
	{
		cout << "Inverse Matrix:" << endl;
		cout << "(1/" << Det(M) << ")*" << endl;
		for (int i = 0; i < M.size(); i++)
			for (int j = i; j < M.size(); j++)
				if (i != j)
				{
					int temp = M[i][j];
					M[i][j] = M[j][i];
					M[j][i] = temp;
				}

		for (int i = 0; i < M.size(); i++)
		{
			for (int j = 0; j < M.size(); j++)
			{
				vector<vector<int>> find;
				for (int p = 0; p < M.size(); p++)
				{
					vector<int> num;
					for (int q = 0; q < M.size(); q++)
						if (p != i && q != j)
						{
							num.push_back(M[p][q]);
						}
					if(p!=i)
						find.push_back(num);
				}
				if (Det(find) == 0)
					cout << "0 ";
				else
					cout << pow(-1, i)*pow(-1, j)*Det(find) << " ";
			}
			cout << endl;
		}
	}

}

bool matrix::IsSameShape(matrix m1)
{
	if ((M.size() != m1.M.size()) || (M[0].size() != m1.M[0].size()))
		return false;
	return true;
}


bool matrix::SquareMatrix()
{
	//TO_DO: Return true if matrix is a square matrix, otherwise return fasle.
	if (M.size() == M[0].size())
		return true;
	return false;
}

void matrix::GetDet()
{
	if (!SquareMatrix())
		cout << "Not a Square Matrix" << endl;
	else
		cout << "Determinant of matrix : " << Det(M) << endl;
	
}

int matrix::Det(vector<vector<int>>& m)
{

	//TO_DO: Compute the determinant of matrix m.
	if (m.size() == 2)
		return m[0][0] * m[1][1] - m[0][1] * m[1][0];
	else if (m.size() == 1)
		return m[0][0];
	else
	{
		int ans = 0;
		for (int i = 0; i < m.size(); i++)
		{
			vector<vector<int>> find;
			for (int j = 1; j < m.size(); j++)
			{
				vector<int> num;
				for (int k = 0; k < m.size(); k++)
				{
					if (k != i)
						num.push_back(m[j][k]);
				}
				find.push_back(num);
			}
			ans += m[0][i]*pow(-1, i)*Det(find);
		}
		return ans;
	}
}

void matrix::Print()
{
	for (int i = 0; i < M.size(); i++) {
		for (int j = 0; j < M[0].size(); j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}
