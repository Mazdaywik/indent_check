import queue
import re

from utils import print_errors


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

    if not line.strip() or line.strip().startswith('//'):
        key_list.append('EMPTY')
        # print(key_list)
        return key_list
    elements = queue.PriorityQueue()

    comment = line.rfind('//')
    if comment != -1:
        line = line[:comment]
    if len(line.strip()) > 1 and ';' == line.strip()[-1]:
        elements.put((99999, ';'))
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

    # print(key_list)
    return key_list


def filter_lines(lines):
    indexes = []
    pattern = r"=(\w|\s)*{"
    for i, line in enumerate(lines):
        if re.search(pattern, line):
            indexes.append(i)

    for index in indexes:
        lines[index] = lines[index].replace('{', 'x')
        flag = 1
        current_index = index
        while flag:
            if '}' in lines[current_index]:
                flag = 0
                lines[current_index] = lines[current_index].replace('}', 'same')
            else:
                lines[current_index] = lines[current_index].replace(';', '')
            current_index += 1
    return lines


def get_matrix(file_path, indent_size):
    with open(file_path, 'r') as file:
        lines = []
        for line in file:
            lines.append(line)
        indent_matrix = []
        lines = filter_lines(lines)
        for line in lines:
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
    sing_statement_offset = [0, 0]
    errors = []
    skip = False

    flag = 0

    for number, line in enumerate(matrix, start=1):
        if 'EMPTY' in line or skip:
            if skip:
                skip = ';' != line[-1]
            continue

        open_exist = '{' in line
        close_exist = '}' in line
        statement_exist = 'for' in line or 'if' in line or 'while' in line or 'else' in line

        if len(sing_statement_offset) == 0:
            sing_statement_offset = [0]

        if style == 'kernel':
            if close_exist:
                if len(sing_statement_offset) >= 1 and flag != number - 1:
                    sing_statement_offset.pop()
                indent_level -= 1
                errors = check_indent(line, indent_level + sum(sing_statement_offset), number, errors)
            if open_exist:
                if next_level_plus:
                    next_level_plus = False
                errors = check_indent(line, indent_level + sum(sing_statement_offset), number, errors)
                sing_statement_offset.append(0)
                indent_level += 1
            if statement_exist and ';' != line[-1] and not open_exist and not close_exist:
                next_level_plus = True
                errors = check_indent(line, indent_level + sum(sing_statement_offset), number, errors)
                sing_statement_offset[-1] += 1
            if not open_exist and not close_exist and (not statement_exist or not ';' != line[-1]):
                if ';' != line[-1] and indent_level > 0:
                    skip = True
                if next_level_plus:
                    errors = check_indent(line, indent_level + sum(sing_statement_offset), number, errors)
                    next_level_plus = False
                    if len(sing_statement_offset) >= 1:
                        flag = number
                        sing_statement_offset.pop()
                else:
                    errors = check_indent(line, indent_level + sum(sing_statement_offset), number, errors)

        elif style == 'gnu':
            if next_level_plus and not open_exist and not close_exist:
                sing_statement_offset[-1] += 1

            if open_exist:
                sing_statement_offset.append(0)
                if next_level_plus:
                    next_level_plus = False
                errors = check_indent(line, indent_level + sum(sing_statement_offset) + 1,
                                      number, errors)
                indent_level += 2
            elif close_exist:
                indent_level -= 2
                if len(sing_statement_offset) >= 1 and flag != number - 1:
                    sing_statement_offset.pop()
                errors = check_indent(line, indent_level + sum(sing_statement_offset) + 1,
                                      number, errors)
            elif statement_exist and ';' != line[-1]:
                next_level_plus = True
                errors = check_indent(line, indent_level + sum(sing_statement_offset),
                                      number, errors)
            else:
                if next_level_plus:
                    errors = check_indent(line,
                                          indent_level + sum(sing_statement_offset),
                                          number, errors)
                    next_level_plus = False
                    if len(sing_statement_offset) >= 1:
                        flag = number
                        sing_statement_offset.pop()
                else:
                    errors = check_indent(line, indent_level, number, errors)

        elif style == 'allman':
            if next_level_plus and not open_exist and not close_exist:
                sing_statement_offset[-1] += 1

            if open_exist:
                sing_statement_offset.append(0)
                if next_level_plus:
                    next_level_plus = False
                errors = check_indent(line, indent_level + sum(sing_statement_offset),
                                      number, errors)
                indent_level += 1
            elif close_exist:
                indent_level -= 1
                if len(sing_statement_offset) >= 1 and flag != number - 1:
                    sing_statement_offset.pop()
                errors = check_indent(line, indent_level + sum(sing_statement_offset),
                                      number, errors)
            elif statement_exist and ';' != line[-1]:
                next_level_plus = True
                errors = check_indent(line, indent_level + sum(sing_statement_offset),
                                      number, errors)
            else:
                if next_level_plus:
                    errors = check_indent(line,
                                          indent_level + sum(sing_statement_offset),
                                          number, errors)
                    next_level_plus = False
                    if len(sing_statement_offset) >= 1:
                        flag = number
                        sing_statement_offset.pop()
                else:
                    errors = check_indent(line, indent_level, number, errors)

    print_errors(errors)


