#include "fdf.h"

void	test_valid_extensions(void);
void	test_invalid_extensions(void);
void	test_map_dimensions(void);

int	main(void)
{
	test_valid_extensions();
	test_invalid_extensions();
	test_map_dimensions();
	return (0);
}

void	test_valid_extensions(void)
{
	ft_printf("Testing valid extensions.\n");
	// map.fdf
	if (is_valid_extension("map.fdf") == 1)
		ft_printf("	PASS: map.fdf\n");
	else
		ft_printf("  FAIL: map.fdf\n");
	// a.fdf
	if (is_valid_extension("a.fdf") == 1)
		ft_printf("	PASS: a.fdf\n");
	else
		ft_printf("	FAIL: a.fdf\n");
	// folder/map.fdf
	if (is_valid_extension("folder/map.fdf") == 1)
		ft_printf("	PASS: folder/map.fdf\n");
	else
		ft_printf("	FAIL: folder/map.fdf\n");
	// another.map.fdf
	if (is_valid_extension("another.map.fdf") == 1)
		ft_printf("	PASS: another.map.fdf\n");
	else
		ft_printf("	FAIL: another.map.fdf\n");
}

void	test_invalid_extensions(void)
{
	ft_printf("Testing invalid extensions.\n");
	// map.txt
	if (is_valid_extension("map.txt") == 0)
		ft_printf("	PASS: map.txt\n");
	else
		ft_printf("	FAIL: map.txt\n");
	// map.fdfa
	if (is_valid_extension("map.fdfa") == 0)
		ft_printf("	PASS: map.fdfa\n");
	else
		ft_printf("	FAIL: map.fdfa\n");
	// map.fdg
	if (is_valid_extension("map.fdg") == 0)
		ft_printf("	PASS: map.fdg\n");
	else
		ft_printf("	FAIL: map.fdg\n");
	// map.FDF
	if (is_valid_extension("map.FDF") == 0)
		ft_printf("	PASS: map.FDF\n");
	else
		ft_printf("	FAIL: map.FDF\n");
	// map fdf
	if (is_valid_extension("map fdf") == 0)
		ft_printf("	PASS: map fdf\n");
	else
		ft_printf("	FAIL: map fdf\n");
	// .fdf
	if (is_valid_extension(".fdf") == 0)
		ft_printf("	PASS: .fdf\n");
	else
		ft_printf("	FAIL: .fdf\n");
	// a.f
	if (is_valid_extension("a.f") == 0)
		ft_printf("	PASS: a.f\n");
	else
		ft_printf("	FAIL: a.f\n");
	// map
	if (is_valid_extension("map") == 0)
		ft_printf("	PASS: map\n");
	else
		ft_printf("	FAIL: map\n");
	// ""
	if (is_valid_extension("") == 0)
		ft_printf("	PASS: """"\n");
	else
		ft_printf("	FAIL: """"\n");
}

void	test_map_dimensions(void)
{
	t_map	test_map;

	test_map.height = 0;
	test_map.width = 0;

	ft_printf("\n--- Testing Map Dimensions ---\n");

	get_map_dimensions("maps/42.fdf", &test_map);

	ft_printf("Result -> Width: %d | Height: %d\n", test_map.width, test_map.height);

	if (test_map.width > 0 && test_map.height > 0)
		ft_printf(" PASS: Dimensions read successfully.\n");
	else
		ft_printf(" FAIL: Width or Height is 0.\n");
}
