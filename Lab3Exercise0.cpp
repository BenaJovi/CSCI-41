/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  
 *  
 */

#include <iostream>
using namespace std;
class MyArray 
{
private:
    double* arr;
    size_t size;

public:
    MyArray(double* elements, size_t sz) : arr(new double[sz]), size(sz) 
    {
        for (size_t i = 0; i < size; ++i) 
        {
            arr[i] = elements[i];
        }
    }

    ~MyArray() 
    {
        delete[] arr;
    }

    bool Search1(double x) 
    {
        for (size_t i = 1; i < size; ++i) 
        {
            if (arr[i] == x) 
            {
                return true;
            }
        }
        return false;
    }

    bool Search2(double x) 
    {
        size_t i = 1;
        while (i < size) {
            if (arr[i] == x) 
            {
                return true;
            }
            ++i;
        }
        return false;
    }

    bool Search3(double x) 
    {
        size_t i = 1;
        do {
            if (arr[i] == x) 
            {
                return true;
            }
            ++i;
        } while (i < size);
        return false;
    }

    bool Search4Recursive(double x, size_t index) 
    {
        if (index >= size) 
        {
            return false;
        }
        if (arr[index] == x) 
        {
            return true;
        }
        return Search4Recursive(x, index + 1);
    }

    bool Search4(double x) {
        return Search4Recursive(x, 0);
    }

    bool IsAllEven1() 
    {
        for (size_t i = 0; i < size; ++i) 
        {
            if (static_cast<int>(arr[i]) % 2 != 0) 
            {
                return false;
            }
        }
        return true;
    }

    bool IsAllEven2() 
    {
        size_t i = 0;
        while (i < size) 
        {
            if (static_cast<int>(arr[i]) % 2 != 0) 
            {
                return false;
            }
            ++i;
        }
        return true;
    }

    bool IsAllEven3() 
    {
        size_t i = 0;
        do {
            if (static_cast<int>(arr[i]) % 2 != 0) 
            {
                return false;
            }
            ++i;
        } while (i < size);
        return true;
    }

    bool IsAllEven4Recursive(size_t index) 
    {
        if (index >= size) 
        {
            return true;
        }
        if (static_cast<int>(arr[index]) % 2 != 0) 
        {
            return false;
        }
        return IsAllEven4Recursive(index + 1);
    }

    bool IsAllEven4() 
    {
        return IsAllEven4Recursive(0);
    }

   MyArray FindIndicesOfValue(double x) 
   {
        size_t count = 1;
        for (size_t i = 1; i < size; i++) 
        {
            if (arr[i] == x) 
            {
                count++;
            }
        }

        double* indices = new double[count];
        size_t j = 1;
        for (size_t i = 1; i < size; i++) 
        {
            if (arr[i] == x) 
            {
                indices[j++] = i;
            }
        }
        MyArray result(indices, count);
        delete[] indices;
        return result;
    }
    void SwapAll(double x, double y) 
    {
        for (size_t i = 1; i <=size; ++i) 
        {
            if (arr[i] == x) 
            {
                arr[i] = y;
            }
        }
    }

    void RemoveALL(double x) 
    {
        size_t newSize = 0;
        for (size_t i = 1; i <=size; ++i) 
        {
            if (arr[i] != x) 
            {
                arr[newSize++] = arr[i];
            }
        }
        size = newSize;
    }

    void Print() 
    {
        
        for (size_t i = 1; i <size; ++i)
        {
            
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    size_t size;
    cout << "Enter the size of the array: ";
    cin >> size;

    double* elements = new double[size];
    cout << "Enter the elements of the array: "<<endl;
    for (size_t i = 1; i <= size; ++i) 
    {
        cout<<"Enter ["<<i<<"]: ";
        cin>>elements[i];
    }


    cout<<"Entered array [";
    for (int j=1; j<=size; ++j)
    {
        if (size==1){cout<<elements[j];break;}
        cout<<elements[j]<<",";
    }
    cout<<"]"<<endl;
    


    MyArray myArray(elements, size);
    double x;
    double y;
    double z;
    cout<<"Enter value for x:"<<endl;
    cin>>x;
    // Search methods
    cout << "using For Loop:"<<myArray.Search1(x) << endl; 
    cout << "using While Loop:"<<myArray.Search2(x) << endl; 
    cout << "using Do While Loop:"<<myArray.Search3(x) << endl; 
    cout << "using return:"<<myArray.Search4(x) << endl; 

    // IsAllEven methods
    cout <<"Checks if all elements in the array are even using For Loop:"<< myArray.IsAllEven1() << endl; 
    cout <<"Checks if all elements in the array are even using While Loop:"<< myArray.IsAllEven2() << endl; 
    cout << "Checks if all elements in the array are even using Do While Loop:"<<myArray.IsAllEven3() << endl; 
    cout << "Checks if all elements in the array are even using Recursive:"<<myArray.IsAllEven4() << endl;

    // FindIndicesOfValue
    cout<<"The index where x is located in the array"<<endl;
    MyArray indices = myArray.FindIndicesOfValue(x);
    indices.Print(); 

    // SwapAll
    cout<<"Enter value for y:"<<endl;
    cin>>y;
    cout<<"Now all x values will be swaped with y values"<<endl;
    myArray.SwapAll(x, y);
    myArray.Print(); 

    // RemoveALL
    cout<<"enter a value for z:"<<endl;
    cin>>z;
    cout<<"this will remove all z values in the array"<<endl;

    myArray.RemoveALL(z);
    myArray.Print(); 
    delete[] elements;
    return 0;
}