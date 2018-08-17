#include "stdafx.h"
#include "Date.h"


Date::Date(uint y, uint m, uint d) :
	year(y), month(m), day(d)
{
	str[4] = str[7] = '-';
	str[10] = '\0';
	Normalize();
}

Date Date::operator+(uint d)const
{
	return Date(year, month, day + d);
}
bool Date::operator>(Date date) const
{
	return year > date.year
		|| (year == date.year&&month > date.month)
		|| (year == date.year&&month == date.month&&day > date.day);
}
const char* Date::ToString()const
{
	return str;
}
Date Date::Now()
{
	time_t timer;
	time(&timer);
	return Date(1970, 1, 1) + uint(timer / 86400);
}
//��ȡĳһ�·ݵ�����
//year:���
//month:�·�
uint Date::DaysOfMonth(uint year, uint month)
{
	if (2 == month)                             //����Ƕ��·�
	{                                           //���귵��29
		return IsLeapYear(year) ? 29 : 28;      //ƽ�귵��28
	}
	switch (month)
	{
	case 4:case 6:case 9:case 11:               //�����·����Ƿ�Ϊ�����޹�
		return 30;                              //4��6��9��11�·���30
	default:                                    //�����·ݷ���31
		return 31;
	}
}

void Date::Normalize()
{
	while (day > DaysOfMonth(year, month))
	{
		day -= DaysOfMonth(year, month);
		month++;
		if (month > 12)
		{
			year += month / 12;
			month %= 12;
		}
	}
	uint t;
	t = year;
	str[3] = '0' + t % 10;
	t /= 10;
	str[2] = '0' + t % 10;
	t /= 10;
	str[1] = '0' + t % 10;
	t /= 10;
	str[0] = '0' + t;
	t = month;
	str[6] = '0' + t % 10;
	t /= 10;
	str[5] = '0' + t;
	t = day;
	str[9] = '0' + t % 10;
	t /= 10;
	str[8] = '0' + t;
}
