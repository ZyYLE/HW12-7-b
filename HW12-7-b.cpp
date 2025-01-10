// HW12-7-b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <string>
#include <iostream>

using namespace std;

void computeLPS(string pat, int* lps)
{
    int j = 0;

    lps[0] = 0; // lps[0] is always 0 

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool IsKPeriodic(unsigned k, string s)
{
    int len = s.length();
    int* lpsarr = new int[len];

    bool result = false;

    //Проверкм: (сначала низкобюджетные)
    
    // ненулевая входная  кратность
    if (k == 0) return false;

    // остаток от деления длины строки на К должен быть 0 
    if (!(len % k)) result = true; 

    // теперь затратная проверка:
    
    computeLPS(s, lpsarr);
  
    // сумма K и последнего LPS =длине строки
    if (!((k + lpsarr[len - 1]) == len)&&result)
    {
        result = false;
    }
    
  
    delete[] lpsarr;

    return result;
}

int main()
{
    

    string ms = "abababac";
    int len = ms.length();
    int* lpsarr=new int[len];

    cout <<"String: " << ms << endl;

    computeLPS(ms, lpsarr);  //дополнительно считается и выводится тоолько для наглядности. 
    
    cout << "String.lenght(): " << ms.length() << endl;
    cout << "LPS Array: " << endl;
    for (int i = 0; i < len; i++) cout << lpsarr[i] << " " ;
    cout << endl;


    for (int j = 1; j <= len;j++)
    {
        cout << "K:" << j << ": ";
        if (IsKPeriodic(j, ms))
        {
            cout << "TRUE" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }


    delete[] lpsarr;
}

