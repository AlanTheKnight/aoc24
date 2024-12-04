with open("inputs/4.txt") as f:
    lines = f.readlines()


def is_valid(y, x):
    return 0 <= y < len(lines) and 0 <= x < len(lines[y])


def process_variant(variant):
    word = ""
    for y, x in variant:
        if not is_valid(y, x):
            return False
        word += lines[y][x]
    if word == "XMAS":
        return True
    return False


def get_variants(y, x):
    return [
        # Vertical
        ((y, x), (y + 1, x), (y + 2, x), (y + 3, x)),
        ((y, x), (y - 1, x), (y - 2, x), (y - 3, x)),
        # Horizontal
        ((y, x), (y, x + 1), (y, x + 2), (y, x + 3)),
        ((y, x), (y, x - 1), (y, x - 2), (y, x - 3)),
        # Diagonal
        ((y, x), (y + 1, x + 1), (y + 2, x + 2), (y + 3, x + 3)),
        ((y, x), (y - 1, x - 1), (y - 2, x - 2), (y - 3, x - 3)),
        ((y, x), (y + 1, x - 1), (y + 2, x - 2), (y + 3, x - 3)),
        ((y, x), (y - 1, x + 1), (y - 2, x + 2), (y - 3, x + 3)),
    ]


ans = 0

for y in range(len(lines)):
    for x in range(len(lines[0])):
        for variant in get_variants(y, x):
            if process_variant(variant):
                ans += 1

print(ans)
