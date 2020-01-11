#include "gtest/gtest.h"
#include "array.hpp"


class ArrayTest : public ::testing::Test
{
protected:
    Array<int> array_default;
};

TEST_F(ArrayTest, DefaultConstructor)
{
    EXPECT_EQ(array_default.size(), size_t(0));

    auto it = array_default.iterator();
    EXPECT_FALSE(it.hasNext());
    EXPECT_FALSE(it.hasPrev());
}

TEST_F(ArrayTest, CapacityConstructor)
{
    Array<int> arr{ 10 };
    EXPECT_EQ(arr.size(), size_t(0));

    auto it = arr.iterator();
    EXPECT_FALSE(it.hasNext());
    EXPECT_FALSE(it.hasPrev());
}


TEST_F(ArrayTest, CopyAssignment)
{
    for (auto i = 0; i < 10; ++i)
        array_default.insert(i);

    Array<int> arr;
    arr = array_default;
    auto it = arr.iterator();

    EXPECT_EQ(array_default.size(), size_t(10));
    EXPECT_EQ(arr.size(), size_t(10));
    for (auto i = 0; it.hasNext(); it.next(), ++i)
        EXPECT_EQ(it.get(), i);
}

TEST_F(ArrayTest, Insert)
{
    for (auto i = 0; i < 10; ++i)
        array_default.insert(i);
    EXPECT_EQ(array_default.size(), size_t(10));

    auto it = array_default.iterator();
    for (auto i = 0; it.hasNext(); it.next(), ++i)
        EXPECT_EQ(it.get(), i);
}

TEST_F(ArrayTest, InsertAt)
{
    for (auto i = 0; i < 10; ++i)
        array_default.insert(size_t(i), i);
    EXPECT_EQ(array_default.size(), size_t(10));

    auto it = array_default.iterator();
    for (auto i = 0; i < 10; ++i, it.next())
        EXPECT_EQ(it.get(), i);

    for (auto i = 0; i < 10; ++i)
        array_default.insert(size_t(i), i);
    EXPECT_EQ(array_default.size(), size_t(20));

    auto it2 = array_default.iterator();
    for (auto i = 0; i < 10; ++i, it2.next())
        EXPECT_EQ(it2.get(), i);
    for (auto i = 0; i < 10; ++i, it2.next())
        EXPECT_EQ(it2.get(), i);
}

TEST_F(ArrayTest, Remove)
{
    array_default.insert(3);
    array_default.remove(0);
    EXPECT_EQ(array_default.size(), size_t(0));

    for (auto i = 0; i < 10; ++i)
        array_default.insert(i);
    array_default.remove(0);
    EXPECT_EQ(array_default.size(), size_t(9));
    array_default.remove(array_default.size() - 1);
    EXPECT_EQ(array_default.size(), size_t(8));
    array_default.remove((array_default.size() - 1) / 2);
    EXPECT_EQ(array_default.size(), size_t(7));
}


TEST_F(ArrayTest, Iterators)
{
    for (auto i = 0; i < 10; ++i)
        array_default.insert(i);

    auto it = array_default.iterator();
    it.toIndex(5);

    EXPECT_EQ(it.get(), 5);
}

