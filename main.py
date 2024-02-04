import sys
from indent import find_first_indented_line, check_indentation_consistency, multiplicity_of_spaces
from matrix import check_indent_matrix
from style import set_brace_style, check_brace_style

size_indent = 0
style_indent = ''
file_path = sys.argv[1]


# Модуль стилей 1
style_indent = set_brace_style(file_path, style_indent)

# Модуль отступов

size_indent = find_first_indented_line(file_path, size_indent, style_indent)

check_indentation_consistency(file_path, size_indent)
if size_indent > 0:
    multiplicity_of_spaces(file_path, size_indent)

    # Модуль стилей 2

    check_brace_style(file_path, style_indent, size_indent)

    # Модуль матриц

    matrix = check_indent_matrix(file_path, size_indent, style_indent)


