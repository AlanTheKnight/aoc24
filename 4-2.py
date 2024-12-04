with open("inputs/4.txt") as f:
    lines = f.readlines()


def is_valid(y, x):
    return 0 <= y < len(lines) and 0 <= x < len(lines[y])


def process_variants(variants):
    for variant in variants:
        for y, x in variant:
            if not is_valid(y, x):
                return False

    word1 = "".join(map(lambda a: lines[a[0]][a[1]], variants[0]))
    word2 = "".join(map(lambda a: lines[a[0]][a[1]], variants[1]))

    if word1 in ("MAS", "SAM") and word2 in ("MAS", "SAM"):
        return True

    return False


def get_variants(y, x):
    return [
        ((y - 1, x - 1), (y, x), (y + 1, x + 1)),
        ((y - 1, x + 1), (y, x), (y + 1, x - 1)),
    ]


ans = 0

for y in range(len(lines)):
    for x in range(len(lines[0])):
        if is_valid(y, x) and lines[y][x] == "A":
            variants = get_variants(y, x)
            if process_variants(variants):
                ans += 1

print(ans)
