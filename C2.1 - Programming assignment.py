import re
if_name_

sample_file = open('A.2.2 - regex text data.txt')

text = sample_file.read()
number_regex = '[0-9]+'
numbers = re.findall(number_regex, text) 
total = sum(int(num) for num in numbers)

print(total)
sample_file.close()