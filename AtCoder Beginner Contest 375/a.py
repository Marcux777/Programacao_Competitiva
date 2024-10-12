def count_palindromic_triples(S):
    from collections import defaultdict

    N = len(S)
    char_positions = defaultdict(list)

    # Step 1: Group positions by characters
    for idx, char in enumerate(S):
        char_positions[char].append(idx + 1)  # Positions are 1-based

    total_triples = 0

    # Step 2: Calculate triples for each character group
    for char, positions in char_positions.items():
        m = len(positions)
        if m < 2:
            continue  # Need at least two positions to form a pair (i, k)

        # Iterate through all pairs (i, k) and count valid j in between
        for i in range(m):
            for k in range(i + 1, m):
                # The valid middle j is between positions[i] and positions[k]
                total_triples += positions[k] - positions[i] - 1

    return total_triples


# Example Usage
if __name__ == "__main__":
    import sys

    # Read input string
    S = sys.stdin.read().strip()

    # Compute the number of valid triples
    result = count_palindromic_triples(S)

    # Output the result
    print(result)
