#include "money.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

//����� ����������� � ���
money money::init(long a, unsigned char b)
{
    money tmp;
    tmp.grn = a;
    tmp.coin = b;
    return tmp;
}

//����� ����������� ������������
void money::read()
{
    cout << "Grn: ";
    cin >> grn;
    cout << "Coin: ";
    int tmp;
    cin >> tmp;
    coin = tmp;
}

//��������� ������ �� �����
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

//����������� ������ � string ������
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

//��������� ������� �� ������ �� ��� ��������
money money::add(long a, unsigned char b)
{
    money tmp;
    tmp.grn = grn + a;
    tmp.coin = (int)coin + (int)b;
    return tmp;
}

//³������� ������� �� ������ �� ��� ��������
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

//ĳ����� ���� �� �����
money money::divide(int a)
{
    money tmp;
    float b = (float)grn / (float)a;
    tmp.grn = (int)b;
    float fractionalPart = (b - (int)b) * 100;
    tmp.coin = (int)coin / a + (int)fractionalPart;
    return tmp;
}

//ĳ����� ���� �� ����� � �����
money money::dividefloat(float a)
{
    money tmp;
    float b = (float)grn / (float)a;
    tmp.grn = (int)b;
    //����������� ������� � ������� ���� ������ �������
    float fractionalPart = (b - (int)b) * 100;
    tmp.coin = (int)coin / a + (int)fractionalPart;
    return tmp;
}

//�������� �� ����� � �����
money money::multiplyfloat(float a)
{
    money tmp;
    float b = (float)grn * a;
    //� grn ���������� ���� ����� ���� ��������
    tmp.grn = (int)b;
    //����������� ������� � ������� ���� �������� �������
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

//��������� ���� � �����
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

//����������� �� �������������.
money::money()
{
    grn = 100;
    coin = 50;
}

//����������� � �����������
money::money(long grn, unsigned char coin)
{
    this->grn = grn;
    this->coin = coin;
}

//���������������� ��������� +
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

//���������������� ��������� -
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

//���������������� ��������� >
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

//���������������� ��������� <
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

//���������������� ��������� ==
bool money::operator==(const money& other)
{
    return (grn == other.grn && coin == other.coin);
}
