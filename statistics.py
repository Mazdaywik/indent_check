import os
import subprocess


def collect_statistics(directory):
    positive = 0  # положительные результаты
    negative = 0  # отрицательные результаты
    false_positive = 0  # ложноположительные результаты
    false_negative = 0  # ложноотрицательные результаты
    rej = 1
    acc = 0

    for filename in os.listdir(directory):
        file_path = os.path.join(directory, filename)
        my_result = subprocess.run(['python3', 'main.py', file_path], capture_output=True, text=True)


        if not my_result.returncode:
            print(filename)

        # Проверяем соответствие результатов
        if my_result.returncode and rej:
            negative += 1
        elif not my_result.returncode and not rej:
            positive += 1
        elif not my_result.returncode and rej:
            false_positive += 1
        elif my_result.returncode and not rej:
            false_negative += 1

    return {
        'positive': positive,
        'negative': negative,
        'false_positive': false_positive,
        'false_negative': false_negative
    }


print(collect_statistics('/Users/aleksey.egorov/Developer/DELETE/tests/rej'))
