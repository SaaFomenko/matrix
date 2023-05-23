#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template<class T>
class Matrix 
{
	private:

		const int row_;
		const int col_;
		std::vector<std::vector<T>>* double_vector;

	public:

		Matrix(const int row, const int col) :
			row_(row),
			col_(col)
		{
			double_vector = new std::vector<std::vector<T>>[row_];

			for (int i = 0; i < row_; ++i)
			{
				double_vector[i] = new std::vector<T>[col_];
			}
		}

		virtual ~Matrix() 
		{
			for (int i = 0; i < row_; ++i)
			{
				delete[] double_vector[i];
			}

			delete[] double_vector;
			double_vector = nullptr;
		}

};

#endif
