#include <iostream>
#include <assert.h>
#include <cassert>


int dayInYear(int day, int month, int year);

int main() 
{
    int month, day, total;
    for (int year = 0; year <= 2022; year++)
    {
        month = 0;
        total = 0;
        if (year % 4 != 0)
        {
                while (total != 365)
                {
                    while (month != 12)
                    {
                        month++;
                        day = 0;
                        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                        {
                            while (day != 31)
                            {
                                day++;
                                total++;
                                assert(dayInYear(day, month, year) == total);
                            }
                        }
                        else if (month == 2)
                        {
                            while (day != 28)
                            {
                                day++;
                                total++;
                                assert(dayInYear(day, month, year) == total);
                            }
                        }
                        else
                        {
                            while (day != 30)
                            {
                                day++;
                                total++;
                                assert(dayInYear(day, month, year) == total);
                            }
                        }
                    }
                }
        }
        else
        {
            if ((year % 100 == 0 && year % 400 == 0) || year % 100 != 0)
            {
                while (total != 366)
                {
                    while (month != 12)
                    {
                        month++;
                        day = 0;
                        if (month == 1 || month ==3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                        {
                            while (day != 31)
                            {
                                day++;
                                total++;
                                assert(dayInYear(day, month, year) == total);
                            }
                        }
                        else if (month == 2)
                        {
                            while (day != 29)
                            {
                                day++;
                                total++;
                                assert(dayInYear(day, month, year) == total);
                            }
                        }
                        else
                        {
                            while (day != 30)
                            {
                                day++;
                                total++;
                                assert(dayInYear(day, month, year) == total);
                           }
                        } 
                    }
                }
            }
            else
            {
                while (total != 365)
                {
                    while (month != 12)
                    {
                        month++;
                        day = 0;
                        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                        {
                            while (day != 31)
                            {
                                day++;
                                total++;
                                assert(dayInYear(day, month, year) == total);
                            }
                        }
                        else if (month == 2)
                        {
                            while (day != 28)
                            {
                                day++;
                                total++;
                                assert(dayInYear(day, month, year) == total);
                            }
                        }
                        else
                        {
                            while (day != 30)
                            {
                                day++;
                                total++;
                                assert(dayInYear(day, month, year) == total);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}