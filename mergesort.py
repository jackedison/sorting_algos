def mergesort_lists(list_a, list_b):

    result = []
    ele_a = ele_b = 0  # Starting elements of list
    len_a, len_b = len(list_a), len(list_b)  # Lengths of lists for efficiency

    # Loop through lists comparing until one is finished
    while ele_a < len_a and ele_b < len_b:
        if list_a[ele_a] <= list_b[ele_b]:
            result.append(list_a[ele_a])
            ele_a += 1
        else:
            result.append(list_b[ele_b])
            ele_b += 1

    # Return result + remainder of sorted list which hasn't been finished
    return result + list_b[ele_b:] + list_a[ele_a:]

def mergesort(my_list):
    '''Takes in two sorted lists and merges them
    Merging lists takes O(n) time
    Number of merges needed is O(log(n))'''
    # Convert all eles into list of their own for first iteration
    my_list = [[ele] for ele in my_list]

    while len(my_list) > 1:
        next_list = []
        # Loop through list by twos and mergesort
        for i in range(0, len(my_list)-1, 2):
            next_list.append(mergesort_lists(my_list[i], my_list[i+1]))

        # If len of list is odd then add final list that wasn't mergesorted
        if len(my_list) % 2 != 0:
            next_list.append(my_list[-1])

        # Set new list and loop again
        my_list = next_list

    return my_list[0]


if __name__ == "__main__":
    import random

    test_list = random.sample(range(-100, 100), 50)

    assert mergesort(test_list) == sorted(test_list)

    print(mergesort(test_list))

