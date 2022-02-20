# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;

template <typename T>
void output_vector(std::vector<T> v, std::string str)
{
    std::cout << str;
    for_each(v.begin(), v.end(), [](std::string s){
        std::cout << s << " ";
    });
    std::cout << "\n";
}

std::vector<std::string> input_vector()
{
    std::vector<std::string> v;
    std::string str;
    int num;

    std::cout << "Number of strings: ";
    std::cin >> num;

    if (num > 0) {
        std::cout << "Strings:\n";

        for (int i = 0; i < num; i++)
        {
            std::cin >> str;
            v.push_back(str);
        }
    } else {
        std::cout << "Okay, let's use the default strings!\n";
        v = { "asA321op", "Pas2reas", "1Tutu", "1YYAreasasas3", "lI2dj4ea5s", "e56d7xhrasas", "Jd89Aj" };
    }

    output_vector(v, "\nBefore: ");
    return (v);
}

std::vector<std::string> erase_digits(std::vector<std::string> v)
{
    for_each(v.begin(), v.end(), [](std::string &s){
        std::string::iterator chit = std::remove_if(s.begin(), s.end(), []( int x ) { return ::isdigit(x); });
        auto new_size = std::distance(chit, s.end());
        s.erase(chit, s.end());
        s.append(new_size, '+');
    });

    output_vector(v, " After: ");
    return (v);
}


std::string create_string(std::vector<std::string> v, std::string substr)
{
    std::vector<std::string>::iterator iter = v.begin();
    std::string result;

    while (iter != v.end())
    {
        int count = 0;
        for (int i = 2; (i = (*iter).find(substr, i)) != (int)std::string::npos; i++) {
            count++;
        }
        if (count > 1)
            result += (*iter).substr(0, 2) + " ";
        iter++;
    }

    if (result.size())
        result.erase(result.size() - 1, 1); // Erase the space at the end
    return (result);
}

int main ()
{
    std::vector<std::string> v = input_vector();
    std::string substr;
    std::string result;

    v = erase_digits(v);

    std::cout << "\nSubstring: ";
    std::cin >> substr;

    result = create_string(v, substr);
    if (result.size())
        std::cout << "Result: " << result;
    else std::cout << "There are no substrings that match the condition.";
    return (0);
}
