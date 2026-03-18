#include "Matrix.h"

//double** data;
//size_t rows;
//size_t cols;


void Matrix::copyFrom(const Matrix& other)
{
	rows = other.rows;
	cols = other.cols;
	data = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			data[i][j] = other.data[i][j];
		}
	}
}

void Matrix::free()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[] data;
	data = nullptr;
	rows = 0;
	cols = 0;
}

void Matrix::moveFrom(Matrix&& other) noexcept
{
	data = other.data;
	rows = other.rows;
	cols = other.cols;

	other.rows = other.cols = 0;
	other.data = nullptr;
}

Matrix::Matrix(size_t r, size_t c) : rows(r), cols(c) {
	data = new double* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		data[i] = new double[cols];
	}
}

Matrix::Matrix(size_t r, size_t c, double** data) : rows(r), cols(c), data(data) {}

Matrix::Matrix(const Matrix& other)
{
	copyFrom(other);
}

Matrix::Matrix(Matrix&& other) noexcept
{
	moveFrom(std::move(other));
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept
{
	if (this != &other) {
		moveFrom(std::move(other));
	}
	return *this;
}

Matrix::~Matrix()
{
	free();
}

double& Matrix::at(size_t r, size_t c)
{
	return data[r][c];
}

const double& Matrix::at(size_t r, size_t c) const
{
	return data[r][c];
}

Matrix Matrix::transposed() const
{
	Matrix m(cols, rows);
	for (size_t i = 0; i < cols; i++)
	{
		for (size_t j = 0; j < rows; j++)
		{
			m.data[i][j] = data[j][i];
		}
	}

	return m;
}

size_t Matrix::getRows() const
{
	return rows;
}

size_t Matrix::getCols() const
{
	return cols;
}
