#include <iostream>
class smartArray
{
private:
    int asize;
    int* array;
    int index = 0;
public:

    smartArray(int size)
    {
        asize = size;
        array = new int[2 * asize];

    };
    ~smartArray()
    {
        delete[] array;

    }

    void elementValue(int value)
    {


        std::cout << " / Element index" << index << " / " << " 2*asize" << 2 * asize << std::endl;
        if ((index >= 2 * asize) || (index < 0))

        {
            // std::cout << "throw" << std::endl;
            throw std::runtime_error("\n Error. Index is out of range.");
        }
        else {
            std::cout << " / " << index << " / " << std::endl;
            array[index] = value;
        }
        index++;
    }
    int getElement(int position)
    {
        if ((position < 0) || (position >= index))

        {

            throw std::exception("\n Error. No valuable element.");
        }
        std::cout << " /  index " << index << " / " << std::endl;
        std::cout << " / position" << position << " / " << std::endl;
        return array[position];
    }
    smartArray& operator=(const smartArray& other) {
        asize = other.asize * 2;
        delete[] array;
        array = new int[2 * asize];
        for (int i = 0; i < 2 * asize; i++)
            array[i] = other.array[i];
        return *this;
    }
};

int main()
{
    smartArray a(2);
    smartArray b(2);
    for (int i = 0; i < 10; i++)
    {
        try {
            a.elementValue(i);
            b.elementValue(i + 100);
        }

        catch (const std::exception& e) {
            std::cout << e.what();
        }

    }
    for (int i = 0; i < 10; i++)
    {
        try {
            std::cout << "Array a element (index): " << "(" << i << ") " << a.getElement(i) << std::endl;
            std::cout << "Array b element (index): " << "(" << i << ") " << b.getElement(i) << std::endl;
        }

        catch (const std::exception& e) {
            std::cout << e.what();

        };
    }
    /*try
    {
        a.elementValue(20);
        std::cout << a.getElement(20) << std::endl;
    }
    catch (const std::exception& e) { std::cout << e.what(); };*/
    a = b;
    for (int i = 0; i < 10; i++)
    {
        try
        {
            std::cout << "Array a element  (index): " << "(" << i << ") " << a.getElement(i) << std::endl;

        }
        catch (const std::exception& e)
        {
            std::cout << e.what();
        }

    }

    return 0;
}
