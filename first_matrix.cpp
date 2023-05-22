#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template<class T>
class Matrix : public std::vector
{
	const int row_;
	const int col_;
	std::vector<T> double_array;

	public:

		Matrix(const int row, const int col) :
			row_(row),
			col_(col)
		{
			double_array = new T**[row_]();
  
			for (int i = 0; i < row_; ++i)
			{
				double_array[i] = new T*[col_]();
			}
		}

		virtual ~Matrix() 
		{
			for (int i = 0; i < row_; ++i)
			{
				delete[] double_array[i];
			}	
			delete[] double_array;
			double_array = nullptr;
		}

		const T*& operator[](int index)
		{
			return double_array[index];
		}

		const T**& operator[][]()
		{
			return double_array;
		}

		T& operator[][](int i, int j)
		{
			return double_array[i][j];
		}
};

#endif
