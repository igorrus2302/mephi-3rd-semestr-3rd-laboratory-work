#include <iostream>



template <typename T>
class ContainerForUniquePtr
{
private:
    T* data;
    int capacity;
    int size;

    void Resize(int newCapacity)
    {
        T* newData = new T[newCapacity];

        for (int i = 0; i < size; ++i)
            newData[i] = std::move(data[i]);

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    ContainerForUniquePtr() : data(nullptr), capacity(0), size(0) {}

    ContainerForUniquePtr(int capacity) : capacity(capacity), size(0)
    {
        data = new T[capacity];
    }

    ~ContainerForUniquePtr()
    {
        delete[] data;
    }

    ContainerForUniquePtr(ContainerForUniquePtr&& other) noexcept
            : data(other.data), capacity(other.capacity), size(other.size)
    {
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }

    ContainerForUniquePtr& operator=(ContainerForUniquePtr&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;

            data = other.data;
            capacity = other.capacity;
            size = other.size;

            other.data = nullptr;
            other.capacity = 0;
            other.size = 0;
        }
        return *this;
    }

    ContainerForUniquePtr(const ContainerForUniquePtr&) = delete;
    ContainerForUniquePtr& operator=(const ContainerForUniquePtr&) = delete;

    T& operator[](int index)
    {
        return data[index];
    }

    const T& operator[](int index) const
    {
        return data[index];
    }

    void PushBack(const T& value)
    {
        if (size >= capacity)
        {
            Resize(capacity * 2);
        }
        data[size++] = value;
    }

    int GetSize() const
    {
        return size;
    }

    int GetCapacity() const
    {
        return capacity;
    }

    T* GetData()
    {
        return data;
    }

    const T* GetData() const
    {
        return data;
    }
};

