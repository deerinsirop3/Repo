#include <fstream>
#include <cmath>
#include <iostream>
const long double e = 0.0012244;
const long double Pi = 3.14159265358;
const double eps = 0.00001;
double excentricToTrue(double E)
{
	return atan(sqrt((1 + e) / (1 - e)) * tan(E / 2)) * 2;//уравнение Кеплера для эллиптической орбиты
}
/**Часть 1. Метод итераций(метод неподвижной точки или метод последовательных
	приближений)
	Главная идея : заменить уравнение 𝑓(𝐸) = 0 на 𝐸 = 𝜑(𝐸).
	В итоге : 𝐸(𝑘 + 1) = 𝑒𝑠𝑖𝑛(𝐸(𝑘)) + 𝑀,
	Нулевая итерация : 𝐸(0) = 𝑀,
	Точность вычисления : | 𝐸(𝑘 + 1)− 𝐸(𝑘) | < 𝜀
	/**/
double iterationMethod(double Enext, double Enow, double M)
{

	if (fabs(Enow - Enext) < eps)//проверка точности вычислений
	{
		std::cout << Enext << std::endl;
		return Enext;//запись в файл
	}
	else
	{
		return iterationMethod(e * sin(Enext) + M, Enext, M);
	}
}
/**Часть 2. Метод половинного деления
Главная идея: выбрать произвольный отрезок и делить его пополам: 𝑐 =
𝑏+𝑎
2
В итоге: 𝑓(𝐸(𝑘)) = 𝐸(𝑘)− 𝑒𝑠𝑖𝑛(𝐸(𝑘)) − 𝑀 = 0,
Нулевая итерация: любое 𝑎 = 𝐸𝑎 < 0, любое 𝑏 = 𝐸𝑏 > 0 после проверки 𝑓(𝑎)𝑓(𝑏) < 0
Точность вычисления: |𝑏 − 𝑎| < 2𝜀 || |𝑓(𝑐(𝑘))| < 𝜀
/**/
double PolovinaMethod(double a, double b, double M)

{
	if (fabs(b - a) < 2 * eps || fabs(((a + b) / 2) - e * sin((a + b) / 2) - M) < eps)
	{
		return b + a / 2;
	}
	else if ((a - e * sin(a) - M) * (((a + b) / 2) - e * sin((a + b) / 2) - M) < 0)
	{
		return PolovinaMethod(a, (a + b) / 2, M);
	}
	else
	{
		return PolovinaMethod((a + b) / 2, b, M);
	}
}
/**Часть 3. Метод золотого сечения
Главная идея: выбрать произвольный отрезок и делить его в соотношении золотого
сечения: 𝑐 = 𝑎 + 𝑏−𝑎
𝜒 , где 𝜒 =
√5+1
2
В итоге: 𝑓(𝐸(𝑘)) = 𝐸(𝑘)− 𝑒𝑠𝑖𝑛(𝐸(𝑘)) − 𝑀 = 0,
Нулевая итерация: любое 𝑎 = 𝐸𝑎 < 0, любое 𝑏 = 𝐸𝑏 > 0 после проверки 𝑓(𝑎)𝑓(𝑏) < 0
Точность вычисления: |𝑏 − 𝑎| < 2𝜀 || |𝑓(𝑐(𝑘))| < 𝜀
/**/
double goldenMethod(double a, double b, double X, double M)
{
	if (fabs(b - a) < 2 * eps || fabs(((a + b) / 2) - e * sin((a + b) / 2) - M) < eps)
	{
		return a + (b - a) / X;
	}
	else if ((a - e * sin(a) - M) * (((a + b) / 2) - e * sin((a + b) / 2) - M) < 0)
	{
		return goldenMethod(a, a + (b - a) / X, X, M);
	}
	else
	{
		return goldenMethod(a + (b - a) / X, b, X, M);
	}
}
/**Часть 4. Метод Ньютона (или метод касательных)
Главная идея: находить 𝐸(𝑘+1) с помощью производной 𝑓′(𝐸(𝑘)), то есть:
𝐸(𝑘+1) = 𝐸(𝑘)−𝑓(𝐸(𝑘))/𝑓′(𝐸(𝑘))
В итоге: 𝑓(𝐸(𝑘)) = 𝐸(𝑘)− 𝑒𝑠𝑖𝑛(𝐸(𝑘)) − 𝑀 = 0,
Нулевая итерация: любая точка оси абсцисс, так как корень у уравнения Кеплера –
единственный.
Точность вычисления: |𝐸(𝑘+1)− 𝐸(𝑘)| < 𝜀
/**/
double NutoneMethod(double dif, double E, double M)
{
	if (dif < eps)
	{
		return E - dif;
	}
	else
	{
		return NutoneMethod((E - e * sin(E) - M) / ((eps - e * sin(E + eps) - e * sin(E)) / eps), E - (E - e * sin(E) - M) / ((eps - e * sin(E + eps) - e * sin(E)) / eps), M);
	}
}

int main()
{
	std::ofstream fout;
	std::ifstream fin;
	fout.open("iterationMethod.txt");
	if (fout.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			double E1 = e * sin(i * 2 * Pi / 360) + (i * 2 * Pi / 360);
			double E0 = i * 2 * Pi / 360;
			fout << iterationMethod(E1, E0, i * 2 * Pi / 360) << std::endl;
		}
	}

	fout.close();
	fin.open("iterationMethod.txt");
	fout.open("trueIterationMethod.txt");
	if (fin.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			char ch[50];
			fin.getline(ch, 50);
			std::string str = ch;
			char* ptrEnd;
			fout << excentricToTrue(strtod(ch, &ptrEnd)) << std::endl;
		}
	}
	fin.close();
	fout.close();

	fout.open("PolovinaMethod.txt");
	if (fout.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			fout << PolovinaMethod((i - 10) * 2 * Pi / 360, (i + 10) * 2 * Pi / 360, i * 2 * Pi / 360) << std::endl;
		}
	}
	fout.close();
	fin.open("PolovinaMethod.txt");
	fout.open("truePolovinaMethod.txt");
	if (fin.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			char ch[50];
			fin.getline(ch, 50);
			std::string str = ch;
			char* ptrEnd;
			fout << excentricToTrue(strtod(ch, &ptrEnd)) << std::endl;
		}
	}
	fin.close();
	fout.close();

	fout.open("goldenMethod.txt");
	if (fout.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			fout << goldenMethod((i - 10) * 2 * Pi / 360, (i + 10) * 2 * Pi / 360, (pow(5, 0.5) + 1) / 2, i * 2 * Pi / 360) << std::endl;
		}
	}
	fout.close();
	fin.open("goldenMethod.txt");
	fout.open("goldenMethod.txt");
	if (fin.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			char ch[50];
			fin.getline(ch, 50);
			std::string str = ch;
			char* ptrEnd;
			fout << excentricToTrue(strtod(ch, &ptrEnd)) << std::endl;
		}
	}

	fin.close();
	fout.close();

	fout.open("NutoneMethod.txt");
	if (fout.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			fout << NutoneMethod(((i + 20) * 2 * Pi / 360 - e * sin((i + 20) * 2 * Pi / 360) - i * 2 * Pi / 360) / ((eps - e * sin((i + 20) * 2 * Pi / 360 + eps) - e * sin((i + 20) * 2 * Pi / 360)) / eps), (i + 20) * 2 * Pi / 360, i * 2 * Pi / 360) << std::endl;
		}
	}
	fout.close();
	fin.open("NutoneMethod.txt");
	fout.open("trueNutoneMethod.txt");
	if (fin.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			char ch[50];
			fin.getline(ch, 50);
			std::string str = ch;
			char* ptrEnd;
			fout << excentricToTrue(strtod(ch, &ptrEnd)) << std::endl;
		}
	}
	fin.close();
	fout.close();



	return 0;
}