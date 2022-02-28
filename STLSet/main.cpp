# include <iostream>
# include <string>
# include <set>
# include <time.h>
# include <vector>
# include <algorithm>

using namespace std;
static void	output_set(std::set<int> some_set, std::string name, bool dig)
{
    std::set<int>::iterator it = some_set.begin();
    std::cout << " " << name << ": ";

    for ( int i=1; it != some_set.end(); i++, it++) {
        if (dig) {
            if (i % 2)
                std::cout << *it << " ";
        }
        else std::cout << *it << " ";
    }
    std::cout << "\n";
}

static std::set<int>	input_u()
{
    int a;
    int b;
    std::set<int> U;

    std::cout << " Left index = ";
    std::cin >> a;
    std::cout << " Right index = ";
    std::cin >> b;

    if (a <= 0 || b <= 0 || a >= b)
    {
        std::cout << " Retry: 0 < left < right";
        exit(1);
    }

    for (int i = a; i < b+1; i++)
        U.insert(i);

    std::cout << "\n";

    return (U);
}

static std::set<int>	input_a(std::set<int> U)
{
    int a = 0;
    int b = U.size();
    std::set<int> A;

    for (int i = 0; i < (int)U.size(); i++)
    {
        std::set<int>::iterator it = U.begin();

        auto rand_index = [] (int left, int right) {
            return rand() % (right - left) + left;
        };

        for (int j = 0; j < rand_index(a, b) && it != U.end(); j++, it++);

        if (it != U.end())
            A.insert(*it);
    }

    return (A);
}

static std::set<int>	input_b(std::set<int> U)
{
    std::set<int> B;
    for (std::set<int>::iterator it = U.begin(); it != U.end(); it++)
        if (*it % 2)
            B.insert(*it);

    return (B);
}

static void	not_intersection(std::set<int> A, std::set<int> B, std::set<int> U)
{
    std::vector<int> intersect;
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(intersect));

    std::vector<int> not_intersect;
    std::set_difference(U.begin(), U.end(), intersect.begin(), intersect.end(), std::back_inserter(not_intersect));

    std::cout << "\n /(A ^ B)  : ";

    for_each(not_intersect.begin(), not_intersect.end(), [](int s){
        std::cout << s << " ";
    });

    std::cout << "\n";
}

static void	diffs_union(std::set<int> A, std::set<int> B, std::set<int> U)
{
    std::vector<int> not_a;
    std::set_difference(U.begin(), U.end(), A.begin(), A.end(), std::back_inserter(not_a));

    std::vector<int> not_b;
    std::set_difference(U.begin(), U.end(), B.begin(), B.end(), std::back_inserter(not_b));

    std::vector<int> unions;
    std::set_union(not_a.begin(), not_a.end(), not_b.begin(), not_b.end(), std::back_inserter(unions));

    std::cout << " (/A v /B) : ";

    for_each(unions.begin(), unions.end(), [](int s){
        std::cout << s << " ";
    });

    std::cout << "\n Wow! De Morgan's law! \n\n";
}

int main ()
{
    srand(time(0));

    // U = множество всех натуральных чисел из диапазона [a, b]
    std::set<int> U = input_u();
    output_set(U, "U", false);

    // A = случайные индексы U
    std::set<int> A = input_a(U);
    output_set(A, "A", false);

    // B = нечетные по значению элементы U
    std::set<int> B = input_b(U);
    output_set(B, "B", false);

    // /(A^B) == /Av/B
    not_intersection(A, B, U);
    diffs_union(A, B, U);

    // Вывод четных по индексу элементов
    output_set(U, "U", true);
    output_set(A, "A", true);
    output_set(B, "B", true);


    return (0);
}
