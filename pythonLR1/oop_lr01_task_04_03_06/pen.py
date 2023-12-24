# Программирование на языке высокого уровня (Python).
# Задание № 04_03_06. Вариант 17
#
# Выполнил: Переверза В.А.
# Группа: ПИН-б-о-22-1
# E-mail: vladislav.pereverza@gmail.com


from oop_lr01_task_04_03_06.writing_affiliation import WritingAffiliation


class Pen(WritingAffiliation):
    NAME = 'ручка'

    def __init__(self, *, color: str, width: float, remains: int = 100):
        if not 0 <= remains <= 100:
            raise TypeError('Остаток ручки должен быть процентом')

        self._remains = remains
        super().__init__(color=color, width=width)

    @property
    def remains(self) -> int:
        return self._remains

    def write(self, text: str) -> None:
        if self.remains > 0 and super().write(text):
            self._remains -= 0.1
        elif self.remains <= 0:
            print(f'{self.NAME.capitalize()} закончилась')
