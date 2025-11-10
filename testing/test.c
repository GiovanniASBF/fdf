#include "fdf.h"

void	test_valid_extensions(void);
void	test_invalid_extensions(void);

int	main(void)
{
	// parsing
	test_valid_extensions();
	test_invalid_extensions();
	return (0);
}

void	test_valid_extensions(void)
{
	ft_printf("Testing valid extensions.\n");
	// map.fdf
	if (is_invalid_extension("map.fdf") == 0)
		ft_printf("	PASS: map.fdf\n");
	else
		ft_printf("  FAIL: map.fdf\n");
	// a.fdf
	if (is_invalid_extension("a.fdf") == 0)
		ft_printf("	PASS: a.fdf\n");
	else
		ft_printf("	FAIL: a.fdf\n");
	// folder/map.fdf
	if (is_invalid_extension("folder/map.fdf") == 0)
		ft_printf("	PASS: folder/map.fdf\n");
	else
		ft_printf("	FAIL: folder/map.fdf\n");
	// another.map.fdf
	if (is_invalid_extension("another.map.fdf") == 0)
		ft_printf("	PASS: another.map.fdf\n");
	else
		ft_printf("	FAIL: another.map.fdf\n");
}

void	test_invalid_extensions(void)
{
	ft_printf("Testing invalid extensions.\n");
	// map.txt
	if (is_invalid_extension("map.txt") == 1)
		ft_printf("	PASS: map.txt\n");
	else
		ft_printf("	FAIL: map.txt\n");
	// map.fdfa
	if (is_invalid_extension("map.fdfa") == 1)
		ft_printf("	PASS: map.fdfa\n");
	else
		ft_printf("	FAIL: map.fdfa\n");
	// map.fdg
	if (is_invalid_extension("map.fdg") == 1)
		ft_printf("	PASS: map.fdg\n");
	else
		ft_printf("	FAIL: map.fdg\n");
	// map.FDF
	if (is_invalid_extension("map.FDF") == 1)
		ft_printf("	PASS: map.FDF\n");
	else
		ft_printf("	FAIL: map.FDF\n");
	// map fdf
	if (is_invalid_extension("map fdf") == 1)
		ft_printf("	PASS: map fdf\n");
	else
		ft_printf("	FAIL: map fdf\n");
	// .fdf
	if (is_invalid_extension(".fdf") == 1)
		ft_printf("	PASS: .fdf\n");
	else
		ft_printf("	FAIL: .fdf\n");
	// a.f
	if (is_invalid_extension("a.f") == 1)
		ft_printf("	PASS: a.f\n");
	else
		ft_printf("	FAIL: a.f\n");
	// map
	if (is_invalid_extension("map") == 1)
		ft_printf("	PASS: map\n");
	else
		ft_printf("	FAIL: map\n");
	// ""
	if (is_invalid_extension("") == 1)
		ft_printf("	PASS: """"\n");
	else
		ft_printf("	FAIL: """"\n");
}
