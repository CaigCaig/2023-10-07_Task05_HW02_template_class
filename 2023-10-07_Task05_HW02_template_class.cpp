#include <iostream>

using namespace std;

template <class T>
class table
{
private:
	T** M; // матрица
	int r; // количество строк
	int c; // количество столбцов
	int r_; // текущая координата в строке
	int c_; // текущая координата в столбце
	int total_size;
	bool f;
public:
	table()
	{
		c = r = 0;
		M = nullptr;
	}

	table(int _r, int _c)
	{
		r = _r;
		c = _c;
		f = 0;
		total_size = (sizeof(T) * r * c);

		M = (T**) new T * [r];

		for (int i = 0; i < r; i++)
			M[i] = (T*)new T[c];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				M[i][j] = 0;
	}

	~table()
	{
		if (c > 0)
		{
			// освободить выделенную память для каждой строки
			for (int i = 0; i < r; i++)
				delete[] M[i];
		}

		if (r > 0)
			delete[] M;
	}

	T GetMij(int i, int j)
	{
	    if ((r > 0) && (c > 0))
	        return M[i][j];
	    else
	        return 0;
	}

	void SetMij(int i, int j, T value)
	{
	    if ((i < 0) || (i >= r))
	        return;
	    if ((j < 0) || (j >= c))
	        return;
	    M[i][j] = value;
	}

	int const Size() { return this->r * this->c; }

	operator T& ()
	{
		return M[r_][c_];
	}

	table& operator = (T val)
	{
		try {
			if ((r_ > (r - 1)) || (r_ < 0) || (c_ > (c - 1)) || (c_ < 0)) throw exception("Out of range");
		}
		catch (const std::exception& ex) {
			cout << ex.what() << endl;
			system("pause");
			exit(1);
		}

		M[r_][c_] = val;
		return *this;
	}

	table& operator = (table& arr)
	{
		try {
			if ((r != arr.r) || (c != arr.c)) throw exception("Out of range");
		}
		catch (const std::exception& ex) {
			cout << ex.what() << endl;
			system("pause");
			exit(1);
		}

		for (int i = 0; i < arr.r; i++)
			for (int j = 0; j < arr.c; j++)
				M[i][j] = arr.M[i][j];
		return *this;
	}

	const table& operator [] (int i) const
	{
		try {
			if (f == false) {
				if ((r_ > (r - 1)) || (r_ < 0)) throw exception("Out of range");
				r_ = i;
			}
			else {
				if ((c_ > (c - 1)) || (c_ < 0)) throw exception("Out of range");
				c_ = i;
			}
			f = !f;
		}
		catch (const exception& ex) {
			cout << ex.what() << endl;
			system("pause");
			exit(1);
		}
	}

	table& operator [] (int i)
	{
		try {
			if (f == 0) {
				if ((r_ > (r - 1)) || (r_ < 0 )) throw exception("Out of range");
				r_ = i;
			}
			else {
				if ((c_ > (c - 1)) || (c_ < 0)) throw exception("Out of range");
				c_ = i;
			}
			f = 1 - f;
		}
		catch (const std::exception& ex) {
			cout << ex.what() << endl;
			system("pause");
			exit(1);
		}
		return *this;
	}

};

int main()
{
	auto test = table<int>(2, 3);
	auto test2 = table<int>(2, 3);
	
	auto size = test.Size();
	test[1][2] = 4;
	test2 = test;
	test2[1][2] = 10;
	cout << test[1][2] << endl; // выводит 4

	cout << test2[1][2] << endl;

	system("pause");
}