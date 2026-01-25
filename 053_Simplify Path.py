"""
Simplify Path

Simplify an absolute Unix-style path.
"""

def simplify_path(path: str) -> str:
    parts = []
    for token in path.split('/'):
        if not token or token == '.':
            continue
        if token == '..':
            if parts: parts.pop()
        else:
            parts.append(token)
    return '/' + '/'.join(parts)


if __name__ == '__main__':
    print('Simplify 1:', simplify_path('/home/'))
    print('Simplify 2:', simplify_path('/a/./b/../../c/'))
    print('Simplify 3:', simplify_path('/../'))

# Time Complexity: O(n)
# Space Complexity: O(n)
