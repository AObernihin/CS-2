#include <iostream>
#include <random>
using namespace std;

template <typename T>
class Matrix {
	int X;
	int Y;
	T** parr;
public:
	Matrix(int X, int Y) : X(X), Y(Y) {
		parr = new int* [X];
		for (int i = 0; i < X; i++) {
			parr[i] = new int[Y];
		}
	}

	~Matrix() {
		for (int i = 0; i < X; ++i)
		{
			delete[] parr[i];
		} delete[] parr;
	}

	void FillManually()
	{

		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				cin >> parr[i][j];
			}
		}
	}

	void FillRandom()
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distrib(1, 2347);
		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				parr[i][j] = distrib(gen);
			}
		}
	}

	void Show() const {
		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				cout << parr[i][j];
			}
			cout << endl;
		}
	}
	Matrix operator+(const Matrix other) {
		if (this->X == other.X && this->Y == other.Y) {
			for (int i = 0; i < X; i++) {
				for (int j = 0; j < Y; j++) {
					parr[i][j] += other[i][j];
				}
			}
		}
		else {
			cout << "invalid size of Matrix" << endl;
		}
	}

	Matrix operator-(const Matrix other) {
		if (this->X == other.X && this->Y == other.Y) {
			for (int i = 0; i < X; i++) {
				for (int j = 0; j < Y; j++) {
					parr[i][j] -= other[i][j];
				}
			}
		}
		else {
			cout << "invalid size of Matrix" << endl;
		}
	}

	Matrix operator*(const Matrix other) {
		if (this->X == other.X && this->Y == other.Y) {
			for (int i = 0; i < X; i++) {
				for (int j = 0; j < Y; j++) {
					parr[i][j] *= other[i][j];
				}
			}
		}
		else {
			cout << "invalid size of Matrix" << endl;
		}
	}
	Matrix operator/(const Matrix other) {
		if (this->X == other.X && this->Y == other.Y) {
			for (int i = 0; i < X; i++) {
				for (int j = 0; j < Y; j++) {
					parr[i][j] /= other[i][j];
				}
			}
		}
		else {
			cout << "invalid size of Matrix" << endl;
		}
	}

	T findMaxElement() const {
		T maxElement = parr[0][0];
		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				if (parr[i][j] > maxElement) {
					maxElement = parr[i][j];
				}
			}
		}
		return maxElement;
	}

	T findMinElement() const {
		T minElement = parr[0][0];
		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				if (parr[i][j] < minElement) {
					minElement = parr[i][j];
				}
			}
		}
		return minElement;
	}
};

int main()
{


}