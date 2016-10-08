
#ifndef EMATRIX_CPP
#define EMATRIX_CPP

#include "ematrix.h"

namespace e
{
	//Parametric constructor                                                
	template<typename T>
	EMatrix<T>::EMatrix(unsigned _rows, unsigned _cols, const T& _initial) {
		_mat.resize(_rows);
		for (unsigned i = 0; i < _mat.size(); i++) {
			_mat[i].resize(_cols, _initial);
		}
		_rows = _rows;
		_cols = _cols;
	}

	//Copy constructor                                         
	template<typename T>
	EMatrix<T>::EMatrix(const EMatrix<T>& rhs) {
		_mat = rhs._mat;
		_rows = rhs.get_rows();
		_cols = rhs.get_cols();
	}

	//General destructor                                         
	template<typename T>
	EMatrix<T>::~EMatrix() {}


	template<typename T>
	EMatrix<T>& EMatrix<T>::operator=(const EMatrix<T>& rhs) {
		if (&rhs == this)
			return *this;

		unsigned new_rows = rhs.get_rows();
		unsigned new_cols = rhs.get_cols();

		_mat.resize(new_rows);
		for (unsigned i = 0; i < _mat.size(); i++) {
			_mat[i].resize(new_cols);
		}

		for (unsigned i = 0; i < new_rows; i++) {
			for (unsigned j = 0; j < new_cols; j++) {
				_mat[i][j] = rhs(i, j);
			}
		}
		_rows = new_rows;
		_cols = new_cols;

		return *this;
	}


	template<typename T>
	EMatrix<T> EMatrix<T>::operator+(const EMatrix<T>& rhs) {
		EMatrix result(_rows, _cols, 0.0);

		for (unsigned i = 0; i < _rows; i++) {
			for (unsigned j = 0; j < _cols; j++) {
				result(i, j) = this->_mat[i][j] + rhs(i, j);
			}
		}

		return result;
	}


	template<typename T>
	EMatrix<T>& EMatrix<T>::operator+=(const EMatrix<T>& rhs) {
		unsigned _rows = rhs.get_rows();
		unsigned _cols = rhs.get_cols();

		for (unsigned i = 0; i < _rows; i++) {
			for (unsigned j = 0; j < _cols; j++) {
				this->_mat[i][j] += rhs(i, j);
			}
		}

		return *this;
	}


	template<typename T>
	EMatrix<T> EMatrix<T>::operator-(const EMatrix<T>& rhs) {
		unsigned _rows = rhs.get_rows();
		unsigned _cols = rhs.get_cols();
		EMatrix result(_rows, _cols, 0.0);

		for (unsigned i = 0; i < _rows; i++) {
			for (unsigned j = 0; j < _cols; j++) {
				result(i, j) = this->_mat[i][j] - rhs(i, j);
			}
		}

		return result;
	}


	template<typename T>
	EMatrix<T>& EMatrix<T>::operator-=(const EMatrix<T>& rhs) {
		unsigned _rows = rhs.get_rows();
		unsigned _cols = rhs.get_cols();

		for (unsigned i = 0; i < _rows; i++) {
			for (unsigned j = 0; j < _cols; j++) {
				this->_mat[i][j] -= rhs(i, j);
			}
		}

		return *this;
	}


	template<typename T>
	EMatrix<T> EMatrix<T>::operator*(const EMatrix<T>& rhs) {
		unsigned _rows = rhs.get_rows();
		unsigned _cols = rhs.get_cols();
		EMatrix result(_rows, _cols, 0.0);

		for (unsigned i = 0; i < _rows; i++) {
			for (unsigned j = 0; j < _cols; j++) {
				for (unsigned k = 0; k < _rows; k++) {
					result(i, j) += this->_mat[i][k] * rhs(k, j);
				}
			}
		}

		return result;
	}


	template<typename T>
	EMatrix<T>& EMatrix<T>::operator*=(const EMatrix<T>& rhs) {
		EMatrix result = (*this) * rhs;
		(*this) = result;
		return *this;
	}


	template<typename T>
	EMatrix<T> EMatrix<T>::transpose() {
		EMatrix result(_rows, _cols, 0.0);

		for (unsigned i = 0; i < _rows; i++) {
			for (unsigned j = 0; j < _cols; j++) {
				result(i, j) = this->_mat[j][i];
			}
		}

		return result;
	}

	template<typename T>
	EMatrix<T> EMatrix<T>::identity()
	{
		if (_rows != _cols)
		{
			throw "Matrix is NOT square, so its identity cannot be determined";
		}

		EMatrix<T> result(_cols, _cols, 0);
		for (unsigned i = 0; i < _cols; i++)
		{
			result(i, i) = (T)1;
		}
		return result;

	}

	template<typename T>
	EMatrix<T> EMatrix<T>::permutative()
	{
		if (_rows != _cols)
		{
			throw "Matrix is NOT square, so its permutation cannot be determined";
		}

		EMatrix<T> result(_cols, _cols, 0);
		for (unsigned i = _cols - 1; i > 0; --i)
		{
			result(i, _cols - 1 - i) = (T)1;
		}
		result(0, _rows - 1) = (T)1;
		return result;
	}


	template<typename T>
	EMatrix<T> EMatrix<T>::operator+(const T& rhs) {
		EMatrix result(_rows, _cols, 0.0);

		for (unsigned i = 0; i < _rows; i++) {
			for (unsigned j = 0; j < _cols; j++) {
				result(i, j) = this->_mat[i][j] + rhs;
			}
		}

		return result;
	}


	template<typename T>
	EMatrix<T> EMatrix<T>::operator-(const T& rhs) {
		EMatrix result(_rows, _cols, 0.0);

		for (unsigned i = 0; i < _rows; i++) {
			for (unsigned j = 0; j < _cols; j++) {
				result(i, j) = this->_mat[i][j] - rhs;
			}
		}

		return result;
	}


	template<typename T>
	EMatrix<T> EMatrix<T>::operator*(const T& rhs) {
		EMatrix result(_rows, _cols, 0.0);

		for (unsigned i = 0; i < _rows; i++) {
			for (unsigned j = 0; j < _cols; j++) {
				result(i, j) = this->_mat[i][j] * rhs;
			}
		}

		return result;
	}


	template<typename T>
	EMatrix<T> EMatrix<T>::operator/(const T& rhs) {
		EMatrix result(_rows, _cols, 0.0);

		for (unsigned i = 0; i < _rows; i++) {
			for (unsigned j = 0; j < _cols; j++) {
				result(i, j) = this->_mat[i][j] / rhs;
			}
		}

		return result;
	}


	template<typename T>
	std::vector<T> EMatrix<T>::operator*(const std::vector<T>& rhs) {
		std::vector<T> result(rhs.size(), 0.0);

		for (unsigned i = 0; i < _rows; i++) {
			for (unsigned j = 0; j < _cols; j++) {
				result[i] = this->_mat[i][j] * rhs[j];
			}
		}

		return result;
	}


	template<typename T>
	std::vector<T> EMatrix<T>::diag_vec() {
		std::vector<T> result(_rows, 0.0);

		for (unsigned i = 0; i < _rows; i++) {
			result[i] = this->_mat[i][i];
		}

		return result;
	}


	template<typename T>
	T& EMatrix<T>::operator()(const unsigned& row, const unsigned& col) {
		return this->_mat[row][col];
	}


	template<typename T>
	const T& EMatrix<T>::operator()(const unsigned& row, const unsigned& col) const {
		return this->_mat[row][col];
	}


	template<typename T>
	unsigned EMatrix<T>::get_rows() const {
		return this->_rows;
	}


	template<typename T>
	unsigned EMatrix<T>::get_cols() const {
		return this->_cols;
	}

	template<typename T>
	bool EMatrix<T>::isSquare() {
		if (this->_rows == this->_cols)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

#endif