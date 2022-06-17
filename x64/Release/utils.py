import re
import string
import collections


FILENAME = "Input.txt"


def DoubleValue(v: int):
    ''' Double the input value '''
    return 2 * v


def MultiplicationTable(x: int):
    ''' Print a multiplication table from 1 to 10 for the input '''
    for i in range(10):
        print(f'{x} x {i+1} = {x*(i+1)}')


def get_counter(filename: str):
    '''Returns an OrderedDict object with the words as the keys'''
    fid = open(filename, "r")
    data = fid.read()
    fid.close()
    counter = collections.Counter(data.split())
    counter = collections.OrderedDict(sorted(counter.items()))
    return counter


def write_counter(filename: str, c):
    '''Writes the counter object to a file'''
    fod = open(filename, "w")
    for word in c:
        fod.write(f'{word} {c[word]}\n')
    fod.close()


def print_counter(c):
    '''Prints the counter object to the screen, and then prints a list of keys and value'''
    print(c)
    print('\n')
    for word in c:
        print(f'{word}: {c[word]}')


def get_count(c, token: str):
    '''Returns the count from the orderedDict c for token'''
    token = token.capitalize()
    if token in c:
        return c[token]
    else:
        return 0


def get_total_items(c):
    '''Returns the total items in the orderedDict c'''
    sum = 0
    for word in c:
        sum += c[word]
    return sum


def get_freq(c, token: str):
    '''Returns the frequency (as a percentage) of token in orderedDict c'''
    num_token = get_count(c, token)
    total_items = get_total_items(c)
    return 100.0*num_token/total_items


def full_get_count(token: str):
    '''get_count suitable for calling from C++ (populates OrderedDict from FILENAME)'''
    c = get_counter(FILENAME)
    return get_count(c, token)


def full_get_freq(token: str):
    '''get_freq suitable for calling from C++ (populates OrderedDict from FILENAME)'''
    c = get_counter(FILENAME)
    return get_freq(c, token)


def full_write_counter():
    '''write_counter suitable for calling from C++ (populates OrderedDict from FILENAME)'''
    c = get_counter(FILENAME)
    write_counter("frequency.dat", c)


def full_print_list():
    '''Prints the full list suitable for calling from C++'''
    c = get_counter(FILENAME)
    for word in c:
        print(f'{word}: {c[word]}')
