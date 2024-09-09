#pragma once
#include <iostream>

template <class T>
class Matrix {

	T** arr;
	int sz;
	
	

public:

	template <class U>
	friend Matrix<U> operator+(const Matrix<U>& lhs, const Matrix<U>& rhs);
	
	template <class U>
	friend Matrix<U> operator-(const Matrix<U>& lhs, const Matrix<U>& rhs);
	
	template <class U>
	friend Matrix<U> operator/(const Matrix<U>& lhs, const Matrix<U>& rhs);
	
	template <class U>
	friend Matrix<U> operator*(const Matrix<U>& lhs, const Matrix<U>& rhs);
   
	
	Matrix() : sz{ 0 }, arr{ nullptr } {}

	Matrix(int sz) : sz{ sz }, arr{ new T * [sz] } {
		for (int i{}; i < sz; ++i) {
			arr[i] = new T[sz]{ 0 };
		}
	}

	Matrix(int sz, int val) : Matrix(sz) {
		for (int i{}; i < sz; ++i) {
			for (int j{}; j < sz; ++j) {
				arr[i][j] = val;
			}
		}
	}

	Matrix(const Matrix& obj):Matrix(obj.sz) {
		for (int i{}; i < sz; ++i) {
			for (int j{}; j < sz; ++j) {
				arr[i][j] = obj.arr[i][j];
			}
		}
	}

	Matrix& operator+=(const Matrix& obj) {
		for (int i{}; i < sz; ++i) {
			for (int j{}; j < sz; ++j) {
				this->arr[i][j] += obj.arr[i][j];
			}
		}

		return *this;
	}

	Matrix& operator-=(const  Matrix& obj) {
		for (int i{}; i < sz; ++i) {
			for (int j{}; j < sz; ++j) {
				this->arr[i][j] -= obj.arr[i][j];
			}
		}

		return *this;
	}

	Matrix& operator*=(const Matrix& obj) {
		for (int i{}; i < sz; ++i) {
			for (int j{}; j < sz; ++j) {
				this->arr[i][j] *= obj.arr[i][j];
			}
		}
		return *this;

	}
 	
	Matrix& operator/=(const Matrix& obj) {
		for (int i{}; i < sz; ++i) {
			for (int j{}; j < sz; ++j) {
				this->arr[i][j] /= obj.arr[i][j];
			}
		}
		return *this;
	}

	Matrix& operator=(const Matrix& obj) {
		if (this != &obj) { 
			if (sz != obj.sz) { 
				for (int i = 0; i < sz; ++i) {
					delete[] arr[i];
				}
				delete[] arr;

				
				sz = obj.sz;
				arr = new T * [sz];
				for (int i = 0; i < sz; ++i) {
					arr[i] = new T[sz];
				}
			}

			
			for (int i = 0; i < sz; ++i) {
				for (int j = 0; j < sz; ++j) {
					arr[i][j] = obj.arr[i][j];
				}
			}
		}
		return *this;
	}

	~Matrix() {
		for (int i{}; i < sz; ++i) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	void print() const {
		for (int i{}; i < sz; ++i) {
			for (int j{}; j < sz; ++j) {
				std::cout << arr[i][j] << " ";

			}
			std::cout << std::endl;
		}
	}

	void rand_val(int val) {
		for (int i{}; i < sz; ++i) {
			for (int j{}; j < sz; ++j) {
				arr[i][j] = rand() % (val + 1);
			}
		}
	}

	void Add_manually() {
		for (int i{}; i < sz; ++i) {
			for (int j{}; j < sz; ++j) {
				std::cout << "Enter a value : ";
				std::cin >> arr[i][j];
			}
		}
	}

	T max_element() const {
		T max = arr[0][0];
		for (int i{}; i < sz; ++i) {
			for (int j{}; j < sz; ++j) {
				if (max < arr[i][i])
					max = arr[i][j];
			}
		}
		return max;
	}

	T min_element() const {
		T min = arr[0][0];
		for (int i{}; i < sz; ++i) {
			for (int j{}; j < sz; ++j) {
				if (min > arr[i][j])
					min = arr[i][j];
			}
		}
		return min;
	}

};

template <class T>
Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs) {
	if (lhs.sz != rhs.sz) {
		throw std::runtime_error("Matrices must be of the same size");
	}

	Matrix<T> result(lhs.sz);
	for (int i = 0; i < lhs.sz; ++i) {
		for (int j = 0; j < lhs.sz; ++j) {
			result.arr[i][j] = lhs.arr[i][j] + rhs.arr[i][j];
		}
	}
	return result;
}

template <class T>
Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs) {
	if (lhs.sz != rhs.sz) {
		throw std::runtime_error("Matrices must be of the same size");
	}

	Matrix<T> result(lhs.sz);
	for (int i = 0; i < lhs.sz; ++i) {
		for (int j = 0; j < lhs.sz; ++j) {
			result.arr[i][j] = lhs.arr[i][j] - rhs.arr[i][j];
		}
	}
	return result;
}

template <class T>
Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs) {
	if (lhs.sz != rhs.sz) {
		throw std::runtime_error("Matrices must be of the same size");
	}

	Matrix<T> result(lhs.sz);
	for (int i = 0; i < lhs.sz; ++i) {
		for (int j = 0; j < lhs.sz; ++j) {
			result.arr[i][j] = lhs.arr[i][j] * rhs.arr[i][j];
		}
	}
	return result;
}

template <class T>
Matrix<T> operator/(const Matrix<T>& lhs, const Matrix<T>& rhs) {
	if (lhs.sz != rhs.sz) {
		throw std::runtime_error("Matrices must be of the same size");
	}

	Matrix<T> result(lhs.sz);
	for (int i = 0; i < lhs.sz; ++i) {
		for (int j = 0; j < lhs.sz; ++j) {
			result.arr[i][j] = lhs.arr[i][j] / rhs.arr[i][j];
		}
	}
	return result;
}
