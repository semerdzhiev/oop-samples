#include <algorithm>

///
/// Represents a dynamic array
///
/// ElementType should have a public default constructor.
/// ElementType should have a public assignment operator.
///
template <typename ElementType>
class DynamicArray
{
private:
    /// Contents of the dynamic array
    ElementType* m_pData;

    /// Size of the allocated buffer, in number of elements
    size_t m_Size;

    /// Number of used cells in the allocated buffer
    size_t m_Used;

public:
    DynamicArray();
    ~DynamicArray();
    DynamicArray(DynamicArray const &);
    DynamicArray& operator=(DynamicArray const &);

private:
    void Resize(size_t);
    void CopyFrom(DynamicArray const &);
    void AllocateBufferAndCopy(ElementType *, size_t, size_t);
    void ZeroAllTheThings();

public:
    ElementType& At(size_t);
    const ElementType& At(size_t) const;
    void Append(const ElementType&);
    void Append(const DynamicArray<ElementType>&);
    size_t GetAllocatedSize() const;
    size_t GetSize() const;
    void Clear();
    bool IsEmpty() const;

public:
    ElementType& operator[](size_t Index);

    DynamicArray<ElementType>& operator+=(const ElementType&);
    DynamicArray<ElementType>& operator+=(const DynamicArray<ElementType>&);

    DynamicArray<ElementType> operator+(const ElementType&);
    DynamicArray<ElementType> operator+(const DynamicArray<ElementType>&);

};


///
/// Construct an empty DynamicArray
///
template <typename ElementType>
DynamicArray<ElementType>::DynamicArray()
{
    ZeroAllTheThings();
}



///
/// Destructor for the DynamicArray class
///
template <typename ElementType>
DynamicArray<ElementType>::~DynamicArray()
{
    Clear();
}



///
/// Copy constructor for the DynamicArray class 
///
template <typename ElementType>
DynamicArray<ElementType>::DynamicArray(DynamicArray const & other)
{
    ZeroAllTheThings();
    CopyFrom(other);
}



///
/// Assignment operator for the DynamicArray class
///
template <typename ElementType>
DynamicArray<ElementType> & DynamicArray<ElementType>::operator=(DynamicArray const & other)
{
    if (this != &other)
    {
        CopyFrom(other);
    }

    return *this;
}


 
///
/// Resizes the dynamic array buffer to NewSize
///
/// If NewSize is larger than the current allocated size of the buffer,
/// the function copies all elements to the new buffer.
/// If NewSize is smaller, the function copies only the first
/// NewSize elements from the old buffer to the new one.
/// In that case, the remaining elements will be lost.
///
/// See the documentation of AllocateBufferAndCopy for
/// more details on error handling.
///
template <typename ElementType>
void DynamicArray<ElementType>::Resize(size_t NewSize)
{
    AllocateBufferAndCopy(m_pData, NewSize, std::min(m_Used, NewSize));
}



///
/// Makes the current object an exact copy of other
///
/// See the documentation of AllocateBufferAndCopy for
/// more details on error handling
///
template <typename ElementType>
void DynamicArray<ElementType>::CopyFrom(DynamicArray const & other)
{
    AllocateBufferAndCopy(other.m_pData, other.m_Size, other.m_Used);
}



///
/// Allocate Size elements for the internal buffer and
/// copy ElementsToCopy elements from pOriginalBuffer to it
///
/// If NumberOfElementsToCopy > Size, then only Size elements will be copied.
///
/// If the function fails, it will throw an exception.
/// In such case, the original object will remain unchanged.
///
/// \throws std::bad_alloc If memory allocation fails
///
/// \throws Unknown
///    If ElementType is a user-defined type and has
///    an assignment operator, which throws an
///    exception, this exception will be rethrown
///    by the function.
///
template<typename ElementType>
void DynamicArray<ElementType>::AllocateBufferAndCopy(
    ElementType * pOriginalBuffer,
    size_t Size,
    size_t NumberOfElementsToCopy)
{
    // If the new size is zero, this means that the
    // memory allocated for the buffer should be freed
    if (Size == 0)
    {
        Clear();
        return;
    }

    // Allocate a new buffer with the desired size
    ElementType* pNewBuffer = new ElementType[Size];

    if (NumberOfElementsToCopy > Size)
        NumberOfElementsToCopy = Size;

    // Copy the elements from the old buffer to the new one
    for (size_t i = 0; i < NumberOfElementsToCopy; ++i)
    {
        try
        {
            pNewBuffer[i] = pOriginalBuffer[i];
        }
        catch (...)
        {
            delete[] pNewBuffer;
            throw;
        }
    }

    // Free the old buffer and set the object to use the new one
    delete[] m_pData;
    m_pData = pNewBuffer;
    m_Used = NumberOfElementsToCopy;
    m_Size = Size;
}



///
/// Assign zero or NULL values to all member-variables
///
template <typename ElementType>
void DynamicArray<ElementType>::ZeroAllTheThings()
{
    m_pData = NULL;
    m_Size = m_Used = 0;
}



///
/// Return the element at position Index in the array
///
/// \throws std::out_of_range If Index is not a valid index in the array
///
template <typename ElementType>
ElementType& DynamicArray<ElementType>::At(size_t Index)
{
    if (Index >= m_Used)
        throw std::out_of_range("Index exceeds the size of the array");

    return m_pData[Index];
}



///
/// Return the element at position Index in the array
///
/// \throws std::out_of_range If Index is not a valid index in the array
///
template<typename ElementType>
const ElementType & DynamicArray<ElementType>::At(size_t Index) const
{
    if (Index >= m_Used)
        throw std::out_of_range("Index exceeds the size of the array");

    return m_pData[Index];
}



///
/// Append a new element to the array
///
template <typename ElementType>
void DynamicArray<ElementType>::Append(const ElementType& Element)
{
    if (m_Used >= m_Size)
        Resize(m_Size ? m_Size * 2 : 2);

    m_pData[m_Used++] = Element;
}



///
/// Append the contents of other to this object
///
template<typename ElementType>
void DynamicArray<ElementType>::Append(const DynamicArray<ElementType>& other)
{
    for (size_t i = 0; i < other.GetSize(); ++i)
        Append(other.At(i));
}



///
/// Get the size (in number of elements) of the underlying buffer
///
template <typename ElementType>
size_t DynamicArray<ElementType>::GetAllocatedSize() const
{
    return m_Size;
}



///
/// Return the number of elements in the array
///
template <typename ElementType>
size_t DynamicArray<ElementType>::GetSize() const
{
    return m_Used;
}



///
/// Empty the dynamic array and free the allocated memory
///
template <typename ElementType>
void DynamicArray<ElementType>::Clear()
{
    delete[] m_pData;
    ZeroAllTheThings();
}



///
/// Check whether the dynamic array has no elements
///
template <typename ElementType>
bool DynamicArray<ElementType>::IsEmpty() const
{
    return m_Size == 0;
}



///
/// Return the element at position Index in the array.
///
/// All this function does is to cal the At() function
/// Check the documentation of At for more details.
///
template<typename ElementType>
inline ElementType & DynamicArray<ElementType>::operator[](size_t Index)
{
    return At(Index);
}



///
/// Append a new element to the array
///
/// All this function does is to cal the Append() function
/// Check the documentation of Append for more details.
///
template<typename ElementType>
inline DynamicArray<ElementType>& DynamicArray<ElementType>::operator+=(const ElementType & element)
{
    Append(element);
    return *this;
}



///
/// Append a new element to the array
///
/// All this function does is to cal the Append() function
/// Check the documentation of Append for more details.
///
template<typename ElementType>
inline DynamicArray<ElementType>& DynamicArray<ElementType>::operator+=(const DynamicArray<ElementType>& other)
{
    Append(other);
    return *this;
}



///
/// Returns a new array, which results from appending element to this object
///
template<typename ElementType>
inline DynamicArray<ElementType> DynamicArray<ElementType>::operator+(const ElementType& element)
{
    DynamicArray<ElementType> result(*this);

    result += element;

    return result;
}



///
/// Returns a new array, which results from appending other to this object
///
template<typename ElementType>
inline DynamicArray<ElementType> DynamicArray<ElementType>::operator+(const DynamicArray<ElementType>& other)
{
    DynamicArray<ElementType> result(*this);

    result += other;

    return result;
}



///
/// Returns a new dynamic array, which results from prepending rhs to lhs
///
template<typename ElementType>
inline DynamicArray<ElementType> operator+(
    const ElementType& lhs,
    DynamicArray<ElementType> rhs)
{
    DynamicArray<ElementType> result;
    result += lhs;
    result += rhs;
    return result;
}