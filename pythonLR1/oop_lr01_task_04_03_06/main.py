# Программирование на языке высокого уровня (Python).
# Задание № 04_03_06. Вариант 17
#
# Выполнил: Переверза В.А.
# Группа: ПИН-б-о-22-1
# E-mail: vladislav.pereverza@gmail.com


from oop_lr01_task_04_03_06.pen import Pen
from oop_lr01_task_04_03_06.pencil import Pencil
from oop_lr01_task_04_03_06.gel_pen import GelPen

if __name__ == "__main__":
    pen = Pen(color='black', width=0.3)
    print('Остаток ручки:', pen.remains)
    pen.write('какой-то текст')
    print('Остаток ручки:', pen.remains)
    print('-------')

    pencil = Pencil(color='gray', width=0.1, length=10)
    print('Длина карандаша', pencil.length)
    print('Толщина линии карандаша', pencil.width)
    pencil.write('ещё какой-то текст')
    print('Длина карандаша', pencil.length)
    print('Толщина линии карандаша', pencil.width)
    pencil.sharpen()
    print('Длина карандаша', pencil.length)
    print('Толщина линии карандаша', pencil.width)
    print('-------')

    gel_pen = GelPen(color='green', width=0.2)
    print('Остаток ручки:', gel_pen.remains)
    gel_pen.write('какой-то текст, уже третий')
    print('Остаток ручки:', gel_pen.remains)
