import itertools
for password in itertools.product(itertools.product('[a-zA-Z0-9]+', repeat=5)):
    print(password)