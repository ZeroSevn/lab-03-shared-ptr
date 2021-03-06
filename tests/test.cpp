// Copyright 2020 Malenko Artem artem.malenko@yandex.ru

#include <gtest/gtest.h>

#include "header.hpp"


TEST(Shared_ptr, assign) {
    Shared_ptr<int> sp1(new int(187));
    auto sp2 = sp1;

    EXPECT_EQ(*sp2, 187);
    EXPECT_EQ(sp1.use_count(), 2);
    EXPECT_EQ(sp1.use_count(), sp2.use_count());

    Shared_ptr<int> sp3(new int(0));

    EXPECT_EQ(sp3.use_count(), 1);

    sp1 = sp3;

    EXPECT_EQ(sp3.use_count(), 2);
    EXPECT_EQ(*sp1, 0);
}

TEST(Shared_ptr, reset_swap) {
    Shared_ptr<int> sp1(new int(20));

    EXPECT_EQ(sp1.use_count(), 1);

    sp1.reset();

    EXPECT_EQ(sp1, false);

    Shared_ptr<int> sp2(new int(20));
    sp1 = sp2;

    EXPECT_EQ(sp2.use_count(), 2);
    EXPECT_EQ(*sp2, 20);

    sp2.reset(new int(2020));

    EXPECT_EQ(sp2.use_count(), 1);
    EXPECT_EQ(*sp2, 2020);
    EXPECT_EQ(sp1.use_count(), 1);
    EXPECT_EQ(*sp1, 20);

    Shared_ptr<int> sp3(sp2);

    EXPECT_EQ(sp3.use_count(), 2);
    EXPECT_EQ(*sp3, 2020);
    EXPECT_EQ(sp1.use_count(), 1);
    EXPECT_EQ(*sp1, 20);

    sp3.swap(sp1);

    EXPECT_EQ(sp3.use_count(), 1);
    EXPECT_EQ(*sp3, 20);
    EXPECT_EQ(sp1.use_count(), 2);
    EXPECT_EQ(*sp1, 2020);
}

TEST(Shared_ptr, initialisation) {
    Shared_ptr<int> sp1;
    EXPECT_EQ(sp1, false);

    Shared_ptr<int> sp2(new int(101));

    EXPECT_EQ(sp2, true);
    EXPECT_EQ(*sp2, 101);
    EXPECT_EQ(sp2.use_count(), 1);

    Shared_ptr<int> sp3(sp2);

    EXPECT_EQ(sp3, true);
    EXPECT_EQ(*sp2, *sp3);
    EXPECT_EQ(sp2.use_count(), 2);
    EXPECT_EQ(sp3.use_count(), 2);
    EXPECT_EQ(sp2.get(), sp3.get());
}
