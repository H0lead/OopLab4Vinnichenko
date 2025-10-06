#include "money.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

//Метод ініціалізації в коді
money money::init(long a, unsigned char b)
{
    money tmp;
    tmp.grn = a;
    tmp.coin = b;
    return tmp;
}

//Метод ініціалізації користувачем
void money::read()
{
    cout << "Grn: ";
    cin >> grn;
    cout << "Coin: ";
    int tmp;
    cin >> tmp;
    coin = tmp;
}

//Виведення змінних на екран
void money::display()
{
    if ((int)coin < 10)
    {
        cout << grn << ",0" << (int)coin << endl;
    }
    else
    {
        cout << grn << "," << (int)coin << endl;
    }
}

//Переведення змінних в string формат
string money::tostring()
{
    string tmp;
    if ((int)coin < 10)
    {
        tmp = to_string(grn) + ",0" + to_string(coin);
    }
    else
    {
        tmp = to_string(grn) + "," + to_string(coin);
    }
    return tmp;
}

//Додавання гривень та копійок до вже існуючих
money money::add(long a, unsigned char b)
{
    money tmp;
    tmp.grn = grn + a;
    tmp.coin = (int)coin + (int)b;
    return tmp;
}

//Віднімання гривень та копійок від вже існуючих
money money::sub(long a, unsigned char b)
{
    money tmp;
    tmp.grn = grn - a;
    if ((int)b > (int)coin)
    {
        tmp.grn -= 1;
        tmp.coin = 100 + (int)coin - (int)b;
    }
    else
    {
        tmp.coin = (int)coin - (int)b;
    }
    return tmp;
}

//Ділення суми на число
money money::divide(int a)
{
    money tmp;
    float b = (float)grn / (float)a;
    tmp.grn = (int)b;
    float fractionalPart = (b - (int)b) * 100;
    tmp.coin = (int)coin / a + (int)fractionalPart;
    return tmp;
}

//Ділення суми на число з комою
money money::dividefloat(float a)
{
    money tmp;
    float b = (float)grn / (float)a;
    tmp.grn = (int)b;
    //Знаходження залишка в копійках після ділення гривень
    float fractionalPart = (b - (int)b) * 100;
    tmp.coin = (int)coin / a + (int)fractionalPart;
    return tmp;
}

//Множення на число з комою
money money::multiplyfloat(float a)
{
    money tmp;
    float b = (float)grn * a;
    //В grn записується ціле число після множення
    tmp.grn = (int)b;
    //Знаходження залишка в копійках після множення гривень
    float fractionalPart = (b - (int)b) * 100;
    if ((int)coin * a + fractionalPart > 100)
    {
        float coins = ((int)coin * a + fractionalPart) / 100;
        tmp.grn += (int)coins;
        tmp.coin = (coins - (int)coins) * 100;
    }
    else
    {
        tmp.coin = (int)coin * a + fractionalPart;
    }
    return tmp;
}

//Порівняння суми з іншою
void money::compare(money a)
{
    if (grn == a.grn)
    {
        if ((int)coin > (int)a.coin)
        {
            cout << tostring() << " is more than " << a.tostring() << endl;
            return;
        }
        else if ((int)coin == (int)a.coin)
        {
            cout << tostring() << " is equal " << a.tostring() << endl;
            return;
        }
        else
        {
            cout << a.tostring() << " is more than " << tostring() << endl;
            return;
        }
    }
    if (grn > a.grn)
    {
        cout << tostring() << " is more than " << a.tostring() << endl;
    }
    else
    {
        cout << a.tostring() << " is more than " << tostring() << endl;
    }
}

//Конструктор за замовчуванням.
money::money()
{
    grn = 100;
    coin = 50;
}

//Конструктор з параметрами
money::money(long grn, unsigned char coin)
{
    this->grn = grn;
    this->coin = coin;
}

//Перенавантаження оператора +
money money::operator+(const money& other)
{
    money tmp;
    tmp.grn = grn + other.grn;
    if (coin + other.coin > 100)
    {
        tmp.grn += 1;
        tmp.coin = (coin + other.coin) - 100;
    }
    else
    {
        tmp.coin = coin + other.coin;
    }
    return tmp;
}

//Перенавантаження оператора -
money money::operator-(const money& other)
{
    money tmp;
    tmp.grn = grn - other.grn;
    if ((int)other.coin > (int)coin)
    {
        tmp.grn -= 1;
        tmp.coin = 100 + (int)coin - (int)other.coin;
    }
    else
    {
        tmp.coin = (int)coin - (int)other.coin;
    }
    return tmp;
}

//Перенавантаження оператора >
bool money::operator>(const money& other)
{
    if (grn > other.grn)
    {
        return true;
    }
    else if (grn == other.grn && coin > other.coin)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Перенавантаження оператора <
bool money::operator<(const money& other)
{
    if (grn < other.grn)
    {
        return true;
    }
    else if (grn == other.grn && coin < other.coin)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Перенавантаження оператора ==
bool money::operator==(const money& other)
{
    return (grn == other.grn && coin == other.coin);
}
