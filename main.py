#!/bin/bash

def create_empty_2D_array(rows, cols):
    output = []
    for i in range(rows):
        temp = []
        for j in range(cols):
            temp.append(' ')
        output.append(temp)
    return output

def read_file(rows, cols, file):
    output = create_empty_2D_array(rows, cols)
    for i in range(rows):
        singular_row_string = file.readline()
        cur_col = 0
        for char in singular_row_string:
            if char != ' ' and char != '\n':
                output[i][cur_col] = char
                cur_col += 1
    return output

def display_2D_array(rows, cols, array):
    for i in range(rows):
        for j in range(cols):
            print(array[i][j], end = ' ')
        print()

def rotate_2D(rows, cols, original):
    output = create_empty_2D_array(cols, rows)
    for i in range(rows):
        for j in range(cols):
            output[j][rows - i - 1] = original[i][j]
    return output

def main():
    original_rows = 3
    original_cols = 7

    input_file = open("input.txt", "r")
    original_array2D = read_file(original_rows, original_cols, input_file)
    input_file.close()

    print("Original 2D Array")
    display_2D_array(original_rows, original_cols, original_array2D)
    print()
    
    print("Rotated 2D Array")
    rotated_array2D = rotate_2D(original_rows, original_cols, original_array2D)
    display_2D_array(original_cols, original_rows, rotated_array2D)
    print()

if __name__ == "__main__":
    main()