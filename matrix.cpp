#ifndef MATRIX_H
#define MATRIX_H


template <class T>
class Matrix
{
	private:
		const unsigned int rows;
		const unsigned int cols;
		T** arr;

	public:
		Matrix(
				const unsigned int rows_, 
				const unsigned int cols_
			) :
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

	T* operator[](int row)
	{
		if (row >= rows) throw "Fail index rows matrix.";
		return arr[row];
	}	

	T* operator[](int row) const
	{
		if (row >= rows) throw "Fail index rows matrix.";
		return arr[row];
	}	

	const unsigned int sizeRows()
	{
		return rows;
	}

	const unsigned int sizeCols()
	{
		return cols;
	}

	const unsigned int Size()
	{
		return rows * cols;
	}
};

#endif
