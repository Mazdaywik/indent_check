import queue
from utils import print_errors


def get_level_indent_in_line(line, size_indent):
    indent_level = 0
    indent = None

    if size_indent > 0:
        indent = ' ' * size_indent
    elif size_indent < 0:
        indent = '\t' * abs(size_indent)

    while line.startswith(indent):
        indent_level += 1
        line = line[len(indent):]

    return indent_level


def get_line_key_elements(line, indent_size):
    key_elements = [
        ['{', 'OPEN'],
        ['}', 'CLOSE'],
        ['if', 'IF'],
        ['while', 'WHILE'],
        ['for', 'FOR'],
    ]
    elements = queue.PriorityQueue()

    for element in key_elements:
        try:
            index = line.index(element[0])
            elements.put((index, element[0]))
        except ValueError:
            pass

    line_indent = get_level_indent_in_line(line, indent_size)

    sorted_list = [f'INDENT_ELEMENT_{line_indent}']
    while not elements.empty():
        sorted_list.append(elements.get()[1])

    print(sorted_list)

    return sorted_list


def get_matrix(file_path, indent_size):
    with open(file_path, 'r') as file:
        lines_key_elements_matrix = []
        # file_lines = file.readlines()
        for line in file:
            if not line.strip():
                lines_key_elements_matrix.append(['EMPTY'])
            else:
                lines_key_elements_matrix.append(get_line_key_elements(line, indent_size))
        return lines_key_elements_matrix


def get_indent_name(size):
    return f"INDENT_ELEMENT_{size}"


def check_indent_matrix(file_path, indent_size, style):
    matrix = get_matrix(file_path, indent_size)

    current_level = 0
    errors = []
    next_level_maybe = False
    single_statements_offset = 0

    for i, line in enumerate(matrix):
        closeExist = '}' in line
        openExist = '{' in line
        index = i + 1
        if 'EMPTY' in line:
            continue

        is_statement = 'for' in line or 'if' in line or 'while' in line
        if not next_level_maybe:
            single_statements_offset = 0
        level = current_level + single_statements_offset

        if style == 'allman':
            if openExist:
                level -= single_statements_offset
                single_statements_offset = 0
                if not f"INDENT_ELEMENT_{level}" in line:
                    errors.append(f"Строка {index}, неправильный отступ перед открывающейся фигурной скобкой. Ожидался отступ уровня - {current_level}")
            if closeExist:
                level -= single_statements_offset
                single_statements_offset = 0
                if not f"INDENT_ELEMENT_{level - 1}" in line:
                    errors.append(f"Строка {index}, неправильный отступ перед закрывающейся фигурной скобкой. Ожидался отступ уровня - {current_level - 1}")
            if not openExist and not closeExist:
                if level != 0 and (line[0] != get_indent_name(level) and (line[0] != get_indent_name(level + 1)) if next_level_maybe else line[0] != get_indent_name(level)):
                    errors.append(f"Строка {index}, неправильный отступ. Ожидался отступ уровня - {level}")
            if openExist:
                current_level += 1
            if closeExist:
                current_level -= 1

            next_level_maybe = False
            if is_statement:
                next_level_maybe = True
                single_statements_offset += 1

        if style == 'gnu':
            if closeExist:
                level -= single_statements_offset
                single_statements_offset = 0
                if not f"INDENT_ELEMENT_{level - 1}" in line:
                    errors.append(f"Строка {index}, неправильный отступ перед закрывающейся фигурной скобкой. Ожидался отступ уровня - {current_level - 1}")
            if openExist:

                if not f"INDENT_ELEMENT_{level + 1}" in line:
                    errors.append(f"Строка {index}, неправильный отступ перед открывающейся фигурной скобкой. Ожидался отступ уровня - {current_level}")
            if not openExist and not closeExist:
                if current_level != 0 and ((line[0] != get_indent_name(level) and line[0] != get_indent_name(level + 1)) if next_level_maybe else line[0] != get_indent_name(level)):
                    errors.append(f"Строка {index}, неправильный отступ. Ожидался отступ уровня - {level}")
            if '{' in line:
                current_level += 2
            if '}' in line:
                current_level -= 2

            next_level_maybe = False
            if is_statement:
                next_level_maybe = True
                single_statements_offset += 1

        if style == 'kernel':
            if closeExist:
                if not f"INDENT_ELEMENT_{level - 1}" in line:
                    errors.append(f"Строка {index}, неправильный отступ перед закрывающейся фигурной скобкой. Ожидался отступ уровня - {current_level - 1}")
            else:
                if current_level != 0 and (line[0] != get_indent_name(level) and (line[0] != get_indent_name(level + 1)) if next_level_maybe else line[0] != get_indent_name(level)):
                    errors.append(f"Строка {index}, неправильный отступ. Ожидался отступ уровня - {level}")
            if openExist:
                current_level += 1
            if closeExist:
                current_level -= 1

            next_level_maybe = False
            if is_statement and not openExist:
                next_level_maybe = True
                single_statements_offset += 1

    print_errors(errors)


