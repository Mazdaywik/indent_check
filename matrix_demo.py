import queue
from utils import print_errors

def error_array(line):
    start_index = line.index('{')
    end_index = line.index('}')
    end_end_index = line.index(';')
    if start_index < end_index and end_end_index - end_index == 1:
        new_line = line[:start_index] + line[start_index + 1:end_index] + \
                                        line[end_end_index + 1:]
        return new_line
    return line

def get_level_indent_in_line(line, indent_size):
    indent_level = 0
    indent = None

    if indent_size > 0:
        indent = ' ' * indent_size
    elif indent_size < 0:
        indent = '\t' * abs(indent_size)

    while line.startswith(indent):
        indent_level += 1
        line = line[len(indent):]

    return indent_level


def get_line_key_elements(line, indent_size):
    key_list = []
    key_elements = [
        '{',
        '}',
        'if',
        'else',
        'while',
        'for',
        'switch',
    ]

    if not line.strip():
        key_list.append('EMPTY')
        print(key_list)
        return key_list
    else:
        if '{' in line and '};' in line:
            line = error_array(line)
        elements = queue.PriorityQueue()
        for element in key_elements:
            try:
                index = line.index(element)
                elements.put((index, element))
            except ValueError:
                pass

        indent_level = get_level_indent_in_line(line, indent_size)
        key_list.append(f'INDENT_ELEMENT_{indent_level}')
        while not elements.empty():
            key_list.append(elements.get()[1])

        print(key_list)
        return key_list


def get_matrix(file_path, indent_size):
    with open(file_path, 'r') as file:
        indent_matrix = []
        for line in file:
            indent_matrix.append(get_line_key_elements(line, indent_size))
    return indent_matrix


def check_indent_matrix(file_path, indent_size, style):

    def check_indent(line, indent_level, number, errors):
        if not f"INDENT_ELEMENT_{indent_level}" in line:
            errors.append(
                f"Строка {number}: неправильный отступ. Ожидался отступ уровня {indent_level}")
        return errors


    matrix = get_matrix(file_path, indent_size)
    next_level_plus = False
    indent_level = 0
    sing_statement_offset = [0]
    errors = []

    for number, line in enumerate(matrix, start=1):
        if 'EMPTY' in line:
            continue
        else:
            open_exist = '{' in line
            close_exist = '}' in line
            statement_exist = 'for' in line or 'if' in line or 'while' in line or 'else' in line

            if style == 'kernel':
                if next_level_plus:
                    sing_statement_offset[len(sing_statement_offset) - 1] += 1
                else:
                    sing_statement_offset[len(sing_statement_offset) - 1] = 0

                if open_exist:
                    errors = check_indent(line, indent_level + sing_statement_offset[len(sing_statement_offset) - 1], number, errors)
                    if next_level_plus:
                        sing_statement_offset.append(sing_statement_offset[len(sing_statement_offset) - 1] - 1)
                    indent_level += 1
                elif close_exist:
                    if len(sing_statement_offset) > 1:
                        sing_statement_offset.pop()
                    indent_level -= 1
                    errors = check_indent(line, indent_level + sing_statement_offset[len(sing_statement_offset) - 1], number, errors)
                elif statement_exist:
                    next_level_plus = True
                    errors = check_indent(line, indent_level + sing_statement_offset[len(sing_statement_offset) - 1], number, errors)
                else:
                    if next_level_plus:
                        errors = check_indent(line, indent_level + sing_statement_offset[len(sing_statement_offset) - 1], number, errors)
                        next_level_plus = False
                    else:
                        errors = check_indent(line, indent_level, number, errors)

            elif style == 'gnu':
                pass
            elif style == 'allman':
                pass

    print(errors)


