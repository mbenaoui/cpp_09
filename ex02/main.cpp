#include <iostream>
#include <vector>
#include <deque>
template <class T>
void sort_arr(T &arr, int l, int m, int r, size_t size)
{
    int i = l;
    int j = m + 1;
    int k = l;
    int temp[size];
     
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
            {
                std :: cout << "::::::::\n";
                temp[k] = arr[j];
                j++;
                k++;

            }
                
    }

    while( i <= m )
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while( j <= r )
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int d = l ; d <= r; d++)
        arr[d] = temp[d];
}

template <class T>
void tasks_arr(T &arr, int i, int j, size_t size)
{
    if (i < j)
    {
        int m = (i + j) / 2;
        tasks_arr(arr, i, m, size);
        tasks_arr(arr, m + 1, j, size);
           
        sort_arr(arr, i, m, j, size);
    }
}
int main(int ac, char **av)
{
    // std ::vector<int> my_vector;
    std ::vector<int> my_vector;
    std ::deque<int> my_deque;
    int i = 1;
    int temp = 0;
    while (av[i])
    {
        my_vector.push_back(atoi(av[i]));
        my_deque.push_back(atoi(av[i]));
        i++;
    }

    tasks_arr(my_vector, 0 , my_vector.size() - 1,my_vector.size());

    // tasks_arr(my_vector, 0 , my_deque.size() - 1, i);
    for (int k = 0; k < my_vector.size(); k++)
        std ::cout << my_vector[k] << " ";
    std ::cout << std::endl;
}