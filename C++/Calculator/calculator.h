#ifndef CALCULATOR_H
#define CALCULATOR_H

template <typename T>
class calculator
{
private:
    T total;

public:
    calculator();
    ~calculator();

    T sum(T);
    T substract(T);
    T multiply(T);
    T divide(T);

    T get_total();
};

template <typename T>
calculator<T>::calculator()
{
    total = 0;
}

template <typename T>
calculator<T>::~calculator()
{
}

template <typename T>
T calculator<T>::sum(T value)
{
    total += value;
    return total;
}

template <typename T>
T calculator<T>::substract(T value)
{
    total -= value;
    return total;
}

template <typename T>
T calculator<T>::multiply(T value)
{
    if(total == 0)
    {
        total = value;
        return total;
    }
    
    total *= value;
    return total;
}

template <typename T>
T calculator<T>::divide(T value)
{
    if(total == 0)
    {
        total = value;
        return total;
    }

    total /= value;
    return total;
}

template <typename T>
T calculator<T>::get_total()
{
    return total;
}

#endif // CALCULATOR_H