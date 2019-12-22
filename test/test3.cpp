#include "gtest/gtest.h"
#include "dictionary.hpp"

TEST(DictionaryTest, DefaultConstruct)
{
    Dictionary<int, int> d;

    EXPECT_EQ(d.getSize(), size_t(0));
}

TEST(DictionaryTest, CopyConstruct)
{
    Dictionary<int, int> d;
    d.put(1, 1);
    d.put(2, 2);
    d.put(3, 3);

    auto d_copy = d;
    EXPECT_EQ(d_copy.getSize(), d.getSize());
}

TEST(DictionaryTest, CopyAssignment)
{
    Dictionary<int, int> d;
    d.put(1, 1);
    d.put(2, 2);
    d.put(3, 3);

    decltype(d) d_copy;
    d_copy[1] = -1;
    d_copy = d;
    EXPECT_EQ(d_copy.getSize(), d.getSize());
}

TEST(DictionaryTest, Put)
{
    Dictionary<int, int> d;

    d.put(1, 1);
    EXPECT_EQ(d.getSize(), size_t(1));
    d.put(2, 1);
    EXPECT_EQ(d.getSize(), size_t(2));
    d.put(2, 2);
    EXPECT_EQ(d.getSize(), size_t(2));
    d.put(3, 3);
    EXPECT_EQ(d.getSize(), size_t(3));
    EXPECT_EQ(d[1], 1);
    EXPECT_EQ(d[2], 2);
    EXPECT_EQ(d[3], 3);
}

TEST(DictionaryTest, Remove)
{
    Dictionary<int, int> d;

    d.put(1, 1);
    d.put(2, 2);
    d.put(3, 3);

    d.remove(2);
    EXPECT_EQ(d.getSize(), size_t(2));
    EXPECT_EQ(d[1], 1);
    EXPECT_FALSE(d.contains(2));
    EXPECT_EQ(d[3], 3);
    EXPECT_EQ(static_cast<const decltype(d)&>(d)[2], int());

    d.remove(1);
    EXPECT_EQ(d.getSize(), size_t(1));
    EXPECT_EQ(static_cast<const decltype(d)&>(d)[1], int());
    EXPECT_FALSE(d.contains(1));
    EXPECT_EQ(d[3], 3);
    EXPECT_EQ(static_cast<const decltype(d)&>(d)[2], int());

    d.remove(3);
    EXPECT_EQ(d.getSize(), size_t(0));
    EXPECT_EQ(static_cast<const decltype(d)&>(d)[3], int());
    EXPECT_FALSE(d.contains(3));
}

