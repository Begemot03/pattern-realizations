#include <iostream>
#include <vector>

template<class T>
struct Vector {
	T x;
	T y;

	Vector<T> (T x, T y) : x(x), y(y) {}
};

class Matrix {
public:
	virtual Vector<int> getVector(int id) = 0;
};

//request for bd imitation
class MatrixBd : public Matrix {
public:
	std::vector<Vector<int>> matrix;

	MatrixBd() {
		this->matrix.push_back(Vector(1, 5));
		this->matrix.push_back(Vector(2, 6));
		this->matrix.push_back(Vector(3, 7));
		this->matrix.push_back(Vector(4, 8));
	}

	Vector<int> getVector(int id) {
		return matrix[id];
	}
};

class MatrixProxy : public Matrix {
public:
	std::vector<Vector<int>> matrix;
	MatrixBd bd;
	
	Vector<int> getVector(int id) {
		if(matrix.size() <= id) {
			if(bd.matrix.empty()) {
				bd = MatrixBd();
			}

			matrix = bd.matrix;
		}

		return matrix[id];
	}
};

int main() {
	Matrix *m = new MatrixProxy();
	std::cout << m->getVector(1).x << std::endl;

	delete m;
	
	return 0;
}