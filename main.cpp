#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;


class Matrix
{
private:
    int s, t;
    vector<vector<int> > mas;//инициализируем динамичсекий массив с помощью вектора
public:
    Matrix(): s(0), t(0) {}; // строка столбец
    Matrix(int _s, int _t) { // конструтор с параметрами
        s = _s;
        t = _t;
        mas.resize(s, vector<int>(t)); // передаем в матрицу количество строк и столбцов
    }
    int operator () (int a, int b) { // обращение к матрице - оператор круглые скобки(перегрузка)
        return mas[a][b];
    }
    int get_s() {  // функция, кот возвращает кол-во строк
        int res_s = this->s;
        return res_s;
    }
    int get_t() {   // возвращает кол-во столбцов
        int res_t = this->t;
        return res_t;
    }
    vector<vector<int> > get_mas() { // возвращает матрицу (вектор векторов )- аксцессоры приватных полей
        return mas;
    }
    void set_val(int i, int j, int a) { // передаем индекс строки и столбцов и занчение, которое надо вставить
        this->mas[i][j] = a;
    }
    Matrix operator + (Matrix b) {
        if(this->s != b.get_s() || this->t != b.get_t()) {
            cout << "Impossible" << endl;
            return Matrix(0,0);
        }
        Matrix c = Matrix(this->s, this->t); // создаем новую матрицу, которую мы вернем
        for(int i = 0; i < this->s; ++i) {
            for(int j = 0; j < this->t; ++j) {
                c.set_val(i, j,this->mas[i][j] + b.get_mas()[i][j]);
            }
        }
        return c;
    }
    
    Matrix operator - (Matrix b) {
        if(this->s != b.get_s() || this->t != b.get_t()) {
            cout << "Impossible" << endl;
            return Matrix(0,0);
        }
        Matrix c = Matrix(this->s, this->t); // создаем новую матрицу, которую мы вернем
        for(int i = 0; i < this->s; ++i) {
            for(int j = 0; j < this->t; ++j) {
                c.set_val(i, j,this->mas[i][j] - b.get_mas()[i][j]);
            }
        }
        return c;
    }
    Matrix operator * (Matrix b) {
        if (this->t != b.get_s() || this->s != b.get_t()){
            cout << "Impossible" << endl;
            return Matrix(0, 0);
        }
        Matrix c = Matrix(this->s, this->t);
        for (int i = 0; i < this->s; ++i) {
            for (int j = 0; j < this->t; ++j) {
                int sum = 0;
                for (int k = 0; k < this-> s; ++k) {
                    sum += this->mas[i][k] * b.get_mas()[k][j];
                }
                c.set_val(i, j, sum);
            }
            
        }
        return c;
    }
    
    Matrix operator *(int a)
    {
        Matrix c = Matrix(this->s, this->t);
        c.s = s;
        c.t = t;
        c.mas = mas;
        for (int i = 0; i <c.s; ++i)
            for (int j = 0; j < c.t; ++j)
                c.mas[i][j] *= a;
        
        return c;
    }
    
    Matrix operator / (float a)
    {
        Matrix c = Matrix (this->s, this->t);
        c.s = s;
        c.t = t;
        c.mas = mas;
        if (a == 0)
        {
            cout << "Impossible! Incorrect number!" << endl;
            return c;
        }
        for (int i = 0; i <c.s; ++i)
            for (int j = 0; j < c.t; ++j)
                c.mas[i][j] /= a;
        return c;
    }
    
    friend ostream &operator << (ostream& os, Matrix &a) { // вывод матрицы
        for(int i = 0; i < a.get_s(); ++i) {
            for(int j = 0; j < a.get_t(); ++j) {
                os << a.get_mas()[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
    Matrix operator = (Matrix m)
    {
        s = m.s;
        t = m.t;
        mas = m.mas;
        //        for (int i = 0; i < s;++i)
        //            for (int j = 0; j < t; ++j)
        //                mas[i][j] = m.mas[i][j];
        return *this;
    }
    
    int operator [] (const Matrix &m)
    {
        auto sum = 0;
        int th;
        s = m.s;
        t = m.t;
        mas = m.mas;
        for (int i = 0; i < this->s; i++)
            for (int j = 0; j < this->t; j++)
            {
                mas[i][j] = th;
                sum += th;
            }
        return sum;
    }
    
    Matrix (const Matrix &m) // конструктор копирования
    {
        s = m.s;
        t = m.t;
        mas = m.mas;
    }
    
    
    ~Matrix () {
        mas.clear();
    };
    
};

int main()
{
    Matrix a;
    a(1,2);
    cout << a << endl;
    return 0;
    
    
    
    
    
    
    
    
    
    
    
}
