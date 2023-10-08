#include <iostream>

using namespace std;

template <typename T>
class table
{
private:
    T** M; // матрица
    int r; // количество строк
    int c; // количество столбцов
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

    T& table operator=(int _r, int _c)
    {
        M[_r][_c] = 0;
    }

    const table& operator [] (int _r, int _c) const
    {
        return M[_r][_c];
    }

    table& operator [] (int i, int j)
    {
        return M[_r][_c];
    }

};

int main()
{
    auto test = table<int>(2, 3);

    auto size = test.Size();
    test[0][0] = 4;
    std::cout << test[0][0]; // выводит 4}

    system("pause");
}