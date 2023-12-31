﻿#include <iostream> 
#include <string> 
using namespace std;
class Coordinator//первый абстрактный класс 
{
	double Pay(int Y, int U, double W2, double W1, double Cost);
	double Know(int c, double price, string prod) {};
};
int h = 0;
int h1 = 0;
int k1 = 0;
class Buyer//покупатель 
{
public:
	string Name, Adress;
	int Phone = 0;
	string* mas = new string[100];
	string prod;
	Buyer() {}
	void Personal(string Name, int Phone, string Adress) //персональные данные клиента 
	{
		try {
			if (Phone < 0)
				throw "Номер телефона не может иметь нулевое значение";
			cout << "Информация о клиенте:" << endl;
			cout << "ФИО клиента: " << Name << endl;
			cout << "Номер телефона клиента: " << Phone << endl;
			cout << "Адрес клиента: " << Adress << endl;
		}
		catch (...)
		{
			cout << "Проверьте персональные данные клиента" << endl;
		}
	}
	void EnterList(int c)//список покупок 
	{
		try
		{
			if (c < 0)
				throw "Число товаров в списке должно иметь положительное значение";
			for (int i = 0; i < c; i++)
			{
				cout << "Введите наименование продукта: ";
				cin >> prod;
				mas[i] = prod;//записываем товары в массив 
				h = h + 1;
			}
			cout << "Количество товаров в списке равно: " << h << " штук" << endl;
		}
		catch (int c)
		{
			cout << "Измените значение: " << c << endl;
		}
	}
};
class Basket
{
public:
	int count = 0, p2 = 0, c = 0, p3 = 0;
	void AddBasket(string basket[100], int k, string prod)//добавить товар в корзину,k-начальная позиция, с которой будут добавляться товары в массиве,k1- конечная позиция, после которой массив больше не будет заполняться
	{
	k1 = k1 + 1;//конечный индекс товара в массиве корзины 
	try {
	if (k < 0)
	cout << "Начальное число товаров в корзине не может иметь отрицательное значение" << endl;
	for (int i = k; i < k1; i++)
	{
	basket[i] = prod;//добавляется товар в корзину 
	h1 = h1 + 1;
	}
	cout << "Количество товаров в корзине: " << h1 << " шт" << endl;
	}
	catch (...)
	{
	cout << "Измените введенные данные о числе товаров в корзине" << endl;
	}
	}
		void BackBasket(string basket[100], string prod, int pol)
	{
		try
		{
			count = 0;
			for (int a = 0; a < h1; a++)
			{
				if (basket[a] == prod)
					count = count + 1;//количество выбранного товара в корзине 
			}
			cout << "Количество имеющегося выбранного вами товара: " << prod << " равно " << count << " штук" << endl;
			if (pol < 0)
				throw "Число выкладываемых товаров не может быть отрицательным";
			if (count < pol)
				throw "Количество выбранного вами товара для удаления из корзины не соответствует его числу в корзине";
			for (int w = 0; w < pol; w++)
			{
				for (int i = 0; i < h1; i++)
				{
					if (basket[i] == prod)//если нашелся товар из корзины 
						for (int j = i; j < h1 - 1; ++j)
						{
							basket[j] = basket[j + 1];
						}
				}
			}
			h1 = h1 - pol;
			cout << "Количество товаров в корзине после выкладывания вами товаров равно: " << h1 << " штук" << endl;
			p2 = k1 - pol;
			if (p2 >= 0)
				k1 = k1 - pol;
			else if (p2 < 0)
				throw "Значение оставшихся в корзине товаров после изъятия товаров из корзины не должно иметь отрицательное или нулевое значение";
		}
		catch (...)
		{
			cout << "Проверьте введенные данные";
		}
	}
};
class WeightProduct :public Buyer, public Coordinator//товар(взвесить, посчитать сумму) 
{
public:
	string* basket = new string[50], prod, answer;
	double x = 0, p = 0, cost = 0, sum = 0, price = 0, pr = 0, cong = 0, k = 0, red = 0, rab = 0;//х-вес 1 штуки товара,p-общий вес товара в одном пакете,sumcon- итоговая сумма
		//Price-цена на овощи/фрукты,c-количество товаров в одном пакете(шт),U-число пакетов товара,Ans2-наименование взвешиваемого товара 
		int U = 0, Y = 0, c = 0, pol = 0;
	Basket r;
	WeightProduct(int u) { U = u; }
	double Know(int c, double price, string prod)//взвесить продукт 
	{
		try {
			if (c <= 0)
				throw "Количество товаров в пакете не может быть нулевым";
			if (price <= 0)
				throw "Цена товара не может иметь нулевое или отрицательное значение";
			if (U <= 0)
				throw "Количество пакетов товара категории фруктов/овощей не должно иметь нулевое или отрицательное значение";
			for (int i = 0; i < U; i++)//цикл, подсчитывающий стоимость всех фруктов/овощей во всех пакетах 
			{
				for (int j = 0; j < c; j++)//подсчитываем сумму за товар во всех пакетах 
				{
					x = rand() % 400 + 50;
					x = x / 1000;//вес одного фрукта/овоща 
					cost = price * x;//стоимость одного фрукта 
					cout << "Стоимость одного фрукта/овоща: " << cost << " руб" << endl;
					sum = sum + cost;//стоимость всех фруктов/овощей в одном пакете 
				}
				cout << "Стоимость продукта категории фрукта/овощей в пакете под номером: " << i + 1 << " равна " << sum << " руб" << endl;
				cong = cong + sum;//стоимость товара во всех пакетах 
				r.AddBasket(basket, h1, prod);
				cout << "Хотите ли вы выложить товар: " << prod << " из корзины?: "; cin >> answer;
				if (answer == "yes")
				{
					cout << "Какое количество данного товара вы бы хотели выложить?: "; cin >> pol;
					for (int q = 0; q < pol; q++)
					{
						cout << "Введите значение суммы товара для взвешивания,который вы бы хотели выложить: "; cin >> red;
						cong = cong - red + 1;
						cout << "Стоимость товара: " << prod << " во всех пакетах теперь равна: " << cong << " руб" << endl;
					}
					r.BackBasket(basket, prod, pol);
				}
				else if (answer == "no")
					cout << "Количество товаров в вашей корзине без их выкладывания равно: " << h1 << " штук" << endl;
				sum = 0;
			}
		}
		catch (...)
		{
			cout << "Проверьте введенные данные" << endl;
		}
		return cong;
	}
	double Counting(int Y)//Y-количество таких товаров 
	{
		try
		{
			if (Y <= 0)
				throw "Количество товаров категории фрукты/овощи не должно иметь отрицательное или нулевое значение";
			for (int j = 0; j < Y; j++)
			{
				cout << "Какой товар вы бы хотели приобрести? " << " "; cin >> prod;
				cout << "Какова цена у вашего продукта? " << " "; cin >> price;
				cout << "Сколько штук товара вам нужно? " << " "; cin >> c;
				cong = 0; pr = Know(c, price, prod);
				cout << "Стоимость взвешиваемого товара во всех пакетах: " << prod << " равна " << pr << " руб" << endl;
				p = p + pr;
			}
			cout << "Стоимость взвешанных товаров равна: " << p << " руб" << endl;
		}
		catch (int Y)
		{
			cout << "Измените значение: " << Y << endl;
		}
		return p;
	}
};
class CountProduct :public WeightProduct//добавить товар в корзину, выложить товар из корзины 
{
public:
	double cost = 0, p = 0, sum = 0, prom = 0;
	int pol = 0;
	//конструктор 
	CountProduct(int u) :WeightProduct(u) { }
	//один товар 
	double Know(int c, double price, string prod) //c-количество товаров 
	{
		try
		{
			//протестировать 
			if (price <= 0)
				throw "Введенная цена товара отрицательна или имеет нулевое значение";
			if (c <= 0)
				throw "Количество не взвешиваемых товаров одной категории должно иметь нулевое или отрицательное значение";
			for (int j = 0; j < c; j++)
			{
				cost = cost + price;//считаем все не взвешаемые товары 
				r.AddBasket(basket, h1, prod);
				cout << "Стоимость товара: " << prod << " равна " << cost << " руб" << endl;
				cout << "Хотите ли вы выложить товар: " << prod << " из корзины?: "; cin >> answer;
				if (answer == "yes")
				{
					cout << "Какое количество данного товара вы бы хотели выложить?: "; cin >> pol;
					r.BackBasket(basket, prod, pol);
					if (pol > j + 1)
						throw "Выбранное вами количество выкладываемых товаров превышает число товара в корзине";
					else if (pol <= j + 1)
					{
						prom = price * pol;
						cost = cost - prom;
					}
				}
				else if (answer == "no")
					cout << "Количество товаров в вашей корзине без их выкладывания равно: " << h1 << " штук" << endl;
			}
		}
		catch (...)
		{
			cout << "Проверьте введенные данные" << endl;
		}
		return cost;
	}
	double Counting1(int Y)//Y-количество таких товаров 
	{
		try {
			if (Y <= 0)
				throw "Количество не взвешиваемых товаров разной категории не может иметь отрицательное или нулевое значение";
			for (int j = 0; j < Y; j++)
			{
				cout << "Какой товар вы бы хотели приобрести? "; cin >> prod;
				cout << "Какова цена у вашего продукта? "; cin >> price;
				cout << "Сколько штук товара вам нужно? "; cin >> c;
				pr = Know(c, price, prod);
				cout << "Стоимость товара, не подлежащего взвешиванию: " << prod << " составляет: " << pr << " руб" << endl;
				p = p + pr;
				cost = 0;
			}
			cout << "Стоимость взвешанных товаров равна: " << p << " руб" << endl;
		}
		catch (int Y)
		{
			cout << "Измените значение: " << Y << endl;
		}
		return p;
	}
};
class Cash :public Coordinator//наличный расчет 
{
public:
	double Sum = 0, remains = 0, W1 = 0, W2 = 0, P = 0, Cost = 0;//P-счетчик для взвешивания товаров 
	int Y = 0, U = 0;//Y-кол-во товаров для взвешивания, U-кол-во товаров без взвешивания 
	Cash(double sum) { Sum = sum; }
	//cost-общая стоимость,sum-сумма наличных в рублях, 
	double Pay(int Y, int U, double W2, double W1, double Cost)
	{
		try {
			int J = Y + U;
			if (Cost <= 0)
				throw "Итоговая стоимость товаров не может иметь отрицательное или нулевое значение";
			if (Y < 0)
				throw "Количество товаров для взвешивания не может иметь отрицательное значение";
			if (U < 0)
				throw "Количество не взвешиваемых товаров не может иметь отрицательное значение";
			if (Sum <= 0)
				throw "Сумма наличных средств не может иметь отрицательное или нулевое значение";
			if (W2 < 0)
				throw "Стоимость взвешиваемых товаров не может иметь нулевое значение";
			if (W1 < 0)
				throw "Стоимость не взвешиваемых товаров не может иметь нулевое значение";
			if (Sum > Cost)//денег достаточно 
			{
				cout << "Ваших средств хватает для оплаты покупки" << endl;
				remains = Sum - Cost;//сдача 
			}
			else if (Sum < Cost)//наличных не хватает 
			{
				cout << "Ваших средств не хватает для оплаты покупки.Выкладывайте товар до тех пор, пока ваших средств хватит для оплаты покупки.";
				if (W2 > 0)//проверка на взвешивание 
				{
					cout << "Товары категории овощи/фрукты взвешаны" << endl;
					Cost = Cost - W2;//вычитаются цены на овощи/фрукты 
					cout << "Стоимость товаров стала равна: " << Cost << " руб" << endl;
				}
				else if (W2 <= 0)//товар не взвешан 
					cout << "Извините, вы не взвешали товары с категорией овощи/фрукты.Выложите их" << endl;
				while (Cost <= Sum)//пока стоимость не станет меньше наличных 
				{
					for (int h = 0; h < J; h++)
					{
						cout << "Введите цену за первый взвешиваемый товар"; cin >> W1; cout << endl;
						Cost = Cost - W1;//минус первый товпр для взвешивания 
						P = P + W1;
						cout << "Стоимость товаров стала равной: " << Cost << " руб" << endl;
					}
				}
				remains = Sum - Cost;
			}
		}
		catch (...)
		{
			cout << "Проверьте введенные данные" << endl;
		}
		return remains;//остаток наличных 
	}
};
class Bonuscard :public Coordinator//безналичный 
{
public:
	double Sum = 0, remains = 0, W1 = 0, W2 = 0, P = 0, remains_bonus = 0, bonus1 = 0, Cost = 0;//P-счетчик для взвешивания товаров 
	int Y = 0, U = 0, bonus = 0, sum_bonus = 0;//Y-кол-во товаров для взвешивания, U-кол-во товаров без взвешивания 
	Bonuscard() { }
	double Pay(int Y, int U, double W2, double W1, double Cost) //оплата безналичным способом, j-количество оощей/фруктов, price1-цена за овощи/фрукты 
	{
		try
		{
			if (Y < 0)
				throw "Количество товаров для взвешивания не может иметь отрицательное значение";
			if (U < 0)
				throw "Количество товаров без взвешивания не может иметь отрицательное значение";
			if (W2 < 0)
				throw "Стоимость взвешанных товаров не может иметь отрицательное значение";
			if (Cost <= 0)
				throw "Итоговая стоимость товаров не может иметь отрицательное или нулевое значение";
			if (W1 < 0)
				throw "Стоимость не взвешиваемых товаров не может иметь нулевое значение";
			int J = Y + U;
			bonus = rand() % 2000 + 1;//количество бонусов на карте 
			sum_bonus = bonus * 10;//сумма средств наличными 
			cout << "Сумма бонусов на вашей карте равно: " << bonus << endl; cout << "Сумма(в рублях) на вашей бонусной карте: " << sum_bonus << endl;
			if (Cost <= 0)
				throw "Итоговая стоимость товаров не может иметь нулевое значение или быть отрицательной";
			if (sum_bonus > Cost)//средств хватает для оплаты 
			{
				cout << "Ваших средств хватает для оплаты покупки" << endl;
				remains_bonus = sum_bonus - Cost;//остаток бонусов в рублях 
				cout << "Сдача(в рублях) составляет: " << remains_bonus << " руб" << endl;
				if (Cost > 555)
					bonus1 = remains_bonus / 10 + Cost / 20;//бонусы, начисляемые за покупку 
				else if (Cost < 555)
					bonus1 = remains_bonus / 10 + Cost / 10;
			}
			else if (sum_bonus < Cost)//средств недостаточно 
			{
				cout << "Ваших средств не хватает для оплаты покупки.Выкладывайте товар до тех пор, пока ваших средств хватит для оплаты покупки.";
				if (W2 > 0)//проверка на взвешивание 
				{
					cout << "Товары категории овощи/фрукты взвешаны" << endl;
					Cost = Cost - W2;//вычитаются цены на овощи/фрукты 
					cout << "Стоимость товаров стала равна: " << Cost << "руб" << endl;
				}
				else if (W2 <= 0)//товар не взвешан 
					cout << "Извините, вы не взвешали товары с категорией овощи/фрукты.Выложите их" << endl;
				while (Cost <= Sum)//пока стоимость не станет меньше наличных 
				{
					for (int h = 0; h < J; h++)
					{
						cout << "Введите цену за первый взвешиваемый товар"; cin >> W1; cout << endl;
						Cost = Cost - W1;//минус первый товпр для взвешивания 
						P = P + W1;
						cout << "Стоимость товаров стала равной: " << Cost << "руб" << endl;
					}
				}
				remains_bonus = sum_bonus - Cost;//остаток бонусов в рублях 
				cout << "Сдача(в рублях) равна: " << remains_bonus << " руб" << endl;
				if (Cost > 555)
					bonus1 = remains_bonus / 10 + Cost / 20;//бонусы, начисляемые за покупку 
				else if (Cost < 555)
					bonus1 = remains_bonus / 10 + Cost / 10;
			}
		}
		catch (...)
		{
			cout << "Проверьте введенные данные" << endl;
		}
		return bonus1;//остаток бонусов на карте 
	}
};
class Mixed :public Coordinator//смешанный 
{
public:
	double Sum = 0, remains = 0, W1 = 0, W2 = 0, N2 = 0, P = 0, remains_bonus = 0, bonus1 = 0;//P-счетчик для взвешивания товаров 
	int Y = 0, U = 0;//Y-кол-во товаров для взвешивания, U-кол-во товаров без взвешивания 
	double Cost = 0, cash = 0, remains_cost = 0; Mixed(double sum) { Sum = sum; }
	int J = Y + U;
	int bonus = 0, sum_bonus = 0;
	//Cost-сумма общей стоимости, Sum-наличные 
	double Pay(int Y, int U, double W2, double W1, double Cost)
	{
		try {
			if (Y < 0)
				throw "Количество товаров для взвешивания не может иметь отрицательное значение";
			if (U < 0)
				throw "Количество товаров без взвешивания не может иметь отрицательное значение";
			if (W2 < 0)
				throw "Стоимость взвешанных товаров не может иметь отрицательное значение";
			if (Cost <= 0)
				throw "Итоговая стоимость товаров не может иметь отрицательное или нулевое значение";
			if (W1 < 0)
				throw "Стоимость не взвешиваемых товаров не может иметь нулевое значение";
			if (Sum <= 0)
				throw "Сумма наличных средств не может иметь отрицательное или нулевое значение";
			bonus = rand() % 2000 + 0;//количество бонусов на карте 
			cout << "Количество бонусов на вашей карте до оплаты покупки: " << bonus << endl;
			sum_bonus = bonus * 10;//сумма средств наличными 
			cout << "Количество бонусов(в рублях) на вашей карте до оплаты покупки: " << sum_bonus << endl;
			cash = Sum + sum_bonus;
			cout << "Сумма доступных вам денежных средств(наличные и сумма бонусов(в рублях)) до оплаты покупки: " << cash << endl;
			if (cash > Cost)//средств достаточно 
			{
				cout << "Ваших средств хватает для оплаты покупки" << endl;
				remains_cost = cash - Cost;//сдача после оплаты наличным и безналичным способами 
				if (Cost > 555)
					bonus1 = Cost / 20;//бонусы, начисляемые за покупку 
				else if (Cost < 555)
					bonus1 = Cost / 10;
				cout << "Количество бонусов на вашей карте(после оплаты покупки равно: " << bonus1 << endl;
			}
			else if (cash < Cost)//средств не хватает 
			{
				cout << "Ваших средств не хватает для оплаты покупки.Выкладывайте товар до тех пор, пока ваших средств хватит для оплаты покупки.";
				if (W2 > 0)//проверка на взвешивание 
				{
					cout << "Товары категории овощи/фрукты взвешаны" << endl;
					Cost = Cost - W2;//вычитаются цены на овощи/фрукты 
					cout << "Стоимость товаров стала равна: " << Cost << "руб" << endl;
				}
				else if (W2 <= 0)//товар не взвешан 
					cout << "Извините, вы не взвешали товары с категорией овощи/фрукты.Выложите их" << endl;
				while (Cost <= Sum)//пока стоимость не станет меньше наличных 
				{
					for (int h = 0; h < J; h++)
					{
						cout << "Введите цену за первый взвешиваемый товар"; cin >> W1; cout << endl;
						Cost = Cost - W1;//минус первый товпр для взвешивания 
						P = P + W1;
						cout << "Стоимость товаров стала равной: " << Cost << "руб" << endl;
					}
				}
				remains_cost = cash - Cost;//сдача после оплаты наличным и безналичным способами 
				if (Cost > 555)
					bonus1 = Cost / 20;//бонусы, начисляемые за покупку 
				else if (Cost < 555)
					bonus1 = Cost / 10;
				cout << "Количество зачисленных бонусов после оплаты покупки равно" << bonus1 << endl;
			}
		}
		catch (...)
		{
			cout << "Проверьте введенные данные" << endl;
		}
		return remains_cost;//остаток наличных 
	}
};
class Cassa :public CountProduct
{
public:
	string Name, ans3;
	int number = rand() % 20 + 1;
	int K = 0;
	double l2 = 0;
	Cassa(int u) :CountProduct(u) { }
	//W2-взвешанные товары, W1-не взвешанные товары 
	void Check(double Cost, double W2, double W1, int Y, int U, int K, double Sum, string Name)//проверка 
	{
		try {
			//проверить совпадает ли список товаров с корзиной 
			if (h == h1)//если товары из корзины совпадают с товарами из списка 
			{
				cout << "Товары из списка и товары в корзине совпадают" << endl;
			}
			else if (h != h1)
			{
				cout << "Товары из списка и товары в корзине не совпадают" << endl;
			}
			if ((h == 0) || (h1 == 0))
				cout << "Извините, вы не выбрали ни одного товара.Пожалуйста, выберите товар или покиньте магазин";
			if (h > 0 && h1 > 0)
			{
				cout << "Клиент подошел к кассе под номером: " << number << endl;
				cout << "Фамилия, Имя и Отчество кассира: " << Name << endl;
				//mixed-смешанно,cash-наличными,bonuscard-бонусная карта 
				cout << "Итоговая стоимость составляет: " << Cost << " руб" << endl;
				cout << "Каким способом вы бы хотели оплатить покупку(bonuscard, cash,mixed)?"; cin >> ans3;
				if (ans3 == "bonuscard")
				{
					Bonuscard f;
					l2 = f.Pay(Y, U, W2, W1, Cost);
					cout << "Количество зачисленных бонусов после оплаты покупки стало равным: " << l2 << " руб" << endl;
				}
				else if (ans3 == "cash")
				{
					Cash g(Sum); l2 = g.Pay(Y, U, W2, W1, Cost);
					cout << "Сдача после оплаты наличным способом составляет: " << l2 << " руб" << endl;
				}
				else if (ans3 == "mixed")
				{
					Mixed s(Sum);
					l2 = s.Pay(Y, U, W2, W1, Cost);
					cout << "Сдача после оплаты покупки смешанным способом составляет: " << l2 << " руб" << endl;
				}
			}
			if ((h < 0) || (h1 < 0))
				throw "Ошибка подсчета товаров в корзине";
		}
		catch (int h)
		{
			cout << "Измените количество: " << h << "товаров" << endl;
		}
		delete[] mas;
		delete[] basket;
	}
};
int main()
{
	//сначала попробовать функции со взвешиванием и т.д. прописывать в классе касса, а потом функции прописывать в main 
	setlocale(LC_ALL, "ru");
	string ans1, ans2, ans3, ans4, ans5, q, ans6, prod;
	int u = 0, l1 = 0, l2 = 0, y = 0, y1 = 0, y2 = 0;
	double sum = 0, sum1 = 0, Cost = 0, s = 0;
	Buyer d;
	d.Personal("Григоренко Павел Викторович", 8951 - 4674 - 45 - 56, "ул.Купеческая,78");
	cout << "Сколько товаров вы бы хотели приобрести(для составления списка)?: "; cin >> l1;
	d.EnterList(l1);//список товаров 
	cout << "Имеются ли в вашем списке товары, которые нужно взвесить?: "; cin >> ans1;
	if (ans1 == "yes")//в списке есть товары для взвешивания 
	{
		cout << "Сколько пакетов товара категории фрукты/овощи вы бы хотели взять?: "; cin >> u;
		cout << "Какое количество товаров категории фрукты/овощи вы бы хотели взять? "; cin >> y;
		WeightProduct p(u);
		sum = p.Counting(y);
		cout << "Есть ли в вашем списке не взвешиваемые товары?: "; cin >> ans2;
		if (ans2 == "yes")//в списке нет товаров для взвешивания 
		{
			cout << "Какое количество не взвешиваемых товаров вы бы хотели взять? "; cin >> y1;
			CountProduct c(u);
			sum1 = c.Counting1(y1);
		}
		else if (ans2 == "no")
		{
			cout << "В вашем списке отсутствуют не взвешанные товары";
		}
		cout << "Теперь, вы можете пройти на кассу" << endl;
		Cassa k(u);
		Cost = sum + sum1;
		cout << "Сумма наличных средств: "; cin >> s;
		k.Check(Cost, sum, sum1, y, u, l1, s, "Цветкова Алла Федоровна");
	}
	else if (ans1 == "no")//в списке нет товаров для взвешивания 
	{
		cout << "Есть ли в вашем списке не взвешиваемые товары?: "; cin >> ans2;
		if (ans2 == "yes")//в списке нет товаров для взвешивания 
		{
			cout << "Какое количество не взвешиваемых товаров вы бы хотели взять? "; cin >> y2;
			CountProduct c(u);
			sum1 = c.Counting1(y2);
		}
		else if (ans2 == "no")
		{
			cout << "В вашем списке отсутствуют не взвешанные товары";
		}
		cout << "Теперь, вы можете пройти на кассу" << endl;
		Cassa k(u);
		Cost = sum1;
		cout << "Сумма наличных средств: "; cin >> s;
		k.Check(Cost, sum, sum1, y, u, l1, s, "Цветкова Алла федоровна");
	}
	system("pause");
	return 0;
}