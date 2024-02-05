import sys
import subprocess


def print_errors(errors):
    if len(errors) > 0:
        for error in errors:
            print(error)
        sys.exit(1)


def most_common(lst):
    return max(set(lst), key=lst.count)

def count_chars_for_indent(line):
    size_indent = 0
    if line.strip() and line[0] == ' ':
        for char in line:
            if char == ' ':
                size_indent += 1
            else:
                print("Размер отступа: " + str(size_indent) + " whitespaces")
                return size_indent
    elif line.strip() and line[0] == '\t':
        for char in line:
            if char == '\t':
                size_indent -= 1  # для табуляции используем отрицательные значения
            else:
                print("Размер отступа: " + str(size_indent * (-1)) + " tab")
                return size_indent

