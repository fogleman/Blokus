PIECES = [
    ('1', ['x']),
    ('2', ['xx']),
    ('F', ['x..', 'xxx', '.x.']),
    ('I3', ['xxx']),
    ('I4', ['xxxx']),
    ('I5', ['xxxxx']),
    ('L4', ['xxx', 'x..']),
    ('L5', ['xxxx', 'x...']),
    ('N', ['xxx.', '..xx']),
    ('O', ['xx', 'xx']),
    ('P', ['xxx', 'xx.']),
    ('T4', ['xxx', '.x.']),
    ('T5', ['xxx', '.x.', '.x.']),
    ('U', ['xx', 'x.', 'xx']),
    ('V3', ['xx', 'x.']),
    ('V5', ['xxx', 'x..', 'x..']),
    ('W', ['x..', 'xx.', '.xx']),
    ('X', ['.x.', 'xxx', '.x.']),
    ('Y', ['xxxx', '.x..']),
    ('Z4', ['xx.', '.xx']),
    ('Z5', ['x..', 'xxx', '..x']),
]

def rotate(data, n=1):
    for i in range(n):
        data = [''.join(x) for x in zip(*data[::-1])]
    return data

def mirror(data):
    return [''.join(reversed(x)) for x in data]

def rotations(data):
    result = set()
    for i in range(4):
        result.add(tuple(rotate(data, i)))
        result.add(tuple(mirror(rotate(data, i))))
    return sorted(result)

def to_array(data):
    result = [[0] * 7 for _ in range(7)]
    for y, row in enumerate(data):
        for x, c in enumerate(row):
            if c != 'x':
                continue
            i, j = x + 1, y + 1
            result[j - 1][i - 1] = 3
            result[j - 1][i + 1] = 3
            result[j + 1][i - 1] = 3
            result[j + 1][i + 1] = 3
    for y, row in enumerate(data):
        for x, c in enumerate(row):
            if c != 'x':
                continue
            i, j = x + 1, y + 1
            result[j - 1][i] = 2
            result[j + 1][i] = 2
            result[j][i - 1] = 2
            result[j][i + 1] = 2
    for y, row in enumerate(data):
        for x, c in enumerate(row):
            if c != 'x':
                continue
            i, j = x + 1, y + 1
            result[j][i] = 1
    return result

def main():
    for i, (name, piece) in enumerate(PIECES):
        for j, data in enumerate(rotations(piece)):
            w, h = len(data[0]), len(data)
            a = to_array(data)
            line = '%d, %d, %d, %d, "%s", %r' % (i, j, w, h, name, a)
            line = line.replace('[', '{')
            line = line.replace(']', '}')
            print line

if __name__ == '__main__':
    main()
