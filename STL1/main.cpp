# define N 13
# define S 3
# define i1 2
# define i2 5

# include <vector>
# include <algorithm>
# include <iostream>
# include <assert.h>
# include <ctime>
# include <cmath>
# include <math.h>

using namespace std;

std::vector<int> integer_vector(int size)
{
    std::vector<int> v(size);
    std::vector<int>::iterator iter = v.begin();

    while (iter != v.end())
    {
        *iter = rand()%1000 - 300;
        iter++;
    }
    return (v);
}

std::vector<float> float_vector(int size)
{
    std::vector<float> v(size);
    std::vector<float>::iterator iter = v.begin();

    while (iter != v.end())
    {
        *iter = pow(-1, rand()%2 + 1) * ((float)(rand()%1000) / (float)(rand()%100));
        iter++;
    }
    return (v);
}

template <typename T>
void output_vector(std::vector<T> v)
{
    typename std::vector<T>::iterator iter = v.begin();

    std::cout << "Out: ";
    while (iter != v.end())
    {
        std::cout << *iter << " ";
        iter++;
    }
    std::cout << "\n";
}

void task_one()
{
    std::vector<int> v = integer_vector(40);
    std::vector<int>::iterator iter = v.begin();

    int sum = 0;
    int nsum = *v.begin();
    int len = 0;
    int nlen = 0;

    while (iter != v.end())
    {
        if (*iter < *(iter+1)) {
            nsum += *(iter+1);
            nlen += 1;
            if (nlen > len) {
                len = nlen;
                sum = nsum;
            }
        }
        else {
            nsum = *(iter+1);
            nlen = 0;
        }
        iter++;
    }

    std::cout << "\nSource array:\n";
    output_vector(v);
    std:: cout << "\nSum of elements of the largest increasing sequence is " << sum << "\n";
}


static void	add_min_pos_to_neg(std::vector<float> *v)
{
    std::vector<float>::iterator iter = v->begin();

    float min_pos = 1000.0f;
    while (iter != v->end())
    {
        if (*iter < min_pos && *iter > 0) min_pos = *iter;
        iter++;
    }
    iter = v->begin();
    while (iter != v->end())
    {
        if (*iter < 0) *iter += min_pos;
        iter++;
    }
}


static void	compress(std::vector<float> *v)
{
    std::vector<float>::iterator iter = v->begin();

    int count = 0;
    while (iter != v->end())
    {
        if (!((int)roundf(*iter) % S)) {
            iter = v->erase(iter);
            count++;
        }
        else iter++;
    }
    iter = v->begin();

    for (int i = 0; i < count; i++) {
        v->insert(v->end(), 0);
    }
}

template <typename T>
bool is_increasing(std::vector<T> v, typename std::vector<T>::iterator end)
{
    typename std::vector<T>::iterator iter = v.begin();

    while (*(iter + 1) != *end && *(iter + 1) != *v.end())
    {
        if (*iter >= *(iter + 1))
            return (false);
        iter++;
    }
    return (true);
}

static std::vector<float>::iterator	find_first_null(std::vector<float> *v)
{
    std::vector<float>::iterator iter = v->begin();

    while (iter != v->end())
    {
        if (*iter == 0)
            return (iter);
        iter++;
    }
    return (v->begin());
}

static std::vector<float>::iterator	find_last_max(std::vector<float> *v)
{
    std::vector<float>::iterator max;
    std::vector<float>::iterator iter = v->begin();

    max = std::max_element(v->begin(), v->end());
    while (iter != v->end())
    {
        if (*iter == *max)
            max = iter;
        iter++;
    }
    return (iter);
}

static void	find_sum_before_max(std::vector<float> *v)
{
    float sum = 0;

    if (find_first_null(v) == v->begin()) {
        std::cout << "Not null element or all elements are null\n";
    }
    else if (is_increasing(*v, find_first_null(v)))
    {
        std::vector<float>::iterator iter = v->begin();
        std::vector<float>::iterator end = find_last_max(v);
            while (iter != end)
            {
                sum += *iter;
                iter++;
            }

            std::cout << "Sum is " << sum << "\n";
    }
    else
        std::cout << "Elements before first null are not increasing\n";
}

static void	remove_not_match_sign(std::vector<float> *v)
{

    std::vector<float>::iterator min;
    std::vector<float>::iterator iter = v->begin();

    min = std::min_element(v->begin(), v->end());
    float smin = *min;
    if (smin == 0) {
        std::cout << "\nMin elem is null: doesn't have sign\n";
    }
    else
    {
            while (iter != v->end())
            {
                if ((*iter > 0.0 && smin < 0.0) or (*iter < 0.0 && smin > 0.0)) {
                    iter = v->erase(iter);
                }
                    else iter++;
            }
            output_vector(*v);
    }
}


static std::vector<float> sort_in_range(std::vector<float> v)
{
    float num;
    for (unsigned long i = i1; i < i2 - 1; i++)
        for(unsigned long j = i + 1; j < i2; j++)
            if (v[i] > v[j])
            {
                num = v[i];
                v[i] = v[j];
                v[j] = num;
            }
    return (v);
}

void task_two()
{
    std::vector<float> v = float_vector(N);

    std::cout << "\nSource array:\n";
    output_vector(v);

    std::cout << "\nAdd the min pos elem for each neg:\n";
    add_min_pos_to_neg(&v);
    output_vector(v);

    std::cout << "\nDelete elems div " << S << ":\n";
    compress(&v);
    output_vector(v);

    find_sum_before_max(&v);

    std::cout << "\nRemove elems not matched sign with min:\n";
    remove_not_match_sign(&v);

    std::cout << "\nSort in range [ "<<i1<<" , "<<i2<<" ]:\n";
    v = sort_in_range(v);
    output_vector(v);
}

int main()
{
        std:: cout << "\n------ TASK 1 ------\n";
        task_one();

        std:: cout << "\n------ TASK 2 ------\n";
        task_two();

        return (0);
}
