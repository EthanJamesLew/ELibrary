#ifndef EMATRIX_H
#define EMATRIX_H

#include <vector>
namespace e
{
	template <typename T> class EMatrix {

	public:
		EMatrix(unsigned _rows, unsigned _cols, const T& _initial);
		EMatrix(const EMatrix<T>& rhs);
		virtual ~EMatrix();

		//Arithmetic matrix-matrix operations                                           
		EMatrix<T>& operator=(const EMatrix<T>& rhs);
		EMatrix<T> operator+(const EMatrix<T>& rhs);
		EMatrix<T>& operator+=(const EMatrix<T>& rhs);
		EMatrix<T> operator-(const EMatrix<T>& rhs);
		EMatrix<T>& operator-=(const EMatrix<T>& rhs);
		EMatrix<T> operator*(const EMatrix<T>& rhs);
		EMatrix<T>& operator*=(const EMatrix<T>& rhs);

		//Square matrix properties
		EMatrix<T> transpose();
		EMatrix<T> identity();
		EMatrix<T> permutative();

		//Arithmetic scalar-matrix operations                                   
		EMatrix<T> operator+(const T& rhs);
		EMatrix<T> operator-(const T& rhs);
		EMatrix<T> operator*(const T& rhs);
		EMatrix<T> operator/(const T& rhs);

		//Arithmetic vector-matrix operations
		std::vector<T> operator*(const std::vector<T>& rhs);
		std::vector<T> diag_vec();

		T& operator()(const unsigned& row, const unsigned& col);
		const T& operator()(const unsigned& row, const unsigned& col) const;

		unsigned get_rows() const;
		unsigned get_cols() const;

		bool isSquare();

	private:
		std::vector<std::vector<T> > _mat;
		unsigned _rows;
		unsigned _cols;

	};
}

#include "ematrix.cpp"

#endif