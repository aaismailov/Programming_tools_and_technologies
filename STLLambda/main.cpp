#include <iostream>
#include <functional>
#include <string>
#include <map>

using namespace std;
const int start = 2, finish = 26;
const int a1 = 6, a2 = 12;

int main() {
    int breanchCount = 0;

    // Прямой ход
    function<int(int, string)> calc = [&calc, &breanchCount](int x, string way) {
        breanchCount++;
        if (x < finish)
            return calc(x + 2, way + " +2") + calc(x + 5, way + " +5");
        else if (x == finish) {
            cout << way << endl;
            return 1;
        }
        return 0;
    };
    cout << "--Forward--\nCount:\n" << calc(start, "") << endl;
    cout << "breanchCount: " << breanchCount << endl;


    // С ограничениями
    breanchCount = 0;
    function<int(int, int, string)> calcA = [&calcA, &breanchCount](int x, int flag, string way) {
        breanchCount++;
        if (x < finish) {
            if ((x == a1) && flag == 0)
                flag = 1;
            if ((x == a2) && flag == 1)
                flag = 2;
            return calcA(x + 2, flag, way + " +2") + calcA(x + 5, flag, way + " +5");
        } else if (x == finish && flag == 2) {
            cout << way << endl;
            return 1;
        }
        return 0;
    };
    cout << "\n--With restrictions--\nCount:\n" << calcA(start, 0, "") << endl;
    cout << "breanchCount: " << breanchCount << endl;

    // Обратный ход
    breanchCount = 0;
    function<int(int, string)> calcBack = [&calcBack, &breanchCount](int x, string way) {
        breanchCount++;
        if (x > start) {
            int count = calcBack(x - 2, way + " -2");
            count += calcBack(x - 5, way + " -5");
            return count;
        } else if (x == start) {
            cout << way << endl;
            return 1;
        }
        return 0;
    };
    cout << "\n--Back--\nCount:\n" << calcBack(finish, "") << endl;
    cout << "breanchCount: " << breanchCount << endl;

    // Метод исследования операций
    breanchCount = 0;
    map<int, int> Space;

    function<int(int)> calcOp = [&Space, &calcOp, &breanchCount](int x) {
        breanchCount++;
        if (Space.count(x)) return Space[x];
        if (x == finish) {
            Space[x] = 1;
            return 1;
        }
        if (x < finish) {
            Space[x] = calcOp(x + 2) + calcOp(x + 5);
            return Space[x];
        }
        return 0;
    };

    cout << "\n--OR--\nCount:\n" << calcOp(start) << endl;
    cout << "breanchCount: " << breanchCount << endl;

    for (auto i: Space)
        cout << i.first << " " << i.second << endl;

    return (0);
}
