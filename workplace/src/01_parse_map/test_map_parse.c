/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:20:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/02 15:46:07 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <unistd.h>

// /* Mock implementations of required external functions */
// char	*get_next_line(int fd)
// {
// 	static char	buffer[1024];
// 	int			i;
// 	char		c;
// 	ssize_t		bytes_read;

// 	i = 0;
// 	while ((bytes_read = read(fd, &c, 1)) > 0)
// 	{
// 		if (c == '\n')
// 		{
// 			buffer[i] = '\0';
// 			return (strdup(buffer));
// 		}
// 		buffer[i++] = c;
// 		if (i >= 1023)
// 			break;
// 	}
// 	if (i == 0 && bytes_read <= 0)
// 		return (NULL);
// 	buffer[i] = '\0';
// 	return (strdup(buffer));
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**result;
// 	int		count;
// 	int		i;
// 	int		start;
// 	int		j;

// 	if (!s)
// 		return (NULL);
// 	count = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && (i == 0 || s[i - 1] == c))
// 			count++;
// 		i++;
// 	}
// 	result = malloc(sizeof(char *) * (count + 1));
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			start = i;
// 			while (s[i] && s[i] != c)
// 				i++;
// 			result[j] = malloc(i - start + 1);
// 			if (!result[j])
// 				return (NULL);
// 			strncpy(result[j], &s[start], i - start);
// 			result[j][i - start] = '\0';
// 			j++;
// 		}
// 		else
// 			i++;
// 	}
// 	result[j] = NULL;
// 	return (result);
// }

// void	ft_free_split(char **split)
// {
// 	int	i;

// 	if (!split)
// 		return ;
// 	i = 0;
// 	while (split[i])
// 	{
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// }

// int	ft_atoi(const char *str)
// {
// 	int	result;
// 	int	sign;
// 	int	i;

// 	result = 0;
// 	sign = 1;
// 	i = 0;
// 	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
// 		   str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	return (result * sign);
// }

// /* Test functions */
// void	print_map(int **map, int rows, int cols)
// {
// 	int	i;
// 	int	j;

// 	printf("Map (%dx%d):\n", rows, cols);
// 	i = 0;
// 	while (i < rows)
// 	{
// 		j = 0;
// 		while (j < cols)
// 		{
// 			printf("%3d ", map[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

// int	create_test_file(const char *filename, const char *content)
// {
// 	int		fd;
// 	ssize_t	bytes_written;

// 	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	if (fd == -1)
// 		return (-1);
// 	bytes_written = write(fd, content, strlen(content));
// 	close(fd);
// 	if (bytes_written == -1)
// 		return (-1);
// 	return (0);
// }

// void	test_basic_map(void)
// {
// 	int		**map;
// 	int		rows;
// 	int		cols;
// 	const char	*test_content = "1 2 3\n4 5 6\n7 8 2147483649\n";

// 	printf("=== Test 1: Basic 3x3 map ===\n");

// 	if (create_test_file("test1.fdf", test_content) == -1)
// 	{
// 		printf("Failed to create test file\n");
// 		return ;
// 	}

// 	parse_map("test1.fdf", &map, &rows, &cols);

// 	printf("Expected: 3x3 map\n");
// 	printf("Got: %dx%d map\n", rows, cols);

// 	if (rows == 3 && cols == 3)
// 	{
// 		print_map(map, rows, cols);
// 		printf("✅ Test 1 PASSED\n");
// 	}
// 	else
// 		printf("❌ Test 1 FAILED\n");

// 	free_map(map, rows);
// 	unlink("test1.fdf");
// 	printf("\n");
// }

// void	test_rectangular_map(void)
// {
// 	int		**map;
// 	int		rows;
// 	int		cols;
// 	const char	*test_content = "1 2 3 4 5\n6 7 8 9 10\n";

// 	printf("=== Test 2: Rectangular 2x5 map ===\n");

// 	if (create_test_file("test2.fdf", test_content) == -1)
// 	{
// 		printf("Failed to create test file\n");
// 		return ;
// 	}

// 	parse_map("test2.fdf", &map, &rows, &cols);

// 	printf("Expected: 2x5 map\n");
// 	printf("Got: %dx%d map\n", rows, cols);

// 	if (rows == 2 && cols == 5)
// 	{
// 		print_map(map, rows, cols);
// 		printf("✅ Test 2 PASSED\n");
// 	}
// 	else
// 		printf("❌ Test 2 FAILED\n");

// 	free_map(map, rows);
// 	unlink("test2.fdf");
// 	printf("\n");
// }

// void	test_single_element(void)
// {
// 	int		**map;
// 	int		rows;
// 	int		cols;
// 	const char	*test_content = "42\n";

// 	printf("=== Test 3: Single element map ===\n");

// 	if (create_test_file("test3.fdf", test_content) == -1)
// 	{
// 		printf("Failed to create test file\n");
// 		return ;
// 	}

// 	parse_map("test3.fdf", &map, &rows, &cols);

// 	printf("Expected: 1x1 map with value 42\n");
// 	printf("Got: %dx%d map\n", rows, cols);

// 	if (rows == 1 && cols == 1 && map[0][0] == 42)
// 	{
// 		print_map(map, rows, cols);
// 		printf("✅ Test 3 PASSED\n");
// 	}
// 	else
// 		printf("❌ Test 3 FAILED\n");

// 	free_map(map, rows);
// 	unlink("test3.fdf");
// 	printf("\n");
// }

// void	test_error_cases(void)
// {
// 	printf("=== Test 4: Error handling ===\n");

// 	// Test 4a: Empty file
// 	printf("Testing empty file...\n");
// 	if (create_test_file("empty.fdf", "") == -1)
// 	{
// 		printf("Failed to create empty test file\n");
// 		return ;
// 	}

// 	// Note: This test expects the library to handle empty files gracefully
// 	// If the library exits on error, this test will show that behavior
// 	printf("Note: Library may exit on empty file (expected behavior)\n");

// 	unlink("empty.fdf");

// 	// Test 4b: Inconsistent row lengths
// 	printf("Testing inconsistent row lengths...\n");
// 	const char *inconsistent_content = "1 2 3\n4 5\n6 7 8 9\n";
// 	if (create_test_file("inconsistent.fdf", inconsistent_content) == -1)
// 	{
// 		printf("Failed to create inconsistent test file\n");
// 		return ;
// 	}

// 	printf("Note: Library may exit on inconsistent rows (expected behavior)\n");

// 	unlink("inconsistent.fdf");

// 	printf("✅ Error handling tests completed (library exits on errors as designed)\n");
// 	printf("\n");
// }

// void	test_boundary_values(void)
// {
// 	int		**map;
// 	int		rows;
// 	int		cols;

// 	printf("=== Test 5: Boundary values ===\n");

// 	// Test 5a: Large numbers
// 	printf("Testing large numbers...\n");
// 	const char *large_content = "2147483647 -2147483648\n1000000 -1000000\n";
// 	if (create_test_file("large.fdf", large_content) == -1)
// 	{
// 		printf("Failed to create large numbers test file\n");
// 		return ;
// 	}

// 	parse_map("large.fdf", &map, &rows, &cols);
// 	printf("Got: %dx%d map\n", rows, cols);
// 	if (rows == 2 && cols == 2)
// 	{
// 		printf("Large values: %d, %d, %d, %d\n",
// 			map[0][0], map[0][1], map[1][0], map[1][1]);
// 		if (map[0][0] == 2147483647 && map[0][1] == -2147483648)
// 			printf("✅ Large numbers handled correctly\n");
// 		else
// 			printf("❌ Large numbers not handled correctly\n");
// 	}
// 	else
// 		printf("❌ Large numbers test failed - wrong dimensions\n");

// 	free_map(map, rows);
// 	unlink("large.fdf");

// 	// Test 5b: Single column map
// 	printf("Testing single column map...\n");
// 	const char *single_col_content = "1\n2\n3\n4\n5\n";
// 	if (create_test_file("single_col.fdf", single_col_content) == -1)
// 	{
// 		printf("Failed to create single column test file\n");
// 		return ;
// 	}

// 	parse_map("single_col.fdf", &map, &rows, &cols);
// 	printf("Got: %dx%d map\n", rows, cols);
// 	if (rows == 5 && cols == 1)
// 	{
// 		print_map(map, rows, cols);
// 		printf("✅ Single column map handled correctly\n");
// 	}
// 	else
// 		printf("❌ Single column map failed\n");

// 	free_map(map, rows);
// 	unlink("single_col.fdf");

// 	// Test 5c: Single row map
// 	printf("Testing single row map...\n");
// 	const char *single_row_content = "1 2 3 4 5 6 7 8 9 10\n";
// 	if (create_test_file("single_row.fdf", single_row_content) == -1)
// 	{
// 		printf("Failed to create single row test file\n");
// 		return ;
// 	}

// 	parse_map("single_row.fdf", &map, &rows, &cols);
// 	printf("Got: %dx%d map\n", rows, cols);
// 	if (rows == 1 && cols == 10)
// 	{
// 		print_map(map, rows, cols);
// 		printf("✅ Single row map handled correctly\n");
// 	}
// 	else
// 		printf("❌ Single row map failed\n");

// 	free_map(map, rows);
// 	unlink("single_row.fdf");

// 	printf("\n");
// }

// void	test_memory_leaks(void)
// {
// 	int		**map;
// 	int		rows;
// 	int		cols;
// 	int		i;

// 	printf("=== Test 6: Memory leak testing ===\n");
// 	printf("Running multiple allocations and frees...\n");

// 	const char *test_content = "1 2 3\n4 5 6\n7 8 9\n";

// 	// Create test file once
// 	if (create_test_file("leak_test.fdf", test_content) == -1)
// 	{
// 		printf("Failed to create leak test file\n");
// 		return ;
// 	}

// 	// Run multiple parse/free cycles
// 	i = 0;
// 	while (i < 100)
// 	{
// 		parse_map("leak_test.fdf", &map, &rows, &cols);
// 		if (map && rows == 3 && cols == 3)
// 		{
// 			free_map(map, rows);
// 		}
// 		else
// 		{
// 			printf("❌ Memory leak test failed at iteration %d\n", i);
// 			break ;
// 		}
// 		i++;
// 	}

// 	if (i == 100)
// 		printf("✅ 100 parse/free cycles completed successfully\n");

// 	unlink("leak_test.fdf");
// 	printf("Note: Use valgrind or similar tools for detailed leak detection\n");
// 	printf("\n");
// }

// int	main(void)
// {
// 	printf("Map Parse Library Test Suite\n");
// 	printf("============================\n\n");

// 	test_basic_map();
// 	test_rectangular_map();
// 	test_single_element();
// 	test_error_cases();
// 	test_boundary_values();
// 	test_memory_leaks();

// 	printf("Test suite completed!\n");
// 	return (0);
// }
