# Программирование на языке высокого уровня (Python).
# Задание № 04_03_06. Вариант 17
#
# Выполнил: Переверза В.А.
# Группа: ПИН-б-о-22-1
# E-mail: vladislav.pereverza@gmail.com


from oop_lr01_task_04_03_06.writing_affiliation import WritingAffiliation


class Pencil(WritingAffiliation):
    NAME = 'карандаш'

    def __init__(self, *, color: str, width: float, length: float = 15) -> None:
        self._length = length
        self._stock_width = width
        super().__init__(color=color, width=width)

    @property
    def length(self) -> float:
        return self._length

    def write(self, text: str) -> None:
        if self.length > 0 and self.width < 0.1 and super().write(text):
            self._width += 0.01
        elif self.length <= 0:
            print(f'{self.NAME.capitalize()} закончился')
        elif self.width >= 0.1:
            print(f'{self.NAME.capitalize()} затупился')

    def sharpen(self) -> None:
        self._width = self._stock_width
        self._length -= 0.1
        print(f'{self.NAME.capitalize()} поточен')
