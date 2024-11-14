
# data = input("Enter the data : ")

vowels = ['a','e','i','o','u','A','E','I','O','U']
# count = 0
# for ch in data:
#     if ch in vowels:
#         count = count+1

# print('Number of vowels in the sentence is : ',count)

# ---> Count the no. of vowels in each line of a file

f = open('interview/strings.txt','r')

for line in f:
    count = 0
    for character in line:
        if character in vowels:
            count = count + 1
    print('The no. of vowels in the line are : ', count)
    count = 0