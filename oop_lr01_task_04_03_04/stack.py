# Программирование на языке высокого уровня (Python).
# Задание № 04_03_04. Вариант 17
#
# Выполнил: Переверза В.А.
# Группа: ПИН-б-о-22-1
# E-mail: vladislav.pereverza@gmail.com

import json
from json.decoder import JSONDecodeError
from typing import Any


class Stack:
    def __init__(self, items: list | str = None) -> None:
        type_error = TypeError('Неверный формат данных для стека')
        self.__stack = items or []
        if isinstance(self.__stack, str):
            try:
                self.__stack = json.loads(self.__stack)
            except JSONDecodeError as exc:
                raise type_error from exc
        if not isinstance(self.__stack, list):
            raise type_error

    def push(self, item) -> None:
        self.__stack.append(item)

    def pop(self) -> Any:
        return self.__stack.pop()

    def peek(self) -> Any:
        return self.__stack[-1]

    def copy(self) -> 'Stack':
        return Stack(self.__stack.copy())

    def save(self, filename) -> None:
        with open(filename, 'w', encoding='utf-8') as f:
            json.dump(self.__stack, f)

    @classmethod
    def load(cls, filename) -> 'Stack':
        with open(filename, 'r', encoding='utf-8') as f:
            return Stack(f.read())

    @classmethod
    def from_string(cls, stack: str) -> 'Stack':
        return Stack(stack)

    @classmethod
    def from_json_format(cls, stack: list[Any]) -> 'Stack':
        return Stack(stack)

    def to_json_format(self) -> list[Any]:
        return self.__stack

    def __str__(self) -> str:
        return str(self.__stack)

    def __repr__(self) -> str:
        return str(self.__stack)

    def __len__(self) -> int:
        return len(self.__stack)

    def __bool__(self) -> bool:
        return bool(self.__stack)

    def __add__(self, item) -> 'Stack':
        result = self.copy()
        result.push(item)
        return result

    def __radd__(self, item) -> 'Stack':
        return self.__add__(item)

    def __eq__(self, other) -> bool:
        return self.__stack == other.__stack

    def __ne__(self, other) -> bool:
        return not self.__eq__(other)
