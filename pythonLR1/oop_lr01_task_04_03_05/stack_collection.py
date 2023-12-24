# Программирование на языке высокого уровня (Python).
# Задание № 04_03_05. Вариант 17
#
# Выполнил: Переверза В.А.
# Группа: ПИН-б-о-22-1
# E-mail: vladislav.pereverza@gmail.com


import json

from oop_lr01_task_04_03_04.stack import Stack


class StackCollection:
    def __init__(self,  data: list[Stack] | None = None) -> None:
        self._data = data or []

    def __str__(self) -> str:
        return '[\n\t' + ',\n\t'.join([str(stack) for stack in self._data]) + '\n]'

    def __getitem__(self, item: int) -> Stack:
        return self._data[item]

    def __setitem__(self, item: int, value: Stack) -> None:
        self._data[item] = value

    def __delitem__(self, item: int) -> None:
        del self._data[item]

    def add(self, item: Stack) -> None:
        if not isinstance(item, Stack):
            raise TypeError
        self._data.append(item)

    def save(self, filename: str) -> None:
        with open(filename, 'w', encoding='utf-8') as f:
            json.dump([stack.to_json_format() for stack in self._data], f)

    @classmethod
    def load(cls, filename: str) ->'StackCollection':
        with open(filename, 'r', encoding='utf-8') as f:
            json_data = [Stack.from_json_format(stack) for stack in json.load(f)]
            return StackCollection(json_data)
