#ifndef MATRIX_H
#define MATRIX_H

//#include <vector>

template <class T>
class Array
{
	private:
		const int size;
		T* arr;

	public:
		Array(int size_) :
			size(size_),
			arr(new T[size])
		{}

		virtual ~Array()
		{
			delete[] arr;
			arr = nullptr;
		}

		T& operator[](int index) const
		{
			return arr[index];
		}

		T& operator[](int index)
		{
			return arr[index];
		}
};

template <class T>
class Matrix
{
	private:
		int rows;
		int cols;
		T** arr;

	public:
		Matrix(int rows_, int cols_) :
			rows(rows_),
			cols(cols_)
		{
			arr = new T*[rows];
			
			for (int i = 0; i < rows; ++i)
			{
				arr[i] = new T[cols];
			}
		}

		virtual ~Matrix()
		{
			for(int i = 0; i < rows; ++i)
			{
				delete[] arr[i];
			}

			delete[] arr;
			arr = nullptr;
		}

	RowInMatrix operator[](int row)
	{
		return RowInMatrix(*this, row);
	}	
};

class RowInMatrix
{
	friend class Matrix;
};

#endif
