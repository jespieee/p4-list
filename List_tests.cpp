// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_ctor) {
    
    List<int> list1;
    ASSERT_TRUE(list1.empty());
    ASSERT_EQUAL(list1.size(), 0);
}

TEST(test_empty) {
    List<int> list1;
    list1.push_front(1);
    ASSERT_FALSE(list1.empty());
    list1.pop_front();
    ASSERT_TRUE(list1.empty());
}

TEST(test_size) {
    List<int> list1;
    list1.push_front(1);
    ASSERT_EQUAL(list1.size(), 1);
    list1.pop_front();
    ASSERT_EQUAL(list1.size(), 0);
}

TEST(test_pushpop_front) {
    List<int> list1;
    list1.push_front(4);
    ASSERT_FALSE(list1.empty());  
    list1.pop_front();
    ASSERT_TRUE(list1.empty());
    ASSERT_EQUAL(list1.size(), 0);
}

TEST(test_pushpop_back) {
    List<int> list2;
    list2.push_back(4);
    list2.push_back(2);
    ASSERT_FALSE(list2.empty());
    ASSERT_EQUAL(list2.size(), 2);
    list2.pop_back();
    ASSERT_EQUAL(list2.size(), 1);
    list2.pop_back();
    ASSERT_EQUAL(list2.size(), 0);
}

TEST(test_front_back) {
    List<int> list1;
    list1.push_front(1);
    ASSERT_EQUAL(list1.front(), 1);
    list1.push_back(2);
    ASSERT_EQUAL(list1.front(), 1);
    ASSERT_EQUAL(list1.back(), 2);
    list1.push_front(4);
    ASSERT_EQUAL(list1.back(), 2);
    ASSERT_EQUAL(list1.front(), 4);
}

TEST(test_clear) {
    List<int> list1;
    list1.push_front(1);
    list1.push_front(1);
    list1.push_front(1);
    list1.push_front(1);
    ASSERT_EQUAL(list1.size(), 4);
    list1.clear();
    ASSERT_TRUE(list1.empty());
}

TEST(test_assignment_operator) {
    List<int> list1;
    List<int> list2;
    list1.push_front(1);
    list1.push_front(2);
    list2 = list1;
    ASSERT_EQUAL(list1.front(), list2.front());
    
}

TEST(test_Iterator_ctor) {

}

TEST(test_erase1) {
    List<int> list1;
    list1.push_front(1);
    list1.push_front(3);
    list1.push_front(7);
    List<int>::Iterator i = list1.begin();
    ASSERT_EQUAL(list1.size(), 3);
    list1.erase(i);
    ASSERT_EQUAL(list1.size(), 2);
    ASSERT_EQUAL(list1.front(), 3);
}

TEST(test_erase2) {
    List<int> list1;
    list1.push_front(3);
    List<int>::Iterator i = list1.begin();
    list1.erase(i);
    ASSERT_TRUE(list1.empty());
}

TEST(test_erase3) {
    List<int> list1;
    list1.push_front(4);
    list1.push_front(3);
    List<int>::Iterator i = list1.begin();
    ++i;
    list1.erase(i);
    ASSERT_EQUAL(list1.size(), 1);
    ASSERT_EQUAL(list1.front(), 3);
}

TEST(test_insert) {
    List<int> list1;
    list1.push_front(1);
    list1.push_front(4);
    list1.push_front(9);
    List<int>::Iterator i = list1.begin();
    list1.insert(i, 18);
    ASSERT_EQUAL(list1.size(), 4);
    ASSERT_EQUAL(list1.front(), 18);
}

TEST(test_insert1) {
    List<int> list1;
    list1.push_front(1);
    List<int>::Iterator i = list1.begin();
    list1.insert(i, 10);
    ASSERT_EQUAL(list1.size(), 2);
    ASSERT_EQUAL(list1.front(), 10);
}

TEST_MAIN()
