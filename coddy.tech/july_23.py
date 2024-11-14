""" Escape rooms have become a popular way to test your wits against puzzles and challenges. In this escape room, you face a numeric combination lock. Your goal is to input the correct combination and escape! The lock has a numeric keypad with 4 specific digits. The combination is a sequence of the four digits, for example, 1234. You know the combination contains 4 digits, but you don't know the correct order. You have a piece of paper with three hints, like this:

0 is in position 3

2 is in position 1

4 is not in position 2

Write a function escape(hints, digits) that takes a list of three hints and a list of possible digits as input and returns the correct four-digit combination.

--> TEST CASES

["0 is in position 3", "2 is not in position 1", "4 is in position 2"]
[0,2,4,6]

["0 is not in position 1", "9 is in position 3", "1 is in position 4"]
[1,0,3,9]

["7 is in position 1", "1 is in position 2", "3 is not in position 3"]
[7,1,3,5]

["7 is not in position 4", "5 is in position 1", "9 is in position 3"]
[5,7,2,9]

["2 is in position 2", "3 is not in position 1", "1 is in position 3"]
[4,3,2,1]

["8 is in position 3", "6 is not in position 1", "9 is in position 4"]
[9,5,8,6]
"""


def escape(hints, digits):
    # Write code here
    copy_digits = digits.copy()
    # hints = sorted(hints,key=len)
    index = dict()
    for hint in hints:
        if("not" in hint):
            index[int(hint[0])] = -int(hint[-1])
            digits.remove(int(hint[0]))
            
        else:
            index[int(hint[0])] = int(hint[-1])
            digits.remove(int(hint[0]))

    for i in index.items():

        if i[1] > 0:
            copy_digits[i[1]] = i[0]
        
        else:
            pass
