from utils import print_errors, most_common, count_chars_for_indent


def find_first_indented_line(file_path, size_indent, style_indent):
    with open(file_path, 'r') as file:
        access_to_get_size = False
        for line in file:
            if access_to_get_size and line.strip() and (line[0] == ' ' or line[0] == '\t'):
                size_indent = count_chars_for_indent(line)
                return size_indent
            elif "{" in line:
                if style_indent == 'gnu' and line.strip():
                    size_indent = count_chars_for_indent(line)
                    return size_indent
                elif line.split()[0][0] == "{" or line.split()[-1][-1] == "{":
                    access_to_get_size = True
    print("Отформатируйте код! Добавьте отступы!")
    return 0


def check_indentation_consistency(file_path, expected_indentation):
    if expected_indentation == 0:
        return
    with open(file_path, 'r') as file:
        errors = []
        if expected_indentation > 0:
            for line_number, line in enumerate(file, start=1):
                if line.strip() and (line[0] == ' ' or line[0] == '\t'):
                    for char in line:
                        if char == ' ':
                            pass
                        elif char == '\t':
                            errors.append("Строка " + str(
                                line_number) + " : использование табуляций при пробельных отступах запрещено!")
                            break
                        else:
                            break
        elif expected_indentation < 0:
            for line_number, line in enumerate(file, start=1):
                if line.strip() and (line[0] == ' ' or line[0] == '\t'):
                    for char in line:
                        if char == ' ':
                            errors.append("Строка " + str(
                                line_number) + " : использование пробелов при tab-отступах запрещено!")
                            break
                        elif char == '\t':
                            pass
                        else:
                            break
    print_errors(errors)
    return


def multiplicity_of_spaces(file_path, expected_indentation):
    comment_counter = 0
    with open(file_path, 'r') as file:
        errors = []
        for line_number, line in enumerate(file, start=1):
            number_of_spaces = 0

            if line.startswith('/*'):
                comment_counter += 1
            if line.strip().endswith('*/'):
                comment_counter -= 1
                continue
            if comment_counter != 0:
                continue

            if line.strip() and line[0] == ' ':
                for char in line:
                    if char == ' ':
                        number_of_spaces += 1
                    else:
                        break
                if number_of_spaces % expected_indentation != 0:
                    errors.append("Строка " + str(
                        line_number) + " : количество пробелов не соответствует заявленному отступу!")
    print_errors(errors)
    return
