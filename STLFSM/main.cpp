#include <iostream>
#include <string>
#include <set>
#include <stdio.h>
#include <cassert>

using namespace std;
bool FSM(char ch, int & S) // Возвращается флаг ошибки
{
    switch (S) {
    case 0:
        if (ch == 'i') {
            S = 1;
            return false;
        }
        S = -1;
        return true;
    case 1:
        if (ch == 'f') {
            S = 2;
            return false;
        }
        S = -1;
        return true;
    case 2:
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
          S = 3;
          return false;
        }
        S = -1;
        return true;
    case 3:
        switch (ch) {
        case 'a' ... 'z':
        case 'A' ... 'Z':
        case '0' ... '9':
            S = 3;
            return false;
        case ' ':
            S = 10;
            return false;
        case '>':
        case '=':
            S = 4;
            return false;
        case '<':
            S = 5;
            return false;
        default:
            S = -1;
            return true;
        }
    case 4:
        switch (ch) {
        case 'a' ... 'z':
        case 'A' ... 'Z':
            S = 9;
            return false;
        case '+':
        case '-':
            S = 7;
            return false;
        default:
            S = -1;
            return true;
        }
    case 5:
        switch (ch) {
        case 'a' ... 'z':
        case 'A' ... 'Z':
            S = 9;
            return false;
        case '+':
        case '-':
            S = 7;
            return false;
        case '>':
            S = 6;
            return false;
        default:
            S = -1;
            return true;
        }
    case 6:
        switch (ch) {
        case 'a' ... 'z':
        case 'A' ... 'Z':
            S = 9;
            return false;
        case '+':
        case '-':
            S = 7;
            return false;
        default:
            S = -1;
            return true;
        }
    case 7:
        if (ch >= '0' && ch <= '9') {
          S = 8;
          return false;
        }
        S = -1;
        return true;
    case 8:
        if (ch >= '0' && ch <= '9') {
          S = 8;
          return false;
        }
        if (ch == ' ') {
          S = 10;
          return false;
        }
        S = -1;
        return true;
    case 9:
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
          S = 9;
          return false;
        }
        if (ch == ' ') {
          S = 10;
          return false;
        }
        S = -1;
        return true;
    case 10:
      if (ch == 't') {
        S = 11;
        return false;
      }
      S = -1;
      return true;
    case 11:
      if (ch == 'h') {
        S = 12;
        return false;
      }
      S = -1;
      return true;
    case 12:
      if (ch == 'e') {
        S = 13;
        return false;
      }
      S = -1;
      return true;
    case 13:
      if (ch == 'n') {
        S = 14;
        return false;
      }
      S = -1;
      return true;
    case 14:
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
          S = 15;
          return false;
        }
        S = -1;
        return true;
    case 15:
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
          S = 15;
          return false;
        }
        if (ch == '=') {
          S = 16;
          return false;
        }
        S = -1;
        return true;
    case 16:
        switch (ch) {
        case 'a' ... 'z':
        case 'A' ... 'Z':
            S = 17;
            return false;
        case '0' ... '9':
            S = 18;
            return false;
        default:
            S = -1;
            return true;
        }
    case 17:
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
          S = 17;
          return false;
        }
        if (ch == '+' || ch == '-') {
          S = 21;
          return false;
        }
        S = -1;
        return true;
    case 18:
        if (ch >= '0' && ch <= '9') {
          S = 18;
          return false;
        }
        if (ch == '.') {
          S = 19;
          return false;
        }
        S = -1;
        return true;
    case 19:
        if (ch >= '0' && ch <= '9') {
          S = 20;
          return false;
        }
        S = -1;
        return true;
    case 20:
        if (ch >= '0' && ch <= '9') {
          S = 20;
          return false;
        }
        if (ch == '+' || ch == '-') {
          S = 21;
          return false;
        }
        S = -1;
        return true;
    case 21:
        switch (ch) {
        case 'a' ... 'z':
        case 'A' ... 'Z':
            S = 22;
            return false;
        case '0' ... '9':
            S = 23;
            return false;
        default:
            S = -1;
            return true;
        }
    case 22:
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
          S = 22;
          return false;
        }
        if (ch == ' ') {
          S = 26;
          return false;
        }
        S = -1;
        return true;
    case 23:
        if (ch >= '0' && ch <= '9') {
          S = 23;
          return false;
        }
        if (ch == '.') {
          S = 24;
          return false;
        }
        S = -1;
        return true;
    case 24:
        if (ch >= '0' && ch <= '9') {
          S = 25;
          return false;
        }
        S = -1;
        return true;
    case 25:
        if (ch >= '0' && ch <= '9') {
          S = 25;
          return false;
        }
        if (ch == ' ') {
          S = 26;
          return false;
        }
        S = -1;
        return true;
    case 26:
        if (ch >= 'e') {
          S = 27;
          return false;
        }
        S = -1;
        return true;
    case 27:
        if (ch == 'n') {
          S = 40;
          return false;
        }
        if (ch == 'l') {
          S = 28;
          return false;
        }
        S = -1;
        return true;
    case 28:
        if (ch == 's') {
          S = 29;
          return false;
        }
        S = -1;
        return true;
    case 29:
        if (ch == 'e') {
          S = 30;
          return false;
        }
        S = -1;
        return true;
    case 30:
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
          S = 31;
          return false;
        }
        S = -1;
        return true;
    case 31:
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
          S = 31;
          return false;
        }
        if (ch == '=') {
          S = 32;
          return false;
        }
        S = -1;
        return true;
    case 32:
        switch (ch) {
        case 'a' ... 'z':
        case 'A' ... 'Z':
            S = 33;
            return false;
        case '0' ... '9':
            S = 34;
            return false;
        default:
            S = -1;
            return true;
        }
    case 33:
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
          S = 33;
          return false;
        }
        if (ch == '+' || ch == '-') {
          S = 35;
          return false;
        }
        S = -1;
        return true;
    case 34:
        if (ch >= '0' && ch <= '9') {
          S = 34;
          return false;
        }
        if (ch == '+' || ch == '-') {
          S = 35;
          return false;
        }
        S = -1;
        return true;
    case 35:
        switch (ch) {
        case '0' ... '9':
            S = 36;
            return false;
        case 'a' ... 'z':
        case 'A' ... 'Z':
            S = 37;
            return false;
        default:
            S = -1;
            return true;
        }
    case 36:
        if (ch >= '0' && ch <= '9') {
          S = 36;
          return false;
        }
        if (ch == ' ') {
          S = 38;
          return false;
        }
        S = -1;
        return true;
    case 37:
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
          S = 37;
          return false;
        }
        if (ch == ' ') {
          S = 38;
          return false;
        }
        S = -1;
        return true;
    case 38:
        if (ch >= 'e') {
          S = 39;
          return false;
        }
        S = -1;
        return true;
    case 39:
        if (ch == 'n') {
          S = 40;
          return false;
        }
        S = -1;
        return true;
    case 40:
        if (ch == 'd') {
          S = 41;
          return false;
        }
        S = -1;
        return true;
    case 41:
        if (ch == 'i') {
          S = 42;
          return false;
        }
        S = -1;
        return true;
    case 42:
        if (ch == 'f') {
          S = 43;
          return false;
        }
        S = -1;
        return true;
    case 43:
        break;
  }
}

int main() {
    // Тестирование
    int K = 0;
    for (auto i: "")
        if (FSM(i, K)) break;
    assert (K == -1);
    K = 0;
    for (auto i: "ifA>")
        if (FSM(i, K)) break;
    assert (K == -1);
    K = 0;
    for (auto i: "ifz1=-24 thenz1=32.6+b2b endif")
        if (FSM(i, K)) break;
    assert (K == 43);
    K = 0;
    for (auto i: "ifA01<>Fs2 thenA01=Fs2-0.465 elseA01=23+Fs2 endif")
        if (FSM(i, K)) break;
    assert (K == 43);

  int S = 0;
  string str;
  set < int > Final = {
    43
  }; // Множество конечных состояний автомата
  bool FEnter = false;
  while (getline(cin, str), str != "") {
    if (!FEnter)
      FEnter = true;
    else
      FSM('\n', S);
    for (auto i: str)
      if (FSM(i, S)) break;
  }

  cout << S << endl;
  if (Final.count(S)) // Проверяем, находится ли автомат в конечном состоянии
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
