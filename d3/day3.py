import re

def sum_enabled_mul(filepath):
    # Regular expressions for matching
    mul_pattern = r"mul\((\d{1,3}),(\d{1,3})\)"
    do_pattern = r"do\(\)"
    dont_pattern = r"don't\(\)"

    enabled = True  # Initial state
    total_sum = 0  # Sum of products

    # Read the file content
    with open(filepath, "r") as file:
        data = file.read()

    # Split the data into tokens based on the patterns
    tokens = re.split(r"(mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\))", data)

    # Process each token
    for token in tokens:
        token = token.strip()
        if re.fullmatch(mul_pattern, token):  # If it's a valid `mul`
            if enabled:
                # Extract X and Y, and calculate their product
                x, y = map(int, re.findall(r"\d+", token))
                total_sum += x * y
        elif re.fullmatch(do_pattern, token):  # If it's a `do()` instruction
            enabled = True
        elif re.fullmatch(dont_pattern, token):  # If it's a `don't()` instruction
            enabled = False

    return total_sum

# File path
file_path = "input.txt"

# Run the function on the uploaded file
enabled_mul_sum = sum_enabled_mul(file_path)
print(enabled_mul_sum)
