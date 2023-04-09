#include <iostream>
using namespace std;

class trapezoid
{
public:
	void set_sides();
	double get_side_a() { return a; };
	double get_side_b() { return b; };
	double get_side_c() { return c; };
	double get_side_d() { return d; };
	void increase(int k);
	void decrease(int k);
	double middle_line();
	double height();
	double perimeter();
	double area();
	void similarity(trapezoid* arr, int index);

private:
	double a, b, c, d;
};

void trapezoid::set_sides()
{
	cout << "Введите размеры сторон a, b и c трапеции: " << "\na: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	d = sqrt(pow(c, 2) + pow((a - b), 2));
	cout << endl;
}

void trapezoid::increase(int k)
{
	a *= k; b *= k; c *= k; d *= k;
}

void trapezoid::decrease(int k)
{
	a /= k; b /= k; c /= k; d /= k;
}

double trapezoid::middle_line()
{
	return (a + b) / 2;
}

double trapezoid::height()
{
	return sqrt(pow(c, 2) - (pow((((pow(c, 2) - pow(d, 2)) / (b - a)) + b - a), 2)) / 4);
}

double trapezoid::perimeter()
{
	return a + b + c + d;
}

double trapezoid::area()
{
	return middle_line() * height();
}

void trapezoid::similarity(trapezoid* arr, int index)
{
	if (get_side_a() / arr[index].get_side_a() == trunc(get_side_a() / arr[index].get_side_a()) and
		get_side_b() / arr[index].get_side_b() == trunc(get_side_b() / arr[index].get_side_b()) and
		get_side_c() / arr[index].get_side_c() == trunc(get_side_c() / arr[index].get_side_c()) and
		get_side_d() / arr[index].get_side_d() == trunc(get_side_d() / arr[index].get_side_d()))
		cout << "\nТрапеции подобны!\n\n";
	else
		cout << "\nТрапеции НЕ подобны!\n\n";
}

int main()
{
	system("chcp 1251");
	system("cls");
	
	trapezoid arr_trap[3] = {};

	for (int i = 0; i < 3; i++)
		arr_trap[i].set_sides();

	arr_trap[0].increase(2);
	arr_trap[1].decrease(2);

	for (int i = 0; i < 3; i++)
	{
		cout << "\nСтороны трапеции " << i + 1 << ":";
		cout << "\na = " << arr_trap[i].get_side_a();
		cout << "\tb = " << arr_trap[i].get_side_b();
		cout << "\tc = " << arr_trap[i].get_side_c();
		cout << "\td = " << arr_trap[i].get_side_d();
		cout << endl;
	}

	cout << endl << endl;

	cout << "Высота: " << arr_trap[2].height() << endl;
	cout << "Средняя линия: " << arr_trap[2].middle_line() << endl;
	cout << "Периметр: " << arr_trap[0].perimeter() << endl;
	cout << "Площадь: " << arr_trap[1].area() << endl;

	arr_trap[0].similarity(arr_trap, 1);

	system("pause");
	return 0;
}