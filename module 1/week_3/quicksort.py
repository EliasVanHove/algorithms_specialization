import numpy as np
import math

def sort_tuples(l):
    return sorted(l, key = lambda x:x[0])

def get_upper_lower_list(l, i, j):
    if i>0:
        lower_list = l[0:i]
    else:
        lower_list = []

    if j>i:
        upper_list = l[i+1:j+1]
    else:
        upper_list = []

    return lower_list, upper_list

def choose_pivot_and_swap(l, first=True, last=False, median=False):
    if first + last + median ==0:
        raise ValueError("please select a pivot rule!")
    elif first + last + median > 1:
        raise ValueError("only select one pivot rule!")

    elif first:
        return l

    elif last:
        l[0], l[-1] =  l[-1], l[0]
        return l

    elif median:
        middle, middle_index = l[math.ceil(len(l)/2)-1], math.ceil(len(l)/2)-1
        first_element, first_element_index = l[0], 0
        last_element, last_element_index = l[-1], -1
        tuple_list= [(middle, middle_index), (first_element, first_element_index), (last_element, last_element_index)]
        sorted_tuples = sort_tuples(tuple_list)
        pivot_element = sorted_tuples[1][1]
        l[0], l[pivot_element] = l[pivot_element], l[0]
        return l


def partition_list(l):
    i, j = 0, 0
    for k in range(1, len(l)):
        if i==j:
            if l[k]>l[0]:
                j+=1
            elif l[k]<l[0]:
                i+=1
                j+=1
        elif j>i:
            if l[k]>l[0]:
                j+=1
            elif l[k]<l[0]:
                l[i+1], l[k] = l[k], l[i+1]
                i+=1
                j+=1
    return l, i, j

def Quicksort(l):
    if len(l)==0:
        return l, 0 
    l=choose_pivot_and_swap(l, first=False, last=False, median=True)
    l,i,j = partition_list(l)
    l[0], l[i] = l[i], l[0]
    lower_list, upper_list = get_upper_lower_list(l, i, j)

    sorted_lower_list, comparisons_lower = Quicksort(lower_list)
    sorter_upper_list, comparisons_upper = Quicksort(upper_list)

    return sorted_lower_list + [l[0]] + sorter_upper_list, comparisons_lower + comparisons_upper + len(l) - 1

    

if __name__ == "__main__":
    integers = []
    with open("QuickSort.txt") as infile:
        for line in infile:
            line_integer = line.split(' ')
            integers.append(int(line_integer[0]))
    test_tuples = [(10,2),(6,0),(8,1)]
    print(sort_tuples(test_tuples)[1][1])

    test_partition = [8,10]
    print(partition_list(test_partition))

    test_partition = [8,6]
    print(partition_list(test_partition))

    test_partition = [8]
    print(partition_list(test_partition))

    test_partition = [3,6,4,1,8,2]
    print(partition_list(test_partition))

    test_partition = [3,0,4,1,8,2]
    print(partition_list(test_partition))

    test_quicksort = [2,4,1,0,3]
    print(Quicksort(test_quicksort))

    sorted_list, comparisons = Quicksort(integers)
    print(comparisons)