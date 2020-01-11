#include "gtest/gtest.h"
#include "sort.h"

const auto intComparatorLambda = [](int a, int b) { return a < b; };

template<typename T>
bool isEqual(T* first, T* second, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (first[i] != second[i])
        {
            return false;
        }
    }
    return true;
}

TEST(SortTest, PivotTest)
{
    const int length = 7;
    int arrayTest[length] = { 6, 5, 4, 3, 2, 1, 0 };

    int pivot = pivot_point(arrayTest, arrayTest + length - 1, intComparatorLambda);
    ASSERT_EQ(pivot, 3);
}

TEST(SortTest, DescSortedArrayTest)
{
    const int length = 7;
    int arrayTest[length] = { 6, 5, 4, 3, 2, 1, 0 };
    int expectedArray[length] = { 0, 1, 2, 3, 4, 5, 6 };

    sort(arrayTest, arrayTest + length - 1, intComparatorLambda);
    ASSERT_EQ(isEqual(expectedArray, arrayTest, length), true);
}

TEST(SortTest, SortedArrayTest)
{
    const int length = 7;
    int arrayTest[length] = { 0, 1, 2, 3, 4, 5, 6 };
    int expectedArray[length] = { 0, 1, 2, 3, 4, 5, 6 };

    sort(arrayTest, arrayTest + length - 1, intComparatorLambda);
    ASSERT_EQ(isEqual(expectedArray, arrayTest, length), true);
}

TEST(SortTest, SingleElementTest)
{
    const int length = 1;
    int arrayTest[length] = { 5 };
    int expectedArray[length] = { 5 };

    sort(arrayTest, arrayTest + length - 1, intComparatorLambda);
    ASSERT_EQ(isEqual(expectedArray, arrayTest, length), true);
}