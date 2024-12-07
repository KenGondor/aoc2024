def count_x_mas_in_file(filename):
    # Read the file content and parse the grid
    with open(filename, "r") as file:
        grid = [list(line.strip()) for line in file.readlines()]

    rows, cols = len(grid), len(grid[0])

    # Define all valid MAS patterns
    patterns = [
        ("MAS", "MAS"),  # diagonal down MAS, diagonal up MAS
        ("MAS", "SAM"),  # diagonal down MAS, bottom-right SAM
        ("SAM", "MAS"),  # Upper-left SAM, bottom-right MAS
        ("SAM", "SAM"),  # Upper-left SAM, bottom-right SAM
    ]

    count = 0

    # Helper function to check if a 3x3 region matches an X-MAS pattern
    def is_x_mas(x, y, upper_left, bottom_right):
        try:
            return (
                (grid[x][y] == upper_left[0] and grid[x + 2][y ] == bottom_right[0]) and  # Diagonal: M
                (grid[x + 1][y + 1] == upper_left[1] and grid[x + 1][y + 1] == bottom_right[1]) and  # Center: A
                (grid[x + 2][y + 2] == upper_left[2] and grid[x][y + 2] == bottom_right[2])  # Diagonal: S
            )
        except IndexError:
            return False

    # Scan every 3x3 region of the grid
    for i in range(rows - 2):
        for j in range(cols - 2):
            for upper_left, bottom_right in patterns:
                if is_x_mas(i, j, upper_left, bottom_right):
                    count += 1

    return count


# File location
filename = "input.txt"

# Count all occurrences of X-MAS
result = count_x_mas_in_file(filename)
print(result)
