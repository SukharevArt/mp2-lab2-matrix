#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	TMatrix<int> t(m);
  //ADD_FAILURE(m==t);
  EXPECT_EQ(m,t);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	TMatrix<int> t(m);
	m[0][0] = 3;
	t[0][0] = 4;
  EXPECT_NE(m,t);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> t(6);
  ASSERT_NO_THROW(t.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	int b;
	ASSERT_NO_THROW(m[2][3] = 3);
	ASSERT_NO_THROW(m[2][4] = 3);
	ASSERT_NO_THROW(b=m[1][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1][0]=3);
	ASSERT_ANY_THROW(m[0][-1]=3);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[2][5]=3);
	ASSERT_ANY_THROW(m[8][3]=3);
	ASSERT_ANY_THROW(m[8][12]=3);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	m[2][4] = 3;
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5),m1(5);
	m[2][4] = 3;
	m1[2][4] = 8;
	ASSERT_NO_THROW(m = m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5), m1(7);
	m = m1;
	EXPECT_EQ(7,m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5), m1(7);
	ASSERT_NO_THROW(m = m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(5), m1(m);
	EXPECT_TRUE(m==m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(5);
	EXPECT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(5), m1(6);
	EXPECT_FALSE(m == m1);
	EXPECT_TRUE(m != m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(5), m1(5),r(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			r[i][j] = m[i][j] + m1[i][j];
	ASSERT_NO_THROW(m + m1);
	EXPECT_EQ(r, m + m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(5), m1(6);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(5), m1(5), r(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			r[i][j] = m[i][j] - m1[i][j];
	ASSERT_NO_THROW(m - m1);
	EXPECT_EQ(r, m - m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(5), m1(6);
	ASSERT_ANY_THROW(m - m1);
}

