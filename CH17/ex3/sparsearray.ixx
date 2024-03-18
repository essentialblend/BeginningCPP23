export module sparsearray;

import std;

export template<typename T>
class SparseArray
{
public:
    T& operator[](std::size_t index);  
    
    T& at(std::size_t index);
    const T& at(std::size_t index) const; 

    bool elementExistsAt(std::size_t index) const;

private:
    std::vector<std::pair<std::size_t, T>> m_values;
    
    T* findAt(std::size_t index);
    const T* findAt(std::size_t index) const;
};

template<typename T>
T& SparseArray<T>::operator[](std::size_t index)
{
    if (auto* foundElem{ findAt(index) }; foundElem)
    {
        return *foundElem;
    }
    else
    {
        m_values.push_back({ index, T{} });
        return m_values.back().second;
    }
}

template<typename T>
const T& SparseArray<T>::at(std::size_t index) const
{
    const auto* found{ findAt(index) };
    if (found)
    {
        return *found;
    }
    else
    {
        throw std::out_of_range{ "No value at index " + std::to_string(index) };
    }
}

template<typename T>
T& SparseArray<T>::at(std::size_t index)
{
    return const_cast<T&>(std::as_const(*this).at(index));
}

template<typename T>
bool SparseArray<T>::elementExistsAt(std::size_t index) const
{
    return findAt(index) != nullptr;
}

template<typename T>
const T* SparseArray<T>::findAt(std::size_t index) const
{
    for (auto& keyVal : m_values)
    {
        if (keyVal.first == index)
            return &keyVal.second;
    }
    return nullptr;
}

template<typename T>
T* SparseArray<T>::findAt(std::size_t index)
{
    return const_cast<T*>(std::as_const(*this).findAt(index));
}

