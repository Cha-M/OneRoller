#include <iostream>
#include <istream>
#include <algorithm>
#include <iterator>
#include <time.h>
using std::cout;
using std::endl;
using std::cin;

int STREAM_LIMIT = std::numeric_limits<std::streamsize>::max();

int rand10()
{
    return rand() % 10 + 1;
}

int results[10];

unsigned int pool = 10;

void recSetResults(int n = 0)
{
    if (n > pool)
    {
        return;
    }

    results[n] = rand10();
    n++;
    recSetResults(n);
}

void poolSort()
{
    //sorts the range in use
    std::sort(&results[0], &results[pool-1]);
}


int pairetc(int i, int n = 0, int j = 0, int k = 0)
{
    //n is used for the index
    //i for the value
    //j for the counter
    //k for the index of the last i found.

    //       at the end
    //       not found
    //       found

    if (n == pool)
    {
        if (j > 1)
        {
            cout << j << "x" << i << endl;
        }
        j = 0;
        return k;
    }
    else if (i == results[n])
    {
        n++;
        j++;
        k++;
        pairetc(i, n, j);
    }
    else
    {
        n++;
        k++;
        pairetc(i, n, j);
    }
}


void compareAll(int i = 1)
{
    if (i > 10)
    {
        return;
    }
    pairetc(i);
    i++;
    compareAll(i);
}

void showResults(int n = 0)
{
    if (n == pool)
    {
        cout << endl;
        return;
    }
    cout << results[n] << " ";
    n++;
    showResults(n);
}

void roll()
{
    cout << "Dice to roll: ";
    cin >> pool;

    while (!pool || !cin)
    {
        cout << "Input an integer >0." << endl;// this currently displays when not
        cin.clear();
        cin.ignore(STREAM_LIMIT, '\n');
        cout << "Dice to roll: ";
        cin >> pool;
    }

    pool = abs(pool);

    if (pool > 1000)
    {
        pool = 1000;
    }

    recSetResults();
    cout << "Rolled " << pool << "d: ";
    showResults();
    poolSort();
    compareAll();
    cin.clear();
    cout << endl;
    roll();

}

int main()
{
    srand(time(NULL));
    cout << "OneRoller" << endl;
    cout << "A dice roller for One Roll Engine games." << endl << endl;
    roll();
    return 0;
}
