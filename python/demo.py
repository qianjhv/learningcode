# import this

arr = [i ** 3 for i in range(0, 10)]
arr.pop()
arr.append('hello')
print(arr)
print(arr[::-1])

d = {'a': 1, 'b': 2, 'c': 3}
print(d)

print(range(10))
print(list(range(10, 20, 2)))

d = {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5}
for key, value in d.items():
    print(f'key: {key}, value: {value}')


# message = input("Tell me something, and I will repeat it back to you: ")
# print(message)

word = 'hello'
# word[0] = 'm'     # strings are immutable
'm' + word[1:]

def fct(b, c, a = 1, *args, **kwargs):
    return a + b

def fct2(*tuples):
    return tuples

try:
    1 / 0
except ZeroDivisionError as e:
    print(e)